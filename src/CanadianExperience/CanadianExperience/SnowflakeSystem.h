/**
* \file SnowflakeSystem.h
*
* \author Gabriel Morcote
*
* \brief class that represents the Snowflake System
*/

#pragma once
#include <memory>
#include "LinkedListPool.h"
#include "LinkedListActive.h"

class CPicture;

/* \brief System class to represent our Snowflake System */
class CSnowflakeSystem
{
public:
	CSnowflakeSystem();
	virtual ~CSnowflakeSystem();

	/** \brief Copy constructor disabled */
	CSnowflakeSystem(const CSnowflakeSystem &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CSnowflakeSystem &) = delete;

	/// Our drawing function
	void Draw(Gdiplus::Graphics *graphics);

	/// Update the system based on a timer
	void Update(double elapsed);

	/// Start and Stop capabilities of the system.
	void Start();
	void Stop();

	// belongs to a picture!!
	void SetPicture(CPicture *picture){ mPicture = picture; }

	//owns an inactive linked list and an Active
	//void SetActiveLinkedList(CLinkedListActive *active){ mLinkedListActive = active; }
	//void SetPoolLinkedList(CLinkedListPool *pool){ mLinkedListPool = pool; }

private:
	CPicture *mPicture = nullptr; ///< The Picture the System belongs to.

	std::shared_ptr<CLinkedListPool> mLinkedListPool = nullptr;	///< The Linked list POOL

	std::shared_ptr<CLinkedListActive> mLinkedListActive = nullptr;	///< The ACTIVE linked list

	bool mIsRunning = false;	///< Flag to represent the running state.

};

