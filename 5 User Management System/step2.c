
// Masking password disabled program

#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define CREDENTIAL_LENGTH 30

typedef struct
{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
} user;

user users[MAX_USERS];
int user_count = 0;

void register_user();
int login_user();             // Returns the user index
void fix_fgets_input(char *); //   \n ko '\0' karne ka function jo by default karna padta he fgets me
void input_credentials(char *username, char *password);

int main()
{
    int option;

    while (1) // Infinite loop
    {
        printf("\nWelcome to User Management System\n");
        printf("\n1. Register");
        printf("\n2. Login");
        printf("\n3. Exit");
        printf("\nSelect an option: ");
        scanf("%d", &option);
        getchar(); // Consume the trailing newline character

        switch (option)
        {
        case 1:
            register_user();
            break;

        case 2:
        {
            int user_index = login_user();
            if (user_index >= 0)
            {
                printf("\nLogin Successful! Welcome, %s\n", users[user_index].username);
            }
            else
            {
                printf("\nLogin failed! Incorrect username or password.\n");
            }
            break;
        }
        case 3:
            printf("\nExiting program.\n");
            return 0;

        default:
            printf("\nInvalid option. Please try again.\n");
            break;
        }
    }

    return 0;
}

void register_user()
{
    if (user_count >= MAX_USERS)
    {
        printf("\nUser registration limit reached. Cannot register more users.\n");
        return;
    }

    int new_index = user_count;

    printf("\nRegister a new user");
    fgets(users[new_index].username, CREDENTIAL_LENGTH, stdin);
    fix_fgets_input(users[new_index].username);

    input_credentials(users[new_index].username, users[new_index].password);

    user_count++;

    printf("\nRegistration Successful!\n");
}

int login_user()
{
    // Ye ek new username & password he jo compare hoga pehle wale username & password se
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];

    input_credentials(username, password);

    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0)
        {
            return i;
        }

    }

    return -1;
}

void input_credentials(char *username, char *password)
{
    printf("\nEnter username: ");
    fgets(username, CREDENTIAL_LENGTH, stdin);
    fix_fgets_input(username);

    printf("Enter password: ");
    fgets(password, CREDENTIAL_LENGTH, stdin);
    fix_fgets_input(password);
}

void fix_fgets_input(char *string)
{
    int index = strcspn(string, "\n"); // 'strcpn' to Find the position of '\n'
    string[index] = '\0';              // Replace '\n' with '\0'
}
