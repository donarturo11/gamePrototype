#include "KeyboardInterface.h"

KeyboardInterface::KeyboardInterface()
{
    printf("KeyboardInterface Contructor\n");
    startLoop();
}

KeyboardInterface::~KeyboardInterface()
{
    printf("KeyboardInterface Destructor\n");
}

void KeyboardInterface::startLoop()
{
    int keyCode;
    while (1){
        keyCode=capture();
        printf("%i\n", keyCode);
        if (keyCode=='q') break;
    }
}

int KeyboardInterface::capture()
{
    int key=getch();
    while(kbhit()){
        key+=getch();
    }
    return key;
}


