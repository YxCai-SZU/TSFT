#include <stdbool.h>

/*@
    requires 1 <= a <= 5000;
    requires 1 <= b <= 5000;
    requires 1 <= c <= 10000;
    ensures \result == 1 <==> (((c) - (b) > 0) && ((c) - (b) <= (a)));
*/
bool func(int a, int b, int c)
{
    bool condition;
    int new_value;

    condition = false;
    //@ assert condition == false;

    if (c - b > 0)
    {
        new_value = c - b;
        //@ assert new_value == c - b;

        if (new_value <= a)
        {
            condition = true;
            //@ assert condition == true;
        }
        else
        {
            condition = false;
            //@ assert condition == false;
        }
    }
    else
    {
        condition = false;
        //@ assert condition == false;
    }

    //@ assert condition == 1 <==> (((c) - (b) > 0) && ((c) - (b) <= (a)));
    return condition;
}
