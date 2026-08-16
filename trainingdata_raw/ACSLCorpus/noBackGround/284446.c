#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000);
    ensures \result <= 2 * n;
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t res;
    uint64_t i;

    //@ assert (1 <= (n) && (n) <= 1000000);
    res = 0;
    i = 1;

    /*@
        loop invariant ((1 <= ((n)) && ((n)) <= 1000000) &&
        1 <= (i) && (i) <= (n) + 1 &&
        (res) <= 2 * ((i) - 1) &&
        ((i) > 1 ==> (res) <= 2 * (n)));
        loop assigns res, i;
        loop variant ((n) - (i) + 1);
    */
    while (i <= n)
    {
        //@ assert ((1 <= ((n)) && ((n)) <= 1000000) &&         1 <= (i) && (i) <= (n) + 1 &&         (res) <= 2 * ((i) - 1) &&         ((i) > 1 ==> (res) <= 2 * (n)));
        if (i <= n - i)
        {
            //@ assert i <= n - i;
            res += 2;
        }
        else
        {
            //@ assert !(i <= n - i);
            res += 1;
        }
        i += 1;
        //@ assert ((1 <= ((n)) && ((n)) <= 1000000) &&         1 <= (i) && (i) <= (n) + 1 &&         (res) <= 2 * ((i) - 1) &&         ((i) > 1 ==> (res) <= 2 * (n)));
    }
    //@ assert i == n + 1;
    //@ assert res <= 2 * n;
    return res;
}

int main()
{
    return 0;
}
