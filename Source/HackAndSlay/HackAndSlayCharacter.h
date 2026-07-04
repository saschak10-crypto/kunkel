#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HackAndSlayCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

/**
 * Third-person player character. Provides the core control set from the
 * concept doc (docs/Konzept.md, section 6.1): move, look, dodge, attack.
 * Combat and dodge logic are left as stubs for the combat-prototype pass.
 */
UCLASS()
class HACKANDSLAY_API AHackAndSlayCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AHackAndSlayCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Dodge(const FInputActionValue& Value);
	void Attack(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat")
	float DodgeCooldownSeconds = 0.6f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat")
	float AttackComboWindowSeconds = 0.8f;

private:
	bool bIsDodging = false;
	float DodgeCooldownRemaining = 0.0f;
	int32 CurrentComboIndex = 0;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	UCameraComponent* FollowCamera;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* DodgeAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* AttackAction;
};
