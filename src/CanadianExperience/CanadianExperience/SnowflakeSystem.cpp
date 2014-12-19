/**
* \file SnowflakeSystem.cpp
*
* \author Gabriel Morcote
*/



#include "stdafx.h"
#include "SnowflakeSystem.h"

using namespace Gdiplus;


/** \brief Constructor */
CSnowflakeSystem::CSnowflakeSystem()
{
	//instantiate member variable, should have 3 snowflakes cuz LL constructor
	mLinkedListActive = std::make_shared<CLinkedListActive>();
	mLinkedListActive->SetSnowflakeSystem(this);

	mLinkedListPool = std::make_shared<CLinkedListPool>();
	mLinkedListPool->SetSnowflakeSystem(this);
	mLinkedListPool->SetLinkedListActive(mLinkedListActive);

	mLinkedListActive->SetLinkedListPool(mLinkedListPool);
}

/** \brief Destructor */
CSnowflakeSystem::~CSnowflakeSystem()
{
}


/** \brief Draw this picture on a device context
* \param graphics The device context to draw on
*/
void CSnowflakeSystem::Draw(Gdiplus::Graphics *graphics)
{
	mLinkedListActive->Draw(graphics);
}


/** \brief Update this System on a time context
* \param elapsed The elapsed time so far
*/
void CSnowflakeSystem::Update(double elapsed)
{
	mLinkedListActive->Update(elapsed);
}


/** \brief Start the system */
void CSnowflakeSystem::Start()
{

}


/** \brief Stop the system */
void CSnowflakeSystem::Stop()
{

}

