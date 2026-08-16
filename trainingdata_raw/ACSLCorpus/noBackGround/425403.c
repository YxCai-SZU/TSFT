#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    ensures \result == ((a) * (a));
    assigns \nothing;
*/
int func(int a)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert 1 <= ((a) * (a)) <= 10000;
    //@ assert ((a) * (a)) == a * a;
    return a * a;
}
