# raylib-template

Visual Studio project template for C++ games made with raylib.

## Requirements

- Visual Studio 2026 (toolset v145) with the "Desktop development with C++" workload
- Windows x64

raylib 6.2 is included in `lib/`, no extra setup needed.

## Project structure

```
├─ bin/       Executables, one folder per configuration (generated on build)
├─ obj/       Intermediate files, one folder per configuration (generated on build)
├─ lib/       External libraries (include/ and lib/ inside each one)
├─ src/       Source code
├─ res/       Final assets loaded by the game
└─ res_raw/   Raw/editable assets (.psd, .aseprite, etc.)
```

## Configuration

| | Debug | Release |
|---|---|---|
| Console | Yes | No |
| Warning level | 4, treated as errors | 4, treated as errors |
| C++ standard | C++20 | C++20 |

- raylib is linked statically, no `.dll` needed next to the executable.
- `src/` is an include directory, so includes don't need relative paths.
- A post-build step copies `res/` into `bin/<Configuration>/res/`, so the `.exe` runs outside Visual Studio.

## Starting a new project

1. Create a new repository from this template on GitHub (**Use this template**).
2. Rename `Game.slnx`, `Game.vcxproj`, `Game.vcxproj.filters` and update the project name inside `Game.slnx` and `<RootNamespace>` in `Game.vcxproj`.
3. Rename the `game` namespace to the project's namespace.
4. Open the `.slnx`, select **x64**, and build.
