// Fill out your copyright notice in the Description page of Project Settings.


#include "CodeHackerCharacterRepository.h"
#include <vector>

namespace CodeHacker::Database
{
	namespace Repository
	{
    using Item = typename FCharacterModel;
    class FCodeHackerCharacterRepository::RepositoryImpl
    {

    };
    FCodeHackerCharacterRepository::FCodeHackerCharacterRepository()
    {
    }

    FCodeHackerCharacterRepository::~FCodeHackerCharacterRepository()
    {
    }

    Item* FCodeHackerCharacterRepository::GetByID(int32_t itemId) const
    {
      return nullptr;
    }
    int32_t FCodeHackerCharacterRepository::GetAll(std::vector<Item*>& outItems) const
    {
      return 0;
    }
    void FCodeHackerCharacterRepository::Delete(Item*)
    {

    }
    void FCodeHackerCharacterRepository::DeleteById(int32_t)
    {

    }
    void FCodeHackerCharacterRepository::Save(Item*)
    {

    }
  }
}

