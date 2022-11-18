#include "GameStateLoop.h"
  
//global variables
int gridSize = 50;
int screenWidth = GetScreenWidth();
int screenHeight = GetScreenHeight();
int padsReached = 0;
bool isRiding = false;
float timeElapsed = 0.0f;
float timeLimit = 60.0f;

//initialize player
Player* player = new Player();

//initialize UIObject
UIObject* ui = new UIObject(player, timeElapsed, timeLimit, 50, screenHeight - 48);

//initialize scrolling objects vector
std::vector<ScrollingObject*> scrollingObjects;

//initialize lilypad vector
std::vector<LilyPad*> lilyPads;

//initialize background tiles vector
std::vector<Background*> backgroundTiles;

std::vector<int> activatedPads;

GameStateLoop::GameStateLoop()
{
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();

    this->Start();
}

GameStateLoop::~GameStateLoop()
{
    //clear memory
    delete player;

    //clear memory
    for (int j = 0; j < scrollingObjects.size(); j++)
    {
        delete scrollingObjects[j];
    }
    scrollingObjects.clear();

    //clear memory
    for (int j = 0; j < lilyPads.size(); j++)
    {
        delete lilyPads[j];
    }
    lilyPads.clear();

    //clear memory
    for (int j = 0; j < backgroundTiles.size(); j++)
    {
        delete backgroundTiles[j];
    }
    backgroundTiles.clear();

    delete ui;
}


void GameStateLoop::Start()
{
    if (timeElapsed >= timeLimit)
    {
        timeElapsed = 0.0f;
    }

    player = new Player();
    ui = new UIObject(player, timeElapsed, timeLimit, 50, screenHeight - 48);

    //for each column:
    for (int width = 0; width < (screenWidth / gridSize); width++)
    {
        //internal counter for scrollingObjects vector iteration
        int i = 0;
        int j = 0;
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
                        if (j == 0)
                        {
                            //initialize a scrolling object that is moving to the RIGHT and is NOT A HAZARD
                            scrollingObjects.push_back(new ScrollingObject(true, false, 2.0f));
                            //set position to left of screen, at the corresponding height value
                            scrollingObjects[i]->SetPosition(-100, height * gridSize);
                        }
                        else if (j == 1)
                        {
                        //initialize a scrolling object that is moving to the RIGHT and is NOT A HAZARD
                        scrollingObjects.push_back(new ScrollingObject(true, false, 1.75f));
                        //set position to left of screen, at the corresponding height value
                        scrollingObjects[i]->SetPosition(-150, height * gridSize);
                        }
                        else if (j == 2)
                        {
                        //initialize a scrolling object that is moving to the RIGHT and is NOT A HAZARD
                        scrollingObjects.push_back(new ScrollingObject(true, false, 1.5f));
                        //set position to left of screen, at the corresponding height value
                        scrollingObjects[i]->SetPosition(-200, height * gridSize);
                        }
                        i++;
                    }
                    //otherwise it is EVEN
                    else
                    {
                    if (j == 0)
                    {
                        //initialize a scrolling object that is moving to the LEFT and IS NOT A HAZARD
                        scrollingObjects.push_back(new ScrollingObject(false, false, 0.7f));
                        //set position to left of screen, at the corresponding height value
                        scrollingObjects[i]->SetPosition(screenWidth - 100, height * gridSize);
                    }
                    else if (j == 1)
                    {
                        //initialize a scrolling object that is moving to the LEFT and IS NOT A HAZARD
                        scrollingObjects.push_back(new ScrollingObject(false, false, 1.0f));
                        //set position to left of screen, at the corresponding height value
                        scrollingObjects[i]->SetPosition(screenWidth - 50, height * gridSize);
                    }
                    else
                    {
                        //initialize a scrolling object that is moving to the LEFT and IS NOT A HAZARD
                        scrollingObjects.push_back(new ScrollingObject(false, false, 1.2f));
                        //set position to left of screen, at the corresponding height value
                        scrollingObjects[i]->SetPosition(screenWidth, height * gridSize);
                    }
                    i++;
                    j++;
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
                //check for fast lane
                if (height == 9)
                {
                    //initialize a scrolling object that is moving to the LEFT and IS a hazard
                    //  this one is in the fast lane
                    scrollingObjects.push_back(new ScrollingObject(false, true, 4.0f));
                }
                else
                {
                    //initialize a scrolling object that is moving to the LEFT and IS a hazard
                    scrollingObjects.push_back(new ScrollingObject(false, true, 2.75f));
                }
                //set position to the right of screen at corresponding height value
                scrollingObjects[i]->SetPosition(screenWidth, height * gridSize);
                i++;
            }
            //OTHERWISE THEY GO RIGHT
            else if (height > 10 && width == 0)
            {
                //check for fast lane
                if (height == 11)
                {
                    //initialize a scrolling object that is moving to the LEFT and IS a hazard
                    //  this one is in the fast lane
                    scrollingObjects.push_back(new ScrollingObject(true, true, 4.0f));
                }
                else
                {
                    //initialize a scrolling object that is moving to the LEFT and IS a hazard
                    scrollingObjects.push_back(new ScrollingObject(true, true, 2.75f));
                }
                //set position to the right of screen at corresponding height value
                scrollingObjects[i]->SetPosition(screenWidth, height * gridSize);
                i++;
            }
            }
        }
    }

    //set a random lilyPad as active
    //  set all other lilyPads as inactive
    int visiblePad = GetRandomValue(0, lilyPads.size() - 1);
    activatedPads.push_back(visiblePad);
    for (int j = 0; j < lilyPads.size(); j++)
    {
        if (j == visiblePad)
        {
            lilyPads[j]->activated = false;
            lilyPads[j]->visible = true;
        }

        else
        {
            lilyPads[j]->activated = false;
            lilyPads[j]->visible = false;
        }
    }
}

