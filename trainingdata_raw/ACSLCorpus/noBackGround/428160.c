#include <stdbool.h>

/*@
    requires (-40 <= (a) <= 40);
    requires (-40 <= (b) <= 40);
    requires (-40 <= (c) <= 40);
    requires (-40 <= (d) <= 40);
    requires (-40 <= (e) <= 40);
    ensures ((\result) == true <==> 
        ((a) <= (e) && (e) <= (c) && 
         ((b) == 0 || (d) == 0 || ((d) > 0 && (e) >= (b)) || ((d) < 0 && (e) <= (b)))));
*/
bool func(int a, int b, int c, int d, int e)
{
    bool result = false;
    
    //@ assert (-40 <= (a) <= 40) && (-40 <= (b) <= 40) && (-40 <= (c) <= 40) && (-40 <= (d) <= 40) && (-40 <= (e) <= 40);
    
    if (a <= e && e <= c)
    {
        if (b == 0 || d == 0)
        {
            result = true;
        }
        else if (d > 0 && e >= b)
        {
            result = true;
        }
        else if (d < 0 && e <= b)
        {
            result = true;
        }
    }
    
    //@ assert ((result) == true <==>          ((a) <= (e) && (e) <= (c) &&           ((b) == 0 || (d) == 0 || ((d) > 0 && (e) >= (b)) || ((d) < 0 && (e) <= (b)))));
    
    return result;
}
