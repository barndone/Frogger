/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2022 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "GameStateLoop.h"
#include "EndScreenState.h"
#include "NextLevelState.h"
#include "MainMenuState.h"


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 750;
    const int screenHeight = 750;

    int Score = 0;

    InitWindow(screenWidth, screenHeight, "Frog does NOT go splat");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    //initialize player
    GameState *currentGameState = new MainMenuState();
 
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        currentGameState->Update();
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);
        currentGameState->Draw();
        EndDrawing();
        //----------------------------------------------------------------------------------
        //  Manage current Game State
        if (currentGameState->StateShouldChange())
        {
            GameStateLoop* derivedState = dynamic_cast<GameStateLoop*>(currentGameState);
            if (dynamic_cast<GameStateLoop*>(currentGameState) != NULL)
            {
                Score += derivedState->GetScore();
            }
            GameStates nextGameState = currentGameState->GetNextGameState();
            switch (nextGameState)
            {
            case Menu:
                delete currentGameState;
                currentGameState = new MainMenuState();
                break;
            case GameLoop:
                delete currentGameState;
                currentGameState = new GameStateLoop();
                break;
            case NextLevel:
                delete currentGameState;
                currentGameState = new NextLevelState(Score);
                break;
            case EndScreen:
                delete currentGameState;
                currentGameState = new EndScreenState(Score);
                break;

            }
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    delete currentGameState;
    //--------------------------------------------------------------------------------------

    return 0;
}