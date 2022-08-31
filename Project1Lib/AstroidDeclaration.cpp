/**
 * @file AstroidDeclaration.cpp
 * @author Isabella Beth Engelman
 *
 * Astroid Declaration implementation file
 */

#include "pch.h"
#include "AstroidDeclaration.h"
#include "Astroid.h"

using namespace std;

/**
 * Astroid Declaration Constructor
 * @param game Game this declaration is tied to
 * @param filename Filename this declaration gets its image and bitmap from
 * @param id Id the xml gives this declaration
 */
AstroidDeclaration::AstroidDeclaration(Game* game, const std::wstring & filename, std::wstring & id) : Declaration(game, filename, id) {

}

/**
 * Create function, creates an astroid object
 * @return returns an astroid object using this declarations id, image and bitmap
 */
std::shared_ptr<Item> AstroidDeclaration::Create()
{
    auto astroid = std::make_shared<Astroid>(GetGame(), mImage, mBitmap);
    astroid->SetId(GetId());
    return astroid;
}