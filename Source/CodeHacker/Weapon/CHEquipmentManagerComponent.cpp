// Fill out your copyright notice in the Description page of Project Settings.


#include "CHEquipmentManagerComponent.h"

#include "CHEquipmentDefinition.h"
#include "CHEquipmentInstance.h"

#include "MLibrary.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHEquipmentManagerComponent)

//---FCHEquipmentListEntry Definition
#pragma region FCHEquipmentListEntry Definition
FString FCHEquipmentListEntry::ToString() const
{
	return FString::Printf(TEXT("%s of %s"), *GetNameSafe(m_instance), *GetNameSafe(m_equipmentDefClass));
}

TSubclassOf<UCHEquipmentDefinition> FCHEquipmentListEntry::GetDefinitionClass() const
{
	return m_equipmentDefClass;
}

UCHEquipmentInstance* FCHEquipmentListEntry::GetInstance() const
{
	return m_instance;
}
#pragma endregion FCHEquipmentListEntry Definition
//---End of FCHEquipmentListEntry Definition

//---FCHEquipmentList Definition
#pragma region FCHEquipmentList Definition
UCHEquipmentInstance* FCHEquipmentList::AddEntry(TSubclassOf<UCHEquipmentDefinition> equipmentDef)
{
	check(equipmentDef != nullptr);
	check(GLOBAL_SCOPE::IsValid(m_ownerComp));

	// CDO = Class Default Object
	const UCHEquipmentDefinition* equipDefCDO = GetDefault<UCHEquipmentDefinition>(equipmentDef);
	
	// MEMO
	// Definitionのオブジェクトを作るじゃなく、デフォルトオブジェクトを取得することによって、
	// メモリの確保と解放が省かれる？
	// デフォルトオブジェクトを使って初期化する（BP classによってパラメーター初期化済み）
	TSubclassOf<UCHEquipmentInstance> instanceType = equipDefCDO->InstanceType;
	if (instanceType == nullptr)
	{
		instanceType = UCHEquipmentInstance::StaticClass();
	}

	UCHEquipmentInstance* instance = NewObject<UCHEquipmentInstance>(m_ownerComp->GetOwner(), instanceType);
	FCHEquipmentListEntry newEntry(equipmentDef, instance);

	instance->SpawnAppearanceActors(equipDefCDO->AppearancesToSpawn);

	return instance;
}

void FCHEquipmentList::RemoveEntry(UCHEquipmentInstance* removeInstance)
{
	// ConstIterator bool()
	for (auto entryIt = m_entries.CreateIterator(); entryIt; ++entryIt)
	{
		const FCHEquipmentListEntry& entry = *entryIt;
		if (entry.GetInstance() == removeInstance)
		{
			removeInstance->DestroyAppearanceActors();

			entryIt.RemoveCurrent();
		}
	}
}

const TArray<FCHEquipmentListEntry>& FCHEquipmentList::GetEntries_ConstRef() const
{
	return m_entries;
}
#pragma endregion FCHEquipmentList Definition
//--- End of FCHEquipmentList Definition

// Sets default values for this component's properties
UCHEquipmentManagerComponent::UCHEquipmentManagerComponent()
	: m_equipmentList(this)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;
	// ...
}

void UCHEquipmentManagerComponent::InitializeComponent()
{
	Super::InitializeComponent();
}

void UCHEquipmentManagerComponent::UninitializeComponent()
{
	const TArray<FCHEquipmentListEntry>& constEntries = m_equipmentList.GetEntries_ConstRef();
	TArray<UCHEquipmentInstance*> allEquipmentInstances;

	for (const FCHEquipmentListEntry& entry : constEntries)
	{
		allEquipmentInstances.Emplace(entry.GetInstance());
	}

	for (UCHEquipmentInstance* instance : allEquipmentInstances)
	{
		UnequipItem(instance);
	}

	Super::UninitializeComponent();
}


// Called when the game starts
void UCHEquipmentManagerComponent::BeginPlay()
{
	Super::BeginPlay();
}

UCHEquipmentInstance* UCHEquipmentManagerComponent::EquipItem(TSubclassOf<UCHEquipmentDefinition> equipmentDef)
{
	if (equipmentDef == nullptr)
	{
		return nullptr;
	}

	UCHEquipmentInstance* equipmentInstance = m_equipmentList.AddEntry(equipmentDef);
	if (equipmentInstance != nullptr)
	{
		equipmentInstance->OnEquipped();
	}

	return equipmentInstance;
}

void UCHEquipmentManagerComponent::UnequipItem(UCHEquipmentInstance* removeItem)
{
	if (GLOBAL_SCOPE::IsValid(removeItem))
	{
		removeItem->OnUnequipped();

		m_equipmentList.RemoveEntry(removeItem);
	}
}



