#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int yes=1, choice;
char upass[100];
char cpass[100];

int top=-1,stack[100];

///
FILE *fp;
struct info
{

    char name[30];
    char address[30];
    char acc[30];
    char date[15];
    char bdt[15];
    char nid[30];
    char phone[20];
    int age;
    double balance;
    struct info *next;

};
typedef struct info node;

/// required function
void header_design();
void showMenu();
void create();
int home();
node *read();
void customar_list(node *head);
int information(node *head);
void write(node *head);
int update(node *head);
int transactions(node *head);
int deletion(node *head);
void upper_string(char s[]);  ///for name make uppercase
void skull();


///
void skull()
{
        printf("                   uuuuuuu\n");
        printf("               uu$$$$$$$$$$$uu\n");
        printf("             uu$$$$$$$$$$$$$$$$$uu\n");
        printf("            u$$$$$$$$$$$$$$$$$$$$$u\n");
        printf("           u$$$$$$$$$$$$$$$$$$$$$$$u\n");
        printf("          u$$$$$$$$$$$$$$$$$$$$$$$$$u\n");
        printf("          u$$$$$$$$$$$$$$$$$$$$$$$$$u\n");
        printf("          u$$$$$$\"   \"$$$\"   \"$$$$$$u\n");
        printf("          \"$$$$\"      u$u       $$$$\"\n");
        printf("           $$$u       u$u       u$$$\n");
        printf("           $$$u      u$$$u      u$$$\n");
        printf("            \"$$$$uu$$$   $$$uu$$$$\"\n");
        printf("             \"$$$$$$$\"   \"$$$$$$$\"\n");
        printf("               u$$$$$$$u$$$$$$$u\n");
        printf("                u$\"$\"$\"$\"$\"$\"$u\n");
        printf("     uuu        $$u$ $ $ $ $u$$       uuu\n");
        printf("     u$$$$        $$$$$u$u$u$$$       u$$$$\n");
        printf("      $$$$$uu      \"$$$$$$$$$\"     uu$$$$$$\n");
        printf("    u$$$$$$$$$$$uu    \"\"\"\"\"    uuuu$$$$$$$$$$\n");
        printf("    $$$$\"\"\"$$$$$$$$$$uuu   uu$$$$$$$$$\"\"\"$$$\"\n");
        printf("     \"\"\"      \"\"$$$$$$$$$$$uu \"\"$\"\"\"\n");
        printf("               uuuu \"\"$$$$$$$$$$uuu\n");
        printf("      u$$$uuu$$$$$$$$$uu \"\"$$$$$$$$$$$uuu$$$\n");
        printf("      $$$$$$$$$$\"\"\"\"           \"\"$$$$$$$$$$$\"\n");
        printf("       \"$$$$$\"                      \"\"$$$$\"\"\n");
        printf("         $$$\"                         $$$$\"\n");

        printf("\t        Developed by gHoSt\n\n");
        printf("\nCopyright: 2017 - 2018 Ghost Ltd. All rights reserved. \n\n");

}
void header_design()
{
    printf("\n\n\n\t\t  \xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2 ");
    printf("\n                  \xb2\xb2      UNITED GROUP BANKING MANAGEMENT SYSTEM       \xb2\xb2  ");
    printf("\n\t\t  \xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2 ");
}

