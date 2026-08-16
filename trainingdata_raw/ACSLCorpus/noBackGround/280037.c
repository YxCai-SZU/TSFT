#include <stdbool.h>

/*@
    requires (1 <= (x) <= 10000) && (1 <= (y) <= 10000) && (1 <= (z) <= 10000);
    ensures \result == (x * y <= z);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y, unsigned int z)
{
    // Variable declarations at scope top
    bool result;

    //@ assert x <= 10000;
    //@ assert y <= 10000;
    //@ assert z <= 10000;
    //@ assert ((x) * (y) <= 10000 * 10000);

    result = (x * y <= z);
    return result;
}

int main(void)
{
    return 0;
}
