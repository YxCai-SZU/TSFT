#include <stdint.h>

/*@ requires (0 <= (n) && (n) <= 100 &&
        0 <= (m) && (m) <= 100);
    ensures \result <= m;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    uint32_t result = 0;
    uint32_t remaining = n;

    /*@
        loop invariant ((0 <= ((n)) && ((n)) <= 100 &&
        0 <= ((m)) && ((m)) <= 100) &&
        0 <= (remaining) && (remaining) <= (n) &&
        0 <= (result) && (result) <= (m) &&
        (result) <= (n) - (remaining));
        loop assigns remaining, result;
        loop variant remaining;
    */
    while (remaining > 0 && m > result) {
        //@ assert remaining > 0 && m > result;
        remaining -= 1;
        result += 1;
    }

    //@ assert result <= m;
    return result;
}

/*@ ensures \true;
    assigns \nothing;
*/
void example9(void)
{
    uint8_t s[4];
    uint8_t expected1[3] = {1, 5, 3};
    uint8_t expected2[4] = {1, 5, 3, 7};

    s[0] = 1;
    s[1] = 2;
    s[2] = 3;

    s[1] = 5;
    //@ assert (\forall integer i; 0 <= i < (3) ==> (&s[0])[i] == (&expected1[0])[i]);

    s[3] = 7;
    //@ assert (\forall integer i; 0 <= i < (4) ==> (&s[0])[i] == (&expected2[0])[i]);
}
