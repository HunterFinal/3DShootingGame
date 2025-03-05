// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "CodeHackerCharacter.generated.h"

class UCHSpringArmComponent;
class UCHCameraComponent;

class UCHAbilitySystemComponent;
class UCodeHackerPawnExtensionComponent;

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game, meta = (ShortTooltip = "Code Hackerプロジェクトに使われるキャラクターベースクラス"))
class ACodeHackerCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACodeHackerCharacter();

	//---Begin of APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	//---End of APawn Interface
	
	//---Begin of IAbilitySystemInterface Interface
	UAbilitySystemComponent* GetAbilitySystemComponent() const override final;
	//---End of IAbilitySystemInterface Interface

	UFUNCTION(BlueprintCallable, Category = "CodeHacker|Character")
	UCHAbilitySystemComponent* GetCHAbilitySystemComponent() const;

private:
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCHSpringArmComponent> CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCHCameraComponent> FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UCHEquipmentDefinition> RangedWeaponDef;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UCHEquipmentManagerComponent> EquipmentManagerComp;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UCodeHackerPawnExtensionComponent> PawnExtComponent;

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
			

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class UCHSpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCHCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

