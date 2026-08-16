#include <stdint.h>


uint32_t func(uint32_t A, uint32_t B, uint32_t C)
{
    uint32_t min_val;
    uint32_t ans;

    //@ assert (1 <= (A) <= 100);
    //@ assert (1 <= (B) <= 100);
    //@ assert (1 <= (C) <= 100);

    if (B / A < C)
    {
        min_val = B / A;
    }
    else
    {
        min_val = C;
    }

    //@ assert min_val == (((B) / (A) < (C)) ? ((B) / (A)) : (C));
    ans = C - min_val;
    //@ assert ans == ((C) - ((((B)) / ((A)) < ((C))) ? (((B)) / ((A))) : ((C))));
    
    //@ assert ans >= 0;
    //@ assert ans <= C;
    
    return ans;
}
