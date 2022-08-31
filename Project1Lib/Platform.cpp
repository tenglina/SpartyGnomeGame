/**
 * @file Platform.cpp
 * @author Xianting Zhang
 *
 * Platform implementation file
 */

#include "pch.h"
#include "Platform.h"
#include <wx/graphics.h>

using namespace std;

/**
 * Constructor
 * @param game Game we are tied to
 * @param imageLeft left image of platform
 * @param bitmapLeft left bitmap of platform
 * @param image  middle image of platform
 * @param bitmap  middle bitmap of platform
 * @param imageRight  right image of platform
 * @param bitmapRight  right bitmap of platform
 */
Platform::Platform(Game * game, std::shared_ptr<wxImage> imageLeft, std::shared_ptr<wxBitmap> bitmapLeft,
        std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap,
        std::shared_ptr<wxImage> imageRight, std::shared_ptr<wxBitmap> bitmapRight) : Item(game, image, bitmap)
{
    mItemImageLeft = std::move(imageLeft);
    mItemBitmapLeft = std::move(bitmapLeft);
    mItemImageRight = std::move(imageRight);
    mItemBitmapRight = std::move(bitmapRight);

}

/**
 * Draw this item
 * @param graphics Graphics context to draw on
 */
void Platform::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    int placeX = GetX() - (mWidth/2) + 16;
    int tilesNeeded = mWidth / 32;
    if(tilesNeeded == 1)
    {
        int wid = mItemBitmap->GetWidth();
        int hit = mItemBitmap->GetHeight();
        graphics->DrawBitmap(*mItemBitmap,
                placeX, (int)GetY() - hit / 2,
                wid + 1, hit);
        return;
    }

    for(int i = 0; i < tilesNeeded; i++)
    {
        if(i == 0)
        {
            int wid = mItemBitmapLeft->GetWidth();
            int hit = mItemBitmapLeft->GetHeight();
            graphics->DrawBitmap(*mItemBitmapLeft,
                    placeX, ((int)GetY() - hit / 2),
                    wid + 1, hit);
            placeX += 32;
            continue;
        }
        if(i == tilesNeeded - 1)
        {
            int wid = mItemBitmapRight->GetWidth();
            int hit = mItemBitmapRight->GetHeight();
            graphics->DrawBitmap(*mItemBitmapRight,
                    placeX, ((int)GetY() - hit / 2),
                    wid + 1, hit);
            continue;
        }
        int wid = mItemBitmap->GetWidth();
        int hit = mItemBitmap->GetHeight();
        graphics->DrawBitmap(*mItemBitmap,
                placeX, ((int)GetY() - hit / 2),
                wid + 1, hit);

        placeX += 32;
    }

}
/**
 * Draw this item
 * @param graphics Graphics context to draw on
 * @param scrollX The amount of pixels being scrolled
 */
void Platform::Draw(std::shared_ptr<wxGraphicsContext> graphics, int scrollX)
{
    int placeX = GetX() - (mWidth/2) + 16;
    int tilesNeeded = mWidth / 32;
    if(tilesNeeded == 1)
    {
        int wid = mItemBitmap->GetWidth();
        int hit = mItemBitmap->GetHeight();
        graphics->DrawBitmap(*mItemBitmap,
                placeX + scrollX, ((int)GetY() - hit / 2),
                wid + 1, hit);
        return;
    }

    for(int i = 0; i < tilesNeeded; i++)
    {
        if(i == 0)
        {
            int wid = mItemBitmapLeft->GetWidth();
            int hit = mItemBitmapLeft->GetHeight();
            graphics->DrawBitmap(*mItemBitmapLeft,
                    placeX + scrollX, ((int)GetY() - hit / 2),
                    wid + 1, hit);
            placeX += 32;
            continue;
        }
        if(i == tilesNeeded - 1)
        {
            int wid = mItemBitmapRight->GetWidth();
            int hit = mItemBitmapRight->GetHeight();
            graphics->DrawBitmap(*mItemBitmapRight,
                    placeX + scrollX, ((int)GetY() - hit / 2),
                    wid + 1, hit);
            continue;
        }
        int wid = mItemBitmap->GetWidth();
        int hit = mItemBitmap->GetHeight();
        graphics->DrawBitmap(*mItemBitmap,
                placeX + scrollX, ((int)GetY() - hit / 2),
                wid + 1, hit);

        placeX += 32;
    }

}




