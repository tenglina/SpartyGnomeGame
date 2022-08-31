/**
 * @file Level.cpp
 * @author Isabella Beth Engelman
 *
 * Level implementation file
 */

#include "pch.h"
#include "Level.h"
#include "Item.h"
#include "Declaration.h"
#include "BackgroundDeclaration.h"
#include "PlatformDeclaration.h"
#include "WallDeclaration.h"
#include "MoneyDeclaration.h"
#include "WisconsonCatDeclaration.h"
#include "WickedWolverineDeclaration.h"
#include "StanleyDeclaration.h"
#include "LevelEndDoorDeclaration.h"
#include <filesystem>
#include "SpartyGnomeDeclaration.h"
#include "SpartyGnome.h"
#include "WormHole.h"
#include "WormHoleDeclaration.h"
#include "AstroidDeclaration.h"

using namespace std;

/**
 * Level Constructor
 * @param game Game we are tied to
 * @param scoreboard Scprenpard we are tied to
 */
 Level::Level(Game *game, Scoreboard* scoreboard): mGame(game), mScoreboard(scoreboard)
{
     // Runs next level to load level 1 automatically
     // NEXT LEVEL CAUSES THE WINDOW TO DISSAPEAR
    //NextLevel();
    CreateSparty();
}

/**
 * Add an item to the Level
 * @param item New item to add
 */
void Level::AddItem(std::shared_ptr<Item> item)
{

    mItems.push_back(item);

}

/**
 * Add an item to the Level
 * @param declaration Declaration to add
 */
void Level::AddDeclaration(std::shared_ptr<Declaration> declaration)
{
    mDeclarations.push_back(declaration);
}

/**
 * Moves a given item to the front (end of the vector)
 * @param item the given item to move to front
 */
void Level::MoveToFront(shared_ptr<Item> item)
{
    auto loc = find(begin(mItems), end(mItems), item);
    if(loc != end(mItems))
    {
        mItems.push_back(*loc);
    }
}

/**
 * Create Sparty function
 */
 void Level::CreateSparty()
 {
     // sparty declaration
     wstring imagewstring = L"gnome.png";
     // why is it i000 ? because it does not matter what we put for id
     wstring idwstring = L"i000";

     wstring spartyLeft = L"images/gnome-walk-left-1.png";
     wstring spartyLeft2 = L"images/gnome-walk-left-2.png";

     wstring spartyDead = L"images/gnome-sad.png";

     wstring spartyRight = L"images/gnome-walk-right-1.png";
     wstring spartyRight2 = L"images/gnome-walk-right-2.png";

     auto sparty = make_shared<SpartyGnomeDeclaration>(mGame, imagewstring, idwstring );

     std::shared_ptr<wxImage> mImageLeft = make_shared<wxImage>(spartyLeft, wxBITMAP_TYPE_ANY);
     std::shared_ptr<wxBitmap> mBitmapLeft = make_shared<wxBitmap>(*mImageLeft);
     std::shared_ptr<wxImage> mImageLeft2 = make_shared<wxImage>(spartyLeft2, wxBITMAP_TYPE_ANY);
     std::shared_ptr<wxBitmap> mBitmapLeft2 = make_shared<wxBitmap>(*mImageLeft2);

     std::shared_ptr<wxImage> mImageDead = make_shared<wxImage>(spartyDead, wxBITMAP_TYPE_ANY);
     std::shared_ptr<wxBitmap> mBitmapDead = make_shared<wxBitmap>(*mImageDead);

     std::shared_ptr<wxImage> mImageRight = make_shared<wxImage>(spartyRight, wxBITMAP_TYPE_ANY);
     std::shared_ptr<wxBitmap> mBitmapRight = make_shared<wxBitmap>(*mImageRight);
     std::shared_ptr<wxImage> mImageRight2 = make_shared<wxImage>(spartyRight2, wxBITMAP_TYPE_ANY);
     std::shared_ptr<wxBitmap> mBitmapRight2 = make_shared<wxBitmap>(*mImageRight2);

     auto spartyitem = std::make_shared<SpartyGnome>(mGame, sparty->GetImage(), sparty->GetBitmap(),
             mImageLeft, mBitmapLeft,
             mImageRight, mBitmapRight,
             mImageLeft2, mBitmapLeft2,
             mImageRight2, mBitmapRight2,
             mImageDead, mBitmapDead);

     mSparty = spartyitem;
 }

/**
 * Load the level file from a .xml XML file
 *
 * Opens the XML file and reads the nodes, creating items as appropriate.
 *
 * @param filename The filename of the file to load the level from.
 */
