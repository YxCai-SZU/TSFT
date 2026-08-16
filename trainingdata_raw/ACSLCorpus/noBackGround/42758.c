#include <stdint.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result == ((((x)) / 500) * 1000 + (((((x)) % 500)) / 5) * 5);
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    int32_t ans = 0;
    uint32_t x_mut = x;
    uint32_t quotient_500 = 0;
    uint32_t remainder_500 = x_mut;

    //@ ghost uint32_t original_x = x;

    /*@
        loop invariant (1 <= (original_x) <= 100000);
        loop invariant 0 <= quotient_500 <= ((original_x) / 500);
        loop invariant remainder_500 == original_x - quotient_500 * 500;
        loop invariant remainder_500 >= 0;
        loop assigns quotient_500, remainder_500;
        loop variant remainder_500;
    */
    while (remainder_500 >= 500)
    {
        //@ assert remainder_500 >= 500;
        remainder_500 -= 500;
        quotient_500 += 1;
    }

    //@ assert quotient_500 == ((original_x) / 500);
    //@ assert remainder_500 == ((original_x) % 500);
    ans += (int32_t)quotient_500 * 1000;

    uint32_t quotient_5 = 0;
    uint32_t remainder_5 = remainder_500;

    /*@
        loop invariant (1 <= (original_x) <= 100000);
        loop invariant 0 <= quotient_5 <= ((remainder_500) / 5);
        loop invariant remainder_5 == remainder_500 - quotient_5 * 5;
        loop invariant remainder_5 >= 0;
        loop assigns quotient_5, remainder_5;
        loop variant remainder_5;
    */
    while (remainder_5 >= 5)
    {
        //@ assert remainder_5 >= 5;
        remainder_5 -= 5;
        quotient_5 += 1;
    }

    //@ assert quotient_5 == ((remainder_500) / 5);
    //@ assert remainder_5 == ((remainder_500) % 5);
    ans += (int32_t)quotient_5 * 5;

    //@ assert ans == ((((original_x)) / 500) * 1000 + (((((original_x)) % 500)) / 5) * 5);
    return ans;
}

int main()
{
    return 0;
}
