#include "E_Lexicon.h"

void MainMenuSelect( LinkedList *obj )
{
    char msel_Num;
    static char password[10] = "20240315";
    while( 1 == scanf( "%c", &msel_Num ) )
    {
        scanf( "%*[^\n]" );
        scanf( "%*c" );
        switch ( msel_Num )
        {
            case '1':
            {
                if ( !obj )
                {
                    obj = createlist();
                    read_to_file( obj );
                    printf( "��ɣ�\n" );
                }
                else
                {
                    printf( "�ѳɹ��������ʿ⣬�����ٴδ�����\a " );
                }
                break;
            }
            case '2':
            {
                if ( !obj )
                {
                    printf( "���ȴ������ʿ⣡\a" );
                    break;
                }
                system( "cls" );
                ShowMenu();
                ShowMenuSelect( obj );
                break;
            }
            case '3':
            {
                if ( !obj )
                {
                    printf( "���ȴ������ʿ⣡\a" );
                    break;
                }
                readpassword( password );
                if ( passwordpass( password ) == false )
                {
                    printf( "���Ѿ����3�����룬���Ժ����ԣ�\a" );
                }
                else
                {
                    system( "cls" );
                    EditMenu();
                    EditMenuSelect( obj );
                }
                break;
            }
            case '4':
            {
                if ( !obj )
                {
                    printf( "���ȴ������ʿ⣡\a" );
                    break;
                }
                system( "cls" );
                FindMenu();
                FindMenuSelect( obj );
                break;
            }
            case '5':
            {
                if ( !obj )
                {
                    printf( "���ȴ������ʿ⣡\a" );
                    break;
                }
                readpassword( password );
                char *newpassword = changepassword();
                if ( !strcmp( password, newpassword ) )
                {
                    printf( "�����������ã�\n" );
                }
                else
                {
                    strcpy( password, newpassword );
                    savepassword( password );
                    printf( "���ĳɹ���\n" );
                }
                break;
            }
            case '0':
            {
                printf( "��л��ʹ�ñ�������ټ���\n" );
                Sleep( 5000 );
                break;
            }
            default:
                printf( "ѡ����ڣ�������ѡ��\a" );
        }
        if ( msel_Num == '0' )
        {
            break;
        }
        else
        {
            Sleep( 3000 );
            system( "cls" );
            MainMenu();
        }
    }
}

void ShowMenuSelect( LinkedList *obj )
{
    char ssel_Num;
    char isretn = 'n';
    while ( 1 == scanf( "%c", &ssel_Num ) )
    {
        scanf( "%*[^\n]" );
        scanf( "%*c" );
        switch ( ssel_Num )
        {
            case '1':
            {
                while ( isretn == 'n' || isretn == 'N' )
                {
                    system( "cls" );
                    printlist_all( obj );
                    printf( "�Ƿ񷵻أ�[y/n]��" );
                    while( 1 == scanf( "%c", &isretn ) )
                    {
                        scanf( "%*[^\n]" );
                        scanf( "%*c" );
                        if ( isretn == 'n' || isretn == 'N' || isretn == 'y' || isretn == 'Y' )
                        {
                            break;
                        }
                        printf( "ѡ����ڣ�������ѡ��\a" );
                    }
                    if ( isretn == 'y' || isretn == 'Y' )
                    {
                        printf( "���Եȣ�\n" );
                        break;
                    }
                }
                break;
            }
            case '2':
            {
                while ( isretn == 'n' || isretn == 'N' )
                {
                    system( "cls" );
                    printlist_zh( obj );
                    printf( "�Ƿ񷵻أ�[y/n]��" );
                    while( 1 == scanf( "%c", &isretn ) )
                    {
                        scanf( "%*[^\n]" );
                        scanf( "%*c" );
                        if ( isretn == 'n' || isretn == 'N' || isretn == 'y' || isretn == 'Y' )
                        {
                            break;
                        }
                        printf( "ѡ����ڣ�������ѡ��\a" );
                    }
                    if ( isretn == 'y' || isretn == 'Y' )
                    {
                        printf( "���Եȣ�\n" );
                        break;
                    }
                }
                break;
            }
            case '3':
            {
                while ( isretn == 'n' || isretn == 'N' )
                {
                    system( "cls" );
                    printlist_en( obj );
                    printf( "�Ƿ񷵻أ�[y/n]��" );
                    while( 1 == scanf( "%c", &isretn ) )
                    {
                        scanf( "%*[^\n]" );
                        scanf( "%*c" );
                        if ( isretn == 'n' || isretn == 'N' || isretn == 'y' || isretn == 'Y' )
                        {
                            break;
                        }
                        printf( "ѡ����ڣ�������ѡ��\a" );
                    }
                    if ( isretn == 'y' || isretn == 'Y' )
                    {
                        printf( "���Եȣ�\n" );
                        break;
                    }
                }
                break;
            }
            case '4':
            {
                printf( "���Եȣ�\n" );
                break;
            }
            case '0':
            {
                printf( "��л��ʹ�ñ�������ټ���\n" );
                Sleep( 5000 );
                exit( 0 );
            }
            default:
                printf( "ѡ����ڣ�������ѡ��\a" );
        }
        if ( ssel_Num >= '0' && ssel_Num <= '4' )
            break;
    }
    if ( ssel_Num == '4' )
    {
        return;
    }
    else
    {
        Sleep( 3000 );
        system( "cls" );
        ShowMenu();
        ShowMenuSelect( obj );
    }
}

