#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= x <= 100;
    ensures \result == true <==> (x <= a + b && a <= x);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    bool c = false;

    //@ assert 0 <= a <= 100 && 0 <= b <= 100 && 0 <= x <= 100;

    if (x <= a + b && a <= x)
    {
        c = true;
    }

    //@ assert c == true <==> (x <= a + b && a <= x);

    return c;
}
