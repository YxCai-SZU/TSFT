#include <stdbool.h>

/*@
  requires (-40 <= (a) <= 40) && (-40 <= (b) <= 40);
  ensures \result == true <==> (a <= 8 && b <= 8) || (a >= -8 && b >= -8);
*/
bool func(int a, int b)
{
    // Variable declarations at scope top
    bool result;

    if ((a <= 8 && b <= 8) || (a >= -8 && b >= -8))
    {
        result = true;
    }
    else
    {
        //@ assert (-40 <= (a) <= 40);
        //@ assert (-40 <= (b) <= 40);
        result = false;
    }

    return result;
}
