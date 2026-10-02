#pragma once
#include <cstdint>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

namespace duatfall {
struct Chamber { std::string id; std::uint32_t weight; };
class RunGenerator {
public:
    explicit RunGenerator(std::uint32_t seed) : state_(seed == 0 ? 0x6d2b79f5U : seed) {}
    std::vector<std::string> generate(const std::vector<Chamber>& table, std::size_t count) {
        if (table.empty() || count > 10000) throw std::invalid_argument("invalid chamber table or run length");
        std::uint64_t sum = 0;
        for (const auto& room : table) {
            if (room.id.empty()) throw std::invalid_argument("empty chamber identifier");
            sum += room.weight;
        }
        if (sum == 0 || sum > std::numeric_limits<std::uint32_t>::max()) throw std::invalid_argument("invalid total chamber weight");
        const auto total = static_cast<std::uint32_t>(sum);
        std::vector<std::string> result; result.reserve(count);
        for (std::size_t i = 0; i < count; ++i) {
            std::uint32_t choice = bounded(total);
            for (const auto& room : table) {
                if (choice < room.weight) { result.push_back(room.id); break; }
                choice -= room.weight;
            }
        }
        return result;
    }
private:
    std::uint32_t next() { state_ ^= state_ << 13; state_ ^= state_ >> 17; state_ ^= state_ << 5; return state_; }
    std::uint32_t bounded(std::uint32_t bound) {
        // Reject the incomplete upper bucket. No standard-library distribution drift.
        const std::uint32_t limit = std::numeric_limits<std::uint32_t>::max() - std::numeric_limits<std::uint32_t>::max() % bound;
        std::uint32_t value; do { value = next(); } while (value > limit);
        return (value - 1U) % bound;
    }
    std::uint32_t state_;
};
}
