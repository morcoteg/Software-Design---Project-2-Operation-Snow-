/**
* \file LinkedListActive.h
*
* \author Gabriel Morcote
*
* \brief class that represents Linked List of ACTIVE Snowflake objects
*/

#pragma once
#include "LinkedList.h"
#include "LinkedListPool.h"
#include "Snowflake.h"

class CSnowflakeSystem;


class CLinkedListActive : public CLinkedList
{
public:
	CLinkedListActive();
	virtual ~CLinkedListActive();
	
	/// Our drawing function
	void Draw(Gdiplus::Graphics *graphics);

	/// Update the system based on a timer
	void Update(double elapsed);

	// is owned by the SYSTEM
	void SetSnowflakeSystem(CSnowflakeSystem *system){ mSnowflakeSystem = system; }

	//refers to a pool
	void SetLinkedListPool(std::shared_ptr<CLinkedListPool> pool){ mLinkedListPool = pool; }

	std::shared_ptr<CLinkedListPool> GetPool(){ return mLinkedListPool; }

private:
	CSnowflakeSystem *mSnowflakeSystem = nullptr;	///< The associated Snowflake System

	std::shared_ptr<CLinkedListPool> mLinkedListPool = nullptr;				///< The associated Pool of snowflakes

};

