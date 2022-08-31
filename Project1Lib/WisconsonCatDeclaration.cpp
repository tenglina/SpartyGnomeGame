/**
 * @file WisconsonCatDeclaration.cpp
 * @author Isabella Beth Engelman
 *
 * WisconsonCatDeclaration implementation file
 */

#include "pch.h"
#include "WisconsonCatDeclaration.h"
#include "WisconsonCat.h"

/**
 * WisconsonCatDeclaration Constructor
 * @param game Game we are tied to
 * @param filename Filename to create Images and Bitmaps from
 * @param id Id assigned from xml level file
 */
WisconsonCatDeclaration::WisconsonCatDeclaration(Game* game, const std::wstring& filename, std::wstring& id) : Declaration(game, filename, id){

}

/**
 * Create function
 * @return The WisconsonCat object we created
 */
std::shared_ptr<Item> WisconsonCatDeclaration::Create()
{
    auto wisconsoncat = std::make_shared<WisconsonCat>(GetGame(), mImage, mBitmap);
    wisconsoncat->SetId(GetId());
    return wisconsoncat;

}