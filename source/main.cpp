// commenting out the following DEBUG definition will show the console output. Will be useful later.

#define DEBUG

#ifndef DEBUG
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#include <game.h>

int main()
{
   Game game;
   game.run();
   

    return 0;
}