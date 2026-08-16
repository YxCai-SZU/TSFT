#include <stdint.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == a + b || \result == a - b || \result == a * b;
    ensures \result >= a + b && \result >= a - b && \result >= a * b;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t sum;
    int64_t diff;
    int64_t prod;
    
    sum = a + b;
    diff = a - b;
    
    //@ assert -10000 <= a * b <= 10000;
    prod = a * b;
    
    if (sum > diff && sum > prod)
    {
        //@ assert sum >= a + b && sum >= a - b && sum >= a * b;
        return sum;
    }
    else if (diff > prod)
    {
        //@ assert diff >= a + b && diff >= a - b && diff >= a * b;
        return diff;
    }
    else
    {
        //@ assert prod >= a + b && prod >= a - b && prod >= a * b;
        return prod;
    }
}
