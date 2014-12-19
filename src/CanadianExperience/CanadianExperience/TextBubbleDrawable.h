/**
* \file TextBubbleDrawable.h
*
* \author Gabriel Morcote
*
* \brief Adapter class so that we can use Text Bubble as a Drawable
*/


#pragma once
#include <string>
#include <memory>

#include "Drawable.h"
#include "TextBubble.h"
#include "TextBubbleDlg.h"
#include "AnimChannelPoint.h"
#include "AnimChannelText.h"
#include "AnimChannelMirror.h"


/* \brief The Adapter class for a Text Bubble as a Drawable */
class CTextBubbleDrawable : public CDrawable
{
public:
	CTextBubbleDrawable();
	virtual ~CTextBubbleDrawable();


	/** \brief Copy constructor disabled */
	CTextBubbleDrawable(const CTextBubbleDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CTextBubbleDrawable &) = delete;

	virtual void OnRButtonDown() override;

	void Draw(Gdiplus::Graphics *graphics);
	bool HitTest(Gdiplus::Point pos);

	virtual void SetActor(CActor *actor) override;
	virtual void SetTimeline(CTimeline *timeline) override;
	virtual void SetKeyframe() override;
	virtual void GetKeyframe() override;

	virtual bool IsMovable() { return true; }

private:
	CTextBubble mBubble;  ///< the text bubble we edit
	
	/// Channel for the head position
	CAnimChannelPoint mPositionChannel;

	CAnimChannelText mTextChannel;   ///< Channel for text that will fill out the bubble

	CAnimChannelMirror mMirrorChannel;
};

