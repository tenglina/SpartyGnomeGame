/**
 * @file GameApp.cpp
 * @author Tim Moran
 */

#include "pch.h"
#include "GameApp.h"
#include <MainFrame.h>

/**
 * Initialize the application.
 * @return
 */
bool GameApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    ///ADDEDCODEBYISABELLA
    // Add image type handlers
    wxInitAllImageHandlers();

    auto frame = new MainFrame();
    frame->Initialize();
    frame->Show(true);



    return true;
}
