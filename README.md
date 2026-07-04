# Hack and Slay

3D Third-Person Hack-and-Slay Action-RPG built in Unreal Engine 5.

See [`docs/Konzept.md`](docs/Konzept.md) for the full game design concept
(story, mechanics, enemy types, progression, scope).

## Requirements

- Unreal Engine 5.3+ (installed via the Epic Games Launcher or built from
  source). Not bundled in this repo — Epic's EULA and the ~30+ GB engine
  install mean it has to be installed locally.
- Visual Studio 2022 (Windows) or Xcode (Mac) with the Unreal Engine
  workload, for compiling the C++ module.

## Opening the project

1. Install Unreal Engine 5.3 (or update `EngineAssociation` in
   `HackAndSlay.uproject` to match your installed version).
2. Right-click `HackAndSlay.uproject` → "Generate Visual Studio project files"
   (or run `UnrealBuildTool` / `UnrealVersionSelector` equivalently).
3. Open `HackAndSlay.uproject` in Unreal Editor, or open the generated
   `.sln` and launch with debugging.
4. Follow [`Content/README.md`](Content/README.md) to create the Enhanced
   Input assets and a test level referenced by the C++ character/game mode,
   since binary editor assets can't be authored outside the editor.

## Project layout

- `Source/HackAndSlay/` — core C++ module (`AHackAndSlayCharacter`,
  `AHackAndSlayGameMode`)
- `Config/` — engine/game/input defaults
- `Content/` — Blueprint/asset content (created in-editor, see above)
- `docs/` — design documentation
