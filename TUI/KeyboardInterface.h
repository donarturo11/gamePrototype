#ifndef _KEYBOARDINTERFACE_H
#define _KEYBOARDINTERFACE_H

#include <cstdlib>
#include <cstdio>
#include "TUI.h"

class KeyboardInterface
{
    public:
        KeyboardInterface();
        ~KeyboardInterface();
    private:
        void startLoop();
        int capture();
        
};

#endif
