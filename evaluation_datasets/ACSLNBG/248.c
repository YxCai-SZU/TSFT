#include <stdbool.h>
#include <stddef.h>


size_t func(size_t x)
{
    size_t ans;
    //@ assert x <= 1 && x >= 0;
    
    if (x == 1) {
        //@ assert ((x) == 1);
        ans = 0;
    } else {
        //@ assert ((x) == 0);
        ans = 1;
    }
    
    return ans;
}
