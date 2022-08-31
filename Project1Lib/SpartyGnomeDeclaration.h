/**
 * @file SpartyGnomeDeclaration.h
 * @author Isabella Beth Engelman
 *
 * SpartyGnomeDeclaration header file
 */

#ifndef PROJECT1_SPARTYGNOMEDECLARATION_H
#define PROJECT1_SPARTYGNOMEDECLARATION_H

#include "Declaration.h"

/**
 * SpartyGnomeDeclaration object
 */
class SpartyGnomeDeclaration: public Declaration {
private:

public:
    // Constructor
    SpartyGnomeDeclaration(Game* game, const std::wstring& filename, std::wstring& id);

    /**
     * Returns the image
     * @return wxImage to return
     */
    std::shared_ptr<wxImage> GetImage(){return mImage;}

    /**
     * Returns the bitmap
     * @return wxBitmap to return
     */
    std::shared_ptr<wxBitmap> GetBitmap(){return mBitmap;}
};

#endif //PROJECT1_SPARTYGNOMEDECLARATION_H
