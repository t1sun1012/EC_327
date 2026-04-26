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

## Step 2 Notes

- Replaced the fixed-size arrays in `Model` with STL `list` containers.
- Added `active_ptrs`, which stores the objects that should still be updated and displayed.
- Kept `object_ptrs` as the ownership list. The destructor deletes objects from `object_ptrs`, so even objects removed from `active_ptrs` still get cleaned up.
- Kept type-specific lists for command lookup: `mage_ptrs`, `spire_ptrs`, `hideout_ptrs`, and `roamingdemon_ptrs`.
- Updated `Model::Update()`, `Display()`, `ShowStatus()`, and all `Get*Ptr()` functions to use list iterators.
- Added a removal pass in `Model::Update()` that removes non-visible objects from `active_ptrs` and prints `Dead object removed.`
- Learning point: lists remove the old artificial limit of 10 objects and prepare the program for PA4 Step 4, where new objects are created at runtime.
- Learning point: there is an important ownership difference between deleting an object and removing one pointer from a list. We remove from `active_ptrs` without deleting, because `object_ptrs` still owns the object.

## Step 3 Notes

- Added `Input_Handling.h` with the `Invalid_Input` exception class from the PA4 handout.
- Updated `GameCommand` so invalid object IDs throw `Invalid_Input` instead of printing errors directly.
- Added helper input functions in `main.cpp` for reading integers, non-negative integers, and doubles.
- Wrapped command handling in a `try`/`catch` block so input errors are reported from one central place.
- Tested invalid command letters, wrong argument types, invalid Mage IDs, and normal movement after an error.
- Learning point: exceptions separate the normal command path from error handling. The command code can focus on "what should happen" while the catch block handles recovery.
- Learning point: after a stream input failure, `cin.clear()` and `cin.ignore(...)` are needed so the next command can be read correctly.

## Step 4 Notes

- Added the `n TYPE ID X Y` command for creating objects during program execution.
- Added `Model::NewCommand(char type, int id, Point2D location)` to own the object creation logic.
- Supported PA4 type codes:
  - `s` creates a `ManaSpire`
  - `d` creates a `DemonHideout`
  - `g` creates a `Mage`
  - `o` creates a `RoamingDemon`
- New objects are added to the correct type-specific list, `object_ptrs`, and `active_ptrs`.
- Duplicate ID checks are type-specific, so a Mage and a ManaSpire can share the same ID, but two Mages cannot.
- Unknown type codes and duplicate IDs throw `Invalid_Input`.
- Learning point: replacing arrays with lists in Step 2 made Step 4 much easier, because new objects can be appended without worrying about fixed array capacity.
- Learning point: `Model` is the right place to create new objects because it owns the object lists and destructor cleanup.

## Step 5 Notes

- Added `save(ofstream& file)` and `restore(ifstream& file, Model& model)` to the `GameObject` hierarchy.
- Each derived class saves/restores its own fields after calling its superclass version, following the same pattern as `ShowStatus()`.
- Added `Model::save()` to write the current time, an active-object catalog, and then each active object's data.
- Added `Model::restore()` to delete the current world, recreate objects from the catalog, and then restore the saved field values.
- Added commands:
  - `S filename` saves the game.
  - `R filename` restores the game.
- Pointer fields are saved as object IDs instead of memory addresses. For example, a Mage saves the ID of its current spire, hideout, or demon.
- Tested saving/restoring at startup and saving/restoring after adding new objects and making a RoamingDemon follow a Mage.
- Learning point: the save order and restore order must match exactly because file streams are sequential.
- Learning point: raw pointer addresses cannot be persisted. Object IDs are the stable information that lets the restored model reconnect relationships.

