#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>

/// Update & Insert Function
void insertfirst(int data, char foodname[50], int quantity, float price);
void insertlast(int data, char foodname[50], int quantity, float price);
void updatefood(int udata, int quantity);

/// Display Function
void order_view(int order, int quantity, int number);
int window();
void main_menu();
void food_list();

void serve();
void time_e();

///login & password related function
int register_user();
int logIn();
int check(char name[30]);
int verifyLogIn(char name[30], char key[30]);


///START Structure Here

struct Node
{
    int data;
    int quantity;
    char foodname[50];
    float price;
    struct Node *next;


};

struct Record
{
    char uName[30];
    char uPassword[30];

};

struct Record eRecord;

///Global Type
typedef struct Node node;
node *front=NULL, *rear;
int pay,confirm,ps_menu,admin,cs,food_choice, menu,admin,food_quantity,count=0;

int main()

{

    system("title ...Developed by Reza Rahman...");

    int n,item,quantity,order=0,c=0;
    int t_order[50],order_quantity[100];
    float totalmoney =0;

    insertfirst(1,"Hoeddeok      ",18,250.00);
    insertlast(2,"Bulgogi       ",12,720.83);
    insertlast(3,"Samgyeopsal   ",17,520.29);
    insertlast(4,"Japchae       ",23,190.00);
    insertlast(5,"Kimchi        ",34,180.23);
    insertlast(6,"Ddukbokki     ",21,135.13);
    insertlast(7,"Sundubu-jjigae",45,215.50);
    insertlast(8,"Bibimbap      ",46,170.23);
    insertlast(9,"Seolleongtang ",73,220.13);
    insertlast(10,"Water        ",46,110.23);

main_menu:

    main_menu();
    scanf("%d",&menu);
    fflush(stdin);
    int ok=0;
    if(menu == 1)
    {
        while(ok==0)
        {
            ok=register_user();
        }
        main();
    }
    else if( menu == 2)
    {
        while(ok==0)
        {
            ok=logIn();
        }
        node *temp;
        temp=rear;
r1:

        system("cls");
        window();
        gotoxy(40,7);
        printf(" 1. Food List");
        gotoxy(40,8);
        printf(" 2. Food Order");
        gotoxy(40,9);
        printf(" 3. Order Preview");
        gotoxy(40,10);
        printf(" 4. Serve Order");
        gotoxy(40,11);
        printf(" 5. Total cash Today");
        gotoxy(40,12);
        printf(" 9. Main Menu");
        gotoxy(40,13);
        printf(" 0. Exit");
        gotoxy(40,14);
        printf(" Enter your choice:");
        scanf("%d",&admin);
        fflush(stdin);
        if(admin==1)
        {
            system("cls");
            window();
            food_list();
            printf("\t\tPress 1 to back");
            scanf("%d",&n);
            fflush(stdin);
            if(n==1)
            {
                goto r1;
            }

            else
                system("cls");
            window();
            gotoxy(42,6);
            printf("Wrong choice!");
            getch();
            goto r1;
        }
        else if(admin==2)
        {
foodlist:

            system ("cls");
            window();
            gotoxy(42,5);
            printf("0.Menu");
            food_list();

            gotoxy(88,8);
            printf("Place Your Order: ");
            fflush(stdin);
            scanf("%d",&food_choice);
            fflush(stdin);
            if(food_choice==0)
            {
                goto r1;
            }

            node *temp;
            temp = rear ;

            while(temp->data != food_choice)
            {

                temp = temp->next;
                if(temp==NULL)
                {
                    gotoxy(88,9);
                    printf("Please Choice From List");
                    getch();

                    goto foodlist;
                }

            }
            if(food_choice == temp->data)
            {

fcquantity:

                gotoxy(88,9);
                printf("Enter Food Quantity : ");
                int fcquantity;
                scanf("%d",&fcquantity);
                fflush(stdin);
                system("cls");
                if(fcquantity==0)

                {
                    gotoxy(88,10);
                    printf("Wrong input!");
                    getch();
                    system("cls");

                    goto foodlist;
                }

                else if(fcquantity>temp->quantity)

                {
                    system("cls");
                    window();
                    gotoxy(42,6);
                    printf("Sorry!Out of Stock-_-");
                    getch();

                    goto foodlist;
                }


confirm:

                system("cls");
                window();
                gotoxy(40,6);
                printf("Your Choses food :%s",temp->foodname);
                gotoxy(40,7);
                printf("Price :%0.2f taka only",temp->price*fcquantity);
                gotoxy(40,9);
                printf("1. Confirm to buy this");
                gotoxy(40,10);
                printf("2. Food List");
                gotoxy(40,12);
                printf("Enter your choice:");

                scanf("%d",&confirm);
                fflush(stdin);
                if(confirm == 1 )
                {
                    count++;
                    totalmoney += temp->price*fcquantity;
                    order++;
                    t_order[order]=food_choice;
                    order_quantity[order]=fcquantity;
                    quantity = temp->quantity - fcquantity;
                    updatefood(food_choice,quantity);

psmenu:

                    system("cls");
                    window();
                    gotoxy(40,8);
                    printf("Ordered Successfully ...");
                    gotoxy(40,10);
                    printf("1.Do you want to buy another food?");
                    gotoxy(40,11);
                    printf("2. Menu");
                    gotoxy(40,12);
                    printf("3.Exit");
                    gotoxy(40,13);
                    printf("Enter your choice:");

                    scanf("%d",&ps_menu);
                    fflush(stdin);
                    if(ps_menu==1)
                    {
                        goto foodlist;
                    }
                    else if(ps_menu==2)
                    {
                        goto r1;
                    }
                    else
                    {
                        gotoxy(40,14);
                        printf("Please Choice from list :");
                        getch();

                        goto psmenu;
                    }

                }

                else if(confirm == 2)
                {
                    goto foodlist;

                }

                else
                {
                    gotoxy(40,14);
                    printf("Enter Choice from List : ");
                    getch();

                    goto confirm;
                }
            }

            else
            {
                gotoxy(40,14);

                printf("Please Enter Choice From List");

                goto foodlist;

            }

        }

        else if(admin==3)
        {

            system("cls");
            window();
            gotoxy(42,6);
            time_e();

            printf("\n\n\t\t\t------------------------------------------------------------\n");
            printf("\t\t\t|  Order No.  |  Food Name        |  Quantity |  In Stock  |\n");
            printf("\t\t\t------------------------------------------------------------\n");
            int o;
            for( o=1; o<=order; o++)
            {
                order_view(t_order[o],order_quantity[o],o);

            }

            printf("\t\t\t1.Press 1 to back ");
            scanf("%d",&n);
            fflush(stdin);

            if(n==1)
            {
                goto r1;
            }

            else
                system("cls");
            window();
            gotoxy(42,7);
            printf("Wrong choice!");

            getch();
            goto r1;

        }

        else if(admin==4)
        {
            serve();
            getch();
            goto r1;
        }
        else if(admin==5)
        {
            system("cls");
            gotoxy(40,9);
            printf("Todays Total Cash : %0.2f taka.\n",totalmoney);
            getch();
            goto r1;
        }
        else if(admin==9)
        {

            goto main_menu;
        }

        else if(admin==0)
        {
            system("cls");
            window();
            gotoxy(30,7);
            printf("-_- THANK YOU FOR USING OUR SYSTEM -_-\n\n");
            exit(0);
        }
        else

        {
            window();
            gotoxy(40,16);
            printf(" Please Choice From List :");
            getch();
            goto r1;

        }
    }

    else if(menu==3)

    {
        system("cls");
        window();
        gotoxy(29,8);
        printf("-_- Thank You For Using Our System -_-\n\n\n");
        exit(0);

    }
    else
    {
        gotoxy(40,12);
        printf("Please Enter Correct Choice.");
        getch();
        goto main_menu;
    }
}
///end of main function

