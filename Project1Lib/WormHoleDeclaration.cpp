/**
 * @file WormHoleDeclaration.cpp
 * @author Isabella Beth Engelman
 *
 * WormHoleDeclaration implementation file
 */

#include "pch.h"
#include "WormHoleDeclaration.h"
#include "WormHole.h"

/**
 * WormHoleDeclaration Constructor
 * @param game Game we are tied to
 * @param filename Filename to create image and bitmaps from
 * @param id Id assigned from xml level file
 */
WormHoleDeclaration::WormHoleDeclaration(Game* game, const std::wstring& filename, std::wstring& id) : Declaration(game, filename, id){

}

/**
 * Create function
 * @return Wormhole item we create
 */
std::shared_ptr<Item> WormHoleDeclaration::Create()
{
    auto  wormhole = std::make_shared<WormHole>(GetGame(), mImage, mBitmap);
    wormhole->SetId(GetId());
    return wormhole;

}