void GameStateLoop::Update()
{
    timeElapsed += GetFrameTime();
    ui->Update(timeElapsed);
    for (int i = 0; i < backgroundTiles.size(); i++)
    {
        backgroundTiles[i]->SetActive(true);
    }

    //Update each of the scrolling objects (hazards and platforms)
    for (int j = 0; j < scrollingObjects.size(); j++)
    {
        scrollingObjects[j]->Update();
    }
    //  iterate through each object in the scrollingObjects vector
    for (int i = 0; i < scrollingObjects.size(); i++)
    {
        //check for collision with the player
        if (CheckCollisionCircleRec(player->GetPosition(),                          //position of player (already centered)
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
        //otherwise, there is no collision with the player
        else
        {
            //frog is not riding anything
            isRiding = false;
        }

        //iterate through list of backgroundTile objects
        for (int j = 0; j < backgroundTiles.size(); j++)
        {
            //if the scrolling object comes into contact with the background tile, set the background tile to inactive.
            if (CheckCollisionRecs(scrollingObjects[i]->rec, backgroundTiles[j]->rec))
            {
                //if the tile is a hazard (water)
                if (backgroundTiles[j]->GetHazard() == true)
                {
                    //check if it is active
                    if (backgroundTiles[j]->GetActive() == true)
                    {
                        //if it is, set it to inactive
                        backgroundTiles[j]->SetActive(false);
                    }
                }
            }
        }
    }

    player->Update();

    //  iterate through list of lilypads to see if player is on one of them (same process as above)
    for (int i = 0; i < lilyPads.size(); i++)
    {
        //is the lilypad visible?
        if (lilyPads[i]->visible)
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
                padsReached++;

                //  ACTIVATE A NEW LILYPAD
                bool newVal = false;
                //  executes while newVal is false
                do
                {
                    //  get a random value
                    int newPad = GetRandomValue(0, lilyPads.size() - 1);
                    //  used within the for loop, if still true after loop execution, will set newVal to true
                    bool internalCheck = true;
                    //  check each of the current visible lilypads
                    for (int j = 0; j < activatedPads.size(); j++)
                    {
                        //  if the random value is equal to a value stored within activatedPads
                        if (newPad == activatedPads[j])
                        {
                            //internal check did not pass
                            internalCheck = false;
                            //exit the for loop and start again
                            break;
                        }
                        //otherwise the value did not match
                        else
                        {
                            //value does not yet match, so is still true
                            internalCheck = true;
                        }
                    }
                    //if after executing the for loop internal check is still true
                    if (internalCheck)
                    {
                        //we have a valid lilyPad to activate, set it to visible
                        lilyPads[newPad]->visible = true;
                        //set newVal to true to exit do/while loop
                        newVal = true;
                    }
                } while (newVal == false);

                

            }
        }
        //otherwise don't do nothing!
    }
    //  iterate through list of background tiles to see if the player has landed in the water
    for (int i = 0; i < backgroundTiles.size(); i++)
    {
        //check if the tile is a hazard (water), otherwise do nothing
        if (backgroundTiles[i]->GetHazard() == true)
        {
            //check for player collision
            //  check if the tile is active
            //otherwise, do nothing
            if (backgroundTiles[i]->GetActive() == true &&
                CheckCollisionCircleRec(player->GetPosition(), 1.0f,
                    backgroundTiles[i]->rec))
            {
                //if the player collides with the tile and the tile is active, respawn the player
                player->Respawn();
            }
        }
    }
}

void GameStateLoop::Draw()
{

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

    ui->Draw();

    //draw player last to put on top-most layer
    player->Draw();
}

bool GameStateLoop::StateShouldChange()
{
    return (timeLimit - timeElapsed) < 0 || player->Lives == 0 || padsReached == lilyPads.size();
}

GameStates GameStateLoop::GetNextGameState()
{
    if ((timeLimit - timeElapsed) < 0)
    {
        return EndScreen;
    }
    else
    {
        return NextLevel;
    }
}

int GetScore()
{
    return player->Score;
}