void Level::Load(const wxString &filename)
{
    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Unable to load level file");
        return;
    }
    Clear();

    // Get the XML document root(top) node. Reads line by line
    auto root =xmlDoc.GetRoot();

    //creating new strings for sparty
    wxString spartyX = root->GetAttribute(L"start-x");
    wxString spartyY = root->GetAttribute(L"start-y");

    double spartyXdouble;
    spartyX.ToDouble(&spartyXdouble);
    // positioning
    double spartyYdouble;
    spartyY.ToDouble(&spartyYdouble);


    mSparty->SetLocation(spartyXdouble, spartyYdouble);

    // Turns off sparty's Gravity temporarily
    mSparty->Reset();


    //
    // Traverse the children of the root
    // node of the XML document in memory!!!!
    //

    //gets the first line in declaration
    auto declarationsThenItems = root->GetChildren();

    auto child = declarationsThenItems->GetChildren();


    // Declarations loop
    //child is like out [i]
    for (; child; child=child->GetNext())
    {
        XmlDeclaration(child);
    }

    declarationsThenItems = declarationsThenItems->GetNext();
    child = declarationsThenItems->GetChildren();
    // Items loop
    for (; child; child=child->GetNext())
    {
        XmlItem(child);
    }
    AddItem(mSparty);
    mSparty->SetLevel(this);
}

/**
 * Handle a node of type Item
 * @param node XML node of the item in XML file
*/
void Level::XmlItem(wxXmlNode* node)
{
    // A pointer for the item we are loading
    shared_ptr<Item> item;

    // We have an item. What type?
    auto name = node->GetName();

    wxString id = node->GetAttribute(L"id");
    //conversion from wxString to StdWstring
    wstring idwstring = id.ToStdWstring();
    wxString x = node->GetAttribute(L"x");
    wxString y = node->GetAttribute(L"y");
    //every item has an x and y, and declaration dosent hold that information.
    double xDouble;
    x.ToDouble(&xDouble);
    double yDouble;
    y.ToDouble(&yDouble);
    //has the Id we just got from Item node, and loops through declaration in mdeclarsaion and finds the declartion with the same id
    //Take found declaration and call create function
    for(auto declaration : mDeclarations)
    {
        wstring iddec = declaration->GetId();//of each declaration
        if(idwstring == declaration->GetId()) { //check to see if same as the id we pulled from item node
            item = declaration->Create();//id tells us
            break;
        }
    }
//find name of node, we know what inform we need
//dont need to call constructor we have an object
//we just need to fill in information  we got from our node
    if(name == L"background")
    {

    }
    if(name == L"platform")
    {
        wxString width = node->GetAttribute(L"width");
        wxString height = node->GetAttribute(L"height");
        // SET THE HEIGHT AND WIDTH
        int widthInt = wxAtoi(width);
        int heightInt = wxAtoi(height);
        item->SetHeightWidth(heightInt, widthInt);

    }
    if(name == L"money")
    {

    }
    if(name == L"villain")
    {

    }
    if(name == L"tuition-up")
    {

    }
    if(name == L"wall")
    {
        wxString width = node->GetAttribute(L"width");
        wxString height = node->GetAttribute(L"height");
        // SET THE HEIGHT AND WIDTH
        int widthInt = wxAtoi(width);
        int heightInt = wxAtoi(height);
        item->SetHeightWidth(heightInt, widthInt);

    }
    if(name == L"door")
    {

    }
    if(name == L"wormhole")
    {

    }
    if(name == L"asteroid")
    {

        item->SetSparty(mSparty);
    }

    item->SetLocation(xDouble, yDouble);

    if(item != nullptr)
    {
        AddItem(item);
    }

}

/**
 * Handle a node of type Declaration
 * @param node XML node of declaration
 */
