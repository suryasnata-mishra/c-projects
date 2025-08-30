
// Menu Only

#include <stdio.h>

void create_account();
void deposit_money();
void withdraw_money();
void check_balance();

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
    printf("\nCreating account");
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
    printf("\nChecking");
}
