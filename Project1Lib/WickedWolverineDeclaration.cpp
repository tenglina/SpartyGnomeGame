/**
 * @file WickedWolverineDeclaration.cpp
 * @author Isabella Beth Engelman
 *
 * WickedWolverineDeclaration implementation file
 */
#include "pch.h"
#include "WickedWolverineDeclaration.h"
#include "WickedWolverine.h"

/**
 * WickedWolverineDeclaration constructor
 * @param game Game we are tied to
 * @param filename Filename to create image and bitmap from
 * @param id Id assigned from xml level file
 */
WickedWolverineDeclaration::WickedWolverineDeclaration(Game* game, const std::wstring& filename, std::wstring& id) : Declaration(game, filename, id){

}

/**
 * Create function
 * @return WickedWolverine item we create
 */
std::shared_ptr<Item> WickedWolverineDeclaration::Create()
{
    auto wickedwolverine = std::make_shared<WickedWolverine>(GetGame(), mImage, mBitmap);
    wickedwolverine->SetId(GetId());
    return wickedwolverine;

}