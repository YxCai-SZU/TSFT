#include <stdbool.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    ensures \result == true <==> (a < 0 && b > 0);
    assigns \nothing;
*/
bool func(int a, int b)
{
    bool result;

    //@ assert -100 <= a <= 100;
    //@ assert -100 <= b <= 100;

    if (a < 0 && b > 0)
    {
        //@ assert ((((a)) < 0) && (((b)) > 0));
        result = true;
    }
    else
    {
        //@ assert !((((a)) < 0) && (((b)) > 0));
        result = false;
    }

    //@ assert result == true <==> ((((a)) < 0) && (((b)) > 0));
    return result;
}
