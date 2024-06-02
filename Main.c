#include "E_Lexicon.h"

int main()
{
    FILE *newfile = fopen( "E-Lexicon.txt", "r" );
    if ( !newfile )
    {
        newfile = fopen( "E-Lexicon.txt", "w" );
        fprintf( newfile, "apple    苹果\n" );
        fprintf( newfile, "banana   香蕉\n" );
        fprintf( newfile, "photo    照片\n" );
    }
    fclose( newfile );
    LinkedList *obj = NULL;
    MainMenu();
    MainMenuSelect( obj );
    return 0;
}
