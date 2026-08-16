#include <stdbool.h>

/*@
    requires -40 <= x <= 40;
    ensures \result == true <==> x >= 30;
    assigns \nothing;
 */
bool func(int x)
{
    bool result;

    //@ assert -40 <= x <= 40;

    if (x < 30)
    {
        //@ assert x < 30;
        result = false;
    }
    else
    {
        //@ assert x >= 30;
        result = true;
    }

    //@ assert result == true <==> x >= 30;
    return result;
}

/*@
    requires -40 <= x <= 40;
    ensures \result == true <==> x >= 30;
    assigns \nothing;
 */
bool func2(int x)
{
    bool result;

    //@ assert -40 <= x <= 40;

    if (x >= 30)
    {
        //@ assert x >= 30;
        result = true;
    }
    else
    {
        //@ assert x < 30;
        result = false;
    }

    //@ assert result == true <==> x >= 30;
    return result;
}

/*@
    requires -40 <= x <= 40;
    ensures \result == true <==> x >= 30;
    assigns \nothing;
 */
bool func3(int x)
{
    bool result;

    //@ assert -40 <= x <= 40;

    if (x >= 30)
    {
        //@ assert x >= 30;
        result = true;
    }
    else
    {
        //@ assert x < 30;
        result = false;
    }

    //@ assert result == true <==> x >= 30;
    return result;
}