void showMenu()
{   printf("\n\n\n\t\t  \xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2 ");
    printf("\n                  \xb2\xb2      UNITED GROUP BANKING MANAGEMENT SYSTEM       \xb2\xb2  ");
    printf("\n                  \xb2\xb2             WELCOME TO THE MAIN MENU              \xb2\xb2  ");
    printf("\n\t\t  \xb2\xb2\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb2\xb2");
    printf("\n                  \xb2\xb2                                                   \xb2\xb2  ");
    printf("\n                  \xb2\xb2      1.Create New Account                         \xb2\xb2  ");
    printf("\n                  \xb2\xb2      2.Update Information of Existing Account     \xb2\xb2  ");
    printf("\n                  \xb2\xb2      3.For Transactions                           \xb2\xb2  ");
    printf("\n                  \xb2\xb2      4.Check the Details of Existing Account      \xb2\xb2  ");
    printf("\n                  \xb2\xb2      5.Removing Existing Account                  \xb2\xb2  ");
    printf("\n                  \xb2\xb2      6.View Customer's List                       \xb2\xb2  ");
    printf("\n                  \xb2\xb2      7.Exit                                       \xb2\xb2  ");
    printf("\n                  \xb2\xb2                                                   \xb2\xb2  ");
    printf("\n\t\t  \xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2 ");
}
int information(node *head)
{
    int True;
    do
    {
        True=1;
        //header_design();
        printf("\n\n\n\t\t  \xb2\xb2\xb2 Enter the Account number of the customer: ");
        gets(cpass);
        node *temp;
        temp=head;
        while(temp!=NULL)
        {
            if(strcmp(temp->acc,cpass) == 0)
            {
                //header_design();
                system("cls");
                printf("\n\t\t  \xb2\xb2\xb2 Registration date: ");
                printf("%s \n",temp->date);
                printf("\n\t\t  \xb2\xb2\xb2 Account number   : ");
                printf("%s \n",temp->acc);
                printf("\n\t\t  \xb2\xb2\xb2 Name             : ");
                printf("%s \n",temp->name);
                printf("\n\t\t  \xb2\xb2\xb2 Birth Date       : ");
                printf("%s \n",temp->bdt);
                printf("\n\t\t  \xb2\xb2\xb2 Age              : ");
                printf("%d \n",temp->age);
                printf("\n\t\t  \xb2\xb2\xb2 Address          : ");
                printf("%s \n",temp->address);
                printf("\n\t\t  \xb2\xb2\xb2 NID no           : ");
                printf("%s \n",temp->nid);
                printf("\n\t\t  \xb2\xb2\xb2 Phone number     : ");
                printf("%s \n",temp->phone);
                printf("\n\t\t  \xb2\xb2\xb2 Account Balance  : ");
                printf("%lf \n",temp->balance);
                printf("\t\t----------------------------------------");

                return home();
            }
            temp=temp->next;
        }
        printf("\n\n\t\t  \xb1\xb1The Account does not exist !!!");
        Sleep(1500);
        system("cls");
        header_design();
        printf("\n\n\n\t\t  \xb2\xb2\xb2 Press 1 to try again,Press 2 to go home,Press 0 to exit \xb2\xb2\xb2");
        printf("\n\n\t\t  \xb2\xb2 Enter your choice: ");
        scanf("%d",&choice);
        fflush(stdin);
        if(choice==1)
        {
            system("cls");
        }
        else if(choice==2)
        {
            system("cls");
            return 2;
        }
        else if(choice==0)
        {
            system("cls");
            printf("\n\t\t       Developed by gHoSt\n\n");
            skull();
            Sleep(2000);
            exit(0);
        }
    }
    while(True==1);

}

void customar_list(node *head)
{
    node *temp;
    temp=head;
    //design
    if(head==NULL)
    {   header_design();
        printf("\n\n\n\t\t  \xb2\xb2\xb2 Customer list is empty !!\n\n");
    }
    else
    {
        //header_design();
        printf("\n\n\n  \xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1 \n");
        printf("    \n     A/C Number \t    Account Name \t    Address \t    Phone Number      \n");

        for(int i = 0; i<2; i++)
        {
            printf("   ");
            for(int j = 0; j<81; j++)
            {
                printf("-");
            }
            printf("\n");
        }
        while(temp!=NULL)
        {
            printf("\n");
            printf("      %s\t",temp->acc);
            printf("  \t    %s\t",temp->name);
            printf("            %s\t",temp->address);
            printf("    %s\t",temp->phone);
            printf("\n");
            temp=temp->next;
        }
        printf("\n\n  \xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1 \n");
        printf("\n\n\n");
    }

}

