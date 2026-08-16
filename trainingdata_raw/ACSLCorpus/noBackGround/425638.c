#include <stdint.h>

/*@
    requires n >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
uint32_t count_set_bits(uint32_t n)
{
    uint32_t num;
    uint32_t count;

    num = n;
    count = 0;

    /*@
        loop invariant ((num) <= (n) && (count) <= (n) && (num) + 2 * (count) <= 2 * (n));
        loop invariant num >= 0;
        loop assigns num, count;
        loop variant num;
    */
    while (num > 0)
    {
        //@ assert ((num) <= (n) && (count) <= (n) && (num) + 2 * (count) <= 2 * (n));
        count += num % 2;
        num /= 2;
    }

    //@ assert count <= n;
    return count;
}