void Level::XmlDeclaration(wxXmlNode* node)
{
    // A pointer for the declaration we are loading
    shared_ptr<Declaration> declaration;

    // We have a declaration. What type?
    auto name = node->GetName();
    //store as stirng, doing this once
    wxString id = node->GetAttribute(L"id");
    wstring idwstring = id.ToStdWstring();
    if(name == L"background")
    {

        wxString image = node->GetAttribute(L"image");
        wstring imagewstring = image.ToStdWstring();
        //making a declaration
        declaration = make_shared<BackgroundDeclaration>(mGame, imagewstring, idwstring);
    }
    if(name == L"platform")
    {

        wxString imageLeft = node->GetAttribute(L"left-image");
        wstring imageLeftwstring = imageLeft.ToStdWstring();
        wxString imageMiddle = node->GetAttribute(L"mid-image");
        wstring imageMiddlewstring = imageMiddle.ToStdWstring();
        wxString imageRight = node->GetAttribute(L"right-image");
        wstring imageRightwstring = imageRight.ToStdWstring();

        declaration = make_shared<PlatformDeclaration>(mGame, imageLeftwstring, imageMiddlewstring, imageRightwstring, idwstring);
    }
    if(name == L"wall")
    {

        wxString image = node->GetAttribute(L"image");
        ///converting form wxstring to wstring
        wstring imagewstring = image.ToStdWstring();

        declaration = make_shared<WallDeclaration>(mGame, imagewstring, idwstring);
    }
    if(name == L"money")
    {

        wxString image = node->GetAttribute(L"image");
        wstring imagewstring = image.ToStdWstring();
        wxString value = node->GetAttribute(L"value");
        int valueInt = wxAtoi(value);
        //calling construtor once information is pulled xml file
        declaration = make_shared<MoneyDeclaration>(mGame, imagewstring, idwstring, valueInt);
    }
    if(name == L"tuition-up")
    {

        wxString image = node->GetAttribute(L"image");
        wstring imagewstring = image.ToStdWstring();
        //param are diffent based on constructor
        declaration = make_shared<StanleyDeclaration>(mGame, imagewstring, idwstring);
    }
    if(name == L"villain")
    {

        wxString image = node->GetAttribute(L"image");
        wstring imagewstring = image.ToStdWstring();
        if(image == L"UofM.png")
        {
            declaration = make_shared<WickedWolverineDeclaration>(mGame, imagewstring, idwstring);
        }
        if(image == L"wisc.png")
        {
            declaration = make_shared<WisconsonCatDeclaration>(mGame, imagewstring, idwstring);
        }

    }
    if(name == L"door")
    {
        wxString image = node->GetAttribute(L"image");
        wstring imagewstring = image.ToStdWstring();
        declaration = make_shared<LevelEndDoorDeclaration>(mGame, imagewstring, idwstring);
    }
    if(name == L"wormhole")
    {
        wxString image = node->GetAttribute(L"image");
        wstring imagewstring = image.ToStdWstring();
        declaration = make_shared<WormHoleDeclaration>(mGame, imagewstring, idwstring);
    }
    if(name == L"asteroid")
    {
        wxString image = node->GetAttribute(L"image");
        wstring imagewstring = image.ToStdWstring();
        declaration = make_shared<AstroidDeclaration>(mGame, imagewstring, idwstring);
    }



   ///catching the cases, if we find the name of our node then dd to mdeclartion
    if(declaration != nullptr)
    {
        AddDeclaration(declaration);
        //declaration->XmlLoad(node)
    }
}

/**
 * Clear the level data.
 *
 * Deletes all known items in the game.
 */
void Level::Clear()
{
    mItems.clear();
    mDeclarations.clear();
}

/**
 * Resets the current level
 */
void Level::ResetLevel()
{
    filesystem::path p = filesystem::current_path();
    p = p.parent_path();

    if (mLevelWeAreOn==0) {
        p += L"/xml/level0.xml";
        mScoreboard->SetTitle("Level 0: Press Space to Begin");
    }
    else if (mLevelWeAreOn==1) {
        p += L"/xml/level1.xml";
        mScoreboard->SetTitle("Level 1: Press Space to Begin");
    }
    else if (mLevelWeAreOn==2) {
        p += L"/xml/level2.xml";
        mScoreboard->SetTitle("Level 2: Press Space to Begin");
    }
    else if(mLevelWeAreOn==3)
    {
        p += L"/xml/level3.xml";
        mScoreboard->SetTitle("Level 3: Press Space to Begin");
    }

    mScoreboard->ResetTimer();
    Clear();
    Load(p.string());
}

/**
 * Loads the next level
 * based on what level we are on now
 */
 void Level::NextLevel()
{
    filesystem::path p = filesystem::current_path();
    p = p.parent_path();

    if (mLevelWeAreOn==-1) {
        p += L"/xml/level0.xml";
        mLevelWeAreOn = 0;
        mScoreboard->SetTitle("Level 0: Press Space to Begin");
    }
    else if (mLevelWeAreOn==0) {
        p += L"/xml/level1.xml";
        mLevelWeAreOn = 1;
        mScoreboard->SetTitle("Level 1: Press Space to Begin");
    }
    else if (mLevelWeAreOn==1) {
        p += L"/xml/level2.xml";
        mLevelWeAreOn = 2;
        mScoreboard->SetTitle("Level 2: Press Space to Begin");
    }
    else if (mLevelWeAreOn==2) {
        p += L"/xml/level3.xml";
        mLevelWeAreOn = 3;
        mScoreboard->SetTitle("Level 3: Press Space to Begin");
    }

    // Temporary closed loop until we make a win condition
    else if(mLevelWeAreOn==3)
    {
        p += L"/xml/level1.xml";
        mLevelWeAreOn = 1;
        mScoreboard->SetTitle("YOU WON! Press space to play again!");
    }

    mScoreboard->ResetTimer();
    Clear();
    Load(p.string());
    mScoreboard->UpdateLevelIndicator(mLevelWeAreOn);
}

