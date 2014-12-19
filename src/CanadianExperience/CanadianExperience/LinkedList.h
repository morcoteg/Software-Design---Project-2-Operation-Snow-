/**
* \file LinkedList.h
*
* \author Gabriel Morcote
*
* \brief class that represents Linked Lists of Snowflake objects
*/

#pragma once
#include <memory>
#include "Snowflake.h"

class CLinkedList
{
public:
	CLinkedList();
	virtual ~CLinkedList();

	/// INSERT/DELETE/CLEAR snowflakes from the list, Derived classes can use these methods
	virtual void Insert();
	virtual void Delete(CSnowflake *snowflake);
	virtual void Clear();

	// to move snowflake to the Inactive POOL
	void AddFront(std::shared_ptr<CSnowflake> snowflake);

	void SetHead(std::shared_ptr<CSnowflake> head){ mHead = head; }
	std::shared_ptr<CSnowflake> GetHead(){ return mHead; }

protected:
	std::shared_ptr<CSnowflake> mHead;

};

