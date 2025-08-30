
// Final

#include <stdio.h>
#include <string.h>
#include <conio.h> // For Windows password masking

#define MAX_USERS 10
#define CREDENTIAL_LENGTH 30

typedef struct
{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
} User;     

User users[MAX_USERS];
int user_count = 0;

void register_user();
int login_user(); // Returns the user index
void fix_fgets_input(char *); // fgets "Enter" ko v user name consider kar leta he so replaced'\0' with '\n'
void input_credentials(char *username, char *password);

int main()
{
    int option;

    while (1)
    {
        printf("\nWelcome to User Management System");
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
                printf("\nLogin successful! Welcome, %s!\n", users[user_index].username);
            }
            else
            {
                printf("\nLogin failed! Incorrect username or password.\n");
            }
            break;
        }
        case 3:
            printf("\nExiting Program.\n");
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
        printf("\nMaximum %d users are supported! No more registrations allowed.\n", MAX_USERS);
        return;
    }

    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];

    printf("\nRegister a new user:");
    input_credentials(username, password);

    // Check for duplicate username
    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(username, users[i].username) == 0)
        {
            printf("\nUsername already exists. Please try a different one.\n");
            return;
        }
    }
 
    strcpy(users[user_count].username, username);
    strcpy(users[user_count].password, password);
    user_count++;
    printf("\nRegistration successful!\n");
}

int login_user()
{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];

    printf("\nLogin:");
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

    printf("Enter password (masked): ");
    int i = 0;
    char ch;

    while (1)
    {
        ch = getch(); // Get character without echoing to console
        if (ch == '\r')
        { // Enter key pressed
            break;
        }
        else if (ch == '\b')
        { // Backspace key pressed
            if (i > 0)
            {
                i--;
                printf("\b \b"); // Remove the last character on the console
            }
        }
        else if (i < CREDENTIAL_LENGTH - 1)
        { // Regular character
            password[i++] = ch;
            printf("*"); // Print '*' for masking
        }
    }
    password[i] = '\0'; // Null-terminate the password
    printf("\n");       // Move to the next line after password input
}

void fix_fgets_input(char *string)
{
    int index = strcspn(string, "\n"); // This function Finds index of a single character in a string
    string[index] = '\0';              // Replace '\n' with '\0'
}
