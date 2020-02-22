#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct hotel
{
    char dname[20];
    char name[50];
    float rent;
    int available;
    int code;
    int amount;


    struct hotel *next;
}*head=NULL;
int total=0,tmp=0;
float total_rent=0;
char password[15];
int registration()
{
    char uname[15],rpass[15],j[15],ch;
    int i=0;

    printf("Enter username: \n");
    scanf("%s",uname);
    printf("Enter password:\n");

    while (1)
    {
        ch=getch();
        if(ch == 13)
        {
            break;
        }
        else if(ch==8||ch==127)
        {
            putch('\b');
            putch(NULL);
            putch('\b');
            i--;
            continue;
        }
        password[i]= ch;
        i++;
        ch = '*';
        putch(ch);
    }
    password[i] = '\0';
    if(strcmp(password,j)==0)
    {
        printf("\n");
        printline();
        return 1;

    }
    else
    {
        printf("\n");
        printline();
        return 0;
    }
    printf("U are registered\n");
}


void user()
{


    while(1)
    {


        int ops;
        printf("\n=======what do u want========\n");
        printf("1.Browse hotel\n2.search hotel\n3.Calculate Rent\n4.main menu\n0.Exit\nEnter your choice:");
        scanf("%d",&ops);
        switch(ops)
        {
        case 1:
            hotellist(head);
            break;
        case 2:
            search(head);
            break;
        case 3:
            rent();
            break;
        case 0:
            return 0;
            break;
        default:
            printf("invalid ");
            break;

        }
    }

}




void adminpanel()
{
    int option;

    printf("\n======Welcome To Admin Panel======\n");

    printf("    1.Add new hotel\n    2.Modify an hotel\n    3.Remove an hotel\n    0.Return to Main menu\nEnter your choice: ");
    scanf("%d",&option);

    switch(option)
    {
    case 1:
        addhotel(head);
        break;
    case 2:
        modifyhotel(head);
        break;
    case 3:
        removehotel(head);
        break;
    case 0:
        return;
    default:
        printf("Invalid Choice !!! Please try again...\n");
    }

    printline();
    return;
}

void addhotel(struct hotel *link)
{
    int ch;
    if(head->next==NULL && tmp == 0)
    {
        printf("Enter district name: ");
        scanf("%s",head->dname);
        printf("\nEnter Hotel name: ");
        scanf("%s",head->name);
        printf("Enter available number of room: ");
        scanf("%d",&head->available);
        printf("\nEnter rent of room: ");
        scanf("%f",&head->rent);

        printf("Enter amount of room what you want???: ");
        scanf("%d",&head->amount);

        total++;
        head->code=total;
        tmp++;
    }
    else
    {
        while(link->next!=NULL)
        {
            link=link->next;
        }

        link->next=(struct hotel*)malloc(sizeof(struct hotel));
        printf("Enter district name: ");
        scanf("%s",link->next->dname);

        printf("Enter hotel name: ");
        scanf("%s",link->next->name);
        printf("Enter available number of room: ");
        scanf("%d",&link->next->available);
        printf("\nEnter rent of room : ");
        scanf("%f",&link->next->rent);
        printf("\nEnter amount of room what you want??: ");
        scanf("%d",&link->next->amount);

        total++;
        link->next->code=total;
        link->next->next=NULL;
    }
    printline();
    printf("    1.Continue adding\n    2.Return to admin panel\n    3.Return to Main menu\nEnter your choice: ");
    scanf("%d",&ch);
    if(ch==1)
    {
        addhotel(head);
    }
    else if(ch==2)
    {
        printline();
        adminpanel();

    }
    else if(ch==3)
    {
        printline();
        return;
    }
    else
    {
        printf("Invalid input !!! Please Try again...\n");
        printline();
    }

    return;

}

