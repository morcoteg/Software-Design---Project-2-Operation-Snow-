/**
* \file LinkedListActive.cpp
*
* \author Gabriel Morcote
*/

#include "stdafx.h"
#include "LinkedListActive.h"

/** \brief Constructor */
CLinkedListActive::CLinkedListActive()
{
	for (int i = 0; i < 100; i++)
	{
		// insert a bunch of snowflakes into the linked list
		Insert();
	}
}

/** \brief Destructor */
CLinkedListActive::~CLinkedListActive()
{
}


/** \brief Draw this picture on a device context		HAVE snowflake DRAW ITSELF!!!!!!!!!!!!******
* \param graphics The device context to draw on
*/
void CLinkedListActive::Draw(Gdiplus::Graphics *graphics)
{
	// iterate over the snowflakes, making it call it's own Draw function
	std::shared_ptr<CSnowflake> snowflake = (this)->GetHead();
	while (snowflake != nullptr)
	{
		// Draw the Snowflake
		snowflake->Draw(graphics);

		snowflake = snowflake->GetNext();
	}
	
	
}


/** \brief Update this System on a time context
* \param elapsed The elapsed time so far
* 
* This iterates over the linked list, calling each Snowflake's Update method
*/
void CLinkedListActive::Update(double elapsed)
{
	// iterate over the snowflakes, making it call it's own UPDATE function
	std::shared_ptr<CSnowflake> snowflake = (this)->GetHead();
	while (snowflake != nullptr)
	{
		// UPDATE each Snowflake
		snowflake->Update(elapsed);

		snowflake = snowflake->GetNext();
	}

}