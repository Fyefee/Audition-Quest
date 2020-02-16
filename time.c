#include <stdio.h>
#include <time.h>

int main()
{
    //....
    time_t initial_time = time(NULL);
    float time_limit = 10.0f;

    //...
    while ( (time(NULL) - initial_time) < time_limit )
    {
        printf(".");
        // ... do stuff
    }

    // clean up etc.
}
