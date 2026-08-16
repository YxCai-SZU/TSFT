#include <limits.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
int func(int a)
{
    int result;

    //@ assert (1 <= (a) <= 10);
    //@ assert ((a) * (a)) >= 1;
    //@ assert ((a) * (a)) <= 100;
    //@ assert ((a) * (a) * (a)) >= 1;
    //@ assert ((a) * (a) * (a)) <= 1000;

    result = a + (a * a) + (a * a * a);
    //@ assert result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    return result;
}