node* read()
{

    node *start=NULL,*point,*temp1;

    fp=fopen("record.txt","r");

    node *temp;
    temp=new node();
    temp->next=NULL;
    char p;
    int c;
    while ( (c=fgetc(fp)) != EOF )
    {
        fscanf(fp,"%c ",&p);
        fscanf(fp,"%s ",temp->date);
        fscanf(fp,"%s ",temp->acc);
        fscanf(fp,"%s ",temp->name);
        fscanf(fp,"%s ",temp->bdt);
        fscanf(fp,"%d ",&temp->age);
        fscanf(fp,"%s ",temp->address);
        fscanf(fp,"%s ",temp->nid);
        fscanf(fp,"%s ",temp->phone);
        fscanf(fp,"%lf ",&temp->balance);

        if(start==NULL)
        {
            start=new node();
            start->next=NULL;
            strcpy(start->date,temp->date);
            strcpy(start->acc,temp->acc);
            strcpy(start->name,temp->name);
            strcpy(start->bdt,temp->bdt);
            strcpy(start->address,temp->address);
            strcpy(start->nid,temp->nid);
            strcpy(start->phone,temp->phone);
            start->age=temp->age;
            start->balance=temp->balance;

            point=start;

        }
        else
        {
            temp1=new node();
            temp1->next=NULL;
            strcpy(temp1->date,temp->date);
            strcpy(temp1->acc,temp->acc);
            strcpy(temp1->name,temp->name);
            strcpy(temp1->bdt,temp->bdt);
            strcpy(temp1->address,temp->address);
            strcpy(temp1->nid,temp->nid);
            strcpy(temp1->phone,temp->phone);
            temp1->age=temp->age;
            temp1->balance=temp->balance;

            point->next=temp1;
            point=temp1;

        }
    }
    fclose(fp);

    return start;
}
void upper_string(char s[])
{
   int c = 0;

   while (s[c] != '\0') {
      if (s[c] >= 'a' && s[c] <= 'z') {
         s[c] = s[c] - 32;
      }
      c++;
   }
}
void create()
{
    node *temp;
    temp=new node();
    temp->next=NULL;
    system("cls");

    header_design();
    printf("\n\t\t\t\t      ---ADD RECORD---\n");
    fp=fopen("record.txt","a");
    fprintf(fp,". ");
    printf("\n\n");

    printf("\t\t  \xb1\xb1 Enter Today's Date(mm/dd/yyyy): ");
    gets(temp->date);
    fflush(stdin);
    fprintf(fp,"%s ",temp->date);
    printf("\n");

    printf("\t\t  \xb1\xb1 Enter the Account Number : ");
    gets(temp->acc);
    fflush(stdin);
    fprintf(fp,"%s ",temp->acc);
    printf("\n");

    printf("\t\t  \xb1\xb1 Enter the Name : ");
    gets(temp->name);
    fflush(stdin);
    upper_string(temp->name);  //uppercase for name
    fprintf(fp,"%s ",temp->name);
    printf("\n");

    printf("\t\t  \xb1\xb1 Enter the Date Of Birth(mm/dd/yyyy) : ");
    gets(temp->bdt);
    fflush(stdin);
    fprintf(fp,"%s ",temp->bdt);
    printf("\n");

    printf("\t\t  \xb1\xb1 Enter the Age : ");
    scanf("%d",&temp->age);
    fflush(stdin);
    fprintf(fp,"%d ",temp->age);
    printf("\n");

    printf("\t\t  \xb1\xb1 Enter the Address : ");
    gets(temp->address);
    fflush(stdin);
    fprintf(fp,"%s ",temp->address);
    printf("\n");

    printf("\t\t  \xb1\xb1 Enter the NID number : ");
    gets(temp->nid);
    fflush(stdin);
    fprintf(fp,"%s ",temp->nid);
    printf("\n");

    printf("\t\t  \xb1\xb1 Enter the Phone number : ");
    gets(temp->phone);
    fflush(stdin);
    fprintf(fp,"%s ",temp->phone);
    printf("\n");

    printf("\t\t  \xb1\xb1 Enter the amount to Deposit : BDT  : ");
    scanf("%lf",&temp->balance);
    fflush(stdin);
    fprintf(fp,"%lf",temp->balance);
    printf("\n");

    fprintf(fp,"\n\n");

    fclose(fp);
    printf("\n\n\t\t  \xb2\xb2\xb2 Account created successfully!.....\xb2\xb2\xb2\n\n");

}
int home()
{
    int True;
    do
    {
        True=1;
        printf("\n\n\t\t  \xb2\xb2\xb2 Enter 1 to go to main menu and 0 to exit. \xb2\xb2\xb2\n\n");
        int choice;
        printf("\n\n\t\t  \xb2\xb2\xb2 Enter your choice : ");
        scanf("%d",&choice);
        if(choice == 1)
        {
            system("cls");
            return 2;

        }
        else if(choice==0)
        {
            system("cls");
            printf("\n\t      Developed by gHoSt\n\n");
            skull();
            Sleep(2000);
            exit(0);
        }
        else
        {
            system("cls");
            printf("Invalid Choice !!!");
            Sleep(1000);
            system("cls");
        }
    }
    while(True==1);
}
void write(node *head)
{

    fp=fopen("record.txt","w");
    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        fprintf(fp,". ");
        fprintf(fp,"%s ",temp->date);
        fprintf(fp,"%s ",temp->acc);
        fprintf(fp,"%s ",temp->name);
        fprintf(fp,"%s ",temp->bdt);
        fprintf(fp,"%d ",temp->age);
        fprintf(fp,"%s ",temp->address);
        fprintf(fp,"%s ",temp->nid);
        fprintf(fp,"%s ",temp->phone);
        fprintf(fp,"%lf ",temp->balance);
        fprintf(fp,"\n");

        temp=temp->next;
    }
    fclose(fp);

}

