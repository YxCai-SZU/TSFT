#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    ensures \result == ((a) * ((a) + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    uint32_t sum = 0;
    uint32_t i = 1;

    //@ assert (1 <= (a) <= 100);
    //@ assert 1 <= i <= a + 1;
    //@ assert 0 <= sum;
    //@ assert sum == ((i - 1) * ((i - 1) + 1) / 2);

    /*@
        loop invariant 1 <= i <= a + 1;
        loop invariant 0 <= sum;
        loop invariant sum == ((i - 1) * ((i - 1) + 1) / 2);
        loop assigns sum, i;
        loop variant a - i + 1;
    */
    while (i <= a)
    {
        //@ assert i <= a + 1;
        //@ assert sum + i >= sum;
        //@ assert sum + i == ((i) * ((i) + 1) / 2);
        //@ assert 0 <= ((i) * ((i) + 1) / 2) <= ((100) * ((100) + 1) / 2);

        sum += i;
        i += 1;

        //@ assert i - 1 <= a + 1;
        //@ assert sum <= ((i - 1) * ((i - 1) + 1) / 2);
    }

    //@ assert sum == ((a) * ((a) + 1) / 2);
    return sum;
}

int main()
{
    return 0;
}