void EditMenuSelect( LinkedList *obj )
{
    char esel_Num;
    char en[20], zh[80];
    while ( 1 == scanf( "%c", &esel_Num ) )
    {
        scanf( "%*[^\n]" );
        scanf( "%*c" );
        switch ( esel_Num )
        {
            case '1':
            {
                printf( "�밴��ʽ���루���磺English Ӣ������������ӣ������롰C ȡ������\n" );
                while ( 2 == scanf( "%20s %80s", &en, &zh ) )
                {
                    if ( strcmp( en, "C" ) == 0 && strcmp( zh, "ȡ��" ) == 0 )
                    {
                        printf( "���Եȣ�\n" );
                        scanf( "%*c" );
                        break;
                    }
                    addnewword( obj, en, zh );
                }
                break;
            }
            case '2':
            {
                printf( "�밴��ʽ���루���磺English Ӣ����������ɾ���������롰C ȡ������\n" );
                while ( 2 == scanf( "%20s %80s", &en, &zh ) )
                {
                    if ( strcmp( en, "C" ) == 0 && strcmp( zh, "ȡ��" ) == 0 )
                    {
                        printf( "���Եȣ�\n" );
                        scanf( "%*c" );
                        break;
                    }
                    deleteword( obj, en, zh );
                }
                break;
            }
            case '3':
            {
                printf( "�밴��ʽ���루���磺English Ӣ�����������޸ģ������롰C ȡ������\n" );
                while ( 2 == scanf( "%20s %80s", &en, &zh ) )
                {
                    if ( strcmp( en, "C" ) == 0 && strcmp( zh, "ȡ��" ) == 0 )
                    {
                        printf( "���Եȣ�\n" );
                        scanf( "%*c" );
                        break;
                    }
                    editword( obj, en, zh );
                }
                break;
            }
            case '4':
            {
                printf( "���Եȣ�\n" );
                break;
            }
            case '0':
            {
                printf( "��л��ʹ�ñ�������ټ���\n" );
                Sleep( 5000 );
                exit( 0 );
            }
            default:
                printf( "ѡ����ڣ�������ѡ��\a" );
        } 
        if ( esel_Num >= '0' && esel_Num <= '4' )
            break;
    } 
    if ( esel_Num == '4' )
    {
        return;
    }
    else
    {
        Sleep( 3000 );
        system( "cls" );
        EditMenu();
        EditMenuSelect( obj );
    }
}

void FindMenuSelect( LinkedList *obj )
{
    char fsel_Num;
    char en[20] = " ";
    char zh[80] = " ";
    while ( 1 == scanf( "%c", &fsel_Num ) )
    {
        scanf( "%*[^\n]" );
        scanf( "%*c" );
        switch ( fsel_Num )
        {
            case '1':
            {
                printf( "������Ӣ�ġ�������ٲ�ѯ�������롰CF����\n" );
                while ( 1 == scanf( "%20s", &en ) )
                {
                    scanf( "%*[^\n]" );
                    scanf( "%*c" );
                    if ( !strcmp( en, "CF" ) )
                    {
                        printf( "���Եȣ�\n" );
                        break;
                    }
                    findword( obj, en, zh );
                }
                break;
            }
            case '2':
            {
                printf( "���������ġ�������ٲ�ѯ�������롰CF����\n" );
                while ( 1 == scanf( "%20s", &zh ) )
                {
                    scanf( "%*[^\n]" );
                    scanf( "%*c" );
                    if ( !strcmp( zh, "CF" ) )
                    {
                        printf( "���Եȣ�\n" );
                        break;
                    }
                    findword( obj, en, zh );
                }
                break;
            }
            case '3':
            {
                printf( "���Եȣ�\n" );
                break;
            }
            case '0':
            {
                printf( "��л��ʹ�ñ�������ټ���\n" );
                Sleep( 5000 );
                exit( 0 );
            }
            default:
                printf( "ѡ����ڣ�������ѡ��\a" );
        }
        if ( fsel_Num >= '0' && fsel_Num <= '3' )
            break;
    }
    if ( fsel_Num == '3' )
    {
        return;
    }
    else
    {
        Sleep( 3000 );
        system( "cls" );
        FindMenu();
        FindMenuSelect( obj );
    }
}