int update(node *head)
{
    int True;
    do
    {
        True=1;

        printf("\n\n\t\t  \xb2\xb2\xb2 Enter the Account number of the customer: ");
        gets(cpass);
        node *temp;
        temp=head;
        while(temp!=NULL)
        {
            if(strcmp(temp->acc,cpass) == 0)
            {
                //design
                system("cls");
                header_design();
                printf("\n\n\t\t\t\tWhat do you want to update? \n\n\n\t\t  \xb2\xb2\xb2 1.Address\n\n\n\t\t  \xb2\xb2\xb2 2.phone number\n\n\n\t\t  \xb2\xb2\xb2 3.Name\n\n\n\t\t  \xb2\xb2\xb2 4.NID number\n\n\n\t\t  \xb2\xb2\xb2 5.Birth Date\n\n\n\t\t  \xb2\xb2\xb2 Press any other key to go home\n\nEnter your choice: ");
                scanf("%d",&choice);
                fflush(stdin);
                if(choice==1)
                {
                    system("cls");
                    header_design();
                    printf("\n\n\t\t  \xb2\xb2\xb2 Enter new address : ");
                    gets(temp->address);
                    fflush(stdin);
                    write(head);
                    printf("\n\n\n\t\t  \xb2\xb2\xb2 Address has been updated !!\n");
                }

                else if(choice==2)
                {
                    system("cls");
                    header_design();
                    printf("\n\n\n\t\t  \xb2\xb2\xb2 Enter new phone number : ");
                    gets(temp->phone);
                    fflush(stdin);
                    write(head);
                    printf("\n\n\n\t\t  \xb2\xb2\xb2 Phone number has been updated !!\n");
                }

                else if(choice==3)
                {
                    system("cls");
                    header_design();
                    printf("\n\n\n\t\t  \xb2\xb2\xb2 Enter correct name : ");
                    gets(temp->name);
                    fflush(stdin);
                    write(head);
                    printf("\n\n\n\t\t  \xb2\xb2\xb2 Name has been  updated !!\n");
                }

                else if(choice==4)
                {
                    system("cls");
                    header_design();
                    printf("\n\n\n\t\t  \xb2\xb2\xb2 Enter correct NID number : ");
                    gets(temp->nid);
                    fflush(stdin);
                    write(head);
                    printf("\n\n\n\t\t  \xb2\xb2\xb2 NID number has been  updated !!\n");
                }

                else if(choice==5)
                {
                    system("cls");
                    header_design();
                    printf("\n\n\n\t\t  \xb2\xb2\xb2 Enter correct Birth Date : ");
                    gets(temp->bdt);
                    fflush(stdin);
                    write(head);
                    printf("\n\n\n\t\t  \xb2\xb2\xb2 Birth Date has been  updated !!\n");
                }

                else
                {
                    return 2;
                }
                return home();
            }
            temp=temp->next;
        }
        printf("\n\n\t\t  \xb1\xb1The Account does not exist !!!");
        Sleep(1500);
        system("cls");
        header_design();
        printf("\n\n\n\t\t  \xb2\xb2\xb2 Press \"1\" to try again,Press \"2\" to go home,Press \"0\" to exit");
        printf("\n\n\n\t\t  \xb2\xb2\xb2 Enter your choice: ");
        scanf("%d",&choice);
        fflush(stdin);
        if(choice==1)
        {
            system("cls");
        }
        else if(choice==2)
        {
            system("cls");
            return 2;
        }
        else if(choice==0)
        {
            system("cls");
            header_design();
            printf("\n\n\n\t\t  \xb2\xb2\xb2 Developed by gHoSt\n\n");
            skull();
            Sleep(2000);
            exit(0);
        }
    }
    while(True==1);

}
int transactions(node *head)
{
    int True;
    do
    {
        True=1;
        printf("\n\n\n\t\t  \xb2\xb2\xb2 Enter the Account number of the customer: ");
        gets(cpass);
        node *temp;
        temp=head;
        while(temp!=NULL)
        {
            if(strcmp(temp->acc,cpass) == 0)
            {
                //design
                system("cls");
                header_design();
                printf("\n\n\n\t\t\t  \xb2\xb2 Your Current Balance is: %lf \xb2\xb2\n",temp->balance);
                printf("\t                    ------------------------------------");
                printf("\n\n\n\t\t  \xb2\xb2\xb2 What do you want to do? \n\n\n\t\t  \xb2\xb2\xb2 1.Deposit\n\n\n\t\t  \xb2\xb2\xb2 2.Withdraw\n\n\n\t\t  \xb2\xb2\xb2 Press any other key to go home\n\n\n\t\t  \xb2\xb2\xb2 Enter your choice : ");
                scanf("%d",&choice);
                fflush(stdin);
                if(choice==1)
                {

                    printf("\n\n\n\t\t  \xb2\xb2\xb2 Enter how much money you want to Deposit : ");
                    double x;
                    scanf("%lf",&x);
                    fflush(stdin);
                    temp->balance=temp->balance+x;
                    printf("\n\n\n\t\t          \xb2\xb2\xb2 Now your updated balance is %lf BDT\xb2\xb2\n",temp->balance);
                    printf("\t                     -------------------------------------------");
                    write(head);

                }
                else if(choice==2)
                {

                    printf("\n\n\n\t\t  \xb2\xb2\xb2 Enter how much money you want to Withdraw : ");
                    double x;
                    scanf("%lf",&x);
                    fflush(stdin);
                    temp->balance=temp->balance-x;
                    printf("\n\n\n\t\t          \xb2\xb2\xb2 Now your updated balance is %lf BDT\xb2\xb2\n",temp->balance);
                    printf("\t                     --------------------------------------------");
                    write(head);

                }
                else
                {
                    return 2;
                }
                return home();
            }
            temp=temp->next;
        }
        printf("\n\n\xb1\xb1 The Account does not exist !!!");
        Sleep(1500);
        system("cls");
        printf("\n\n\n\t\t  \xb2\xb2\xb2 Press 1 to try again,Press 2 to go home,Press 0 to exit");
        printf("\n\n\n\t\t  \xb2\xb2\xb2 Enter your choice: ");
        scanf("%d",&choice);
        fflush(stdin);
        if(choice==1)
        {
            system("cls");
        }
        else if(choice==2)
        {
            system("cls");
            return 2;
        }
        else if(choice==0)
        {
            system("cls");
            printf("\n\t      Developed by gHoSt\n\n");
            skull();
            Sleep(2000);
            exit(0);
        }
    }
    while(True==1);
}

