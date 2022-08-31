/**
 * @file BackgroundDeclaration.cpp
 * @author Isabella Beth Engelman
 *
 * BackgroundDeclaration implementation file
 */

#include "pch.h"
#include "BackgroundDeclaration.h"
#include "Background.h"

using namespace std;

/**
 * BackgroundDeclaration constructor
 * @param game The game this declaration is a part of
 * @param filename The filename to use when making image and bitmaps
 * @param id The id assigned by the xml level file
 */
BackgroundDeclaration::BackgroundDeclaration(Game* game, const std::wstring& filename, std::wstring& id) : Declaration(game, filename, id)
{

}

/**
 * Create a background from this declaration
 * @return Pointer to background item we created
 */
shared_ptr<Item> BackgroundDeclaration::Create()
 {
     auto background = std::make_shared<Background>(GetGame(), mImage, mBitmap);
     background->SetId(GetId());
     return background;

 }

