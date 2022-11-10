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

    InitWindow(screenWidth, screenHeight, "Frog does NOT go splat");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    //initialize player
    Player * player = new Player();
    // Testing - initialize scrolling objects
    std::vector<ScrollingObject*> scrollingObjects;

    ScrollingObject* LeftToRight = new ScrollingObject(true, false);
    ScrollingObject* RightToLeft = new ScrollingObject(false, false);

    scrollingObjects.push_back(LeftToRight);
    scrollingObjects.push_back(RightToLeft);
    

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        player->Update();
        LeftToRight->Update();
        RightToLeft->Update();

        //  iterate through each object in the scrollingObjects vector
        for (int i = 0; i < scrollingObjects.size(); i++)
        {
            //cache the scrolling object center position for easier access during collision detection
            Vector2 ScrollingObjectCenterPos = { scrollingObjects[i]->GetXPos() + gridSize / 2.0f, scrollingObjects[i]->GetYPos() + gridSize / 2.0f };
            //  check if the player has collided with any of the objects in the vector
            if (CheckCollisionCircles(player->GetPosition(), 1.0f, ScrollingObjectCenterPos, gridSize / 2.0f))
            {
                //  if there is a collision and the object is marked as a hazard:
                if (scrollingObjects[i]->isHazard)
                {
                    //  kill the player, subtract a life, reset pos
                    //  TODO: implement me
                }
                //  otherwise, it is a platform
                else
                {
                    //  make frog ride that platform
                    player->RidingObject(scrollingObjects[i]);
                }
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

        
        for (int j = 0; j < scrollingObjects.size(); j++)
        {
            scrollingObjects[j]->Draw();
        }

        player->Draw();
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