/* INNOVATIVE PROJECT
Title: ATM MANAGEMENT SYSTEM
SUBMITTED BY: PRADEEP SHARMA
ROLL NO: 2K20/A7/44
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

//User Defined Functions
int intro();
int home();
int login_for();
int end();
int banking();
int statement();
int dep();

//Main Code
int main()
{
    intro();
    return 0;
}
int intro ()//WELCOME
{   char ch;
    printf ("\033[0;32m");
    printf ("\n\n\n");
    printf ("\t\t\t\t * * *  ****  *      ****  ***   ***   ****\n");
    printf ("\t\t\t\t * * * *      *     *     *   * * * * *\n");
    printf ("\t\t\t\t * * * *****  *     *     *   * * * * *****\n");
    printf ("\t\t\t\t * * * *      *     *     *   * * * * *\n");
    printf ("\t\t\t\t  ***   ****  *****  ****  ***  * * *  ****\n");
    printf ("\n\n");
    printf ("\t\t\t\t=============================================\n");
    printf ("\t\t\t\t\t\t ATM MACHINE\n");
    printf ("\t\t\t\t=============================================\n");
    printf ("\nPress ENTER to continue...");
    scanf ("%c", &ch);
    if ( ch == 10)
    {
        home();
    }
    else
    {
        printf ("Wrong input!!!");
    }
}
int home()//HOME PAGE
 {
     int i,j,c;
     system("CLS");
     printf ("\033[0;33m");
     printf ("\n\n\t\t\t\t");
     for (i=0;i<12;i++)
     {
         printf ("=");
     }
     printf ("ATM MACHINE");
     for (j=0;j<12;j++)
     {
         printf ("=");
     }
     printf ("\n\n\t\t\t\t=============HOME PAGE=============\n\n");
     printf ("\t\t\t\t1. Login Page\n\n");
     printf ("\t\t\t\t2. Exit\n\n");
     printf ("Enter your choice <1-2> ");
     c = getch();
     if (c == '1')
     {
        login_for();
     }
     else if (c == '2')
     {
         end();
     }
     else
    {
        printf("Sorry!!! wrong input...Please insert your card again\n");
    }
 }
int login_for()//TASK SELESTION MENU
{
    int choice;
    system("CLS");
    printf ("\033[0;33m");
    printf ("\n\n");
    printf ("\t\t\t\t Select feature from the following:");
    printf ("\n\n");
    printf ("\t\t\t\t1. BANKING\n\n");
    printf ("\t\t\t\t2. STATEMENT\n\n");
    printf ("\t\t\t\t3. DEPOSIT\n\n");
    printf ("\t\t\t\t4. Back to home page\n\n");
    printf ("ENTER YOUR CHOICE <1-4> : \n");
    choice = getch();
    if (choice == '1')
    {
        banking();
    }
    else if (choice == '2')
    {
        statement();
    }
    else if (choice == '3')
    {
        dep();
    }
    else if (choice == '4')
    {
        home();
    }
    else
    {
        printf("Sorry!!! wrong input...Please insert your card again\n");
    }
}
int end()//AUTHOR'S DETAILS
{   
    system("CLS");
    printf ("\033[0;31m");
    printf ("\n\n\t\t\t THANK YOU FOR USING THIS SOFTWARE");
    printf ("\n\n");
    printf ("\t\t\t NAME             Roll No \n\n");
    printf ("\t\t\t PRADEEP SHARMA   2K20/A7/44 \n");
    printf ("\n\n");
    printf ("\t\t\t\t\t\t SUBMITTED TO: Ms. GULL KAUR\n");
    return 0;
}
int banking() //Its purpose is to withdraw money and to pin change
{

    int pin, n, choose, balance;
    system("CLS");
    FILE *fp;
    char array[256];
    printf ("\033[0;34m");
    printf("Enter PIN: ");
    scanf("%d", &pin); //Enter Your Pin here
    fp = fopen("atmmachine.txt", "r");

    for (int i = 0; i != EOF; i++)
    {
        fscanf(fp, "%s", array);
        n = atoi(array);
        if (pin == n)
        {
            fgets(array, 256, fp);
            printf("Balance: %s", array);
            break;
        }
    }
    fclose(fp);
    printf("\n\nChoose an Apropriate option from below");
    printf("\n1. Withdrawl\n2. Pin Change");
    choose = getch();
    if (choose == '1') //For Withdrawl
    {
        int choose_mode;
        printf("\n\nWhat is the mode of banking ");
        printf("\n1. Current\n2. Saving");
        choose_mode = getch();
        if (choose_mode == '1')
        {
            int amount;
            printf("\n\nEnter the Amount You want to withdraw < %d \n", atoi(array)-5000);
            scanf("%d", &amount);
            if (atoi(array)-amount > 5000)
            {
                printf("\n\nHere is your Money.\n\n");
                printf("\n\nBALANCE LEFT: %d\n",atoi(array)-amount);
            }
            else
            printf("NOT ENOUGH BALANCE");
        }
        else if (choose_mode == '2')
        {
            int amount;
            printf("\n\nEnter the Amount You want to withdraw < %d \n", atoi(array)-1000);
            scanf("%d", &amount);
            if (atoi(array)-amount > 1000)
            {
                printf("\n\nHere is your Money.\n\n");
                printf("\n\nBALANCE LEFT: %d\n",atoi(array)-amount);
            }
            else
            printf("NOT ENOUGH BALANCE");
        }
        end();
    }
    else if (choose == '2') //For PIN CHANGE
    {
        int pinchange;
        system("CLS");
        printf("\n\nEnter the new pin: ");
        scanf("%d", &pinchange);
        fp = fopen("atmmachine.txt", "a");
        fprintf (fp, "\n%d %s", pinchange, array);
        fclose(fp);
        char choose_;
        printf("\n\nYour PIN has been changed successfully!!!\nDo you want to continue(Y/N)?\n");
        scanf(" %c", &choose_);
        if (islower(choose_))
        {
            choose_ = toupper(choose_);
        }
        if (choose_ == 'Y')
        {
            printf("\n\t\tTHANK YOU!!!\n\nNow, access the data using New PIN\n");
            login_for();
        }
        else if (choose_ == 'N')
        {
            printf("OK\n");
            end();
        }
        else
        {
            printf("\nWrong Input!!!\n");
        }
    }
    else
    {
        printf("\n\nWrong Input!!!\nPlease Insert Your Card again!!!");
    }
    return 0;
}

int statement() //Its purpose is to print statement of entered pin
{
    int pin, n, choose, balance;
    system("CLS");
    FILE *fp;
    char array[256];
    printf ("\033[0;33m");
    printf("\n\nEnter PIN: ");
    scanf("%d", &pin);
    fp = fopen("atmmachine.txt", "r");

    for (int i = 0; i != EOF; i++)
    {
        fscanf(fp, "%s", array);
        n = atoi(array);
        if (pin == n)
        {
            fgets(array, 256, fp);
            printf("\n\nYour available balance: %s\n Take your reciept", array);
            break;
        }
    }
    fclose(fp);
    char choose_;
    printf("\n\nDo you want to continue(Y/N)?\n");
    scanf(" %c", &choose_);
    if (islower(choose_))
    {
        choose_ = toupper(choose_);
    }
    if (choose_ == 'Y')
    {
        login_for();
    }
    else if (choose_ == 'N')
    {
        printf("OK\n\nTHANK YOU!!!");
        end();
    }
    else
    {
      ;printf ("Wrong Input!!!\n\n");
    }
    return 0;
}

int dep() //Its purpose is to Deposit some money in bank
{
    int pin, deposit, n, choose, balance;
    system("CLS");
    FILE *fp;
    char array[256];
    printf ("\033[0;32m");
    printf("\n\nEnter PIN:");
    scanf("%d", &pin);
    fp = fopen("atmmachine.txt", "r");

    for (int i = 0; i != EOF; i++)
    {
        fscanf(fp, "%s", array);
        n = atoi(array);
        if (pin == n)
        {
            fgets(array, 256, fp);
            printf("\nYour Balance is %s", array);
            printf("\n\nEnter the amount you want to add:");
            scanf("%d", &deposit);
            printf("\n\nCongrats!!! Your deposit amount is added successfully!!!\n");
            printf ("Now,Your BALANCE is: %d", atoi(array)+deposit);
            break;
        }
    }
    fclose(fp);
    fp = fopen("atmmachine.txt", "a");
        fprintf(fp, "%d %d", pin, atoi(array)+deposit );
        fclose(fp);
    char choose_;
    printf("\nDo you want to continue(Y/N)?\n");
    scanf(" %c", &choose_);
    if (islower(choose_))
    {
        choose_ = toupper(choose_);
    }
    if (choose_ == 'Y')
    {
        login_for();
    }
    else if (choose_ == 'N')
    {
        printf("OK");
        end();
    }
    else
    {
        printf("Wrong Input!!!\n");
    }
    return 0;
}