void insertfirst(int data, char foodname[25], int quantity, float price)

{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->data = data ;
    temp->price = price;
    strcpy(temp->foodname,foodname);
    temp-> quantity = quantity;
    temp->next = front;
    front = temp;
    rear = front ;

}
void insertlast(int data, char foodname[25], int quantity, float price)
{

    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->data = data;
    temp->price = price;
    temp-> quantity = quantity;
    strcpy(temp->foodname,foodname);
    temp->next = NULL;
    if(front==NULL)
    {
        front = temp;
        rear = front;
    }
    else
    {

        while(front->next != NULL)
        {
            front = front->next;
        }

        front->next = temp;
    }

}

///order preview
void order_view(int order, int quantity, int number)
{
    node *temp;
    temp = rear;
    while(temp->data != order)
    {

        temp = temp->next;

    }
    if(temp->data == order)
    {
        printf("\t\t\t|     %d       |  %s   |  %d        |   %d       |\n",number,temp->foodname,quantity,temp->quantity);
        printf("\t\t\t------------------------------------------------------------\n");
        Sleep(100);

    }
}
void updatefood(int udata, int quantity)
{

    node *temp;
    temp = rear;
    while(temp->data!=udata)
    {
        temp = temp->next;
    }
    if(temp->data == udata)
    {

        temp->quantity = quantity;
    }
}

