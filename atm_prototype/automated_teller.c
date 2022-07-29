#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
/**
 * description: automatatic teller machine using c programming language
 * its functionalities includes 1.withdrawal
 *                              2.transfer
 *                              3.balance enquiry
 *                              4.deposit
 */
//global variable and unions
struct User
    {
        char User_id[10];
         double balance;
    };
char filename[50];

//function declarations
int Grant_Access(void);
int Transaction(void);
int welcome();

int main()
{
    char cont = 'y';
    welcome();
    printf("PROCEED:  [Y/N]");
    scanf("%c",&cont);

    while (cont == 'y')
    {
        Grant_Access();
    }

    return (0);
}
/**
 * Grant_Access - gives permission to the user to interact with the machine
 * Return: returns 0 if succesful
 */
int Grant_Access(void)
{
    FILE *fpr;
    struct User User1;
    printf("ENTER YOUR ACCOUNT NUMBER\n");
    scanf("%s",User1.User_id);
    User1.balance = 0.00;

    strcpy(filename,User1.User_id);
    fpr = fopen(strcat(filename, ".txt"), "w");

    fwrite(&User1, sizeof(struct User), 1, fpr);
    fclose(fpr);
    if (fwrite != NULL)
    {
        printf("THIS IS YOUR PIN: %s\n",User1.User_id);
        char pin[10];
        printf("ENTER THE PIN TO ACCESS THE MACHINE\n");
        scanf("%s",pin);
        strcpy(filename, pin);
        fpr = fopen(strcat(filename, ".txt"),"r");
        if (fpr != NULL)
        {
            fread(&User1, sizeof(struct User), 1, fpr);
            fclose(fpr);
            if (!strcmp(pin, User1.User_id))
            {
                printf("YOUR WELCOME %s\n",User1.User_id);
            }
        }
        else
        {
            printf("INCORRECT PIN\n");
            EXIT_FAILURE;
        }

    }
    Transaction();
  
    
}
/**
 * Transaction - performs all the transactional operation of the machine
 *Return: returns 0 if successful
 */
