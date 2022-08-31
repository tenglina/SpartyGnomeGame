cmake_minimum_required(VERSION 3.21)
project(Project1Lib)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES Item.cpp Item.h SpartyGnome.cpp SpartyGnome.h Platform.cpp Platform.h Game.cpp Game.h pch.h MainFrame.cpp MainFrame.h
        GameView.cpp GameView.h LevelEndDoor.cpp LevelEndDoor.h Enemy.cpp Enemy.h WickedWolverine.cpp WickedWolverine.h Astroid.cpp Astroid.h
        WormHole.cpp WormHole.h Stanley.cpp Stanley.h ids.h Background.cpp Background.h Money.cpp Money.h WisconsonCat.cpp WisconsonCat.h Vector.cpp Vector.h
        Declaration.cpp Declaration.h BackgroundDeclaration.cpp BackgroundDeclaration.h
        LevelEndDoorDeclaration.cpp LevelEndDoorDeclaration.h MoneyDeclaration.cpp MoneyDeclaration.h PlatformDeclaration.cpp PlatformDeclaration.h
        SpartyGnomeDeclaration.cpp SpartyGnomeDeclaration.h StanleyDeclaration.cpp StanleyDeclaration.h WickedWolverineDeclaration.cpp WickedWolverineDeclaration.h
        WisconsonCatDeclaration.cpp WisconsonCatDeclaration.h WormHoleDeclaration.cpp WormHoleDeclaration.h Level.cpp Level.h Wall.cpp Wall.h WallDeclaration.cpp WallDeclaration.h
        AstroidDeclaration.h AstroidDeclaration.cpp Scoreboard.cpp Scoreboard.h PlayingArea.cpp PlayingArea.h ItemVisitor.cpp ItemVisitor.h)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)