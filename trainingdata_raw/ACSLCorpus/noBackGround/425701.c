#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result >= 0 || \result == -1;
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    uint32_t n;
    uint32_t temp_n;
    
    //@ assert (1 <= (x) <= 100000);
    
    n = 1;
    
    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant 1 <= n <= 100000;
        loop assigns n, temp_n;
        loop variant 100000 - n;
    */
    while (n < 100000)
    {
        //@ assert n * 8 <= 100000 * 8;
        temp_n = n * 8 / 100;
        
        if (temp_n == x)
        {
            //@ assert (int32_t)n >= 0;
            return (int32_t)n;
        }
        
        //@ assert n + 1 <= 100000;
        n = n + 1;
    }
    
    //@ assert (1 <= (x) <= 100000);
    return -1;
}

int main(void)
{
    return 0;
}
