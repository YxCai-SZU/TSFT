#include <stddef.h>


size_t func(size_t n)
{
    size_t x;
    size_t ans;
    
    //@ assert (1 <= (n) <= 10000);
    
    x = (n + 999) / 1000;
    //@ assert x == (n + 999) / 1000;
    
    ans = x * 1000;
    //@ assert ans == x * 1000;
    
    //@ assert ans >= 1000;
    
    return ans;
}
