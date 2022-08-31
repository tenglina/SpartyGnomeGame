/**
 * @file MainFrame.h
 * @author Tim Moran
 *
 * Main Frame of the program
 */

#ifndef PROJECT1_MAINFRAME_H
#define PROJECT1_MAINFRAME_H

#include "GameView.h"

/**
 * The main frame of the application
 */
class MainFrame: public wxFrame {
private:

    /// Game View member variable, for stop function
    GameView* mGameView;

    /// Exit event
    void OnExit(wxCommandEvent& event);

    /// About event
    void OnAbout(wxCommandEvent& event);

public:
    // Initalize function
    void Initialize();

    // On close event to close the frame
    void OnClose(wxCloseEvent& event);

};

#endif //PROJECT1_MAINFRAME_H
