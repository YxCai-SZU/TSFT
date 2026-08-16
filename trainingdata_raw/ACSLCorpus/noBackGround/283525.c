#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * (r) * 314 / 100);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t ans;
    int64_t temp;
    int64_t count;
    int64_t div;
    int64_t temp2;
    
    // Variable declarations placed at top as required
    pi = 314;
    ans = 0;
    temp = 2 * r * pi;
    count = 0;
    div = 0;
    temp2 = 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314;
        loop invariant 0 <= temp <= 2 * 100 * 314;
        loop invariant temp == 2 * r * pi - 100 * count;
        loop invariant count * 100 + temp == 2 * r * pi;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 100)
    {
        //@ assert temp >= 100;
        temp -= 100;
        count += 1;
    }
    ans = count;
    
    temp2 = ans * 100;
    div = 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314;
        loop invariant 0 <= temp2 <= ans * 100;
        loop invariant temp2 == ans * 100 - 100 * div;
        loop invariant div * 100 + temp2 == ans * 100;
        loop assigns temp2, div;
        loop variant temp2;
    */
    while (temp2 >= 100)
    {
        //@ assert temp2 >= 100;
        temp2 -= 100;
        div += 1;
    }
    ans = div;
    
    //@ assert ans == 2 * r * 314 / 100;
    return ans;
}

int main(void)
{
    return 0;
}
