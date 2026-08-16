#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * ((3141592653589793)) * ((r))) / (1000000000000000));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t scale;
    int64_t product;
    int64_t ans;
    int64_t remainder;
    
    //@ assert (1 <= (r) <= 100);
    
    pi = 3141592653589793;
    scale = 1000000000000000;
    
    //@ assert pi * r <= 100 * 3141592653589793;
    //@ assert 2 * pi * r <= 2 * 100 * 3141592653589793;
    
    product = 2 * pi * r;
    ans = 0;
    remainder = product;
    
    /*@
        loop invariant (1 <= (r) <= 100);
        loop invariant 0 <= ans <= ((2 * ((pi)) * ((r))) / (scale));
        loop invariant remainder == product - ans * scale;
        loop invariant product == 2 * pi * r;
        loop assigns ans, remainder;
        loop variant remainder;
    */
    while (remainder >= scale)
    {
        ans = ans + 1;
        remainder = remainder - scale;
    }
    
    return ans;
}

int main()
{
    return 0;
}
