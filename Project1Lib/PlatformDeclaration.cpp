/**
 * @file PlatformDeclaration.cpp
 * @author Isabella Beth Engelman
 *
 * PlatformDeclaration implementation file
 */

#include "pch.h"
#include "PlatformDeclaration.h"
#include "Platform.h"
#include <wx/graphics.h>

using namespace std;

/**
 * PlatformDeclaration constructor
 * @param game Game we are tied to
 * @param filenameLeft Filename of left image and bitmap we will use
 * @param filename Filename of middle image and bitmap we will use
 * @param filenameRight Filename of right image and bitmap we will use
 * @param id Id assigned by level xml file
 */
PlatformDeclaration::PlatformDeclaration(Game* game, const std::wstring& filenameLeft, const std::wstring& filename, const std::wstring& filenameRight, std::wstring& id) : Declaration(game, filename, id){
    mImageNameLeft += filenameLeft;
    mImageNameRight += filenameRight;
    mImageLeft = make_shared<wxImage>(mImageNameLeft, wxBITMAP_TYPE_ANY);
    mBitmapLeft = make_shared<wxBitmap>(*mImageLeft);
    mImageRight = make_shared<wxImage>(mImageNameRight, wxBITMAP_TYPE_ANY);
    mBitmapRight = make_shared<wxBitmap>(*mImageRight);
}

/**
 * Create a platform from this declaration
 * @return The platform item we have created
 */
shared_ptr<Item> PlatformDeclaration::Create()
{
    auto platform = std::make_shared<Platform>(GetGame(), mImageLeft, mBitmapLeft, mImage, mBitmap, mImageRight, mBitmapRight);
    platform->SetId(GetId());
    return platform;

}