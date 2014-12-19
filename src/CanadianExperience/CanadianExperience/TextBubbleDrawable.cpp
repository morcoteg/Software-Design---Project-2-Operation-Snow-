/**
* \file TextBubbleDrawable.cpp
*
* \author Gabriel Morcote
*/

#include "stdafx.h"
#include "Drawable.h"
#include "Actor.h"
#include "Timeline.h"
#include "TextBubbleDrawable.h"

using namespace Gdiplus;

CTextBubbleDrawable::CTextBubbleDrawable() : CDrawable(L"Bubble")
{

}

CTextBubbleDrawable::~CTextBubbleDrawable()
{
}

void CTextBubbleDrawable::Draw(Gdiplus::Graphics *graphics)
{
	mBubble.SetBubblePosition(mPlacedPosition.X, mPlacedPosition.Y);
	mBubble.DrawMe(graphics);
}


bool CTextBubbleDrawable::HitTest(Gdiplus::Point pos)
{

	return mBubble.IsPointInside(pos.X, pos.Y);
}


/**
* \brief Set the actor. This is where we set the channel name
* \param actor Actor to set
*/
void CTextBubbleDrawable::SetActor(CActor *actor)
{
	CDrawable::SetActor(actor);

	// Set the channel name
	mPositionChannel.SetName(actor->GetName() + L":" + GetName() + L":position");
	mTextChannel.SetName(actor->GetName() + L":" + GetName() + L":TextBubble");
	mMirrorChannel.SetName(actor->GetName() + L":" + GetName() + L":mirror");
}


/**
* \brief Set the timeline. The tells the channel the timeline
* \param timeline Timeline to set
*/
void CTextBubbleDrawable::SetTimeline(CTimeline *timeline)
{
	CDrawable::SetTimeline(timeline);

	timeline->AddChannel(&mPositionChannel);
	timeline->AddChannel(&mTextChannel);
	timeline->AddChannel(&mMirrorChannel);
}


/** \brief Set the keyframe based on the current status.
*/
void CTextBubbleDrawable::SetKeyframe()
{
	CDrawable::SetKeyframe();

	mPositionChannel.SetKeyframe(GetPosition());
	mTextChannel.SetKeyframe(mBubble.GetText());
	mMirrorChannel.SetKeyframe(mBubble.GetMirror());
}

/** \brief Get the current channel from the animation system.
*/
void CTextBubbleDrawable::GetKeyframe()
{
	CDrawable::GetKeyframe();

	if (mPositionChannel.IsValid())
	{
		SetPosition(mPositionChannel.GetPoint());
		mBubble.SetText(mTextChannel.GetText());
	}

	if (mMirrorChannel.IsValid())
		mBubble.SetMirrored(mMirrorChannel.GetMirror());
}


void CTextBubbleDrawable::OnRButtonDown()
{
	// Create the dialog box object
	CTextBubbleDlg dlg;

	// Tell it about the text bubble
	dlg.SetTextBubble(&mBubble);
	if (dlg.DoModal() == IDOK)
	{
		// Take the changes to the text bubble
		dlg.Take();
		
		//  Supposed to UpdateObservers() somewhere.. in CPicture!!! After you do your For loop
	}
}