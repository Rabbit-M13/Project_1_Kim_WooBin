// Project_1_Kim_WooBin.cpp
// C++20표준 환경

#define _CRT_SECURE_NO_WARNINGS
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include <iostream>
#include <random>
#include "GameManager.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    srand(time(0));

    GameManager Game;
    //Game.PlayDebug();
    Game.Play();

    return 0;
}
