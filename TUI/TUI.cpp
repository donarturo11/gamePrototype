#include "TUI.h"
#include "KeyboardInterface.h"

TUI::TUI()
{
    printf("TUI constructor\n");
    testConio();
    init();
    
}

TUI::~TUI()
{
    printf("TUI destructor\n");
}

void TUI::init()
{
    KeyboardInterface keyboard;
}

void TUI::testConio()
{
    int x=0;
    int y=0;
    int bgColor=15;
    char c='a';
    clrscr();
    for (int i=0; i<15; i++){
        if(i==7) {
            x=0;
            y=2;
        }
        if(i==0 && i==7){
            printf(">>");
        }
        gotoxy(x, y);
        textcolor(i);
        textbackground(bgColor);
        printf("%c", c);
        bgColor--;
        c++;
        x++;
    }
    
    normvideo();
    printf("\n\n");
    
}
