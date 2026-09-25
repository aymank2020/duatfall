# DUATFALL: Game Design Document (v0.1)

## 1. Overview
- **Genre:** top-down isometric action roguelite
- **Engine:** Unreal Engine 5.8, gameplay in C++
- **Platform:** PC (Windows); controller and mouse/keyboard
- **Session:** 20–35 minute runs
- **Inspirations:** Hades (boon choice, story that continues through death), Dead Cells (tight combat), Egyptian funerary texts (the Amduat, the Book of Gates)

## 2. Design pillars
1. **Every death teaches.** Runs end, but Feathers, lore and unlocks always carry forward.
2. **Readable, responsive combat.** Clear telegraphs, forgiving input buffering, and a dash that always feels like an escape.
3. **Builds from choices, not stats.** Boons change *how* you play, not just how much damage you do.

## 3. Core loop
Enter chamber → clear waves → choose a reward door (boon / Feathers / healing) → repeat through one Hour → fight the Hour Guardian → die or win → spend Feathers in the Hall of Ma'at → start again.

## 4. Player kit
| Action | Behaviour |
|---|---|
| Attack | 3-hit combo; the third hit knocks back |
| Dash | Short invincibility window; 1 charge, more from upgrades |
| Special | Area strike that spends Ka |
| Cast | Ranged projectile that lodges in enemies and can be picked back up |

**Attributes:** Health, MaxHealth, Ka, MoveSpeed, AttackPower, CritChance.

## 5. Gods and boons
| God | Theme | Example boon |
|---|---|---|
| Ra | Burning, sunlight | *Solar Edge:* attacks apply Burn (damage over time) |
| Thoth | Knowledge, Ka | *Scribe's Echo:* each special repeats itself at 40% strength |
| Sekhmet | Fury, crits | *Lioness Rage:* +crit chance while below 50% HP |
| Anubis | Death, protection | *Scales of Judgment:* killing a marked enemy restores Ka |

There are 16 boons at launch of the MVP, in four rarities, with prerequisites and exclusions (duo boons come later).

## 6. Enemies
| Enemy | Role |
|---|---|
| Shabti Soldier | Melee pressure; telegraphed lunge |
| Ba Wisp | Ranged kiter that keeps its distance |
| Scarab Swarm | Many weak units; punishes standing still |
| Tomb Warden (elite) | Shielded; must be flanked or broken with the special |
| **Hour Guardian (boss)** | 3 phases at 66% and 33% HP; arena hazards change each phase |

## 7. Progression
- **Within a run:** boons, healing, a temporary Ka cap.
- **Across runs:** Feathers buy 8 permanent upgrades in the Hall of Ma'at (extra dash, starting Ka, reroll a boon offer, and more).

## 8. Art and audio direction
Stylised low-poly look with strong silhouettes. Palette: lapis blue shadows against amber torchlight. Hieroglyph-inspired UI. Audio uses frame drums and ney flute, with dynamic layers that rise in combat.

## 9. Scope of the MVP
One Hour (region), 4 enemy types, 1 boss, 16 boons, 8 upgrades, and saving. **Out of scope:** story dialogue system, multiple weapons, duo boons.

## 10. Success criteria
- 60 fps at 1080p medium on an RTX 4050 Laptop
- The same seed reproduces the same run
- Every system is covered by automation tests
