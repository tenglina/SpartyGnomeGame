/**
 * @file WormHole.cpp
 * @author Alexandra Case
 *
 * WormHole implementation file
 */

#include "pch.h"
#include "WormHole.h"
#include "Game.h"
#include <string>

using namespace std;

/**
 * Constructor
 * @param game Game we are tied to
 * @param image Image to use for drawing
 * @param bitmap Bitmap to use for drawing
 */
WormHole::WormHole(Game* game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap) : Item(game, image, bitmap)
{

}

/**
 * Save this item to an XML node
 * @param node
 * @return wxXmlNode* to return
 */
wxXmlNode* WormHole::XmlSave(wxXmlNode* node)
{
    auto itemNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"wormhole");
    node->AddChild(itemNode);

    itemNode->AddAttribute(L"x", wxString::FromDouble(GetX()));
    itemNode->AddAttribute(L"y", wxString::FromDouble(GetY()));

    return itemNode;
}

/**
 * Update for animations
 * @param elapsed elapsed time
 */
void WormHole::Update(double elapsed)
{
    if(rotation == 0){
        rotation++;
        mP.SetX(mP.X() + 4);
    }
    else if(rotation == 1){
        rotation++;
        mP.SetY(mP.Y() - 4);
    }
    else if(rotation == 2){
        rotation++;
        mP.SetX(mP.X() - 4);
    }
    else if(rotation == 3){
        rotation = 0;
        mP.SetY(mP.Y() + 4);
    }

}


