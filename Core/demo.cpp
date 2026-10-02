#include "DuatfallCore.h"
#include <iostream>
static void check(bool ok, const char* message) { if (!ok) throw std::runtime_error(message); }
static void tests() {
    const std::vector<duatfall::Chamber> table{{"combat", 5}, {"rest", 2}, {"boss", 0}};
    duatfall::RunGenerator first(123), replay(123), other(124);
    const auto rooms = first.generate(table, 100);
    check(rooms == replay.generate(table, 100), "same seed reproduces run");
    check(rooms != other.generate(table, 100), "seed affects the run");
    for (const auto& room : rooms) check(room == "combat" || room == "rest", "zero weight excluded");
    duatfall::RunGenerator zero(0); check(zero.generate({{"only", 1}}, 2).size() == 2, "zero seed terminates");
    bool rejected = false;
    try { zero.generate({{"none", 0}}, 2); } catch (const std::invalid_argument&) { rejected = true; }
    check(rejected, "zero total weight rejected");
    rejected = false;
    try { zero.generate({{"a", 4294967295U}, {"b", 1}}, 2); } catch (const std::invalid_argument&) { rejected = true; }
    check(rejected, "weight sum overflow rejected");
    rejected = false;
    try { zero.generate(table, 10001); } catch (const std::invalid_argument&) { rejected = true; }
    check(rejected, "run size bounded");
}
int main(int argc, char** argv) {
    try {
        if (argc == 2 && std::string(argv[1]) == "--self-test") { tests(); std::cout << "Duatfall core checks passed\n"; return 0; }
        if (argc != 1) { std::cerr << "Usage: core-demo [--self-test]\n"; return 2; }
        duatfall::RunGenerator generator(123);
        const auto run = generator.generate({{"combat", 5}, {"rest", 2}}, 5);
        std::cout << "seed=123 rooms="; for (const auto& room : run) std::cout << room << ' '; std::cout << '\n';
    } catch (const std::exception& error) { std::cerr << error.what() << '\n'; return 1; }
}
