#include "E_Lexicon.h"

int main()
{
    FILE *newfile = fopen( "E-Lexicon.txt", "r" );
    if ( !newfile )
    {
        newfile = fopen( "E-Lexicon.txt", "w" );
        fprintf( newfile, "apple    ƻ��\n" );
        fprintf( newfile, "banana   �㽶\n" );
        fprintf( newfile, "photo    ��Ƭ\n" );
    }
    fclose( newfile );
    LinkedList *obj = NULL;
    MainMenu();
    MainMenuSelect( obj );
    return 0;
}
