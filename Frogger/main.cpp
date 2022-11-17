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
#include "LilyPad.h"
#include "Background.h"
#include <vector>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 750;
    const int screenHeight = 750;
    const int gridSize = 50;

    bool isRiding = false;

    float Timer = 0.0f;

    InitWindow(screenWidth, screenHeight, "Frog does NOT go splat");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    //initialize player
    Player * player = new Player();
    // Testing - initialize scrolling objects
    std::vector<ScrollingObject*> scrollingObjects;
    std::vector<LilyPad*> lilyPads;
    std::vector<Background*> backgroundTiles;
    //for each column:
    for (int width = 0; width < (screenWidth / gridSize); width++)
    {
        //internal counter for scrollingObjects vector iteration
        int i = 0;
        //for each tile in the column:
        for (int height = 0; height < (screenHeight / gridSize) - 1; height++)
        {
            //Initilizate background logic:
            //if height < 7 - water
            if (height < 7)
            {
                //create a background object (water) and add to vector
                backgroundTiles.push_back(new Background(true, false, width * gridSize, height * gridSize));
                //even column tiles at height level 0- initialize a lilypad

                if ((height == 0) && (width % 2 == 0))
                {
                    lilyPads.push_back(new LilyPad((float)width * gridSize, (float)height * gridSize));
                }

                //if height is greater than 0: initialize scrolling objects in addition to background Tiles
                if (height > 0 && width == 0)
                {
                    //if the height value is ODD
                    if (height % 2 == 1)
                    {
                        //initialize a scrolling object that is moving to the RIGHT and is NOT A HAZARD
                        scrollingObjects.push_back(new ScrollingObject(true, false));
                        //set position to left of screen, at the corresponding height value
                        scrollingObjects[i]->SetPosition(0, height * gridSize);
                        i++;
                    }
                    //otherwise it is EVEN
                    else
                    {
                        //initialize a scrolling object that is moving to the LEFT and IS NOT A HAZARD
                        scrollingObjects.push_back(new ScrollingObject(false, false));
                        //set position to the right of screen at corresponding height value
                        scrollingObjects[i]->SetPosition(screenWidth, height * gridSize);
                        i++;
                    }
                }
            }
            //if height == 7, 10, 13 - notroad (sidewalk)
            else if (height == 7 || height == 10 || height == 13)
            {
                //create a background object (sidewalk) and add to vector
                backgroundTiles.push_back(new Background(false, false, width * gridSize, height * gridSize));
            }
            //else - it is road
            else
            {
                //create a background object (road) and add to vector
                backgroundTiles.push_back(new Background(false, true, width * gridSize, height * gridSize));
                //if height is less than 10, CARS GO LEFT
                if (height < 10 && width == 0)
                {
                    //initialize a scrolling object that is moving to the LEFT and IS a hazard
                    scrollingObjects.push_back(new ScrollingObject(false, true));
                    //set position to the right of screen at corresponding height value
                    scrollingObjects[i]->SetPosition(screenWidth, height * gridSize);
                    i++;
                }
                //OTHERWISE THEY GO RIGHT
                else if (height > 10 && width == 0)
                {
                    //initialize a scrolling object that is moving to the RIGHT and IS a hazard
                    scrollingObjects.push_back(new ScrollingObject(true, true));
                    //set position to the right of screen at corresponding height value
                    scrollingObjects[i]->SetPosition(screenWidth, height * gridSize);
                    i++;
                }
            }
            
        }
    }
 
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        //Update each of the scrolling objects (hazards and platforms)
        for (int j = 0; j < scrollingObjects.size(); j++)
        {
            scrollingObjects[j]->Update();
        }
        player->Update();

        //  iterate through each object in the scrollingObjects vector
        for (int i = 0; i < scrollingObjects.size(); i++)
        {
        //    //cache the scrolling object center position for easier access during collision detection
        //    Vector2 ScrollingObjectCenterPos = { scrollingObjects[i]->GetXPos() + gridSize / 2.0f, scrollingObjects[i]->GetYPos() + gridSize / 2.0f };
        //    //  check if the player has collided with any of the objects in the vector
        //    //
        //    if (CheckCollisionCircles(  player->GetPosition(),                          //position of the player (already centered to grid spaces
        //                                1.0f,                                           //radius of the player collision zone (1.0f to keep the check to the center point)
        //                                ScrollingObjectCenterPos,                       //position for the center of the scrolling object
        //                                gridSize))                                      //radius of the object is the gridSize (50) / 2 -> takes up entire bounds of grid
        //
            if (CheckCollisionCircleRec(    player->GetPosition(),                          //position of player (already centered)
                                            1.0f,                                           //radius of player collision check
                                            scrollingObjects[i]->rec))                      //rectangle component of scrolling object
            {
                //  if there is a collision and the object is not marked as a hazard:
                if (scrollingObjects[i]->isHazard == false)
                {                    
                    //  make frog ride that platform
                    isRiding = true;
                    player->RidingObject(scrollingObjects[i]);
                }
                //  otherwise, it is a hazard
                else
                {
                    //so respawn the frog
                    player->Respawn();
                }
            }
            //otherwise, there is no collision
            else
            {
                //frog is not riding anything
                isRiding = false;
            }
        }
        //  iterate through list of lilypads to see if player is on one of them (same process as above)
        for (int i = 0; i < lilyPads.size(); i++)
        {
            //Cache the center of the LilyPads for collision detection
            Vector2 LilyPadCenter = { lilyPads[i]->GetXPos() + gridSize / 2.0f, lilyPads[i]->GetYPos() + gridSize / 2.0f };
            //  collision test is same as above EXCEPT also check if the lilypad is NOT activated
            if (CheckCollisionCircles(player->GetPosition(),    //position of the player (already centered to grid spaces
                1.0f,                                           //radius of the player collision zone (1.0f to keep the check to the center point)
                LilyPadCenter,                                  //position for the center of the LilyPad
                gridSize / 2.0f) &&                             //radius of the object is the gridSize (50) / 2 -> takes up entire bounds of grid
                !lilyPads[i]->activated)
            {
                //  if it is not activated, set it to active and change its color
                //  reset the player position, increment points
                lilyPads[i]->activated = true;
                lilyPads[i]->SetColor(PINK);
                player->SetPosition(player->RespawnPos);
                player->Score += 250;
            }
        }

        //  check if the player has entered the water and is NOT riding a log
        for (int i = 0; i < backgroundTiles.size(); i++)
        {
            if (backgroundTiles[i]->GetHazard() == true)
            {
                //Cache the center of the tile for collision detection
                Vector2 tileCenter = { backgroundTiles[i]->GetXPos() + gridSize / 2.0f, backgroundTiles[i]->GetYPos() + gridSize / 2.0f };
                //  collision test is same as above EXCEPT also check if the player is NOT riding a log
                if (CheckCollisionCircles(player->GetPosition(),    //position of the player (already centered to grid spaces
                    1.0f,                                           //radius of the player collision zone (1.0f to keep the check to the center point)
                    tileCenter,                                     //position for the center of the tile
                    gridSize / 2.0f) &&                             //radius of the object is the gridSize (50) / 2 -> takes up entire bounds of grid
                    !CheckCollisionCircleRec(
                    player->GetPosition(),
                    1.0f,
                    player->Platform->rec
                    ))                                      //is the player NOT riding an object
                {
                    player->Respawn();
                }
            }
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        //draw each of the background tiles:
        for (int j = 0; j < backgroundTiles.size(); j++)
        {
            backgroundTiles[j]->Draw();
        }

        //draw a grid (testing purposes)
        //for each column section
        for (int width = 0; width < (screenWidth / gridSize); width++)
        {
            //draw each row of the column
            for (int height = 0; height < (screenHeight / gridSize) - 1; height++)
            {
                //draw the outline of the grid
                DrawRectangleLines(width * gridSize, height * gridSize, gridSize, gridSize, BLACK);
            }
        }
        //draw each of the scrolling objects (hazards and platforms)
        for (int j = 0; j < scrollingObjects.size(); j++)
        {
            scrollingObjects[j]->Draw();
        }
        
        //draw each of the lilypads
        for (int j = 0; j < lilyPads.size(); j++)
        {
            lilyPads[j]->Draw();
        }

        //draw player last to put on top-most layer
        player->Draw();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //clear memory
    delete player;

    //clear memory
    for (int j = 0; j < scrollingObjects.size(); j++)
    {
        delete scrollingObjects[j];
    }

    //clear memory
    for (int j = 0; j < lilyPads.size(); j++)
    {
        delete lilyPads[j];
    }

    //clear memory
    for (int j = 0; j < backgroundTiles.size(); j++)
    {
        delete backgroundTiles[j];
    }

    //--------------------------------------------------------------------------------------

    return 0;
}