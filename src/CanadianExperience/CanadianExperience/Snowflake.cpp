/**
* \file Snowflake.h
*
* \author Gabriel Morcote
*/

#include "stdafx.h"
#include <random>
#include "Snowflake.h"
#include "LinkedList.h"

using namespace Gdiplus;

/** \brief Constructor */
CSnowflake::CSnowflake()
{
	
	//randomly generate the X and Y speeds
	std::random_device rd;
	std::default_random_engine generator(rd()); // rd() provides a random seed
	std::uniform_real_distribution<double> distribution(0.1, 1);

	double speedX = distribution(generator);
	double speedY = distribution(generator);
	
	// set some random speeds
	mSpeedX = speedX;
	mSpeedY = speedY;

	double coordX = rand() % 1000 + 1;     // coordX in the range 1 to 1000
	double coordY = 0;    

	mPosition = PointF(coordX, coordY);
}

/** \brief Destructor */
CSnowflake::~CSnowflake()
{
}


/** \brief Draw this picture on a device context		HAVE snowflake DRAW ITSELF!!!!!!!!!!!!******	
* \param graphics The device context to draw on
*/
void CSnowflake::Draw(Gdiplus::Graphics *graphics)
{
	SolidBrush brush(Color::White);
	graphics->FillEllipse(&brush, int(mPosition.X), int(mPosition.Y), 10, 10);
}


/** \brief Update this System on a time context
* \param elapsed The elapsed time so far
*/
void CSnowflake::Update(double elapsed)
{	
	// update the position of snowflake
	mPosition = PointF((mPosition.X + (mSpeedX*elapsed)), (mPosition.Y + (mSpeedY*elapsed)));

	// check if snowflake is out of bounds! (right side of picture, bottom of picture)
	if ((mPosition.X > 1100) || (mPosition.Y > 600))
	{
		CLinkedList *list = mList;

		// we need to delete this Snowflake
		toDelete = true;
		if (NeedToDeleteMe())
		{
			//CHEATING!!! need to add to LinkedListPool!!!
			ResetPosition(this);
			//CSnowflake *inactiveSnowflake = Delete(this);  /// successfully deletes the snowflakes from the active list
			
		}
	}
		
} 


/** \brief Reset the position of a Snowflake object 
* \param rect The rectangular coordinates of the new position -- ( I think? )
*/
void CSnowflake::ResetPosition(CSnowflake *snowflake)
{
	//randomly generate the X and Y speeds
	std::random_device rd;
	std::default_random_engine generator(rd()); // rd() provides a random seed
	std::uniform_real_distribution<double> distribution(0.1, 1);

	double speedX = distribution(generator);
	double speedY = distribution(generator);

	// set some random speeds
	mSpeedX = speedX;
	mSpeedY = speedY;

	double coordX = rand() % 1000 + 1;     // coordX in the range 1 to 1000
	double coordY = 0;

	mPosition = PointF(coordX, coordY);
}

CSnowflake* CSnowflake::Delete(CSnowflake *snowflake)
{
	std::shared_ptr<CSnowflake> prev = nullptr;
	auto node = mList->GetHead();
	while (node != nullptr)
	{
		auto nextNode = node->GetNext();

		if (node->NeedToDeleteMe())
		{
			if (prev == nullptr)
			{
				// This is the first node in the list. It has no previous node
				mList->SetHead(nextNode);
			}
			else
			{
				prev->SetNext(nextNode);
			}
		}
		else
		{
			// Previous node only changes if we do not delete
			prev = node;
		}

		node = nextNode;
	}

	return snowflake;
}