#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "world.h"
#include "gameManager.h"
#include "graphics.h"


int main(int argc, char* args[])
{
    /*
    * Plan:
    *
    * Kod będzie podzielony na moduły, każdy odpowiedzialny za coś innego (rozpiska
    * tymczasowa - najpewniej jeszcze ulegnie zmianie kilkukrotnie):
    * - gameManager - moduł odpowiedzialny za input/output, t.j. za
    *                 operacje na plikach, user input, ewentualne
    *                 wejście do edytora, menu
    *
    * - world -       obiekt zawierający fizyczną mapę, obiekty oraz funkcje
    *                 odpowiedzialne za zmianę stanu obiektów i mapy
    *
    * - graphics -    moduł odpowiedzialny za renderowanie świata
    *
    */

    gameWorld *world = new gameWorld();
    world->generateSampleMap();

    drawWindow(world);

    return 0;
}
