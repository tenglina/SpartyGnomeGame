/**
 * @file SpartyGnomeDeclaration.cpp
 * @author Isabella Beth Engelman
 *
 * SpartyGnomeDeclaration implementation file
 */

#include "pch.h"
#include "SpartyGnomeDeclaration.h"
#include "SpartyGnome.h"

/**
 * SpartyGnomeDeclaration constructor
 * @param game Game we are tied to
 * @param filename Filename to make image and bitmaps from
 * @param id Id assigned from level xml file
 */
SpartyGnomeDeclaration::SpartyGnomeDeclaration(Game* game, const std::wstring& filename, std::wstring& id) : Declaration(game, filename, id){


}
