/**
* \file AnimChannelText.cpp
*
* \author Gabriel Morcote
*/

#include "stdafx.h"
#include "AnimChannelText.h"

using namespace std;
using namespace Gdiplus;


/**
* \brief Constructor
*/
CAnimChannelText::CAnimChannelText()
{
}


/**
* \brief Destructor
*/
CAnimChannelText::~CAnimChannelText()
{
}


/**
* \brief Set a keyframe
*
* This function allocates a new keyframe and sends it to
* CAnimChannel, which will insert it into the collection of keyframes.
* \param point The point for the keyframe
*/
void CAnimChannelText::SetKeyframe(std::wstring text)
{
	// Create a keyframe of the appropriate type
	// Telling it this channel and the angle
	shared_ptr<KeyframeText> keyframe = make_shared<KeyframeText>(this, text);

	// Insert it into the collection
	InsertKeyframe(keyframe);
}

/** \brief Compute a tweened point between to points
* \param t The tweening t value
*/
void CAnimChannelText::Tween(double t)
{
	std::wstring text1 = mKeyframe1->GetText();
	std::wstring text2 = mKeyframe2->GetText();

	mText = text2;
}


/** \brief Save this keyframe to an XML node
* \param node The node we are going to be a child of
* \returns Allocated XML node.
*/
std::shared_ptr<xmlnode::CXmlNode> CAnimChannelText::KeyframeText::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CAnimChannel::Keyframe::XmlSave(node);
	itemNode->SetAttribute(L"TextBubble", mText);

	return itemNode;
}



/**
* \brief Handle loading this channel's keyframe type
* \param node keyframe tag node
*/
void CAnimChannelText::XmlLoadKeyframe(const std::shared_ptr<xmlnode::CXmlNode> &node)
{

	std::wstring text = node->GetAttributeValue(L"TextBubble", L"");

	// Set a keyframe there
	SetKeyframe(text);
}

