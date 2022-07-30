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
 *                              5.phone recharge
 */
//global variable and unions
struct User
    {
        char User_id[10];
         double balance;
         char user_pin[5];
         unsigned long int account;
    };
char filename[50];

//function declarations
int Grant_Access(void);
int Transaction(void);
int welcome();
int getAccountNumber();
char* substr(const char*,int,int);
int displaytime();

int main()
{
    char cont = 'y';
    welcome();
    printf("\nPROCEED:  [Y/N]\t\t");
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
    char pin[5];
    int i;
    printf("ENTER YOUR NAME \t\t");
    scanf("%s",User1.User_id);
    strcpy(filename,User1.User_id);
    fpr = fopen(strcat(filename, ".txt"), "r");
    if (fpr == NULL)
    {
            printf("\nOPEN AN ACCOUNT  WITH US\n\n");
            printf("\nENTER YOUR NAME\n");
            scanf("%s",User1.User_id);
            User1.balance = 0.00;
            User1.account = getAccountNumber();
            strcpy(filename,User1.User_id);
            fpr = fopen(strcat(filename, ".txt"), "w");
            fwrite(&User1, sizeof(struct User), 1, fpr);
            fclose(fpr);
            if (fwrite != NULL)
            {
                char account[11];
                sprintf(account,"%lu",User1.account);
                char* paccess = substr(account,0,4);
                for (i = 0; i < 5; i++)
                {
                    User1.user_pin[i] = *paccess;
                    paccess++;
                }
                
                printf("THIS IS YOUR PIN: %s\n",User1.user_pin);
                printf("ENTER THE PIN TO ACCESS THE MACHINE\t\t");
                for (i = 0; i < 5; i++)
                {
                    pin[i] = getchar();
                }
                strcpy(filename, User1.User_id);
                fpr = fopen(strcat(filename, ".txt"),"r");
                if (fpr != NULL)
                {
                    fread(&User1, sizeof(struct User), 1, fpr);
                    fclose(fpr);
                    if (!strcmp(pin, User1.user_pin))
                    {
                        printf("YOUR WELCOME %s\n",User1.User_id);
                        Transaction();
                    }
                    else
                    {
                        printf("INCORRECT PASSWORD\n");
                    }
                }
                else
                {
                    printf("INCORRECT PIN\n");
                    EXIT_FAILURE;
                }

            }
            else
            {
                printf("UNABLE TO REGISTER YOUR ACCOUNT NOW");
            }
        
    }
    else
    {
        
        printf("ENTER YOUR PIN:\t\t");
        for (i = 0; i < 5; i++)
        {
            pin[i] = getchar();
        }
        fread(&User1,sizeof(struct User), 1, fpr);
        fclose(fpr);
        printf("%s",pin);
        if (!strcmp(pin,User1.user_pin))
        {
            printf("YOUR WELCOME %s\n",User1.User_id);
            Transaction();
        }
        else
        {
            printf("INCORRECT PIN\n");
        }
    }

   
  
    
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
         displaytime();
           printf("\t\t%lf\t\t\n",User1.balance);
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
/**
 * welcome - this welcome the user to the visitor page of the machine before granting access to the secured features of the machine
 * Return: returns 0 if successful
 */
int welcome()
{
    printf("\n\tWELCOME TO XOXO BANK\t\t\n");
    time_t tm;
    time(&tm);
    printf("\n\t%s\t\n",ctime(&tm));
    printf("\nA REPUTABLE BANK MADE WITH COMMON PEOPLE IN HEART\n");
    printf("\nINSERT YOUR CARD FOR TRANSACTIONS\n");
    return (0);
}

/**
 * getAccountNumber - assignes an account number to a new user
 * Description: this function generate an account number to the first user of the machine as its not connected to a bank that generate an account number, but it will be updated soon;
 * Return: returns a generated account number when called
 */
int getAccountNumber()
{
  srand(time(0));
 unsigned long int accountNumber = rand();
  return (accountNumber);
}
char* substr(const char* src, int m,int n)
{
    int len = n - m;
    char* dest = (char*)malloc(sizeof(char) * (len + 1));
    int i;

    for(i = m; i < n && (*(src + 1) != '\0'); i++)
    {
        *dest = *(src + i);
        dest++;
    }
    *dest = '\0';
    return (dest - len);
}
int displaytime()
{
    time_t tm;
    time(&tm);
    printf("YOUR ACCOUNT BALANCE AS AT %s\n",ctime(&tm));
    return (0);
}