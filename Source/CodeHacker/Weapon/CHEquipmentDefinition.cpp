// Fill out your copyright notice in the Description page of Project Settings.
/*

UCHEquipmentDefinition.cpp

Author : MAI ZHICONG(バクチソウ)

Description : 装備品のデータ定義

Update History: 2025/02/27 作成

Version : alpha_1.0.0

Encoding : UTF-8 

*/
#include "CHEquipmentDefinition.h"

#include "CHEquipmentInstance.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHEquipmentInstance)

UCHEquipmentDefinition::UCHEquipmentDefinition()
{
  InstanceType = UCHEquipmentInstance::StaticClass();
}



