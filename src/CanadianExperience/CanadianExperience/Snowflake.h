/**
* \file Snowflake.h
*
* \author Gabriel Morcote
*
* \brief class that represents a SNOWFLAKE object
*/

#pragma once
#include <memory>

class CLinkedList;
class CLinkedListPool;

class CSnowflake
{
public:
	CSnowflake();
	virtual ~CSnowflake();

	/// Our drawing function, HAVE THE snowflake DRAW ITSELF!!!!!!***********
	void Draw(Gdiplus::Graphics *graphics);

	/// Update the system based on a timer
	void Update(double elapsed);

	/// Reset position of the snowflake, if necessary.
	void ResetPosition(CSnowflake *snowflake);

	//---- snowflake (Node) stuff ----//

	void SetNext(std::shared_ptr<CSnowflake> next){ mNext = next; }
	std::shared_ptr<CSnowflake> GetNext(){ return mNext; }

	void SetList(CLinkedList *list){ mList = list; }

	CSnowflake* Delete(CSnowflake *snowflake);
	bool NeedToDeleteMe(){ return toDelete; }

private:
	Gdiplus::PointF mPosition;  ///< The Snowflake's Position

	double mSpeedX = 0;	  ///< The speed in the X direction

	double mSpeedY = 0;	  ///< The speed in the Y direction

	bool toDelete = false;	///< if we need to delete the Snowflake node


	//TODO -- represent Next pointer.
	std::shared_ptr<CSnowflake> mNext;

	//	  make association with linked list class
	CLinkedList *mList;

};

