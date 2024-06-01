#include "E_Lexicon.h"

int main()
{
    FILE *newfile = fopen( "E-Lexicon.txt", "r" );
    if ( !newfile )
    {
        newfile = fopen( "E-Lexicon.txt", "w" );
        fprintf( newfile, "apple    Æ»¹û\n" );
        fprintf( newfile, "banana   Ïã½¶\n" );
        fprintf( newfile, "photo    ÕÕÆ¬\n" );
    }
    fclose( newfile );
    LinkedList *obj = NULL;
    MainMenu();
    MainMenuSelect( obj );
    return 0;
}
