# PA4 Learning Log

## Goal

PA4 builds on the PA3 Magical Demon Hunters game. The main learning goals are dynamic allocation, program organization, exceptions, save/load persistence, and STL containers.

## Starting Point

- The `PA4/codes` folder currently starts as a copy of the PA3 implementation.
- PA3 uses fixed-size arrays in `Model` to store `GameObject*`, `Mage*`, `ManaSpire*`, and `DemonHideout*`.
- PA4 asks us to replace those arrays with STL `list` containers and add new runtime behavior.

## Required PA4 Steps

1. Add a new `RoamingDemon` class derived from `GameObject`.
2. Replace `Model` arrays with STL `list` containers.
3. Add exception-based input handling using an `Invalid_Input` class.
4. Add a new `n TYPE ID X Y` command to create objects during program execution.
5. Add save and restore commands using persistent object data.

## Current Design Questions

- How should a `RoamingDemon` detect a Mage? The handout allows same-location contact, proximity, random movement, or smarter behavior.
- How should a Mage be affected by a RoamingDemon? The handout says the Mage should lose health/mana faster, but leaves the exact rule to us.
- How much save/restore state should we preserve for each class while keeping the implementation manageable?

## Initial Implementation Strategy

- Start with the smallest working change for each step, then test before moving on.
- Keep PA3 behavior intact unless PA4 explicitly changes it.
- Prefer simple rules for new behavior so the program remains easy to debug.
- Record each major concept learned here as we complete the implementation.

## RoamingDemon Design Decision

- We will keep `RoamingDemon` behavior simple and reliable for grading instead of doing extra-credit behavior that requires a YouTube video.
- Detection rule: a `RoamingDemon` starts following a Mage when they occupy the same location.
- Combat effect: while a Mage is followed by a `RoamingDemon`, the Mage loses extra mana during movement. This satisfies the handout requirement that contact with a demon makes the Mage lose resources faster.
- We will not implement random movement, smart seeking, computer mode, or additional extra-credit classes unless we decide to revisit extra credit later.

## Step 1 Notes

- Added `RoamingDemon.h` and `RoamingDemon.cpp` as a new class derived from `GameObject`.
- Added the required RoamingDemon data: attack, health, variant, combat state, name, and current Mage pointer.
- Added two default RoamingDemons to `Model` at `(10, 12)` and `(15, 5)` and included them in `object_ptrs`.
- Added a same-location contact check in `Model::Update()`. When a living demon and non-knocked-out Mage share coordinates, the demon begins following that Mage.
- Added a `current_demon` pointer to `Mage`. If it is set, movement costs 2 mana instead of the PA3 cost of 1 mana.
- Learning point: inheritance let us add `RoamingDemon` with minimal changes to `View`, because `View` already plots any `GameObject*` through polymorphism.
- Learning point: adding a new interacting object still required careful coordination between classes: `Model` detects contact, `RoamingDemon` records who it follows, and `Mage` applies the gameplay penalty.