void modifyhotel(struct hotel* link)
{
    printline();
    int code,ch,s=0;
    if(total==0)
    {
        printf("List is empty...\n");
    }
    else
    {
        printline();
        printf("Enter hotel code: ");
        scanf("%d",&code);
        while(link!=NULL)
        {
            if(link->code==code)
            {
                s++;
                printf("    1.Modify name\n    2.Modify available number of room\n    3.Modify rent of room\n    4.Modify  amount of room which u want??\n     5.Modify district name\n   6.Return to main menu\nEnter your choice: ");
                scanf("%d",&ch);
                switch(ch)
                {
                case 1:
                    printf("Enter new name: ");
                    scanf("%s",link->name);
                    break;
                case 2:
                    printf("Enter new available number of room: ");
                    scanf("%d",&link->available);
                    break;
                case 3:
                    printf("Enter new rent: ");
                    scanf("%f",&link->rent);
                    break;
                case 4:
                    printf("Enter new amount  of room which you want??: ");
                    scanf("%d",&link->amount);
                    break;


                case 5:
                    printf("Enter new district name: ");
                    scanf("%s",&link->dname);
                    break;
                case 6:
                    return;
                default:
                    printf("Invalid input...\n");
                }
                break;

            }
            else
            {
                link=link->next;
            }
            if(s==0)
            {
                printf("Item not found !!!\n");
            }
        }
    }
    printline();
}

void removehotel(struct hotel* link)
{
    printline();
    int code,flag=0;
    struct hotel* tmp;
    struct hotel* post=head->next;

    if(total==0)
    {
        printf("Sorry !! No hotel in the list...\n");
    }
    else
    {
        printf("Enter hotel code: ");
        scanf("%d",&code);

        if(link->code==code)
        {
            if(link->next == NULL)
            {
                free(link);
                total--;
                flag++;
            }
            else
            {
                tmp=head;
                head=head->next;
                free(tmp);
                total--;
                flag++;
            }
        }
        else
        {
            while(post != NULL)
            {
                if(post->code == code)
                {
                    tmp=post->next;
                    free(post);
                    link->next=tmp;
                    flag=1;
                    total--;
                    break;
                }
                else
                {
                    link=link->next;
                    post=post->next;

                }


            }
            if(flag==0)
            {
                printf("Item does not exists...\n");
                printline();
            }
            else
            {
                printf("Successfully deleted...\n");
                printline();
            }
        }
    }

}

void hotellist(struct hotel* link)
{
    printline();
    int option;
    if(total==0)
    {
        printf("\nSorry !! No items found. Please add any hotel first\n");
    }
    else
    {
        printf("CODE    DISTRICTNAME    HOTELNAME        AVAILABLE       RENT         AMOUNT\n");
        while(link!=NULL)
        {
            printf("%d         %s             %s                %d          %.2f         %d\n",link->code,link->dname,link->name,link->available,link->rent,link->amount);
            link=link->next;
        }
        printf("\n 1.BOOking room\n 2.Return to Main menu\nEnter your choice: ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("Enter hotel code:");
            scanf("%d",&option);
            bookinghotel(option);
            break;
        case 2:
            return;
        default:
            printf("Invalid input....\n");
        }
    }
    printline();
    return ;
}

void search(struct hotel *link)
{
    printline();
    int option,code;
    if(total==0)
    {
        printf("Sorry List is empty....\n");
    }
    else
    {
        printf("Enter hotel code: ");
        scanf("%d",&code);
        while(link != NULL)
        {
            if(link->code==code)
            {
                printf("Search hotel is found...\n\n");
                printf("CODE    NAME       AVAILABLE    RENT    AMOUNT\n");
                printf("%d\t%s\t%d\t%.2f TK\t%d\n\n",link->code,link->name,link->available,link->rent,link->amount);
                printf(" 1.BOOKING\n 2.Search again\n 0.Exit\nEnter your choice: ");
                scanf("%d",&option);
                switch(option)
                {
                case 1:
                    printf("Enter amount of room which you want??:");
                    scanf("%d",&option);

                    if(link->amount==0)
                    {
                        printf("room not available...\n");
                        printline();
                    }
                    else if(option>(link->amount))
                    {
                        printf("%d room not available\n",option);
                    }
                    else
                    {

                        link->amount=(link->amount-option);
                        total_rent=(total_rent+(option*(link->rent)));
                    }

                    break;
                case 2:
                    search(head);
                    break;
                case 0:
                    return;
                default:
                    printf("Invalid input !!! Try again...\n");


                }

            }
            else
            {
                link=link->next;
            }
        }
    }

    printline();
}