int deletion(node *head)
{
    int True;
    do
    {
        True=1;
        printf("\n\n\n\t\t  \xb2\xb2\xb2 Enter the Account number of the customer: ");
        gets(cpass);
        node *temp;
        temp=head;
        while(temp!=NULL)
        {
            if(strcmp(temp->acc,cpass) == 0)
            {
                //design
                system("cls");
                if(head->next==NULL)
                {
                    head=NULL;
                    delete(head);
                }
                else
                {
                    if(temp==head)
                    {
                        head=head->next;
                        delete(temp);
                    }
                    else
                    {
                        node *temp1;
                        temp1=head;
                        while(temp1->next!=temp)
                        {
                            temp1=temp1->next;
                        }
                        temp1->next=temp->next;
                        delete(temp);
                    }
                }
                write(head);
                printf("\n\n\n\t\t\t   \xb2\xb2\xb2 Deletion successful!! \xb2\xb2\xb2\n");
                return home();
            }
            temp=temp->next;
        }

        printf("\n\n\n\t\t  \xb2\xb2\xb2 The Account does not exist !!!");
        Sleep(1500);
        system("cls");
        printf("\n\n\n\t\t  \xb2\xb2\xb2 Press 1 to try again,Press 2 to go home,Press 0 to exit\n\n");
        printf("\n\n\n\t\t  \xb2\xb2\xb2 tEnter your choice: ");
        scanf("%d",&choice);
        fflush(stdin);
        if(choice==1)
        {
            system("cls");
        }
        else if(choice==2)
        {
            system("cls");
            return 2;
        }
        else if(choice==0)
        {
            system("cls");
            printf("\n\t      Developed by gHoSt\n\n");
            skull();
            Sleep(2000);
            exit(0);
        }
    }
    while(True==1);

}



