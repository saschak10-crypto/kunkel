# Content

Empty on purpose: Unreal's binary assets (`.uasset`/`.umap`) can only be
created and saved from within the Unreal Editor, which isn't available in
this environment. Once the project is opened in UE5:

1. Create the Enhanced Input assets referenced by `AHackAndSlayCharacter`:
   - `IMC_Default` (Input Mapping Context)
   - `IA_Move`, `IA_Look`, `IA_Dodge`, `IA_Attack` (Input Actions)
2. Create a Blueprint child of `AHackAndSlayCharacter` (e.g. `BP_PlayerCharacter`)
   and assign the input assets above to its defaults.
3. Create a test level (`Content/Maps/TestArena`) and set it as the project's
   default map, with `AHackAndSlayGameMode` as its game mode.
4. Assign a mesh/animation blueprint to the character for visual feedback.
