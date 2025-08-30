
#include <stdio.h>

#define MAX_USERS 10

typedef struct
{
    char username[30];
    char password[30];
} user;

user users[MAX_USERS];
int user_count = 0;

void register_user();
int login_user(); // Returns the user index

int main()
{

    int user_index;
    int option;
    while (1)  // Making a infinite Loop
    
    {
        printf("\nWelcome to User Management System\n");
        printf("\n1. Register");
        printf("\n2. Login");
        printf("\n3. Exit !");
        printf("\nSelect an option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            register_user();
            break;
        case 2:
            user_index = login_user();
            if (user_index >= 0)
            {
                printf("\nLogin successful ! Welcome , %s!", users[user_index].username);
            }
            else
            {
                printf("\nLogin failed! Incorrect usename or password.\n");
            }
            break;

        case 3:
            printf("\nExiting program.\n");
            return 0;
            break;

        default:
            printf("\nInvalid option , Please try again.\n");
        }
    }

    return 0;
}

void register_user()
{
    printf("Dummy Registration");
}

int login_user()
{
    return -1;
}