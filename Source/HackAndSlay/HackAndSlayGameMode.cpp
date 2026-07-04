#include "HackAndSlayGameMode.h"
#include "HackAndSlayCharacter.h"

AHackAndSlayGameMode::AHackAndSlayGameMode()
{
	DefaultPawnClass = AHackAndSlayCharacter::StaticClass();
}
