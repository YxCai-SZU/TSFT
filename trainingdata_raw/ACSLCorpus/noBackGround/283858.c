#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (r) * 314) / 100);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t ans;
    int64_t temp;
    int64_t div;
    
    pi = 314;
    ans = 0;
    temp = 2 * r * pi;
    div = 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314;
        loop invariant temp >= 0;
        loop invariant temp == 2 * r * pi - 100 * div;
        loop invariant div >= 0;
        loop assigns temp, div;
        loop variant temp;
    */
    while (temp >= 100)
    {
        temp -= 100;
        div += 1;
    }
    
    ans = div;
    
    //@ assert ans == (2 * r * 314) / 100;
    
    return ans;
}

int main(void)
{
    return 0;
}
