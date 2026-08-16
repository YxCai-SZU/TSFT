#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> 
        (((integer)\result) * 8 / 100) == a && 
        (((integer)\result) * 10 / 100) == b;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t n = 0;
    uint32_t temp_n;
    uint32_t eight_percent;
    uint32_t ten_percent;

    /*@
        loop invariant 0 <= n <= 100000;
        loop invariant (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
        loop assigns n, temp_n, eight_percent, ten_percent;
        loop variant 100000 - n;
    */
    while (n < 100000)
    {
        temp_n = n * 8;
        eight_percent = 0;

        /*@
            loop invariant temp_n >= 0;
            loop invariant 0 <= eight_percent <= n * 8 / 100;
            loop invariant temp_n == n * 8 - eight_percent * 100;
            loop assigns temp_n, eight_percent;
            loop variant temp_n;
        */
        while (temp_n >= 100)
        {
            temp_n -= 100;
            eight_percent += 1;
        }

        temp_n = n * 10;
        ten_percent = 0;

        /*@
            loop invariant temp_n >= 0;
            loop invariant 0 <= ten_percent <= n * 10 / 100;
            loop invariant temp_n == n * 10 - ten_percent * 100;
            loop assigns temp_n, ten_percent;
            loop variant temp_n;
        */
        while (temp_n >= 100)
        {
            temp_n -= 100;
            ten_percent += 1;
        }

        //@ assert eight_percent == n * 8 / 100;
        //@ assert ten_percent == n * 10 / 100;

        if (eight_percent == a && ten_percent == b)
        {
            return (int32_t)n;
        }

        n += 1;
    }

    return -1;
}

int main(void)
{
    return 0;
}
