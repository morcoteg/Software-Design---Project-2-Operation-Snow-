/**
* \file LinkedList.cpp
*
* \author Gabriel Morcote
*/

#include "stdafx.h"
#include <memory>
#include "LinkedList.h"

/** \brief Constructor */
CLinkedList::CLinkedList()
{
	mHead = nullptr;
}

/** \brief Destructor */
CLinkedList::~CLinkedList()
{
}


/* \brief Inserts a new Snowflake into the Linked List */
void CLinkedList::Insert()
{
	std::shared_ptr<CSnowflake> newSnowflake = std::make_shared<CSnowflake>();
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


/* \brief Delete a Snowflake from the Linked List */
void CLinkedList::Delete(CSnowflake *snowflake)
{
	std::shared_ptr<CSnowflake> temp = mHead;

	// no nodes
	if (temp == nullptr)
		return;

	//last node in list
	if (temp->GetNext() == nullptr)
	{
		//delete temp;
		mHead = nullptr;
	}
	else
	{
		//parse thru nodes
		std::shared_ptr<CSnowflake> prev;
		do{
			prev = temp;
			temp = temp->GetNext();
		} while (temp != nullptr);
		
		//adjust pointers
		prev->SetNext(temp->GetNext());

		//delete current node
		//delete temp;
	}
}

/* \brief Clear the Linked List */
void CLinkedList::Clear()
{

}


void CLinkedList::AddFront(std::shared_ptr<CSnowflake> snowflake)
{
	assert(snowflake != nullptr);
	snowflake->SetNext(mHead);
	mHead = snowflake;
}


void SetHead(std::shared_ptr<CSnowflake> head)
{

}