int main ()
{
    int yes;
    node *head=NULL;
    do
    {
        yes=1;
        char user[100]="Srabon";
        char mpass[100] = "7349";
        header_design();
    printf("\n\n\n\t\t                  \xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1 ");
    printf("\n                                  \xb1      LOGIN       \xb1  ");
    printf("\n\t\t                  \xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1 \n");

        printf(" \n\t\t\t\t  Username: ");
        gets(upass);

        printf("\n\t\t                  Password: ");
        gets(cpass);

        if((strcmp(user,upass) == 0) && (strcmp(mpass,cpass)==0))
        {
            printf("\n\n\n\t\t\t          PASSWORD MATCHED!\n\t\t\t          LOADING");
            for(int p=0; p<=10; p++)
            {
                printf(".");
                Sleep(250);
            }
            do
            {
                system("cls");
                yes=2;
                showMenu();
                printf("\n\n\n\n\n                          Enter choice: ");
                scanf("%d",&choice);
                fflush(stdin);
                if(choice== 1)
                {
                    system("cls");
                    header_design();
                    create();
                    yes=home();

                }
                else if(choice==2)
                {
                    system("cls");
                    header_design();
                    head=read();
                    yes=update(head);
                }
                else if(choice==3)
                {
                    system("cls");
                    header_design();
                    head=read();
                    yes=transactions(head);
                }
                else if(choice==4)
                {
                    system("cls");
                    header_design();
                    head=read();
                    yes=information(head);

                }
                else if(choice==5)
                {
                    system("cls");
                    header_design();
                    head=read();
                    yes=deletion(head);

                }

                else if(choice==6)
                {
                    system("cls");
                    header_design();
                    head=read();
                    customar_list(head);
                    yes=home();
                }

                else if(choice==7)
                {
                    system("cls");
                    skull();
                    Sleep(2000);
                    exit(0);
                }


                else
                {
                    system("cls");
                    header_design();
                    printf("\n\n\n\t\t  \xb2\xb2\xb2 Invalid Choice !!!");
                    Sleep(1000);
                    system("cls");
                }
            }
            while(yes==2);

        }
        else
        {
            printf("\n\n\n\t\t  \xb2\xb2\xb2 Wrong Password!!...\n");
            printf("\n\n\n\t\t  \xb2\xb2\xb2 Enter 1 to try again Or 0 to Exit\n");

            printf("\n\n\n\t\t  \xb2\xb2\xb2 Enter choice: ");
            scanf("%d",&choice);
            fflush(stdin);
            if(choice==1)
            {
                system("cls");
            }
            else
            {
                system("cls");
                header_design();
                printf("\n\t      Developed by gHoSt\n\n");
                skull();
                Sleep(2000);
                exit(0);
            }
        }
    }
    while(yes==1);
    return 0;
}

