#ifndef GETCHINPUT_H
#define GETCHINPUT_H
/*NOTE: I had a linker error that was being caused when #include "getchInput.h" appeared in multiple source files
I fixed this by declaring the functions inline (which tells the compiler to replace any call to these functions,
with the functions themselves, instead of a call to the function (which would cause a linker error when multiple
function definitions existed (due to #include "getchInput.h" being delcared multiple times)))*/

//key value constants (for use outside of this file)
#ifndef KEY_UP
#define KEY_UP 72
#endif
#ifndef KEY_DOWN
#define KEY_DOWN 80
#endif
#ifndef KEY_LEFT
#define KEY_LEFT 75
#endif
#ifndef KEY_RIGHT
#define KEY_RIGHT 77
#endif
#ifndef ESC_KEY
#define ESC_KEY 27
#endif

#include <conio.h> //for getch() command

//Gets an input as soon as it's inputted (including arrow keys)
inline int getchInput() {
    int input = getch();

    /* NOTE: The reason for this if statement:
     * Arrow keys on a keyboard are represented as escape sequences. When you press an arrow key, your terminal emulator sends an escape character (224 in windows)
     * before sending the value of the arrow key (72, 80, 75, or 77).
     */
    if (input == 224) { // escape character
        input = getch(); // skip the escape character to get key values
        return input;
        /* ARROW KEY VALUES (either use these or key value macros above
         * UP: 72
         * DOWN: 80
         * LEFT: 75
         * RIGHT: 77
         */
    } else { //if arrow key isn't pressed, no escape character needs to be skipped, so just return value
        return input;
    }
}

//Loops getchInput() until either an arrow key is returned, or the ESC key (value of 27) is returned
inline int getchArrowInput() {
    int input = 0;
    while((input != ESC_KEY)&&(input != KEY_UP)&&(input != KEY_DOWN)&&(input != KEY_RIGHT)&&(input != KEY_LEFT))
        input = getchInput();
    return input;
}

#endif // GETCHINPUT_H
