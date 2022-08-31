/**
 * @file Background.cpp
 * @author Elia Spyratos
 *
 * Background implementation file
 */

#include "pch.h"
#include "Background.h"

using namespace std;

/**
 * Constructor
 * @param game Game this Sparty Gnome is a part of
 * @param image The image this item will use
 * @param bitmap The bitmap this item will use
 */
Background::Background(Game* game,  std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap) : Item(game, image, bitmap)
{

}

/**
 * Save this item to an XML node
 * @param node The parent node we are going to be a child of
 * @return wxXmlNode* to return
 */
wxXmlNode* Background::XmlSave(wxXmlNode* node)
{
    auto itemNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"background");
    node->AddChild(itemNode);

    itemNode->AddAttribute(L"x", wxString::FromDouble(GetX()));
    itemNode->AddAttribute(L"y", wxString::FromDouble(GetY()));

    return itemNode;
}

