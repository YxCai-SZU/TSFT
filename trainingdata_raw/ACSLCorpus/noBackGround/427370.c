#include <stdbool.h>

/*@
  requires a >= 1 && b >= 1 && c >= 1;
  ensures \result == true <==> ((a) < (b) && (b) < (c));
  assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool result;
    result = true;

    if (a >= b)
    {
        result = false;
    }
    else
    {
        if (b >= c)
        {
            result = false;
        }
    }

    //@ assert result == true <==> ((a) < (b) && (b) < (c));
    return result;
}
