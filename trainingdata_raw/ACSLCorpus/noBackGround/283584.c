#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 100 && 0 <= (b) && (b) <= 100);
    ensures \result == (((a) * (b)) / 100);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t result = 0;
    uint32_t temp = a * b;

    //@ assert (0 <= (a) && (a) <= 100 && 0 <= (b) && (b) <= 100);
    //@ assert multiplication_bound: a * b <= 10000;

    /*@
        loop invariant 0 <= a && a <= 100;
        loop invariant 0 <= b && b <= 100;
        loop invariant 0 <= result;
        loop invariant temp == a * b - result * 100;
        loop assigns result, temp;
        loop variant temp;
    */
    while (temp >= 100)
    {
        temp -= 100;
        result += 1;
    }

    //@ assert result == (((a) * (b)) / 100);
    return result;
}
