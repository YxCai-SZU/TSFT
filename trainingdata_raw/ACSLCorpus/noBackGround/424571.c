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
    int64_t result;

    sum = a + b;
    diff = a - b;
    
    //@ assert (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    //@ assert -10000 <= a * b <= 10000;
    
    prod = a * b;
    
    if (sum > diff && sum > prod)
    {
        result = sum;
    }
    else if (diff > prod)
    {
        result = diff;
    }
    else
    {
        result = prod;
    }
    
    //@ assert result == a + b || result == a - b || result == a * b;
    //@ assert result >= a + b && result >= a - b && result >= a * b;
    
    return result;
}

int main()
{
    return 0;
}
