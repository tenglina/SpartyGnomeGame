/**
 * @file Item.cpp
 * @author Elia Spyratos
 *
 * Item implementation file
 */

#include "pch.h"
#include "Item.h"
#include "Game.h"
#include <wx/graphics.h>

using namespace std;

/**
 * Destructor
 */
 Item::~Item()
 {

 }

 /**
  * Constructor
  * @param game Game we are a part of
  * @param image wxImage to use
  * @param bitmap wxBitmap to use
  */
Item::Item(Game *game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap) : mGame(game)
{
    mItemImage = std::move(image);
    mItemBitmap = std::move(bitmap);
}

 /**
  * Compute distance from this item to another item
  * @param item Item we are computing the distance to
  * @return Distance in pixels
  */
  double Item::DistanceTo(std::shared_ptr<Item> item)
  {
      auto dx = item->GetX() - GetX();
      auto dy = item->GetY() - GetY();
      return sqrt(dx * dx + dy * dy);
  }

  /**
   * Draw this item
   * @param graphics Graphics context to draw on
   */
   void Item::Draw(std::shared_ptr<wxGraphicsContext> graphics)
   {

       int wid = mItemBitmap->GetWidth();
       int hit = mItemBitmap->GetHeight();
       graphics->DrawBitmap(*mItemBitmap,
               (int)GetX() - wid / 2, (int)GetY() - hit / 2,
               wid + 1, hit);
   }
   /**
    * Draws the scrolling items
    * @param graphics Graphics context to draw on
    * @param scrollX amount to scroll
    */
    void Item::Draw(std::shared_ptr<wxGraphicsContext> graphics, int scrollX)
    {
        int wid = mItemBitmap->GetWidth();
        int hit = mItemBitmap->GetHeight();
        graphics->DrawBitmap(*mItemBitmap,
                (int)GetX() - wid / 2 + scrollX, (int)GetY() - hit / 2,
                wid + 1, hit);
    }

  /**
   * Save this item to an XML node
   * @param node The parent node we are oging to be a child of
   * @return wxXmlNode* wxXmlNode that we saved the item into
   */
   wxXmlNode *Item::XmlSave(wxXmlNode *node)
  {
       auto itemNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"item");
       node->AddChild(itemNode);

       itemNode->AddAttribute(L"x", wxString::FromDouble(mP.X()));
       itemNode->AddAttribute(L"y", wxString::FromDouble(mP.Y()));

       return itemNode;

  }

  /**
   * Load the attributes for an item node
   *
   * This is the base class version that loads the attributes
   * common to all items. OVerride this to lad custom attributes
   * for specific items.
   *
   * @param node The Xml node we are loading the item from
   */
   void Item::XmlLoad(wxXmlNode *node)
  {
       double x;
       double y;
       node->GetAttribute(L"x", L"0").ToDouble(&x);
       node->GetAttribute(L"y", L"0").ToDouble(&y);
       mP.SetX(x);
       mP.SetY(y);
  }




