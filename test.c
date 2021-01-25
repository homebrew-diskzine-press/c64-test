/*
** Fancy hello world program using cc65.
**
** Ullrich von Bassewitz (ullrich@von-bassewitz.de)
**
*/



#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <joystick.h>
#include <c64.h>



/*****************************************************************************/
/*                                   Data                                    */
/*****************************************************************************/



static const char Text1 [] = "Homebrew Diskzine Press";
static const char Text2 [] = "Commodore 64 Test";
static const char Text3 [] = "2021";



/*****************************************************************************/
/*                                   Code                                    */
/*****************************************************************************/



int main (void)
{
    unsigned char XSize, YSize;

    /* Set screen colors */
    (void) textcolor (COLOR_WHITE);
    (void) bordercolor (COLOR_BLACK);
    (void) bgcolor (COLOR_BLACK);

    /* Clear the screen, put cursor in upper left corner */
    clrscr ();

    /* Ask for the screen size */
    screensize (&XSize, &YSize);

    /* Draw a border around the screen */

    /* Top line */
    cputc ('+');
    chline (XSize - 2);
    cputc ('+');

    /* Vertical line, left side */
    cvlinexy (0, 1, YSize - 2);

    /* Bottom line */
    cputc ('+');
    chline (XSize - 2);
    cputc ('+');

    /* Vertical line, right side */
    cvlinexy (XSize - 1, 1, YSize - 2);

    /* Write the greeting in the mid of the screen */
    gotoxy ((XSize - strlen (Text1)) / 2, YSize / 2);
    cprintf ("%s", Text1);

    gotoxy ((XSize - strlen (Text2)) / 2, YSize / 2 + 1);
    cprintf ("%s", Text2);

    gotoxy (XSize - strlen (Text3) - 1, YSize - 2);
    cprintf ("%s", Text3);

#if defined(__NES__) || defined(__PCE__) || defined(__GAMATE__) || defined(__ATARI5200__)

    /* Wait for the user to press a button */
    joy_install (joy_static_stddrv);
    while (!joy_read (JOY_1)) ;
    joy_uninstall ();

#else

    /* Wait for the user to press a key */
    cgetc ();

#endif

    /* Clear the screen again */
    clrscr ();

    /* Done */
    return EXIT_SUCCESS;
}
