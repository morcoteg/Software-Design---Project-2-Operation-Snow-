/**
* \file AnimChannelMirror.cpp
*
* \author Gabriel Morcote
*/

#include "stdafx.h"
#include "AnimChannelMirror.h"
#include "Timeline.h"

using namespace std;

/**
* \brief Constructor
*/
CAnimChannelMirror::CAnimChannelMirror()
{
}


/**
* \brief Destructor
*/
CAnimChannelMirror::~CAnimChannelMirror()
{
}


/**
* \brief Set a keyframe
*
* This function allocates a new keyframe and sends it to
* CAnimChannel, which will insert it into the collection of keyframes.
* \param angle Angle for the keyframe.
*/
void CAnimChannelMirror::SetKeyframe(bool mirror)
{
	// Create a keyframe of the appropriate type
	// Telling it this channel and the angle
	shared_ptr<KeyframeMirror> keyframe = make_shared<KeyframeMirror>(this, mirror);

	// Insert it into the collection
	InsertKeyframe(keyframe);
}


/**
* \brief Tween between two angle keyframes
* \param t The t value between the frames
*/
void CAnimChannelMirror::Tween(double t)
{
	mMirror = mKeyframe1->GetMirror();
}

/** \brief Save this keyframe to an XML node
* \param node The node we are going to be a child of
* \returns Allocated XML node.
*/
std::shared_ptr<xmlnode::CXmlNode> CAnimChannelMirror::KeyframeMirror::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CAnimChannel::Keyframe::XmlSave(node);
	itemNode->SetAttribute(L"mirror", mMirror);

	return itemNode;
}



/**
* \brief Handle loading this channel's keyframe type
* \param node keyframe tag node
*/
void CAnimChannelMirror::XmlLoadKeyframe(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	bool mirror = node->GetAttributeDoubleValue(L"mirror", true);

	// Set a keyframe there
	SetKeyframe(mirror);
}

