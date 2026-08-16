#include <stdbool.h>

/*@
    requires (-40 < (a) <= 40) && (-40 < (b) <= 40) && (-40 < (c) <= 40) && (-40 < (d) <= 40) && (-40 < (e) <= 40) && (-40 < (k) <= 40);
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == true <==> (e - a <= k);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int dist;
    //@ assert (-40 < (a) <= 40) && (-40 < (b) <= 40) && (-40 < (c) <= 40) && (-40 < (d) <= 40) && (-40 < (e) <= 40) && (-40 < (k) <= 40);
    //@ assert ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    
    dist = e - a;
    
    if (dist <= k)
    {
        //@ assert dist <= k;
        return true;
    }
    else
    {
        //@ assert dist > k;
        return false;
    }
}
