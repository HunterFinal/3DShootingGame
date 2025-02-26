// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#ifndef REPOSITORY_INTERFACE
#define REPOSITORY_INTERFACE

namespace std
{
	template<typename T>
	class vector<T>;
}
/**
 * 
 */
template<typename Item>
class IRepository
{
public:
	virtual ~IRepository() = 0 {};

public:
	virtual Item* GetByID(int32_t itemId) const = 0;
	virtual int32_t GetAll(std::vector<Item*>& outItems) const = 0;
	virtual void Delete(Item*) = 0;
	virtual void DeleteById(int32_t) = 0;
	virtual void Save(Item*) = 0;
};

#endif
