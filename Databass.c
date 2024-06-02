#include "E_Lexicon.h"

void write_to_file( LinkedList *obj )
{
    FILE *file = fopen( "E-Lexicon.txt", "w" );
    if ( !file )
    {
        printf( "无法打开文件！\a" );
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
    printf( "正在获取生词库中......\n" );
    Sleep( 3000 );
    if ( !file )
    {
        printf( "找不到生词库，请检查“E-Lexicon.txt”是否与该软件放在同一文件夹中！\a" );
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
    printf( "请输入密码（默认密码为“20240315”）：" );
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
                printf( "密码错误，你还有%d次机会，请重新输入：\a", 3 - not_pass_times );
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
    printf( "请更改你的密码（至多十个字符）：" );
    while ( scanf( "%10s", ppasswd ) != EOF )
    {
        if ( strlen(ppasswd) <= 10 )
        {
            scanf( "%*c" );
            break;
        }
        printf( "已经超过十个字符，请重新输入：\a" );
        scanf( "%*[^\n]" );
        scanf( "%*c" );
    }
    return ppasswd;
}