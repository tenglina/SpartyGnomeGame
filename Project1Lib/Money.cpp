/**
 * @file Money.cpp
 * @author Isabella Beth Engelman
 *
 * Money Implementation file
 */

#include "pch.h"
#include "Money.h"
#include "Game.h"

using namespace std;

/**
 * Money constructor
 * @param game Game we are tied to
 * @param image wxImage to use
 * @param bitmap wxBitmap to use
 * @param value Value of the money
 */
Money::Money(Game *game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap, int value): Item(game, image, bitmap)
{
    mValue = value;
}

/**
 * Save this item to an XML node
 * @param node The parent node we are going to be a child of
 * @return wxXmlNode* to return
 */
wxXmlNode* Money::XmlSave(wxXmlNode* node)
{
    auto itemNode = Item::XmlSave(node);

    itemNode->AddAttribute(L"type", L"money");

    return itemNode;
}

/**
 * Collide function for money
 * @return returns true when collided for the first time
 */
 bool Money::Collide()
 {
     if(mCollided == false)
     {
         mCollided = true;

         mVelocity.SetY(-500);

         return true;
     }

     return false;
 }

 /**
  * Update function
  * @param elapsed The time since last call
  */
  void Money::Update(double elapsed) {

     Vector newP = mP + mVelocity * elapsed;
     SetLocation(newP.X(), newP.Y());

     if(mP.Y() < -100)
     {
         mVelocity.SetY(0);
     }
  }


