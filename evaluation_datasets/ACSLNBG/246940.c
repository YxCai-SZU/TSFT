#include <stdbool.h>


unsigned int func(unsigned int A, unsigned int P)
{
    unsigned int sum;
    unsigned int result;
    unsigned int count;
    bool is_even;
    
    sum = A * 3 + P;
    result = 0;
    count = sum;
    is_even = true;
    
    
    while (count >= 2)
    {
        count -= 2;
    }
    
    if (count == 1)
    {
        is_even = false;
    }
    
    if (is_even)
    {
        result = sum / 2;
    }
    else
    {
        result = sum / 2;
    }
    
    //@ assert result == (((A) * 3 + (P)) / 2);
    return result;
}
