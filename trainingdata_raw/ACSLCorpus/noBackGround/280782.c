#include <stdint.h>

/*@
    requires 1 <= n <= 10000;
    ensures \result == 1000 * ((n + 999) / 1000) - n;
*/
int32_t func(int32_t n)
{
    int32_t result;
    int32_t temp;
    int32_t count;

    result = n;
    temp = n + 999;
    count = 0;

    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant result == n;
        loop invariant temp >= 0;
        loop invariant count >= 0;
        loop invariant temp + 1000 * count == n + 999;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 1000)
    {
        temp -= 1000;
        count += 1;
    }

    //@ assert 0 <= count * 1000 <= 10000 * 1000;
    result = count * 1000 - n;
    //@ assert result == 1000 * ((n + 999) / 1000) - n;
    return result;
}

int main()
{
    return 0;
}