int window()
{
    system("color a");
    gotoxy(26,2);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FOOD ORDERING SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(14,3);
    printf("________________________________________________________________________________");
}
void main_menu()
{
    system("cls");
    window();
    gotoxy(40,7);
    printf("1. New User\n");
    gotoxy(40,8);
    printf("2. Existing User\n");
    gotoxy(40,9);
    printf("3. Exit\n");
    gotoxy(40,10);
    printf("Enter your Choice:");

}

///food list
void food_list()
{

    printf("\n\t\t--------------------------------------------------------------------\n");
    printf("\t\t|  Food No. |  Food Name            |  Price(taka)  |  In Stock    |\n");
    printf("\t\t--------------------------------------------------------------------\n");
    node *temp;
    temp = rear;
    while(temp != NULL)
    {
        printf("\t\t|    %d      |  %s       |  %0.2f       |    %d        |\n",temp->data,temp->foodname, temp->price, temp->quantity);
        printf("\t\t--------------------------------------------------------------------\n");
        temp = temp->next ;
        Sleep(50);

    }
}
///serve order

void serve()
{

    int a=0,b,i,n;
    n=count;
    system("cls");
    window();
    gotoxy(42,6);
    time_e();
    gotoxy(21,9);
    printf("----------------------------------------------------------------\n");
    gotoxy(21,10);
    printf("TOTAL ORDER\tSERVE ORDER\tWAITING ORDER\t WAITING TIME\n");
    gotoxy(21,11);
    printf("----------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        b=count-1;

        printf("\n\t\t\t  %d \t\t   %d \t\t   %d\t\t   %d sec.\n\n",count,i+1,b,a+=10);
        Sleep(10000);
        count--;
    }

    printf("\t\t\t  0 \t\t   0 \t\t   0\t\t    0 sec.\n");
    printf("\n\n\n\t\t\tPress any key to continue:");

}

///for date & time
void time_e()

{

    time_t t;
    time(&t);
    printf("%s",ctime(&t));
}

COORD coord = {0,0};
int gotoxy(int x, int y)     /// X and Y coordinates
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);   ///ff
}

