/**
 * @file PlatformDeclaration.h
 * @author Isabella Beth Engelman
 *
 * PlatformDeclaration header file
 */

#ifndef PROJECT1_PLATFORMDECLARATION_H
#define PROJECT1_PLATFORMDECLARATION_H
#include "Declaration.h"

/**
 * PlatformDeclaration object
 */
class PlatformDeclaration: public Declaration {
private:
    /// Image file name for left platform image
    std::wstring mImageNameLeft = L"images/";

    /// Image file name for right platform image
    std::wstring mImageNameRight = L"images/";

    /// Left platform Image
    std::shared_ptr<wxImage> mImageLeft;

    /// Right platform Image
    std::shared_ptr<wxImage> mImageRight;

    /// Left platform Bitmap
    std::shared_ptr<wxBitmap> mBitmapLeft;

    /// Right platform Bitmap
    std::shared_ptr<wxBitmap> mBitmapRight;

public:

    // Constructor
    PlatformDeclaration(Game* game, const std::wstring& filenameLeft, const std::wstring& filename, const std::wstring& filenameRight, std::wstring& id);

    // Create item based on declaration
    std::shared_ptr<Item> Create() override;

};

#endif //PROJECT1_PLATFORMDECLARATION_H