/**
 * Iterates over mItems (vector of items in this level)
 * calls the Draw function for each item in mItems
 * @param graphics the graphics context of the game
 */
void Level::AddItemsToGame(std::shared_ptr<wxGraphicsContext> graphics)
{

    for (auto item : mItems)
    {
        item->Draw(graphics);
    }

}

/**
 * Update function. Calls update on
 * all items to update the position and collision detection
 * @param elapsed time elapsed since last call
 */
void Level::Update(double elapsed)
{

    if(mSparty->HasStarted()) {
        // empties the intro title while we play
        mScoreboard->SetTitle("");

        for (auto item: mItems) {
            item->Update(elapsed);

            int collision = item->Accept(&mItemVisitor);

            if (collision == 1 && mSparty->DistanceTo(item)<50) {
                NextLevel();
                mSparty->Reset();
                return;
            }

            if (mSparty->DistanceTo(item)<80 && mSparty->IsAlive()) {
                // Collide returns an int.
                // We can use this int to add money to the HUD
                // Or to kill Sparty
                // Default is -1, does nothing.
                bool collideFirstTime = item->Collide();
                if (collision==100 && collideFirstTime) {
                    mScoreboard->AddMoney(100);
                    //mScoreboard->DisplayNumber(mSparty->GetX(), mSparty->GetY(), "$100");
                    mScoreboard->SetMoneyMessage("+$100");
                }
                if (collision==1000 && collideFirstTime) {
                    mScoreboard->AddMoney(1000);
                    mScoreboard->SetMoneyMessage("+$1000");
                }
                // return 2 for enemy killing sparty
                if (collision==2 && collideFirstTime) {
                    mSparty->Die();
                }
                // return 3 for worm hole
                if (collision==3 && collideFirstTime) {
                    mSparty->WormHole();
                }
                // return 4 for Stanley
                if (collision==4 && collideFirstTime) {
                    mScoreboard->Stanley();
                    mScoreboard->SetMoneyMessage("+Tuition\n Up!");
                }
            }

        }

    }

    if(!mSparty->IsAlive())
    {
        mScoreboard->SetTitle("You died, press Space to retry");
    }

    if(mSparty->LevelReset())
    {
        ResetLevel();
    }

}

/**
 * Accept a visitor for the collection of items
 * @param visitor The visitor for the items
 */
void Level::Accept(ItemVisitor* visitor)
{
    for (auto item : mItems)
    {
        item->Accept(visitor);
    }
}

/**
 * Draws items onto the game screen
 * @param graphics Graphics context to use
 * @param scrollX Amount to offset for scrolling purposes
 */
void Level::Draw(std::shared_ptr<wxGraphicsContext> graphics, int scrollX)
{
    for (auto item: mItems)
    {
        item->Draw(graphics, scrollX);
    }
}

/**
 * Collision test for Sparty
 * with platforms and walls
 * @return item Sparty has collided with
 */
std::shared_ptr<Item> Level::CollisionTest(){

    // COLLISION STUFF
    for(auto item : mItems)
    {
        int collision = item->Accept(&mItemVisitor);
        if(collision == 5) {

            double itemTop = item->GetY()-(item->GetHeight()/2.0);
            double itemBottom = item->GetY()+(item->GetHeight()/2.0);
            double itemLeft = item->GetX()-(item->GetWidth()/2.0);
            double itemRight = item->GetX()+(item->GetWidth()/2.0);

            double spartyLeft = mSparty->GetX()-mSparty->GetImageWidth()/2.0;
            double spartyRight = mSparty->GetX()+mSparty->GetImageWidth()/2.0;
            double spartyTop = mSparty->GetY()-mSparty->GetImageHeight()/2.0;
            double spartyBottom = mSparty->GetY()+mSparty->GetImageHeight()/2.0;

            if (!(spartyRight<itemLeft ||  // Completely to the left
                    spartyLeft>itemRight ||  // Completely to the right
                    spartyTop>itemBottom ||  // Completely below
                    spartyBottom<itemTop))    // Completely above
            {
                return item;
            }
        }

    }

    return nullptr;

}