///Password
int register_user()
{
    char uName[30];
    char uPassword[30];
    char c;
    int m = 0;
    printf("\n\t\t\t\t\tWELCOME TO USER REGISTRATION\n");
    printf("\n\t\t\t\t\tEnter Username : ");
    scanf("%s", uName);

    int nameOK = check(uName);

    if(nameOK == 1)
    {
        printf("\n\t\t\t\t\tEnter Password : ");

        while((c = getch()) != 13)
        {
            if(c == 8)
            {
                printf("\b \b");
                uPassword[m--] = '\0';
            }
            else
            {
                uPassword[m++] = c;
                printf("%c", '*');
            }
        }
        uPassword[m] = '\0';
        strcpy(eRecord.uName, uName);
        strcpy(eRecord.uPassword, uPassword);
    }
    else
    {
        return 0;
    }

    CreateDirectory(uName,NULL);

    FILE *fp = fopen(strcat(uName, "\\log.txt"), "w");
    fputs(eRecord.uName, fp);
    fputs("\n", fp);
    fputs(eRecord.uPassword, fp);
    fputs("\n", fp);
    fclose(fp);

    fp = fopen("name_exist.txt", "a+");
    fputs(eRecord.uName, fp);
    fputs("\n", fp);
    fclose(fp);

    printf("\n\t\t\t\t\tRegistration Completed Successfully!\n\t\t\t\t\tPress any key to continue...\n");
    getch();
    return 1;
}
int logIn()
{
    char uName[30];
    char uPassword[30];
    char c;
    int m = 0,n = 0;
    printf("\n\t\t\t\t\tWELCOME TO USER LOGIN\n");
    printf("\n\t\t\t\t\tEnter Username : ");
    scanf("%s", uName);
    printf("\n\t\t\t\t\tEnter Password : ");

    while((c = getch()) != 13)
    {
        if(c == 8)
        {
            printf("\b \b");
            uPassword[m--] = '\0';
        }
        else
        {
            uPassword[m++] = c;
            printf("%c", '*');
        }
    }
    uPassword[m] = '\0';
    int ok = verifyLogIn(uName, uPassword);
    if(ok)
    {
        printf("\n\t\t\t\t\tLogin successful!\n\t\t\t\t\tPress any key to continue...");

    }
    else
    {
        return 0;
    }

    return 1;
}


int check(char name[30])
{
    char str[30] = {'\0'}, s[1] = {'\0'};
    int c, i = 0;
    FILE *fp = fopen("name_exist.txt", "r");
    if(fp == NULL)
    {
        perror("Error opening file");
    }
    else
    {
        while ((c = fgetc(fp)) != EOF)
        {
            if(c == '\n')
            {
                str[i] = '\0';

                if(strcmp(name, str) == 0)
                {
                    printf("\n\t\t\t\t\tUser already exists! Choose another username.\n");
                    fclose(fp);
                    return 0;
                }
                else
                {
                    i = 0;
                }
            }
            else
            {
                str[i++] = (char) c;
            }
        }
    }
    fclose(fp);
    return 1;
}
int verifyLogIn(char name[30], char key[30])
{
    char str[30] = {'\0'};
    char temp[30] = {'\0'};
    char s[1] = {'\0'};
    int c, i = 0, k = 0;

    for(i = 0; i < 30; i++)
    {
        if(name[i] == '\0')
        {
            temp[i] = '\0';
            break;
        }
        temp[i] = name[i];
    }

    i = 0;

    FILE *fp = fopen(strcat(temp, "\\log.txt"), "r");

    if(fp == NULL)
    {
        printf("\n\n\t\t\t\t\tHint : wrong username!\n");
        return 0;
    }
    else
    {
        while ((c = fgetc(fp)) != EOF)
        {

            if(c == '\n')
            {
                str[i] = '\0';

                if(k > 0)
                {
                    if(strcmp(key, str) == 0)
                    {
                        k++;
                    }
                }
                else
                {
                    if(strcmp(name, str) == 0)
                    {
                        k++;
                    }
                }
                if(k == 0)
                {
                    break;
                }
                i = 0;
            }
            else
            {
                str[i++] = (char) c;
            }
        }
        if(k < 2)
        {
            printf("\n\t\t\t\t\tIncorrect username or password. Please try again!\n");
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    return 1;
}

