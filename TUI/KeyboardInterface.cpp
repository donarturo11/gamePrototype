#include "KeyboardInterface.h"

KeyboardInterface::KeyboardInterface()
{
    printf("KeyboardInterface Contructor\n");
    printKeycodes();
    startLoop();
}

KeyboardInterface::~KeyboardInterface()
{
    printf("KeyboardInterface Destructor\n");
}

void KeyboardInterface::printKeycodes()
{
    printf("K_UP = %i\n", K_UP);
    printf("K_DOWN = %i\n", K_DOWN);
    printf("K_RIGHT = %i\n", K_RIGHT);
    printf("K_LEFT = %i\n", K_LEFT);
}

void KeyboardInterface::startLoop()
{
    int keyCode;
    while (1){
        keyCode=capture();
        if (isArrowKey(keyCode)) testArrow(keyCode);
        else printf("%i\n", keyCode);
        if (keyCode=='q') break;
    }
}

int KeyboardInterface::capture()
{
    int keyCode=getch();
    while(kbhit()){
        keyCode+=getch();
    }
    return keyCode;
}

bool KeyboardInterface::isArrowKey(int keyCode)
{
    if (  keyCode == K_UP ||
          keyCode == K_DOWN ||
          keyCode == K_RIGHT ||
          keyCode == K_LEFT
       ) return true;
    else return false;
}

void KeyboardInterface::testArrow(int keyCode)
{
    switch (keyCode) {
        case K_UP: printf("UP\n"); break;
        case K_DOWN: printf("DOWN\n"); break;
        case K_RIGHT: printf("RIGHT\n"); break;
        case K_LEFT: printf("LEFT\n"); break;
    }
}


