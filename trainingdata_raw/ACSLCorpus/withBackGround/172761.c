#include <stdbool.h>

/*@ predicate is_within_bounds(integer v) = -100 <= v && v <= 100; */

/*@
  requires is_within_bounds(a) && is_within_bounds(b);
  ensures \result == true <==> a <= b;
  assigns \nothing;
*/
bool func(int a, int b)
{
    int a_0;
    int b_0;
    bool result;

    a_0 = a;
    b_0 = b;

    //@ assert is_within_bounds(a_0);
    //@ assert is_within_bounds(b_0);

    if (a_0 <= b_0)
    {
        result = true;
    }
    else
    {
        //@ assert a_0 > b_0;
        result = false;
    }

    return result;
}
