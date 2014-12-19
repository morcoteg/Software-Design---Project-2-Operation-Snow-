/**
* \file LinkedListPool.h
*
* \author Gabriel Morcote
*
* \brief class that represents Linked Pool of INACTIVE Snowflake objects
*/

#pragma once

#include "LinkedList.h"
#include "Snowflake.h"

class CSnowflakeSystem;
class CLinkedListActive;

class CLinkedListPool :	public CLinkedList
{
public:
	CLinkedListPool();
	virtual ~CLinkedListPool();

	// is owned by the SYSTEM
	void SetSnowflakeSystem(CSnowflakeSystem *system){ mSnowflakeSystem = system; }

	//refers to active list
	void SetLinkedListActive(std::shared_ptr<CLinkedListActive> active){ mLinkedListActive = active; }
	void InsertInactive(CSnowflake *snowflake);
	
private:
	CSnowflakeSystem *mSnowflakeSystem = nullptr;	///< The associated Snowflake System

	std::shared_ptr<CLinkedListActive> mLinkedListActive = nullptr;				///< The associated Pool of ACTIVE snowflakes
};

