/**
 * @file StanleyDeclaration.cpp
 * @author Isabella Beth Engelman
 *
 * StanleyDeclaration implementation file
 */

#include "pch.h"
#include "StanleyDeclaration.h"
#include "Stanley.cpp"
#include "Game.h"
#include <wx/graphics.h>

/**
 * StanleyDeclaration constructor
 * @param game Game we are tied to
 * @param filename Filename to make image and bitmaps from
 * @param id Id assigned by xml level file
 */
StanleyDeclaration::StanleyDeclaration(Game* game, const std::wstring& filename, std::wstring& id) : Declaration(game, filename, id)
{


}

/**
 * Create function, creates a stanley object
 * @return Stanley item
 */
shared_ptr<Item> StanleyDeclaration::Create()
{
    auto stanley = std::make_shared<Stanley>(GetGame(), mImage, mBitmap);
    stanley->SetId(GetId());
    return stanley;

}


