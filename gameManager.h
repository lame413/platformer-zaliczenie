char** loadMapFromFile(std::string mapFilePath)
{
    // currently gets the map from a text file,
    // should use binary files in the final revision

    int mapWidth;
    int mapHeight;
    char** mapAsStoredInFile;


    std::ifstream gameMapFile (mapFilePath);

    //for(int i = 0;; )
    //{
    //
    //}


    mapAsStoredInFile = new char*[mapHeight];
    for(int i = 0; i<mapHeight; i++)
    {
        mapAsStoredInFile [i] = new char[mapWidth];
    }
}
