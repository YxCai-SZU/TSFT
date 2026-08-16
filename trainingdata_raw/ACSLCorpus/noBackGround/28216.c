#include <stdint.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * r * 3141592 / 1000000;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t ans;
    int64_t res;
    int64_t temp;
    int64_t count;
    
    pi = 3141592;
    ans = 2 * r * pi;
    res = 0;
    temp = ans;
    count = 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 3141592;
        loop invariant ans == 2 * r * pi;
        loop invariant temp >= 0;
        loop invariant temp == ans - count * 1000000;
        loop invariant count * 1000000 <= ans;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 1000000)
    {
        temp -= 1000000;
        count += 1;
    }
    
    res = count;
    return res;
}

int main(void)
{
    return 0;
}
