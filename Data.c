#include "E_Lexicon.h"

ListNode *createwords( char *en, char *zh )
{
    ListNode *words = ( ListNode* )malloc( sizeof( ListNode ) );
    if ( !words )
    {
        printf( "�ڴ治�㣡\a" );
        Sleep( 5000 );
        exit( 0 );
    }
    strcpy( words -> en_words, en );
    strcpy( words -> zh_words, zh );
    words -> next = NULL;
    return words;
}

LinkedList *createlist()
{
    LinkedList *obj = ( LinkedList* )malloc( sizeof( LinkedList ) );
    if ( !obj )
    {
        printf( "�ڴ治�㣡\a" );
        Sleep( 5000 );
        exit( 0 );
    }
    char enfriwd[20] = "Ӣ��";
    char zhfriwd[80] = "����";
    obj -> head = createwords( enfriwd, zhfriwd );
    return obj;
}

void addnewword( LinkedList *obj, char *en, char *zh )
{
    ListNode *toadd = createwords( en, zh );
    if ( obj -> head -> next )
    {
        ListNode *cur = obj -> head -> next;
        while ( cur -> next != NULL && _stricmp( cur -> en_words, toadd -> en_words ) <= 0 && strcmp( cur -> en_words, toadd -> en_words) != 0 )
        {
            cur = cur -> next;
        }
        if ( ( ( cur -> next != NULL && strcmp( cur -> en_words, toadd -> en_words) != 0 ) || ( !(cur -> next) && _stricmp( cur -> en_words, toadd -> en_words ) > 0 ) ) )
        {
            ListNode *prev = obj -> head;
            while ( prev -> next != cur )
            {
                prev = prev -> next;
            }
            toadd -> next = cur;
            prev -> next = toadd;
            printf( "���%s %s�ɹ�����������룺\n", prev -> next -> en_words, prev -> next -> zh_words );
        }
        else
        {
            if ( !strcmp( cur -> en_words, toadd -> en_words ) || !strcmp( cur -> zh_words, toadd -> zh_words ) )
            {
                printf( "����%s %s����������룺\n\a", cur -> en_words, cur -> zh_words );
                free( toadd );
            }
            else
            {
                cur -> next = toadd;
                printf( "���%s %s�ɹ�����������룺\n", cur -> next -> en_words, cur -> next -> zh_words );
            }
        }
    }
    else
    {
        obj -> head -> next = toadd;
        printf( "���%s %s�ɹ�����������룺\n", obj -> head -> next -> en_words, obj -> head -> next -> zh_words );
    }
    write_to_file( obj );
}

void deleteword( LinkedList *obj, char *en, char *zh )
{
    ListNode *cur = obj -> head -> next;
    while ( cur != NULL && ( strcmp( cur -> en_words, en ) != 0 && strcmp( cur -> zh_words, zh ) != 0 ) )
    {
        cur = cur -> next;
    }
    if ( !cur )
    {
        printf( "�Ҳ���%s %s����������룺\n\a", en, zh );
    }
    else
    {
        ListNode *prev = obj -> head;
        while ( prev -> next != cur )
        {
            prev = prev -> next;
        }
        prev -> next = cur -> next;
        printf( "ɾ��%s %s�ɹ�����������룺\n", cur -> en_words, cur -> zh_words );
        free(cur);
        write_to_file( obj );
    }
}

void editword( LinkedList *obj, char *en, char *zh )
{
    ListNode *cur = obj -> head -> next;
    while ( cur != NULL && ( strcmp( cur -> en_words, en ) != 0 && strcmp( cur -> zh_words, zh ) != 0 ) )
    {
        cur = cur -> next;
    } 
    if ( cur )
    {
        strcpy( cur -> en_words, en );
        strcpy( cur -> zh_words, zh );
        printf( "����%s %s�ɹ�����������룺\n", cur -> en_words, cur -> zh_words );
        write_to_file( obj );
    }
    else
    {
        printf( "�Ҳ���%s %s����������룺\n\a", en, zh );
    }
}

void findword( LinkedList *obj, char *en, char *zh )
{
    ListNode *cur = obj -> head -> next;
    while ( cur != NULL && ( strcmp( cur -> en_words, en ) != 0 && strcmp( cur -> zh_words, zh ) != 0 ) )
    {
        cur = cur -> next;
    }
    if ( cur )
    {
        printf( "%-20s\t%-80s\n", cur -> en_words, cur -> zh_words );
        printf( "��������룺\n" );
    }
    else
    {
        printf( "�Ҳ���%s%s��\n\a", en, zh );
        printf( "��������룺\n" );
    }
}

void printlist_all( LinkedList *obj )
{
    ListNode *cur = obj -> head -> next;
    int num = 1;
    printf( "      %-20s\t%-80s\n", obj -> head -> en_words, obj -> head -> zh_words );
    while( cur )
    {
        printf( "%-5d %-20s\t%-80s\n", num ++, cur -> en_words, cur -> zh_words );
        cur = cur -> next;
    }
}

void printlist_en( LinkedList *obj )
{
    ListNode *cur = obj -> head -> next;
    int num = 1;
    printf( "      %-20s\n", obj -> head -> en_words );
    while ( cur )
    {
        printf( "%-5d %-20s\n", num ++, cur -> en_words );
        cur = cur -> next;
    }
}

void printlist_zh( LinkedList *obj )
{
    ListNode *cur = obj -> head -> next;
    int num = 1;
    printf( "      %-80s\n", obj -> head -> zh_words );
    while ( cur )
    {
        printf( "%-5d %-80s\n", num ++, cur -> zh_words );
        cur = cur -> next;
    }
}