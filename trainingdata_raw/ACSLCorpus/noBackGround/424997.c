#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - ((n) / 15) * 200);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t x;
    int32_t y;
    uint32_t count;
    uint32_t temp_n;
    int32_t ans;

    x = (int32_t)n * 800;
    y = 0;
    count = 0;
    temp_n = n;

    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant 0 <= count && count <= n / 15;
        loop invariant temp_n == ((n) - (count) * 15);
        loop invariant temp_n >= 0;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        temp_n -= 15;
        count += 1;
    }

    //@ assert temp_n == ((n) - (count) * 15);

    y = (int32_t)count * 200;

    //@ assert x >= 0 && x <= 100 * 800;
    //@ assert y >= 0 && y <= 100 * 200;

    ans = x - y;

    //@ assert ans == ((n) * 800 - ((n) / 15) * 200);

    return ans;
}

int main()
{
    return 0;
}
