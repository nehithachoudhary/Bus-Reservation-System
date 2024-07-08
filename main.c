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
void border();
void title();
void bookinbus(int,int,char[]);
void cancelinbus(int,char[]);
void delrec(char[]);
void viewstatus1(int,char[]);
struct busbook{
        char name[20];
        int busno;
        int seatno;
    };
int main()
{
    border();
    gotoxy(43,13);
    printf("****WELCOME TO BUS RESERVATION SYSTEM****");
    gotoxy(70,23);
    printf("press any key to continue.");
    getch();
    login();
    gotoxy(70,23);
    printf("press any key to continue.");
    getch();
    menu();
    return 0;
}
void login()
{
   struct login{
        char Username[20];
        char password[20];
    };
    char user[20];
    char pass[20];
    int i;
    char op;
    struct login l;
    system("cls");
    FILE *fp=fopen("login","rb+");
    border();
    for(i=55;i<=75;i=i+2)
    {
        gotoxy(i,5);
        printf("*");
    }
    for(i=55;i<=75;i=i+2)
    {
        gotoxy(i,9);
        printf("*");
    }
    for(i=5;i<=9;i++)
    {
        gotoxy(55,i);
        printf("*");
    }
    for(i=5;i<=9;i++)
    {
        gotoxy(75,i);
        printf("*");
    }
    gotoxy(58,7);
    printf("--LOGIN FORM--");
    gotoxy(50,13);
    printf("ENTER USERNAME:");
    fflush(stdin);
    gets(user);
    gotoxy(50,15);
    printf("ENTER PASSWORD:");
    fflush(stdin);
    gets(pass);
    while(fread(&l,sizeof(l),1,fp)==1)
    {
        if((strcmp(l.Username,user)==0)&&(strcmp(l.password,pass)==0))
        {
            gotoxy(39,17);
            printf("WELCOME TO OUR SYSTEM !!!! LOGIN SUCCESSFULL !");
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    gotoxy(50,18);
    printf("LOGIN UNSUCCESSFULL");
    gotoxy(43,20);
    printf("DO YOU WANT TO TRY AGAIN (y/n):");
    scanf("%c",&op);
    if(op=='y')
    {
        login();
    }
    else
        exit(0);

}
void menu()
{
    char op1;
    int choice;
    system("cls");
    border();
    title();
    gotoxy(50,11);
    printf("[1]=> View Bus List");
    gotoxy(50,13);
    printf("[2]=> Book tickets");
    gotoxy(50,15);
    printf("[3]=> Cancel Booking");
    gotoxy(50,17);
    printf("[4]=> Bus Status Board");
    gotoxy(50,19);
    printf("[5]=> Exit");
    gotoxy(35,22);
    printf("Enter Your Choice::");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:{viewbuslist();break;}
        case 2:{booktickets();break;}
        case 3:{cancelbooking();break;}
        case 4:{busstatusboard();break;}
        case 5:exit(0);
        default:{
                gotoxy(35,23);
                printf("Invalid Choice.");
                gotoxy(70,27);
                printf("press any key to continue");
                getch();
        }
    }
    menu();
}
void viewbuslist()
{
    int i;
    system("cls");
    border();
    title();
    gotoxy(50,12);
    printf("[1]=> Cardiff Express");
    gotoxy(50,14);
    printf("[2]=> Belfast Express");
    gotoxy(50,16);
    printf("[3]=> Derby Express");
    gotoxy(50,18);
    printf("[4]=> Chester Express");
    gotoxy(50,20);
    printf("[5]=> Newport Express");
    gotoxy(70,23);
    printf("press any key to continue.");
    getch();
}
void booktickets()
{
    int bn;
    system("cls");
    border();
    title();
    gotoxy(50,12);
    printf("[1]=> Cardiff Express");
    gotoxy(50,14);
    printf("[2]=> Belfast Express");
    gotoxy(50,16);
    printf("[3]=> Derby Express");
    gotoxy(50,18);
    printf("[4]=> Chester Express");
    gotoxy(50,20);
    printf("[5]=> Newport Express");
    gotoxy(35,22);
    printf("Enter Bus Number::");
    scanf("%d",&bn);
    switch(bn)
    {
        case 1:{bookinbus(1,120,"Cardiff Express");break;}
        case 2:{bookinbus(2,230,"Belfast Express");break;}
        case 3:{bookinbus(3,450,"Derby Express");break;}
        case 4:{bookinbus(4,520,"Chester Express");break;}
        case 5:{bookinbus(5,630,"Newport Express");break;}
        default:{
                gotoxy(35,23);
                printf("Invalid Choice.");
                gotoxy(70,27);
                printf("press any key to continue");
                getch();
                }
    }
}
void cancelbooking()
{
    int bn;
    system("cls");
    border();
    title();
    gotoxy(50,12);
    printf("[1]=> Cardiff Express");
    gotoxy(50,14);
    printf("[2]=> Belfast Express");
    gotoxy(50,16);
    printf("[3]=> Derby Express");
    gotoxy(50,18);
    printf("[4]=> Chester Express");
    gotoxy(50,20);
    printf("[5]=> Newport Express");
    gotoxy(35,22);
    printf("Enter Bus Number to cancel the ticket::");
    scanf("%d",&bn);
    if(bn<=0||bn>=6)
    {
        gotoxy(35,24);
        printf("choose the correct input");
        gotoxy(35,26);
        printf("press any key to continue");
        getch();
        cancelbooking();
    }
    switch(bn)
    {
        case 1:{cancelinbus(1,"Cardiff Express");break;}
        case 2:{cancelinbus(2,"Belfast Express");break;}
        case 3:{cancelinbus(3,"Derby Express");break;}
        case 4:{cancelinbus(4,"Chester Express");break;}
        case 5:{cancelinbus(5,"Newport Express");break;}
        default:{
                gotoxy(35,23);
                printf("Invalid Choice.");
                gotoxy(70,27);
                printf("press any key to continue");
                getch();
                }
    }
}
void busstatusboard()
{
    int bn;
    system("cls");
    border();
    title();
    gotoxy(50,12);
    printf("[1]=> Cardiff Express");
    gotoxy(50,14);
    printf("[2]=> Belfast Express");
    gotoxy(50,16);
    printf("[3]=> Derby Express");
    gotoxy(50,18);
    printf("[4]=> Chester Express");
    gotoxy(50,20);
    printf("[5]=> Newport Express");
    gotoxy(35,22);
    printf("Enter Bus Number to view bus status::");
    scanf("%d",&bn);
    switch(bn)
    {
        case 1:{viewbusstatus(1,"Cardiff Express");break;}
        case 2:{viewbusstatus(2,"Belfast Express");break;}
        case 3:{viewbusstatus(3,"Derby Express");break;}
        case 4:{viewbusstatus(4,"Chester Express");break;}
        case 5:{viewbusstatus(5,"Newport Express");break;}
        default:{
                gotoxy(35,23);
                printf("Invalid Choice.");
                gotoxy(70,27);
                printf("press any key to continue");
                getch();
                }
    }
}
void viewbusstatus(int bno,char bname[50])
{
    system("cls");
    border();
    int i;
    for(i=50;i<=68;i=i+2)
    {
        gotoxy(i,5);
        printf("*");
        gotoxy(i,7);
        printf("*");
    }
    for(i=5;i<=7;i++)
    {
        gotoxy(50,i);
        printf("*");
        gotoxy(68,i);
        printf("*");
    }
    if(bno==1)
    {
        gotoxy(52,6);
        printf("Cardiff Express\n\n");
        gotoxy(45,9);
        printf("BUS ROUTE::::NELLORE<---->CHENNAI");
        gotoxy(52,11);
        printf("<-----TIMINGS----->");
        gotoxy(52,13);
        printf("03:00 AM - 07:00 AM");
        gotoxy(52,14);
        printf("08:00 AM - 12:00 AM");
        gotoxy(52,15);
        printf("13:00 PM - 17:00 PM");
        gotoxy(52,16);
        printf("17:30 PM - 21:30 PM");
        gotoxy(52,17);
        printf("22:00 PM - 02:00 AM");
        gotoxy(48,19);
        printf("Price Of the ticket: %d ",120);
        gotoxy(48,21);
        printf("Present Status Of Bus : Available");
        int op;
        gotoxy(70,23);
        printf("press 0 to view seats:");
        scanf("%d",&op);
        if(op==0)
        {
            viewstatus1(1,"Cardiff Express");
        }
        else
            return 0;

    }
    else if(bno==2)
    {

    }
    else if(bno==3)
    {

    }
    else if(bno==4)
    {

    }
    else
    {

    }

}
void viewstatus1(int bno,char bname[50])
{
        int i,j,A[33],c=1,totalseats=0,temp=1,temp1=0;
        struct busbook b;
        system("cls");
        border();
        FILE *fp=fopen("busboking","rb+");
        for(i=50;i<=68;i=i+2)
        {
            gotoxy(i,5);
            printf("*");
            gotoxy(i,7);
            printf("*");
        }
        for(i=5;i<=7;i++)
        {
            gotoxy(50,i);
            printf("*");
            gotoxy(68,i);
            printf("*");
        }
        gotoxy(52,6);
        printf("%s\n\n",bname);
        i=0;
        while(fread(&b,sizeof(b),1,fp)==1)
        {
            if(b.busno==bno)
            {
                A[i]=b.seatno;
                i++;
            }
            temp++;
        }
        for(i=1;i<=8;i++)
        {
            printf("\n\t\t\t\t\t");
            for(j=1;j<=4;j++)
            {
                temp1=0;
                fseek(fp,0,SEEK_SET);
                for(int k=0;k<=temp;k++)
                {
                    if(c==A[k])
                    {
                        if(c<10)
                            printf("%d",0);
                        printf("%d.BOOKED   ",c);
                        temp1=1;
                    }
                }
                if(temp1==0)
                {
                    if(c<10)
                        printf("%d",0);
                    printf("%d.EMPTY    ",c);
                    totalseats++;
                }
                c++;
            }
        }
        fclose(fp);
        printf("\n\n\t\t\t\tAvailable Seats:%d",totalseats);
        getch();
}
void cancelinbus(int bno,char bname[50])
{
    int temp1=0,temp=0;
    system("cls");
    int n,i,j;
    border();
    struct busbook b;
    int sno;
    char name[20];
    for(i=50;i<=68;i=i+2)
    {
        gotoxy(i,5);
        printf("*");
        gotoxy(i,7);
        printf("*");
    }
    for(i=5;i<=7;i++)
    {
        gotoxy(50,i);
        printf("*");
        gotoxy(68,i);
        printf("*");
    }
    gotoxy(52,6);
    printf("%s\n\n",bname);
    FILE *fp1=fopen("busboking","rb+");
    printf("\n\t\t\t\tEnter Number of Tickets to cancel:");
    scanf("%d",&n);
    int A[33];
    char s[33][20];
    i=0;
    while(fread(&b,sizeof(b),1,fp1)==1)
    {
        if(b.busno==bno)
        {
            A[i]=b.seatno;
            strcpy(s[i],b.name);
            i++;
        }
        temp++;
    }
    for(int i=1;i<=n;i++)
    {
        printf("\n\t\t\t\tEnter the details for cancel ticket no %d ",i);
        printf("\t\t\t\tEnter the seat number:------>");
        scanf("%d",&sno);
        if(sno<=0||sno>=33)
        {
            printf("\n\t\t\t\t");
            printf("Invalid seatno!!\n");
            continue;
        }
        printf("\t\t\t\tEnter the name:------------->");
        fflush(stdin);
        gets(name);
        for(j=0;j<=temp;j++)
        {
            if(sno==A[j]&&strcmp(s[j],name)==0)
            {
                temp1=1;
                break;
            }
        }
        if(temp1==0)
        {
            printf("\n\t\t\t\t");
            printf("WRONG DETAILS!!\n");
            continue;
        }
        fclose(fp1);
        delrec(name);
    }
    getch();
}
void delrec(char deleteName[20])
{

    FILE *fileIn, *fileOut;
    struct busbook b;

    fileIn = fopen("busboking", "r");
    if (fileIn == NULL) {
        perror("Error opening file");
        return 1;
    }

    fileOut = fopen("temp.txt", "a");
    if (fileOut == NULL) {
        perror("Error opening temporary file");
        fclose(fileIn);
        return 1;
    }

    int found = 0;

    while (fread(&b, sizeof(struct busbook), 1, fileIn)) {
        if (strcmp(b.name, deleteName) != 0) {
            fwrite(&b, sizeof(struct busbook), 1, fileOut);
        } else {
            found = 1;
        }
    }

    fclose(fileIn);
    fclose(fileOut);

    if (found) {
        remove("busboking");
        rename("temp.txt", "busboking");
        printf("\n\t\t\t\tRecord deleted successfully.\n");
    } else {
        remove("temp.txt");
        printf("\n\t\t\t\tRecord not found.\n");
    }
}
void bookinbus(int bno,int p,char bname[50])
{

    system("cls");
    for(int i=25;i<=90;i=i+2)
        {
           gotoxy(i,3);
           printf("*");
           gotoxy(i,20);
           printf("*");
        }
    for(int i=3;i<=20;i++)
    {
        gotoxy(24,i);
        printf("*");
        gotoxy(90,i);
        printf("*");
    }
    struct busbook b;
    int i,j,c=1,n,totalseats=0,temp=1,temp1=0,a=0;
    for(i=50;i<=68;i=i+2)
    {
        gotoxy(i,5);
        printf("*");
        gotoxy(i,7);
        printf("*");
    }
    for(i=5;i<=7;i++)
    {
        gotoxy(50,i);
        printf("*");
        gotoxy(68,i);
        printf("*");
    }
    FILE *fp=fopen("busboking","rb+");
    gotoxy(52,6);
    printf("%s\n\n",bname);
    int A[33];
    i=0;
    while(fread(&b,sizeof(b),1,fp)==1)
    {
        if(b.busno==bno)
        {
            A[i]=b.seatno;
            i++;
        }
        temp++;
    }
    for(i=1;i<=8;i++)
    {
        printf("\n\t\t\t\t");
        for(j=1;j<=4;j++)
        {
            temp1=0;
            fseek(fp,0,SEEK_SET);
            for(int k=0;k<=temp;k++)
            {
                if(c==A[k])
                {
                    printf("%d.BOOKED   ",c);
                    temp1=1;
                }
            }
            if(temp1==0)
            {
                printf("%d.EMPTY    ",c);
                totalseats++;
            }
            c++;
        }
    }
    fclose(fp);
    printf("\n\n\t\t\t\tAvailable Seats:%d",totalseats);
    printf("\n\n\n\n\t\t\tENTER NUMBER OF TICKETS FOR BOOKING:");
    scanf("%d",&n);
    for(j=25;j<=90;j++)
        printf("=");
    FILE *fp1=fopen("busboking","ab+");
    for(i=1;i<=n;i++)
    {
        temp1=0;
        printf("\n\t\t\tEnter the details for ticket no %d ",i);
        printf("\n\t\t\t\tEnter the seat number:---------->");
        scanf("%d",&b.seatno);
        for(int k=0;k<=temp;k++)
        {
            if(b.seatno==A[k])
            {
                printf("\n\t\t\tSeat number %d is Already Booked!Please book another seat\n",A[k]);
                temp1=1;
            }
        }
        if(temp1==1)
        {
            for(j=25;j<90;j++)
                printf("=");
            continue;
        }
        if(b.seatno<=0||b.seatno>=33)
        {
            printf("\n\t\t\t\tNo Seat is available with seatno %d",b.seatno);
            continue;
        }
        a=a+p;
        printf("\n\t\t\t\tEnter the name of the person:--->");
        fflush(stdin);
        gets(b.name);
        b.busno=bno;
        fwrite(&b,sizeof(b),1,fp1);
        printf("\n");
        for(j=25;j<=90;j++)
            printf("=");
    }
    fclose(fp1);
    printf("\n\t\t\t\tTotal Amount:%d",a);
    getch();

}
void gotoxy(int x,int y)
{

    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void border(){
    for(int i=25;i<=102;i=i+2)
        {
           gotoxy(i,3);
           printf("*");
           gotoxy(i,25);
           printf("*");
        }
    for(int i=3;i<=25;i++)
    {
        gotoxy(24,i);
        printf("*");
        gotoxy(102,i);
        printf("*");
    }
}
void title()
{
    int i;
    for(i=45;i<=81;i=i+2)
    {
        gotoxy(i,5);
        printf("*");
        gotoxy(i,9);
        printf("*");
    }
    for(i=5;i<=9;i++)
    {
        gotoxy(45,i);
        printf("*");
        gotoxy(82,i);
        printf("*");
    }
    gotoxy(48,7);
    printf("WELCOME TO BUS RESERVATION SYSTEM");

}
