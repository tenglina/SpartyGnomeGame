/**
 * @file MainFrame.cpp
 * @author Tim Moran
 *
 * MainFrame implementation
 */

#include "pch.h"
#include "MainFrame.h"
#include "GameView.h"
#include "ids.h"

/**
 * Initializes the frame
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"Project 1",
            wxDefaultPosition,  wxSize( 1000,800 ));

    // Create a sizer that will lay out child windows vertically
    // one above each other
    auto sizer = new wxBoxSizer( wxVERTICAL );

    // Create the view class object as a child of MainFrame
    mGameView = new GameView();
    mGameView->Initialize(this);

    // Add it to the sizer
    sizer->Add(mGameView,1, wxEXPAND | wxALL );

    // Set the sizer for this frame
    SetSizer(sizer);

    // Layout (place) the child windows.
    Layout();

    // Menus
    //File: save and load
    //Level: select level
    //Add: add items
    auto menuBar = new wxMenuBar( );

    //File Menu
    auto fileMenu = new wxMenu();
    fileMenu->Append(wxID_EXIT, "&Exit\tAlt-X", "Quit this program");
    fileMenu->Append(wxID_SAVEAS, "Save &As...\tCtrl-S", L"Save game as...");
    fileMenu->Append(wxID_OPEN, "Open &File...\tCtrl-F", L"Open game file...");

    //Level select menu
    auto levelMenu = new wxMenu();
    levelMenu->Append(IDM_LEVEL0, "&Level 0\t", "Level 0");
    levelMenu->Append(IDM_LEVEL1, "&Level 1\t", "Level 1");
    levelMenu->Append(IDM_LEVEL2, "&Level 2\t", "Level 2");
    levelMenu->Append(IDM_LEVEL3, "&Level 3\t", "Level 3");

    //Add menu
    auto addMenu = new wxMenu();
    addMenu->Append(IDM_ADDPLATFORM, L"&Platform", L"Add a Platform");
    addMenu->Append(IDM_ADDASTEROID, L"&Asteroid", L"Add an Asteroid");
    addMenu->Append(IDM_ADDWORMHOLE, L"&Wormhole", L"Add a Wormhole");
    addMenu->Append(IDM_ADDWICKEDWOLVERINE, L"&WickedWolverine", L"Add a WickedWolverine Enemy");
    addMenu->Append(IDM_ADDWISCONSONCAT, L"&WisconsonCat", L"Add a Wisconson Cat Enemy");
    addMenu->Append(IDM_ADDMONEY, L"&Money", L"Add Money");
    addMenu->Append(IDM_ADDSTANLEY, L"&Stanley", L"Add Stanley");
    addMenu->Append(IDM_ADDSPARTY, L"&Sparty", L"Add Sparty Gnome");

    menuBar->Append(fileMenu, L"&File");
    menuBar->Append(levelMenu, L"&Levels");
    //menuBar->Append(addMenu, "&Add");

    SetMenuBar(menuBar);

    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);
}
/**
 * Exit option menu handler
 * @param event Command Event
 */
void MainFrame::OnExit(wxCommandEvent &event)
{
    Close(true);
}

/**
 * About menu option handlers
 * @param event Command Event
 */
void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox(L"Welcome to the Game!",
            L"About Game",
            wxOK,
            this);
}

/**
 * Handle a close event. Stop the animation and destroy this window.
 * @param event The Close event
 */
void MainFrame::OnClose(wxCloseEvent& event)
{
    mGameView->Stop();
    Destroy();
}

