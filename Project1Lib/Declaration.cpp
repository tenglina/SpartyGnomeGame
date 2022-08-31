/**
 * @file Declaration.cpp
 * @author Isabella Beth Engelman
 *
 * Declaration implementation file
 */
#include "pch.h"
#include "Declaration.h"
#include "Game.h"

using namespace std;

/**
 * Constructor for declaration object
 * @param game Game object we are tied to
 * @param filename Filename to generate image and bitmap from
 * @param id Id assigned by xml level file
 */
Declaration::Declaration(Game *game, const std::wstring &filename, std::wstring &id)
{
    mGame = game;
    mImageName += filename;
    mImage = make_shared<wxImage>(mImageName, wxBITMAP_TYPE_ANY);
    mBitmap = make_shared<wxBitmap>(*mImage);
    mId = id;
}
