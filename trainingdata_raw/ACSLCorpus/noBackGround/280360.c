#include <stdbool.h>

/*@
    requires 1000 <= a <= 9999;
    ensures \result == true <==> ((a) % 1110 == 0 || (a) % 2110 == 0 || (a) % 3120 == 0 || (a) % 4130 == 0);
    assigns \nothing;
*/
bool func(unsigned int a)
{
    bool result;

    //@ assert 1000 <= a <= 9999;

    if (a % 1110 == 0 || a % 2110 == 0 || a % 3120 == 0 || a % 4130 == 0)
    {
        //@ assert ((a) % 1110 == 0 || (a) % 2110 == 0 || (a) % 3120 == 0 || (a) % 4130 == 0);
        result = true;
    }
    else
    {
        //@ assert !((a) % 1110 == 0 || (a) % 2110 == 0 || (a) % 3120 == 0 || (a) % 4130 == 0);
        result = false;
    }

    return result;
}
