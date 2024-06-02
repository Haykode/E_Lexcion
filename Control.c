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
                    printf( "完成！\n" );
                }
                else
                {
                    printf( "已成功创建生词库，无需再次创建！\a " );
                }
                break;
            }
            case '2':
            {
                if ( !obj )
                {
                    printf( "请先创建生词库！\a" );
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
                    printf( "请先创建生词库！\a" );
                    break;
                }
                readpassword( password );
                if ( passwordpass( password ) == false )
                {
                    printf( "你已经输错3次密码，请稍后再试！\a" );
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
                    printf( "请先创建生词库！\a" );
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
                    printf( "请先创建生词库！\a" );
                    break;
                }
                readpassword( password );
                char *newpassword = changepassword();
                if ( !strcmp( password, newpassword ) )
                {
                    printf( "该密码已设置！\n" );
                }
                else
                {
                    strcpy( password, newpassword );
                    savepassword( password );
                    printf( "更改成功！\n" );
                }
                break;
            }
            case '0':
            {
                printf( "感谢你使用本软件，再见！\n" );
                Sleep( 5000 );
                break;
            }
            default:
                printf( "选项不存在，请重新选择：\a" );
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
                    printf( "是否返回？[y/n]：" );
                    while( 1 == scanf( "%c", &isretn ) )
                    {
                        scanf( "%*[^\n]" );
                        scanf( "%*c" );
                        if ( isretn == 'n' || isretn == 'N' || isretn == 'y' || isretn == 'Y' )
                        {
                            break;
                        }
                        printf( "选项不存在，请重新选择：\a" );
                    }
                    if ( isretn == 'y' || isretn == 'Y' )
                    {
                        printf( "请稍等！\n" );
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
                    printf( "是否返回？[y/n]：" );
                    while( 1 == scanf( "%c", &isretn ) )
                    {
                        scanf( "%*[^\n]" );
                        scanf( "%*c" );
                        if ( isretn == 'n' || isretn == 'N' || isretn == 'y' || isretn == 'Y' )
                        {
                            break;
                        }
                        printf( "选项不存在，请重新选择：\a" );
                    }
                    if ( isretn == 'y' || isretn == 'Y' )
                    {
                        printf( "请稍等！\n" );
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
                    printf( "是否返回？[y/n]：" );
                    while( 1 == scanf( "%c", &isretn ) )
                    {
                        scanf( "%*[^\n]" );
                        scanf( "%*c" );
                        if ( isretn == 'n' || isretn == 'N' || isretn == 'y' || isretn == 'Y' )
                        {
                            break;
                        }
                        printf( "选项不存在，请重新选择：\a" );
                    }
                    if ( isretn == 'y' || isretn == 'Y' )
                    {
                        printf( "请稍等！\n" );
                        break;
                    }
                }
                break;
            }
            case '4':
            {
                printf( "请稍等！\n" );
                break;
            }
            case '0':
            {
                printf( "感谢你使用本软件，再见！\n" );
                Sleep( 5000 );
                exit( 0 );
            }
            default:
                printf( "选项不存在，请重新选择：\a" );
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
                printf( "请按格式输入（例如：English 英语）。如果不再添加，请输入“C 取消”：\n" );
                while ( 2 == scanf( "%20s %80s", &en, &zh ) )
                {
                    if ( strcmp( en, "C" ) == 0 && strcmp( zh, "取消" ) == 0 )
                    {
                        printf( "请稍等！\n" );
                        scanf( "%*c" );
                        break;
                    }
                    addnewword( obj, en, zh );
                }
                break;
            }
            case '2':
            {
                printf( "请按格式输入（例如：English 英语）。如果不再删除，请输入“C 取消”：\n" );
                while ( 2 == scanf( "%20s %80s", &en, &zh ) )
                {
                    if ( strcmp( en, "C" ) == 0 && strcmp( zh, "取消" ) == 0 )
                    {
                        printf( "请稍等！\n" );
                        scanf( "%*c" );
                        break;
                    }
                    deleteword( obj, en, zh );
                }
                break;
            }
            case '3':
            {
                printf( "请按格式输入（例如：English 英语）。如果不再修改，请输入“C 取消”：\n" );
                while ( 2 == scanf( "%20s %80s", &en, &zh ) )
                {
                    if ( strcmp( en, "C" ) == 0 && strcmp( zh, "取消" ) == 0 )
                    {
                        printf( "请稍等！\n" );
                        scanf( "%*c" );
                        break;
                    }
                    editword( obj, en, zh );
                }
                break;
            }
            case '4':
            {
                printf( "请稍等！\n" );
                break;
            }
            case '0':
            {
                printf( "感谢你使用本软件，再见！\n" );
                Sleep( 5000 );
                exit( 0 );
            }
            default:
                printf( "选项不存在，请重新选择：\a" );
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
                printf( "请输入英文。如果不再查询，请输入“CF”：\n" );
                while ( 1 == scanf( "%20s", &en ) )
                {
                    scanf( "%*[^\n]" );
                    scanf( "%*c" );
                    if ( !strcmp( en, "CF" ) )
                    {
                        printf( "请稍等！\n" );
                        break;
                    }
                    findword( obj, en, zh );
                }
                break;
            }
            case '2':
            {
                printf( "请输入中文。如果不再查询，请输入“CF”：\n" );
                while ( 1 == scanf( "%20s", &zh ) )
                {
                    scanf( "%*[^\n]" );
                    scanf( "%*c" );
                    if ( !strcmp( zh, "CF" ) )
                    {
                        printf( "请稍等！\n" );
                        break;
                    }
                    findword( obj, en, zh );
                }
                break;
            }
            case '3':
            {
                printf( "请稍等！\n" );
                break;
            }
            case '0':
            {
                printf( "感谢你使用本软件，再见！\n" );
                Sleep( 5000 );
                exit( 0 );
            }
            default:
                printf( "选项不存在，请重新选择：\a" );
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