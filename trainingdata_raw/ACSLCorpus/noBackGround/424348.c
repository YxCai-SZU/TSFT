#include <stdbool.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == true <==> (a <= 0 && 0 <= b);
    assigns \nothing;
*/
bool func(int a, int b)
{
    bool result;

    //@ assert (-100 <= (a) <= 100) && (-100 <= (b) <= 100);

    if (a > 0 && b < 0)
    {
        result = false;
        //@ assert !(a <= 0 && 0 <= b);
        return result;
    }

    if (a <= 0 && 0 <= b)
    {
        result = true;
        //@ assert a <= 0 && 0 <= b;
        return result;
    }

    if (a <= 0 && 0 <= b)
    {
        //@ assert a > 0 || b < 0;
        result = true;
        return result;
    }

    result = false;
    //@ assert !(a <= 0 && 0 <= b);
    return result;
}
