/**
 * @file WisconsonCat.cpp
 * @author Nandini Tengli
 *
 * WisconsonCat implementation file
 */

#include "pch.h"
#include "WisconsonCat.h"
using namespace std;

/**
 * Constructor
 * @param game Game we are tied to
 * @param image wxImage to use
 * @param bitmap wxBitmap to use
 */
WisconsonCat::WisconsonCat(Game* game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap) :Enemy(game, image, bitmap )
{

}