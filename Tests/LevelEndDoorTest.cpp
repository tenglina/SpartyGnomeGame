/**
 * @file LevelEndDoorTest.cpp
 * @author Nandini Tengli
 */


#include <pch.h>
#include "gtest/gtest.h"
#include <LevelEndDoor.h>
#include <Game.h>

using namespace std;

TEST(LevelEndDoor, Construct){
    LevelEndDoor testDoor(Game *game);
}

