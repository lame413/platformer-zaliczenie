class gameWorld
{
private:
    int mapWidth = 5;
    int mapHeight = 5;

    char **physicalWorld;

public:
    //TODO, implement proper constructors
    gameWorld()
    {
        // set up an array of the right size
        physicalWorld = new char*[mapHeight*20];
        for(int i = 0; i<mapHeight*20; i++)
        {
            physicalWorld[i] = new char[mapWidth*20];
        }
    }

    int generateSampleMap()
    {
        /*
        * should generate this map, upscaled 20fold:
        * XXXXX
        * X   X
        * X X X
        * X# #X
        * XXXXX
        */
        printf("before 1 for");
        for(int i = 0; i<mapWidth*20; i++)
        {
            for(int j = 0; j<mapHeight*20; j++)
            {
                printf("in loop 2, iteration %d, %d\n", i, j);
                // walls and ceiling
                if(i/20 == 0 ||
                        j/20 == 0 ||
                        i/20 == 4 ||
                        j/20 == 4)
                {
                    physicalWorld[i][j] = 'X';
                }
                // center piece
                else if(i/20 == 2 && j/20 == 2)
                {
                    physicalWorld[i][j] = 'X';
                }
                // two hashes at the bottom
                else if(i/20 == 3 && (j/20 == 1 || j/20 == 3))
                {
                    physicalWorld[i][j] = '#';
                }
            }
        }
        return 0;
    }

    gameWorld setPhysicalWorld(char** newWorld){
        physicalWorld = newWorld;
        return *this;
    }

    int getMapHeight(){
        return mapHeight*20;
    }

    int getMapWidth(){
        return mapWidth*20;
    }

    char** getMap(){
        return physicalWorld;
    }

    ~gameWorld()
    {
        for(int i = 0; i<mapHeight; i++)
        {
            delete [] physicalWorld[i];
        }
        delete [] physicalWorld;
    }
};