void bookinghotel(int code)
{
    int x;
    struct hotel *link=head;
    if(total==0)
    {
        printf("Sorry no hotel in the list !!!\n");
        printline();
    }
    else
    {
        while(link!=NULL)
        {
            if(link->code==code)
            {
                printf("Enter amount of  room do u want\n");
                scanf("%d",&x);

                if(x>(link->amount))
                {
                    printf("%d room not available\n",x);
                }
                else
                {
                    link->amount=(link->amount)-x;
                    total_rent=(total_rent+(link->rent*x));
                    break;
                }

            }

            else
            {
                link=link->next;
            }
        }
    }

    printline();
}

void rent()
{

    char tmp,date[15],cname[20],phone[12],ldate[15];
    scanf("%c",&tmp);
    if(total_rent==0)
    {
        printline();
        printf("Please booked a room first ...\n");
        printline();
        return;
    }
    else
    {
        printline();
        printf("Enter the booking Date(dd-mm-yyyy): ");
        gets(date);
        printf("Enter the leaving Date(dd-mm-yyyy): ");
        gets(ldate);

        printf("Enter the name of Customer: ");
        gets(cname);

        printf("Enter the Phone number of customer: ");
        gets(phone);

        printf("\n\n************* Wel - Come *****************\n");
        printf("\nDate: %s",date);
        printf("\nleaving Date:%s",ldate);
        printf("\nCustomer name: %s",cname);
        printf("\nPhone number: %s",phone);
        printf("\nYour Total Rent is =  %.2f Taka only.",total_rent);
        printf("\n\n************** Thank you ****************\n");
        return;
    }
}

void printline()
{
    int i;
    for(i=0; i<50; i++)
    {
        printf("*");
    }
    printf("\n");
    return;
}

int adminvalidate()
{
    char ch;
    char nm[15]="tania";
    char pass[15]="admin";
    int i=0;

    printf("Enter password : ");
    while (1)
    {
        ch=getch();
        if(ch == 13)
        {
            break;
        }
        else if(ch==8||ch==127)
        {
            putch('\b');
            putch(NULL);
            putch('\b');
            i--;
            continue;
        }
        password[i]= ch;
        i++;
        ch = '*';
        putch(ch);
    }
    password[i] = '\0';
    if(strcmp(password,pass)==0)
    {
        printf("\n");
        printline();
        return 1;

    }
    else
    {
        printf("\n");
        printline();
        return 0;
    }
}

int main()
{
    system("COLOR 0A");
    printf("======Welcome to our Hotel======\n");

    head=(struct hotel*)malloc(sizeof(struct hotel));
    head->next=NULL;
    int reg;
    printf("1.registration\n");
    scanf("%d",&reg);
    switch(reg)
    {
    case 1:
        registration();
        break;
    default:
        printf("registration first");
        registration();
        break;
    }

    while(1)
    {

        int op;
        printf("1.Login mode\n2.Admin mode\n0.Exit\nEnter your choice: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            user();
            break;
        case 2:


            while(1)
            {
                int option;

                printf("\n=======MENU=======\n");

                printf("1.Admin panel\n    0.Exit\nEnter your choice: ");
                scanf("%d",&option);
                switch(option)
                {

                case 1:
                    if(adminvalidate()== 1)
                    {
                        adminpanel();
                    }
                    else
                    {
                        printf("Incorrect password...\n\n");
                        printline();
                    }
                    break;



                case 0:
                    return 0;
                default:
                    printf("\nInvalid input!!!\n");
                }
                break;

            case 0:
                return 0;
            default:
                printf("\ninvalid input\n");
            }
        }
    }



    return 0;

}
