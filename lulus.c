#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

// define escape sequences for text formatting
#define R "\033[0m"  // reset
#define H "\033[1;32m"  // bold

void gotoxy(int x, int y) {
    
    COORD coordinate = {0, 0};
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);

}

void print(int x, int y, const char* format, ...) {

    int coloumn, row;
    char buffer[1024];

    CONSOLE_SCREEN_BUFFER_INFO position;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &position);
    coloumn = position.srWindow.Right - position.srWindow.Left + 1;
    row = position.srWindow.Bottom - position.srWindow.Top + 1;
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    
    gotoxy(coloumn / 2 - x, row / 2 - y);
    printf("%s", buffer);

}

int main(){

    bool index1 = true, index2 = false, index3 = false, index4 = false, index5 = false;

    while(1){

        print(22, 2, index1 ? H " [Order Food] " R : " [Order Food] ");
        print(-9, 2, index2 ? H " [Shopping Cart] " R : " [Shopping Cart] ");
        print(19, -2, index3 ? H " [Payment] " R : " [Payment] ");
        print(-9, -2, index4 ? H " [Edit] " R : " [Edit] ");
        print(4, -6, index5 ? H " [Exit] " R : " [Exit] ");
        
        int ch = getch();

        index1 ? (ch == 75 || ch == 77) ? (index1 = !index1, index2 = !index2) : (ch == 80) ? (index1 = !index1, index3 = !index3) : 0 :
        index2 ? (ch == 75 || ch == 77) ? (index2 = !index2, index1 = !index1) : (ch == 80) ? (index2 = !index2, index4 = !index4) : 0 :
        index3 ? (ch == 72) ? (index3 = !index3, index1 = !index1) : (ch == 75 || ch == 77) ? (index3 = !index3, index4 = !index4) : (ch == 80) ? (index3 = !index3, index5 = !index5) : 0 : 
        index4 ? (ch == 72) ? (index4 = !index4, index2 = !index2) : (ch == 75 || ch == 77) ? (index4 = !index4, index3 = !index3) : (ch == 80) ? (index4 = !index4, index5 = !index5) : 0 :
        index5 ? (ch == 75) ? (index5 = !index5, index3 = !index3) : (ch == 77) ? (index5 = !index5, index4 = !index4) : 0 : 0;
        
        index1 ? (ch == 75 || ch == 77) ? (index1 = false, index2 = true) : (ch == 80) ? (index1 = false, index3 = true) : 0 :
        index2 ? (ch == 75 || ch == 77) ? (index2 = false, index1 = true) : (ch == 80) ? (index2 = false, index4 = true) : 0 :
        index3 ? (ch == 72) ? (index3 = false, index1 = true) : (ch == 75 || ch == 77) ? (index3 = false, index4 = true) : (ch == 80) ? (index3 = false, index5 = true) : 0 : 
        index4 ? (ch == 72) ? (index4 = false, index2 = true) : (ch == 75 || ch == 77) ? (index4 = false, index3 = true) : (ch == 80) ? (index4 = false, index5 = true) : 0 :
        index5 ? (ch == 75) ? (index5 = false, index3 = true) : (ch == 77) ? (index5 = false, index4 = true) : 0 : 0;

    }
}