int Transaction(void)
{
    struct User User1,User2;
    FILE *fpr;
    char cont = 'y';
    int choice,amount,balance,choice1;
    char pin[10],phone[11];
   
    while (cont == 'y')
    {
        printf("SELECT TO PERFORM TRANSACTION\n");
        printf("1.BALANCE ENQUIRY\n");
        printf("2.WITHDRAWAL\n");
        printf("3.DEPOSIT\n");
        printf("4.ONLINE TRANSFER\n");
        printf("5.RECHARGE YOUR PHONE\n");
        printf("6.REMOVE CARD\n");
        printf("\nSELECT YOUR TRANSACTION MODE:\t\t");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
        //     struct tm* local;
        //     time_t t = time(NULL);
        //     local = localtime(&t);
  
        //     printf("Local time and date: %s\n",
        //    asctime(local));
            break;
        case 2:
            printf("CHOOSE YOUR AMOUNT TO WITHDRAW\n");
            printf("1.=> 5000\n");
            printf("2.=> 10000\n");
            printf("3.=> 15000\n");
            printf("4.=> 20000\n");
            printf("5.=> OTHERS\n");
            printf("YOUR CHOICE :\t\t");
            scanf("%d",&choice1);
            switch (choice1)
            {
            case 1:
                if (User1.balance >= 5000)
                {
                    User1.balance -= 5000;
                    fpr = fopen(filename, "w");
                    fwrite(&User1, sizeof(struct User), 1, fpr);
                    if (fwrite != NULL)
                    {
                           printf("YOU WITHDRAWAL IS SUCCESSFUL AND YOUR CURRENT ACC. BALANCE IS $%.2lf\n",User1.balance);
                           fclose(fpr);
                    }
                    else
                    {
                        printf("ERROR......CARD SWALLOWED");
                    }
                }
                else
                {
                    printf("INSUFFICIENT BALANCE\n");

                }
            
                break;
            case 2:
                if (User1.balance >= 10000)
                {
                    User1.balance -= 10000;
                    fpr = fopen(filename, "w");
                    fwrite(&User1, sizeof(struct User), 1, fpr);
                    if (fwrite != NULL)
                    {
                            printf("YOU WITHDRAWAL IS SUCCESSFUL AND YOUR CURRENT ACC. BALANCE IS $%.2lf\n",User1.balance);
                            fclose(fpr);
                    }
                    else
                    {
                        printf("ERROR......CARD SWALLOWED");
                    }
                }
                else
                {
                    printf("INSUFFICIENT BALANCE\n");

                }
            
                break;
            case 3:
                if (User1.balance >= 15000)
                {
                    User1.balance -= 15000;
                    fpr = fopen(filename, "w");
                    fwrite(&User1, sizeof(struct User), 1, fpr);
                    if (fwrite != NULL)
                    {
                           printf("YOU WITHDRAWAL IS SUCCESSFUL AND YOUR CURRENT ACC. BALANCE IS $%.2lf\n",User1.balance);
                           fclose(fpr);
                    }
                    else
                    {
                        printf("ERROR......CARD SWALLOWED");
                    }
                }
                else
                {
                    printf("INSUFFICIENT BALANCE\n");

                }
            
                break;
            case 4:
                if (User1.balance >= 20000)
                {
                    User1.balance -= 20000;
                    fpr = fopen(filename, "w");
                    fwrite(&User1, sizeof(struct User), 1, fpr);
                    if (fwrite != NULL)
                    {
                           printf("YOU WITHDRAWAL IS SUCCESSFUL AND YOUR CURRENT ACC. BALANCE IS $%.2lf\n",User1.balance);
                           fclose(fpr);
                    }
                    else
                    {
                        printf("ERROR......CARD SWALLOWED");
                    }
                }
                else
                {
                    printf("INSUFFICIENT BALANCE\n");

                }
            
                break;
            case 5:
                printf("ENTER YOUR DESIRED AMOUNT:\t\t");
                scanf("%d",&balance);
                if (User1.balance >= balance)
                {
                    User1.balance -= balance;
                    fpr = fopen(filename, "w");
                    fwrite(&User1, sizeof(struct User), 1, fpr);
                    if (fwrite != NULL)
                    {
                           printf("YOU WITHDRAWAL IS SUCCESSFUL AND YOUR CURRENT ACC. BALANCE IS $%.2lf\n",User1.balance);
                           fclose(fpr);
                    }
                    else
                    {
                        printf("ERROR......CARD SWALLOWED");
                    }
                }
                else
                {
                    printf("INSUFFICIENT BALANCE\n");

                }
            
                break;
            default:
                printf("OUT OF CONTEXT");
                break;
            }
            break;
        case 3:
            printf("ENTER THE AMOUNT\t\t");
            scanf("%d",&amount);
            User1.balance += amount;
            fpr = fopen(filename, "w");
            fwrite(&User1, sizeof(struct User), 1, fpr);
            if (fwrite != NULL)
            {
                printf("YOU TRANSACTION IS SUCCESSFUL\n");
                printf("YOUR CURRENT BALANCE: %.2lf\n\n",User1.balance);
            }
            else
            {
                printf("UNSUCCEFUL TRANSACTION TRY AGAIN");
            }
            break;
        case 4:
            printf("ENTER RECIPIENT ACC. NUMBER:\t\t");
            scanf("%s",pin);
            printf("\nENTER AMOUNT:\t\t\t");
            scanf("%d",&amount);
            if (User1.balance < amount)
            {
                printf("INSUFFICIENT ACCOUNT BALANCE\n");
            }
            else
            {
                strcpy(filename,pin);
                fpr = fopen(strcat(filename, ".txt"), "w");
                fread(&User2, sizeof(struct User), 1, fpr);
                fclose(fpr);
                fpr = fopen(filename, "w");
                User2.balance += amount;
                fwrite(&User2, sizeof(struct User), 1, fpr);
                fclose(fpr);
                if (fwrite != NULL)
                {
                    printf("YOU TRANSACTION IS SUCCESSFUL\n");
                    printf("YOU TRANSFERED %d TO %s\n",amount,pin);
                    User1.balance -= amount;
                    printf("YOUR ACC. BALANCE :  %lf\n",User1.balance);
                    strcpy(filename,User1.User_id);
                    fpr = fopen(strcat(filename, ".txt"), "w");
                    fwrite(&User1, sizeof(struct User), 1, fpr);
                    User1.balance -= amount;
                    fclose(fpr);
                }
            }
            break;
        case 5:
          printf("ENTER PHONE NO:\t ");
          scanf("%s", phone);
          printf("ENTER AMOUNT \t: ");
          scanf("%d", &amount);
          fpr = fopen(filename, "w");
          fwrite(&User1, sizeof(struct User), 1, fpr);
          User1.balance -= amount;
          fclose(fpr);
          printf("YOUR ACCOUNT HAS BEEN DEBITED $%d AND ACCOUNT BALNCE: $%.2lf\n", amount,User1.balance);
          break;
        case 6:
            welcome();
            cont = 'n';
            break;
        default:
            printf("OUT OF CONTEXT");
            break;
        }
        
    }
    return (0);
}

int welcome()
{
    printf("WELCOME TO **** BANK\n");
    // time_t t = time(NULL);
    // struct tm tm  = *localtime(&t);

    // printf("%d-%02d-%02d-%02d-%02d-%02d\n",tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour,tm.tm_min, tm.tm_sec);
    printf("A REPUTABLE BANK MADE WITH COMMON PEOPLE IN HEART\n");
    printf("INSERT YOUR CARD FOR TRANSACTIONS\n");
    return (0);
}