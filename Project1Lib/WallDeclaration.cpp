/**
 * @file WallDeclaration.cpp
 * @author Alexandra Case
 *
 * WallDeclaration implementation file
 */

#include "pch.h"
#include "WallDeclaration.h"
#include "Wall.h"

/**
 * Constructor
 * @param game Game we are tied to
 * @param filename Filename to make image and bitmaps from
 * @param id Id assigned from xml level file
 */
WallDeclaration::WallDeclaration(Game* game, const std::wstring& filename, std::wstring& id) : Declaration(game, filename, id){

}

/**
 * Create function
 * @return returns a Wall item that this function creates
 */
std::shared_ptr<Item> WallDeclaration::Create()
{
    auto wall = std::make_shared<Wall>(GetGame(), mImage, mBitmap);
    wall->SetId(GetId());
    return wall;

}