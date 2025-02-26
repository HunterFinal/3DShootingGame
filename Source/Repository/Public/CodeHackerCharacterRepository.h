// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory>
#include "IRepository.h"

class FCharacterModel;

/**
 * 
 */
namespace CodeHacker::Database
{
	namespace Repository
	{
		class REPOSITORY_API FCodeHackerCharacterRepository final : public IRepository<FCharacterModel>
		{
			using Repository = typename FCodeHackerCharacterRepository;
			using Item = typename FCharacterModel;
		public:
			FCodeHackerCharacterRepository();
			~FCodeHackerCharacterRepository();

			FCodeHackerCharacterRepository(Repository&&) noexcept;
			Repository&& operator=(Repository&&) noexcept;

		private:
			FCodeHackerCharacterRepository(const Repository&) = delete;
			Repository& operator=(const Repository&) = delete;

		public:
			Item* GetByID(int32_t itemId) const override final;
			int32_t GetAll(std::vector<Item*>& outItems) const override final;
			void Delete(Item*) override final;
			void DeleteById(int32_t) override final;
			void Save(Item*) override final;

		private:
			class RepositoryImpl;
			std::unique_ptr<RepositoryImpl> m_pImpl;
		};
	}
}
