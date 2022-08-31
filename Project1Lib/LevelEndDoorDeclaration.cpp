/**
 * @file LevelEndDoorDeclaration.cpp
 * @author Isabella Beth Engelman
 *
 * LevelEndDoorDeclaration implementation file
 */

#include "pch.h"
#include "LevelEndDoorDeclaration.h"
#include "LevelEndDoor.h"


/**
 * Constructor for LevelEndDoorDeclaration
 * @param game Game we are a part of
 * @param filename Filename to make our wxImage and wxBitmap from
 * @param id Id assigned by level xml file
 */
LevelEndDoorDeclaration::LevelEndDoorDeclaration(Game* game, const std::wstring& filename, std::wstring& id) : Declaration(game, filename, id)
{

}

/**
 * Create function to create a level end door
 * @return returns a level end door item
 */
std::shared_ptr<Item> LevelEndDoorDeclaration::Create()
{
    auto levelenddoor = std::make_shared<LevelEndDoor>(GetGame(), mImage, mBitmap);
    levelenddoor->SetId(GetId());
    return levelenddoor;
}