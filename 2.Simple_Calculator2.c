
#include <stdio.h>
#include <math.h>

void Menu()
{
    printf("\n\n---------------------------------");
    printf("\nWelcome to Simple Calculator\n");
    printf("\nChoose one of the following options:");
    printf("\n1. Add");
    printf("\n2. Subtract");
    printf("\n3. Multiply");
    printf("\n4. Divide");
    printf("\n5. Modulus");
    printf("\n6. Power");
    printf("\n7. Exit");  
    printf("\nNow, enter your choice: ");
    
}

double division(double a, double b)
{
    if (b == 0)
    {
        fprintf(stderr, "\nError: Division by zero is not allowed.\n");
        return NAN;
    }
    else
    {
        return a / b;
    }
}
 
double modulus(int a, int b)
{
    if (b == 0)
    {
        fprintf(stderr, "\nError: Modulus by zero is not allowed.\n");             
        return NAN;
    }
    else
    {
        return a % b;
    }
}

int main()
{
    int choice;
    double first, second, result;

    while (1)
    {
        Menu();
        scanf("%d", &choice);

        if (choice == 7)
        {
            printf("\nExiting the calculator. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 7)
        {
            printf("\nInvalid menu choice. Please try again.\n");
            continue; // Retry the menu
        }

        printf("\nPlease enter the first number: ");
        scanf("%lf", &first); // "lf" for double
        printf("Now, enter the second number: ");
        scanf("%lf", &second);

        switch (choice)
        {
        case 1: // Add
            result = first + second;
            break;
        case 2: // Subtract
            result = first - second;
            break;
        case 3: // Multiply
            result = first * second;
            break;
        case 4: // Divide
            result = division(first, second);
            break;
        case 5: // Modulus
            result = modulus((int)first, (int)second);
            break;
        case 6: // Power
            result = pow(first, second);
            break;
        }

        if (!isnan(result)) // Agar ye NAN nhi he to hi hamko ye dikhana he ..... part of math.h function
        {
            printf("\nResult of operation is: %.2f\n", result);
        }
    }

    return 0;
}
