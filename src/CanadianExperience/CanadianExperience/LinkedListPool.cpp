/**
* \file LinkedListPool.cpp
*
* \author Gabriel Morcote
*/

#include "stdafx.h"
#include "LinkedListPool.h"

/** \brief Constructor */
CLinkedListPool::CLinkedListPool()
{

}

/** \brief Destructor */
CLinkedListPool::~CLinkedListPool()
{
}


/* \brief Inserts a new Snowflake into the Linked List */
void CLinkedListPool::InsertInactive(CSnowflake *snowflake)
{
	// make pointer to shared_ptr
	std::shared_ptr<CSnowflake> newSnowflake(snowflake);

	newSnowflake->SetList(this);

	newSnowflake->SetNext(nullptr);

	//create a temp pointer
	std::shared_ptr<CSnowflake> temp = mHead;

	if (temp != nullptr)
	{
		// traverse the list
		while (temp->GetNext() != nullptr)
			temp = temp->GetNext();

		//point the last node to new node
		temp->SetNext(newSnowflake);
	}

	else     //it's the first snowflake in the list
		mHead = newSnowflake;

}