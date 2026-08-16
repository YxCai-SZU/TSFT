#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (x) <= 200);
    ensures \result == true <==> (x >= a && x <= a + b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    // Variable declarations at scope top
    bool result;

    //@ assert (1 <= (a) <= 100 &&         1 <= (b) <= 100 &&         1 <= (x) <= 200);
    //@ assert ((a) + (b)) <= 200;

    if (x < a || x > a + b)
    {
        //@ assert x < a || x > a + b;
        result = false;
    }
    else
    {
        //@ assert x >= a && x <= a + b;
        result = true;
    }

    return result;
}
