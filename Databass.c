#include "E_Lexicon.h"

void write_to_file( LinkedList *obj )
{
    FILE *file = fopen( "E-Lexicon.txt", "w" );
    if ( !file )
    {
        printf( "�޷����ļ���\a" );
        Sleep( 3000 );
        exit( 0 );
    }
    ListNode *cur = obj -> head -> next;
    while ( cur )
    {
        fprintf( file, "%-20s\t", cur -> en_words );
        fprintf( file, "%-80s\n", cur -> zh_words );
        cur = cur -> next;
    }
    fclose( file );
}

void read_to_file( LinkedList *obj )
{
    FILE *file = fopen( "E-Lexicon.txt", "r" );
    printf( "���ڻ�ȡ���ʿ���......\n" );
    Sleep( 3000 );
    if ( !file )
    {
        printf( "�Ҳ������ʿ⣬���顰E-Lexicon.txt���Ƿ�����������ͬһ�ļ����У�\a" );
        Sleep( 5000 );
        exit( 0 );
    }
    ListNode *word = obj -> head;
    char en[20], zh[80];
    while ( fscanf( file, "%20s\t%80s", &en, &zh ) != EOF )
    {
        word -> next = createwords( en, zh );
        word = word -> next;
    }
    fclose( file );
}

bool passwordpass( char *password )
{
    int not_pass_times = 0;
    char input_password[12] = { 0 };
    printf( "���������루Ĭ������Ϊ��20240315������" );
    while ( scanf( "%12s", &input_password) != EOF )
    {
        scanf( "%*[^\n]" );
        scanf( "%*c" );
        if ( !strcmp( input_password, password ) )
        {
            break;
        }
        else
        {
            not_pass_times ++;
            if ( not_pass_times == 3 )
            {
                return false;
            }
            else
            {
                printf( "��������㻹��%d�λ��ᣬ���������룺\a", 3 - not_pass_times );
            }
        }
    }
    return true;
}

void savepassword( char *password )
{
    FILE *passwd = fopen( "Password.txt", "w" );
    if ( !passwd )
    {
        return;
    }
    fprintf( passwd, "%s", password );
    fclose( passwd );
}

void readpassword( char *password )
{
    FILE *passwd = fopen( "Password.txt", "r" );
    if ( !passwd )
    {
        return;
    }
    fscanf( passwd, "%s", password );
    fclose( passwd );
}

char *changepassword()
{
    static char ppasswd[11] = { 0 };
    printf( "�����������루����ʮ���ַ�����" );
    while ( scanf( "%10s", ppasswd ) != EOF )
    {
        if ( strlen(ppasswd) <= 10 )
        {
            scanf( "%*c" );
            break;
        }
        printf( "�Ѿ�����ʮ���ַ������������룺\a" );
        scanf( "%*[^\n]" );
        scanf( "%*c" );
    }
    return ppasswd;
}