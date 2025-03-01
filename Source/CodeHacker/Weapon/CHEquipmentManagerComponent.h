// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"

#include "CHEquipmentManagerComponent.generated.h"

class UCHEquipmentDefinition;
class UCHEquipmentInstance;

USTRUCT()
struct FCHEquipmentListEntry
{
	GENERATED_BODY()

	FCHEquipmentListEntry()
		: m_equipmentDefClass(nullptr)
		, m_instance(nullptr)
	{}

	FCHEquipmentListEntry(
												TSubclassOf<UCHEquipmentDefinition> equipmentDef,
												UCHEquipmentInstance* instance
											 )
		: m_equipmentDefClass(equipmentDef)
		, m_instance(instance)
	{}

	FString ToString() const;
	TSubclassOf<UCHEquipmentDefinition> GetDefinitionClass() const;
	UCHEquipmentInstance* GetInstance() const;

private:
	UPROPERTY()
	TSubclassOf<UCHEquipmentDefinition> m_equipmentDefClass;

	UPROPERTY()
	TObjectPtr<UCHEquipmentInstance> m_instance;

};

USTRUCT()
struct FCHEquipmentList
{
	GENERATED_BODY()

public:
	FCHEquipmentList()
		: m_entries{}
		, m_ownerComp(nullptr)
	{
	}

	FCHEquipmentList(UActorComponent* inOwnerComp)
		: m_entries{}
		, m_ownerComp(inOwnerComp)
	{
	}

public:
	UCHEquipmentInstance* AddEntry(TSubclassOf<UCHEquipmentDefinition>);
	void RemoveEntry(UCHEquipmentInstance*);
	const TArray<FCHEquipmentListEntry>& GetEntries_ConstRef() const;

private:
	UPROPERTY()
	TArray<FCHEquipmentListEntry> m_entries;

	UPROPERTY()
	TObjectPtr<UActorComponent> m_ownerComp;
};










UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CODEHACKER_API UCHEquipmentManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCHEquipmentManagerComponent();

	//---UActorComponent Interface
	#pragma region UActorComponent Interface
	virtual void InitializeComponent() override;
	virtual void UninitializeComponent() override;
	#pragma endregion UActorComponent Interface
	//---UActorComponent Interface

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UCHEquipmentInstance* EquipItem(TSubclassOf<UCHEquipmentDefinition> equipmentDef);
	void UnequipItem(UCHEquipmentInstance* EquipmentInstance);	

private:
	UPROPERTY()
	FCHEquipmentList m_equipmentList;
};
