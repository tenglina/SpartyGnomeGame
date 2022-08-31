/**
 * @file MoneyDeclaration.cpp
 * @author Isabella Beth Engelman
 *
 * MoneyDeclaration implementation file
 */

#include "pch.h"
#include "MoneyDeclaration.h"
#include "Money.h"

/**
 * Constructor for MoneyDeclaration
 * @param game Game we are tied to
 * @param filename Filename to create Image and Bitmap from
 * @param id Id given by xml level file
 * @param value Value for moneys when we create them
 */
MoneyDeclaration::MoneyDeclaration(Game* game, const std::wstring& filename, std::wstring& id, int &value) : Declaration(game, filename, id){
    mValue = value;
}

/**
 * Create function
 * @return returns an money item object
 */
std::shared_ptr<Item> MoneyDeclaration::Create()
{
    auto money = std::make_shared<Money>(GetGame(), mImage, mBitmap, mValue);
    money->SetId(GetId());
    return money;
}