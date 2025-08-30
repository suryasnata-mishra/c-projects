
// Just time only

#include <stdio.h>
#include <time.h>

int main()
{

    time_t raw_time;
    struct tm *current_time;
    char buffer[50]; // Isi me store hogaa

    time(&raw_time);
    current_time = localtime(&raw_time);

    strftime(buffer, sizeof(buffer), "%H : %M : %S", current_time);

    printf("Current Time : %s", buffer);

    return 0;
}

// For AM & PM

#include <stdio.h>
#include <time.h>

int main()
{

    time_t raw_time;
    struct tm *current_time;
    char buffer[50]; // Isi me store hogaa

    time(&raw_time);
    current_time = localtime(&raw_time);

    strftime(buffer, sizeof(buffer), "%I : %M : %S %p", current_time);

    printf("Current Time : %s", buffer);

    return 0;
}