#include <stdbool.h>

/*@
    requires (-40 <= (x) <= 40);
    ensures \result == (x >= 30);
    assigns \nothing;
*/
bool func(int x)
{
    //@ assert (-40 <= (x) <= 40);
    bool result;
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
    return result;
}

/*@
    requires (-40 <= (x) <= 40);
    ensures \result == (x >= 30);
    assigns \nothing;
*/
bool func_nested(int x)
{
    //@ assert (-40 <= (x) <= 40);
    bool result;
    if (x >= 30)
    {
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
    }
    else
    {
        //@ assert x < 30;
        result = false;
    }
    return result;
}

/*@
    requires (-40 <= (x) <= 40);
    ensures \result == (x >= 30);
    assigns \nothing;
*/
bool func_array(int x)
{
    //@ assert (-40 <= (x) <= 40);
    int y;
    bool result;
    y = x;
    if (y >= 30)
    {
        //@ assert y >= 30;
        result = true;
    }
    else
    {
        //@ assert y < 30;
        result = false;
    }
    return result;
}

/*@
    requires (-40 <= (x) <= 40);
    ensures \result == (x >= 30);
    assigns \nothing;
*/
bool func_tuple(int x)
{
    //@ assert (-40 <= (x) <= 40);
    struct tuple { int f0; } t;
    bool result;
    t.f0 = x;
    if (t.f0 >= 30)
    {
        //@ assert t.f0 >= 30;
        result = true;
    }
    else
    {
        //@ assert t.f0 < 30;
        result = false;
    }
    return result;
}

/*@
    requires (-40 <= (x) <= 40);
    ensures \result == (x >= 30);
    assigns \nothing;
*/
bool func_multi(int x)
{
    //@ assert (-40 <= (x) <= 40);
    struct tuple { int f0; } t;
    int y;
    bool result;
    t.f0 = x;
    y = t.f0;
    if (y >= 30)
    {
        //@ assert y >= 30;
        result = true;
    }
    else
    {
        //@ assert y < 30;
        result = false;
    }
    return result;
}
