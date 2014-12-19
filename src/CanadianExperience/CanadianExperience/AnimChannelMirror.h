/**
* \file AnimChannelMirror.h
*
* \brief An animation channel specific to Text Bubble MIRROR state
*
* \author Gabriel Morcote
*/

#pragma once
#include "AnimChannel.h"

/** \brief An animation channel specific to Text (Communication)
*/
class CAnimChannelMirror : public CAnimChannel
{
public:
	CAnimChannelMirror();
	~CAnimChannelMirror();

	bool GetMirror(){ return mMirror; }

	/// \brief A keyframe for a point channel
	class KeyframeMirror : public Keyframe
	{
	public:
		/** \brief Constructor
		* \param channel The channel we are for
		* \param point The animation position for the keyframe */
		KeyframeMirror(CAnimChannelMirror *channel, bool mirror) :
			Keyframe(channel), mChannel(channel), mMirror(mirror) {}

		/** \brief Default constructor disabled */
		KeyframeMirror() = delete;
		/** \brief Copy constructor disabled */
		KeyframeMirror(const KeyframeMirror &) = delete;
		/** \brief Assignment operator disabled */
		void operator=(const KeyframeMirror &) = delete;

		bool GetMirror(){ return mMirror; }

		/** \brief Use this keyframe as keyframe 1 */
		virtual void UseAs1() override { mChannel->mKeyframe1 = this; }

		/** \brief Use this keyframe as keyfraem 2 */
		virtual void UseAs2() override { mChannel->mKeyframe2 = this; }

		/** \brief Use this keyframe as the angle */
		virtual void UseOnly() override { mChannel->mMirror = mMirror; }

		virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node);

	private:
		/// The keyframe point
		bool mMirror = false;

		/// The channel this keyframe is associated with
		CAnimChannelMirror *mChannel;
	};

	void SetKeyframe(bool mirror);
	void Tween(double t);

protected:
	virtual void XmlLoadKeyframe(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

private:
	/// The Mirror state
	bool mMirror = false;

	/// The first angle keyframe
	KeyframeMirror *mKeyframe1 = nullptr;

	/// The second angle keyframe
	KeyframeMirror *mKeyframe2 = nullptr;
};

