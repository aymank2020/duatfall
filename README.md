# DUATFALL

> A top-down action roguelite set in the Duat, the ancient Egyptian underworld. Built in **Unreal Engine 5.8 (C++)**.

**Status:** pre-production. The design is locked and the engine setup is in progress. No playable build yet. Progress is tracked milestone by milestone in [`docs/STATUS.md`](docs/STATUS.md).

## The pitch
A fallen scribe descends through the twelve hours of the night. Each run you clear procedurally assembled chambers, choose one of three boons from Ra, Thoth, Sekhmet or Anubis, and face the Hour Guardian. When you die you return to the Hall of Ma'at, where Feathers buy permanent upgrades.

## Technical goals
| Area | Approach |
|---|---|
| Abilities & stats | Gameplay Ability System: attribute set, combo attack, dash with i-frames, boons as Gameplay Effects |
| Enemy AI | StateTree (Idle → Chase → Attack → Recover), with ranged and elite variants and a 3-phase boss |
| Run generation | Seeded `FRandomStream` in a GameInstance subsystem; weighted chamber tables using Level Instances |
| Data | All tuning values in Primary Data Assets and DataTables; no magic numbers in code |
| Persistence | Versioned SaveGame with migration tests |
| Quality | Automation specs for every system, run headless from the CLI before each commit |

## Roadmap
- [ ] M0 Repository, project and CI script
- [ ] M1 Character, input, dash
- [ ] M2 GAS combat
- [ ] M3 Enemies and StateTree AI
- [ ] M4 Seeded run generation
- [ ] M5 Boon system (16 boons across 4 gods)
- [ ] M6 Hour Guardian boss
- [ ] M7 Meta-progression and save/load
- [ ] M8 UI and game-feel pass
- [ ] M9 Packaged build and performance report

## Documents
- [Game Design Document](docs/GDD.md)

## Assets
Only engine primitives, Starter Content and CC0 assets are used. Each one is listed in `ASSETS_LICENSES.md` as it is added.

## Development note
Development uses AI coding assistants under my direction and review. Commits carry honest co-author trailers, and the history is never rewritten.
