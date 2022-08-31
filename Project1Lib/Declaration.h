/**
 * @file Declaration.h
 * @author Isabella Beth Engelman
 *
 * Declaration header file
 */

#ifndef PROJECT1_DECLARATION_H
#define PROJECT1_DECLARATION_H

#include "Item.h"

class Game;
/**
 * Declaration class
 *
 * Declarations declared in xml level file, this is how
 * images are only loaded once, despite multiple instances of same items
 */
class Declaration {
private:

    /// Game this declaration is tied to
    Game *mGame;

    /// filename (defaults to images folder)
    std::wstring mImageName = L"images/";

    /// WormHole id
    std::wstring mId;

protected:
    /// wxImage object for image
    std::shared_ptr<wxImage> mImage;

    /// wxBitmap object for bitmap
    std::shared_ptr<wxBitmap> mBitmap;

public:

    // Constructor that includes image filename
    Declaration(Game *game, const std::wstring &filename, std::wstring &id);

    /**
     * Returns the image name
     * @return mImageName
     */
     std::wstring GetImageName(){return mImageName;}

    /**
    * Returns the id
    * @return mId
    */
    std::wstring GetId(){return mId;}

    /**
    * Returns the game
    * @return mId
    */
    Game* GetGame(){return mGame;}

    /**
     * Create item based on declaration (returns null, other declarations should override)
     * @return shared pointer to Item that gets created
     */
    virtual std::shared_ptr<Item> Create() {return nullptr;}

};

#endif //PROJECT1_DECLARATION_H



