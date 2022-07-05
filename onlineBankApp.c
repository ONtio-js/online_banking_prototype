// online bank app program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct which handles the details of the new customer

struct user
{
  char name[50];     // name of the customer
  char email[50];    // email of the customer
  char account[50];  // account number of the customer
  char phone[50];    // phone number of the customer
  char password[50]; // password tohis/her account
  float balance;     //  account balance of the customer
};
int getAccountNumber() // function to generate account number for a new account
{}
int changepassword() // function to change password
{}
void bankActivities()
{
  int option, choice, depositChoice;
  FILE *fp; // for writing and reading the files
  char filename[50], email[50], password[50], phone[20];
  char cont = 'y';
  float amount, depositAmount;
  struct user user1, user2;
  system("cls");
  printf("enter your email:  ");
  scanf("%s", &email);
  printf("enter your password:  ");
  scanf("%s", &password);
  strcpy(filename, email);
  fp = fopen(strcat(filename, ".txt"), "r");
  if (fp == NULL)
  {
    printf("account not registered");
  }
  else
  {

    fread(&user1, sizeof(struct user), 1, fp);
    fclose(fp);
    if (!strcmp(password, user1.password))
    {
      while (cont == 'y')
      {
        system("cls");
        printf("**************************** %s welcome to our bank ****************************\n\n", user1.name);
        printf("press 1: balance inquiry\n");
        printf("press 2: cash withdrawal\n");
        printf("press 3: deposit cash\n");
        printf("press 4: online transfer\n");
        printf("press 5: buy airtime\n");
        printf("press 6:log out\n\n");
        printf("\nselect:  ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
          system("cls");
          printf("your current balance is $%.2f\n", user1.balance);
          break;
        case 2:
          system("cls");
          printf("withdrawal amount: ");
          scanf("%f", &amount);
          if (amount > user1.balance)
          {
            printf("\ninsufficient balance\n");
            _beep(500, 700);
          }
          else
          {
            user1.balance -= amount;
            fp = fopen(filename, "w");
            fwrite(&user1, sizeof(struct user), 1, fp);
            if (fwrite != NULL)
            {
              printf("you have successfully withdrawn $%.2f\n", amount);
              fclose(fp);
            }
          }
          break;
        case 3:
          system("cls");
          printf("amount to deposit:\n\n");
          printf("1. $10000\n");
          printf("2. $15000\n");
          printf("3. $20000\n");
          printf("4. $25000\n");
          printf("5. $50000\n");
          printf("6. others\n");

          printf("select:  ");
          scanf("%d", &depositChoice);
          switch (depositChoice)
          {
          case 1:
            user1.balance += 10000;
            fp = fopen(filename, "w");
            fwrite(&user1, sizeof(struct user), 1, fp);
            if (fwrite != NULL)
            {
              printf("you have successfully deposited $10000.00");
              fclose(fp);
            }
            break;
          case 2:
            user1.balance += 15000;
            fp = fopen(filename, "w");
            fwrite(&user1, sizeof(struct user), 1, fp);
            if (fwrite != NULL)
            {
              printf("you have successfully deposited $15000.00");
              fclose(fp);
            }
            break;
          case 3:
            user1.balance += 20000;
            fp = fopen(filename, "w");
            fwrite(&user1, sizeof(struct user), 1, fp);
            if (fwrite != NULL)
            {
              printf("you have successfully deposited $20000.00");
              fclose(fp);
            }
            break;
          case 4:
            user1.balance += 25000;
            fp = fopen(filename, "w");
            fwrite(&user1, sizeof(struct user), 1, fp);
            if (fwrite != NULL)
            {
              printf("you have successfully deposited $25000.00");
              fclose(fp);
            }
            break;
          case 5:
            user1.balance += 50000;
            fp = fopen(filename, "w");
            fwrite(&user1, sizeof(struct user), 1, fp);
            if (fwrite != NULL)
            {
              printf("you have successfully deposited $50000.00");
              fclose(fp);
            }
            break;
          case 6:
            printf("enter amount:   ");
            scanf("%f", &amount);
            user1.balance += amount;
            fp = fopen(filename, "w");
            fwrite(&user1, sizeof(struct user), 1, fp);
            if (fwrite != NULL)
            {
              printf("you have successfully deposited $%.2f\n", amount);
              fclose(fp);
            }
            break;
          default:
            printf("invalid input");
            break;
          }
          break;
        case 4:
          system("cls");
          printf("enter a recipient email to tansfer the amount ");
          scanf("%s", &email);
          printf("enter amount: ");
          scanf("%f", &amount);
          if (amount > user1.balance)
          {
            printf("insufficient balance");
            _beep(500, 700);
          }
          else
          {
            strcpy(filename, email);
            fp = fopen(strcat(filename, ".txt"), "w");
            fread(&user2, sizeof(struct user), 1, fp);
            fclose(fp);
            fp = fopen(filename, "w");
            user2.balance += amount;
            fwrite(&user2, sizeof(struct user), 1, fp);
            fclose(fp);
            if (fwrite != NULL)
            {
              printf("you have successfully transfered %.2f to %s\n", amount, email);
              user1.balance -= amount;
              printf("your current balance : $ %.2f", user1.balance);
              strcpy(filename, user1.email);
              fp = fopen(strcat(filename, ".txt"), "w");
              fp = fwrite(&user1, sizeof(struct user), 1, fp);
              user1.balance -= amount;
            }
          }
          break;
        case 5:
          system("cls");
          printf("enter a recipient phone: ");
          scanf("%s", &phone);
          printf("enter amount: ");
          scanf("%f", &amount);
          fp = fopen(filename, "w");
          fwrite(&user1, sizeof(struct user), 1, fp);
          user1.balance -= amount;
          fclose(fp);
          printf("your account has been deducted of $%.2f", amount);
          break;
        case 6:
          printf("thank you for banking with us");
          bankActivities();
          break;
        default:
          printf("invalid input");
          break;
        }

        printf("\n\ndo you want to continue transaction [y/n]?");
        scanf("%s", &cont);
      }
    }
    else
    {
      system("cls");
      _beep(500, 900);
      printf("invalid password\n");
      printf("try again......\n");
      printf("\ndo you want to try again..... [y/n]");
      scanf("%s", &cont);
      printf("\n\n select: ");
      if (cont == 'y')
        bankActivities(); // if y ==yes; bank activities function is called to try logging in again
      if (cont == 'n')
        printf("forgotten password??"); // function to change password will be envocked
    }
  }
}
int accountcreation()
{
  int option, choice, depositChoice, choice1;
  FILE *fp; // for writing and reading the files
  char filename[50], email[50], password[50], phone[20];
  char cont = 'y';
  float amount, depositAmount;
  struct user user1, user2;
  system("cls");
  printf("enter your name\t\t\t");
  scanf("%s", &user1.name);
  printf("enter your email\t\t");
  scanf("%s", &user1.email);
  printf("enter your phone number:\t");
  scanf("%s", &user1.phone);
  printf("enter your new password\t\t");
  scanf("%s", &user1.password);
  user1.balance = 0;
  strcpy(filename, user1.name);
  fp = fopen(strcat(filename, ".txt"), "w");
  fwrite(&user1, sizeof(struct user), 1, fp);
  if (fwrite != 0)
  {
    printf("\nyour account is being processed\n");
    printf("wait for a moment.......\n");
    printf("your account is successfully created  ❤\n");
  }
  else
  {
    printf("something went wrong ..");
    printf("\ntry again in some moment later\n");
  }
  fclose(fp);
  system("cls");
  printf("1.login into your new account\n");
  printf("2.exit\n");
  printf("\n\n select :");
  scanf("%d", &choice1);
  switch (choice1)
  {
  case 1:
    bankActivities();
    break;

  case 2:
    printf("thank you for banking with us");
    return 0;
    break;
  default:
    printf("invalid input");
    break;
  }
}
int main()
{
  int option, choice, depositChoice;
  printf("********************welcome to our bank**************************\n\n");
  printf("what do you want to do ?\n");
  printf("1. open an account\n");
  printf("2. login into an account\n");
  printf("your choice:\t");
  scanf("%d", &option);
  if (option == 1)
    accountcreation();

  if (option == 2)

    bankActivities();

  return 0;
}