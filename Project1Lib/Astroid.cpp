/**
 * @file Astroid.cpp
 * @author Alexandra Case
 *
 * Astroid Implementation File
 */


#include "pch.h"
#include "Astroid.h"
#include "SpartyGnome.h"

using namespace std;


/**
 * Constructor
 * @param game Game this Asteroid is a part of
 * @param image The image this item will use
 * @param bitmap The bitmap this item will use
 */
Astroid::Astroid(Game *game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap) : Enemy(game, image, bitmap)
{
    mVelocity.SetY(250);
    mVelocity.SetX(-250);


}

/**
 * Save this item to an XML node
 * @param node
 * @return wxXmlNode* to return
 */
wxXmlNode* Astroid::XmlSave(wxXmlNode* node){
    auto itemNode = Item::XmlSave(node);
    itemNode->AddAttribute(L"type", L"asteroid");
    return itemNode;
}

/**
 * Update function used for the animation
 * @param elapsed elapsed time
 */
void Astroid::Update(double elapsed)
{
    Vector newP = mP + mVelocity * elapsed;
    SetLocationMovement(newP.X(),newP.Y());
    if(mP.Y() > 1500)
    {
        SetLocationMovement(mSparty->GetX() + 925, -100);
    }

    if(rotation == 0){
        rotation++;
        mP.SetX(mP.X() + 20);
    }
    else if(rotation == 1){
        rotation++;
        mP.SetY(mP.Y() - 20);
    }
    else if(rotation == 2){
        rotation++;
        mP.SetX(mP.X() - 20);
    }
    else if(rotation == 3){
        rotation = 0;
        mP.SetY(mP.Y() + 20);
    }
}


