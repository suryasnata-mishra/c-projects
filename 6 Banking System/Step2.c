
// Creating account & Checking balance 

#include <stdio.h>
#include <string.h>

void create_account();
void deposit_money();
void withdraw_money();
void check_balance();

const char* ACCOUNT_FILE = "account.data";

typedef struct
{
    char name[50];
    int acc_no;
    float balance;
} Account;

int main()
{

    while (1)
    {
        int choice;
        printf("\n\n *** Bank Management System ***");
        printf("\n1. Create account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw money");
        printf("\n4. Check balance");
        printf("\n5. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create_account();
            break;

        case 2:
            deposit_money();
            break;

        case 3:
            withdraw_money();
            break;

        case 4:
            check_balance();
            break;

        case 5:
            printf("\nExiting program ! , Thanks for your visit.");
            return 0;
            break;

        default:
            printf("\nInvalid choice ! , Please try again");
        }
    }
}

void create_account()
{
    Account acc;
    FILE *file = fopen("ACCOUNT_FILE", "ab+");

    if (file == NULL)
    {
        printf("\nUnable to open file!!!");
        return;
    }
    char c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);

    printf("\nEnter your name : "); // Idhar wale enter ko terminal pick kar rha he isiliye 'getchar' use karna padta
    fgets(acc.name, sizeof(acc.name), stdin);
    int ind = strcspn(acc.name, "\n");
    acc.name[ind] = '\0';

    printf("Enter your account number : ");
    scanf("%d" , &acc.acc_no);
    acc.balance = 0;

    fwrite(&acc, sizeof(acc), 1, file);
    fclose(file);
    printf("\nAccount created successfully !");
}

void deposit_money()
{
    printf("\nDepositing]");
}

void withdraw_money()
{
    printf("\nWithdrawing");
}

void check_balance()
{
    FILE *file = fopen(ACCOUNT_FILE , "rb"); // read binary

    if(file == NULL){
        printf("Unable to open file !");
        return;
    }

    int acc_no;
    Account acc_read;
    printf("Enter your account number : ");
    scanf("%d" , &acc_no);

    while(fread(&acc_read , sizeof(acc_read) , 1 , file)){
        if(acc_read.acc_no == acc_no){
            printf("\nYour current balance id Rs. %2.f" , acc_read.balance);
            fclose(file);
            return;
        }
    }
    fclose(file);
    printf("\n Account No: %d was not found. \n" , acc_no);
}
