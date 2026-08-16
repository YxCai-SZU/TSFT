#include <stdint.h>

/*@
    requires (1 <= (k) <= 100000);
    ensures \result == (((k) - 1) / 2 + 1);
    assigns \nothing;
*/
uint32_t func(uint32_t k)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert k - 1 >= 0;
    //@ assert (k - 1) / 2 >= 0;
    //@ assert (k - 1) / 2 + 1 >= 0;
    //@ assert k - 1 <= 100000 - 1;
    //@ assert (k - 1) / 2 <= (100000 - 1) / 2;
    //@ assert (k - 1) / 2 + 1 <= (100000 - 1) / 2 + 1;

    result = (k - 1) / 2 + 1;
    return result;
}

int main()
{
    return 0;
}
