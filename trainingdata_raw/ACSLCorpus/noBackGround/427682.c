#include <stdbool.h>

/*@
    requires (-40 <= (k) <= 40) && ((k) != 0);
    ensures \result == (k > 0);
    assigns \nothing;
*/
bool func(int k)
{
    bool result;
    //@ assert (-40 <= (k) <= 40) && ((k) != 0);
    
    if (k > 0)
    {
        //@ assert k > 0;
        result = true;
    }
    else
    {
        //@ assert k <= 0;
        result = false;
    }
    
    return result;
}

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    ensures \result == (a <= c && c <= b);
    assigns \nothing;
*/
bool func2(int a, int b, int c)
{
    bool result;
    //@ assert (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    
    if (a <= c && c <= b)
    {
        //@ assert a <= c && c <= b;
        result = true;
    }
    else
    {
        //@ assert !(a <= c && c <= b);
        result = false;
    }
    
    return result;
}

/*@
    requires (1 <= (s) <= 100) && (1 <= (w) <= 100);
    ensures \result == (s > w);
    assigns \nothing;
*/
bool func3(int s, int w)
{
    bool result;
    //@ assert (1 <= (s) <= 100) && (1 <= (w) <= 100);
    
    if (s <= w)
    {
        //@ assert !(s > w);
        result = false;
    }
    else
    {
        //@ assert s > w;
        result = true;
    }
    
    return result;
}
