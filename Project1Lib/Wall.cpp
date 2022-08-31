/**
 * @file Wall.cpp
 * @author Alexandra Case
 *
 * Wall implementation file
 */

#include "pch.h"
#include "Wall.h"
#include <wx/graphics.h>

using namespace std;

/**
 * Constructor
 * @param game Game we are tied to
 * @param image Image to use
 * @param bitmap Bitmap to use
 */
Wall::Wall(Game* game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap) : Item(game, image, bitmap)
{

}

/**
 * Save this item to an XML node
 * @param node
 * @return wxXmlNode* to return
 */
wxXmlNode* Wall::XmlSave(wxXmlNode* node)
{
    auto itemNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"Wall");
    node->AddChild(itemNode);

    itemNode->AddAttribute(L"x", wxString::FromDouble(GetX()));
    itemNode->AddAttribute(L"y", wxString::FromDouble(GetY()));

    return itemNode;
}

/**
* Draw this item
 * @param graphics Graphics context to draw on
*/
void Wall::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

    int placeY = GetY() - (mHeight/2) + 16;
    int tilesNeeded = mHeight / 32;

    for(int i = 0; i < tilesNeeded; i++)
    {
        int wid = mItemBitmap->GetWidth();
        int hit = mItemBitmap->GetHeight();
        graphics->DrawBitmap(*mItemBitmap,
                (int)GetX() + wid / 2 + 16, placeY - 16,
                wid + 1, hit);
        placeY += 32;
    }
}
/**
* Draw this item
 * @param graphics Graphics context to draw on
 * @param scrollX The amount to scroll
*/
void Wall::Draw(std::shared_ptr<wxGraphicsContext> graphics, int scrollX)
{

    int placeY = GetY() - (mHeight/2) + 16;
    int tilesNeeded = mHeight / 32;

    for(int i = 0; i < tilesNeeded; i++)
    {
        int wid = mItemBitmap->GetWidth();
        int hit = mItemBitmap->GetHeight();
        graphics->DrawBitmap(*mItemBitmap,
                (int)GetX() - wid / 2 + scrollX + 16, placeY - 16,
                wid + 1, hit);
        placeY += 32;
    }
}