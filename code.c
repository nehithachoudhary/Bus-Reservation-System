#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>
void gotoxy(int,int);
void menu();
void viewbuslist();
void booktickets();
void cancelbooking();
void busstatusboard();
int main()
{
    for(int i=0;i<=40;i++)
        {
           gotoxy(i,4);
           printf("*");
        }
    printf("* WELCOME TO BUS RESERVATION SYSTEM *");
    for(int i=0;i<=40;i++)
        {
           printf("*");
        }
    gotoxy(25,15);
    printf("press any key to continue.");
    getch();
    login();
    gotoxy(25,15);
    printf("press any key to continue.");
    getch();
    menu();
    return 0;
}
void menu()
{
    char op='y';
    int choice;
    system("cls");
    for(int i=0;i<=40;i++)
        {
           gotoxy(i,4);
           printf("*");
        }
    printf("* WELCOME TO BUS RESERVATION SYSTEM *");
    for(int i=0;i<=40;i++)
        {
           printf("*");
        }
    do
    {
        gotoxy(50,10);
        printf("[1]=> View Bus List");
        gotoxy(50,12);
        printf("[2]=> Book tickets");
        gotoxy(50,14);
        printf("[3]=> Cancel Booking");
        gotoxy(50,16);
        printf("[4]=> Bus Status Board");
        gotoxy(50,18);
        printf("[5]=> Exit");
        for(int i=0;i<=119;i++)
        {
           gotoxy(i,24);
           printf("*");
        }
        gotoxy(25,27);
        printf("Enter Your Choice::");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:viewbuslist();break;
            case 2:booktickets();break;
            case 3:cancelbooking();break;
            case 4:busstatusboard();break;
            case 5:op='n';
            default:
                gotoxy(10,28);
                printf("Invalid Choice.");
        }
    }
    while(op='n');
    return 0;
}
void gotoxy(int x,int y)
{

    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void login()
{
    char user[20];
    char pass[20];
    int i;
    char op;
    struct login l;
    system("cls");
    FILE *fp=fopen("D:\\CSP\\login\\login","rb+");
    for(i=0;i<=52;i++)
    {
        gotoxy(i,4);
        printf("*");
    }
    printf("--LOGIN FORM--");
    for(i=67;i<=117;i++)
    {
        gotoxy(i,4);
        printf("*");
    }
    gotoxy(40,6);
    printf("ENTER USERNAME:");
    fflush(stdin);
    gets(user);
    gotoxy(40,8);
    printf("ENTER PASSWORD:");
    fflush(stdin);
    gets(pass);
    while(fread(&l,sizeof(l),1,fp)==1)
    {
        if((strcmp(l.Username,user)==0)&&(strcmp(l.password,pass)==0))
        {
            gotoxy(35,10);
            printf("WELCOME TO OUR SYSTEM !!!! LOGIN SUCCESSFULL !");
            return 0;
        }
    }
    gotoxy(35,10);
    printf("LOGIN UNSUCCESSFULL");
    printf("do you want to try again:y/n");
    scanf("%c",&op);
    if(op=='n')
    {
        login();
    }

}
void viewbuslist()
{
    system("cls");
    for(int i=0;i<=40;i++)
        {
           gotoxy(i,4);
           printf("*");
        }
    printf("* WELCOME TO BUS RESERVATION SYSTEM *");
    for(int i=0;i<=40;i++)
        {
           printf("*");

        }

        gotoxy(50,10);
        printf("[1]=> Cardiff Express");
        gotoxy(50,12);
        printf("[2]=> Belfast Express");
        gotoxy(50,14);
        printf("[3]=> Derby Express");
        gotoxy(50,16);
        printf("[4]=> Chester Express");
        gotoxy(50,18);
        printf("[5]=> Newport Express");
        for(int i=0;i<=119;i++)
        {
           gotoxy(i,24);
           printf("*");
        }
        getch();

     return 0;
}
void booktickets()
{
    printf("tickets are booked");
}
void cancelbooking()
{
    printf("booking is canceled");
}
void busstatusboard()
{
    printf("status board is viewed");
}
