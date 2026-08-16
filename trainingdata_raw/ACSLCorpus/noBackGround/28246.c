#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (h) <= 100 && (h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t h)
{
    uint64_t sum;
    uint64_t product;
    uint64_t ans;
    uint64_t count;
    uint64_t temp;

    //@ assert 2 <= a + b <= 200;
    sum = a + b;
    
    //@ assert 2 <= sum * h <= 20000;
    product = sum * h;
    
    ans = 0;
    count = 0;
    temp = product;

    /*@
        loop invariant 0 <= temp <= product;
        loop invariant 0 <= count <= product / 2;
        loop invariant temp == product - 2 * count;
        loop invariant ans == count;
        loop assigns temp, ans, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        ans += 1;
        count += 1;
        //@ assert temp == product - 2 * count;
    }

    //@ assert ans == (a + b) * h / 2;
    return ans;
}
