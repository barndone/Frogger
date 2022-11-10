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
#include "Player.h"
#include "ScrollingObject.h"
#include <vector>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int gridSize = 50;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    //initialize player
    Player * player = new Player();
    // Testing - initialize scrolling objects
    std::vector<ScrollingObject> scrollingPlatforms;

    ScrollingObject* LeftToRight = new ScrollingObject(true, false);
    ScrollingObject* RightToLeft = new ScrollingObject(false, false);

    scrollingPlatforms.push_back(*LeftToRight);
    scrollingPlatforms.push_back(*RightToLeft);
    

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        player->Update();
        LeftToRight->Update();
        RightToLeft->Update();

        //  check if frog is on a platform
        
        for (int i = 0; i < scrollingPlatforms.size(); i++)
        {
            if (CheckCollisionCircles(player->Position, gridSize / 2.0f, scrollingPlatforms[i].Position, gridSize / 2.0f))
            {
                player->RidingObject(&scrollingPlatforms[i]);
            }
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        //draw a grid (testing purposes)
        //for each column section
        for (int width = 0; width < (screenWidth / gridSize); width++)
        {
            //draw each row of the column
            for (int height = 0; height < screenHeight / gridSize; height++)
            {
                DrawRectangleLines(width * gridSize, height * gridSize, gridSize, gridSize, BLACK);
            }
        }

        player->Draw();
        LeftToRight->Draw();
        RightToLeft->Draw();




        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    delete player;
    delete LeftToRight;
    delete RightToLeft;
    //--------------------------------------------------------------------------------------

    return 0;
}