/**
* \file AnimChannelText.h
*
* \brief An animation channel specific to Text Bubbles
*
* \author Gabriel Morcote
*/

#pragma once
#include "AnimChannel.h"

/** \brief An animation channel specific to Text (Communication)
*/
class CAnimChannelText : public CAnimChannel
{
public:
	CAnimChannelText();
	~CAnimChannelText();

	std::wstring GetText(){ return mText; }

	/// \brief A keyframe for a point channel
	class KeyframeText : public Keyframe
	{
	public:
		/** \brief Constructor
		* \param channel The channel we are for
		* \param point The animation position for the keyframe */
		KeyframeText(CAnimChannelText *channel, std::wstring text) :
			Keyframe(channel), mChannel(channel), mText(text) {}

		/** \brief Default constructor disabled */
		KeyframeText() = delete;
		/** \brief Copy constructor disabled */
		KeyframeText(const KeyframeText &) = delete;
		/** \brief Assignment operator disabled */
		void operator=(const KeyframeText &) = delete;

		std::wstring GetText(){ return mText; }

		/** \brief Use this keyframe as keyframe 1 */
		virtual void UseAs1() override { mChannel->mKeyframe1 = this; }

		/** \brief Use this keyframe as keyfraem 2 */
		virtual void UseAs2() override { mChannel->mKeyframe2 = this; }

		/** \brief Use this keyframe as the angle */
		virtual void UseOnly() override { mChannel->mText = mText; }

		virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node);

	private:
		/// The keyframe point
		std::wstring mText;

		/// The channel this keyframe is associated with
		CAnimChannelText *mChannel;
	};

	void SetKeyframe(std::wstring text);
	void Tween(double t);

protected:
	virtual void XmlLoadKeyframe(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

private:
	/// The text we will be editing
	std::wstring mText;

	/// The first angle keyframe
	KeyframeText *mKeyframe1 = nullptr;

	/// The second angle keyframe
	KeyframeText *mKeyframe2 = nullptr;
};

