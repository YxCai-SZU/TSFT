#include <stdbool.h>

/*@
    requires 0 <= x <= 4294967295;
    ensures ((\result) == true ==> (x) % 2 == 0 &&
        (\result) == false ==> (x) % 2 != 0);
    assigns \nothing;
*/
bool is_even(unsigned int x)
{
    //@ assert x >= 0 && x <= 4294967295;
    return x % 2 == 0;
}

/*@
    requires 0 <= x <= 4294967295;
    ensures ((\result) == true ==> (x) % 2 != 0 &&
        (\result) == false ==> (x) % 2 == 0);
    assigns \nothing;
*/
bool is_odd(unsigned int x)
{
    //@ assert x >= 0 && x <= 4294967295;
    return x % 2 != 0;
}
