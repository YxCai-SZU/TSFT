#include <stdbool.h>
#include <stddef.h>


int count_list(int *l, size_t length)
{
    int count = 0;
    size_t i = 0;

    
    while (i < length)
    {
        //@ assert i < length;
        count += 1;
        i += 1;
    }
    //@ assert i == length;
    //@ assert count == (int)length;
    return count;
}
