/**
 * @file LevelEndDoor.cpp
 * @author Nandini Tengli
 *
 * Level End Door implementation file
 */

#include "pch.h"
#include "LevelEndDoor.h"
#include "Game.h"

using namespace std;

/**
 * Constructor
 * @param game Game this door is a part of
 * @param image wxImage this object will use
 * @param bitmap wxBitmap this object will use
 */
LevelEndDoor::LevelEndDoor(Game *game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap) : Item(game, image, bitmap)
{

}

/**
 * Save this end door  to an XML node
 * @param node The parent node we are going to be a child of
 * @return wxXmlNode to return
 */
wxXmlNode* LevelEndDoor::XmlSave(wxXmlNode* node)
{
    auto itemNode = Item::XmlSave(node);

    itemNode->AddAttribute(L"type", L"door");

    return itemNode;
}


/**
 * Load custom door attributes for door node.
 *
 * @param node The Xml node we are loading the item from
 */
void LevelEndDoor::XmlLoad(wxXmlNode *node)
{
    double x;
    double y;
    node->GetAttribute(L"x", L"0").ToDouble(&x);
    node->GetAttribute(L"y", L"0").ToDouble(&y);
    this->SetLocation(x,y);
}

