#include <stdbool.h>

/*@
    requires (-40 <= (n) && (n) <= 40);
    ensures \result == (n >= 30);
*/
bool func(int n)
{
    bool result;
    //@ assert (-40 <= (n) && (n) <= 40);
    result = (n >= 30);
    //@ assert result == (n >= 30);
    return result;
}

/*@
    requires (-40 <= (n) && (n) <= 40);
    ensures \result == (n >= 30 || n <= -10);
*/
bool func_or(int n)
{
    bool result;
    //@ assert (-40 <= (n) && (n) <= 40);
    result = (n >= 30 || n <= -10);
    //@ assert result == (n >= 30 || n <= -10);
    return result;
}

/*@
    requires (-40 <= (n) && (n) <= 40);
    ensures \result == (n >= 30 && n <= 0);
*/
bool func_and(int n)
{
    bool result;
    //@ assert (-40 <= (n) && (n) <= 40);
    result = (n >= 30 && n <= 0);
    //@ assert result == (n >= 30 && n <= 0);
    return result;
}

/*@
    requires (-40 <= (n) && (n) <= 40);
    ensures \result == ((n >= 30 || n <= -10) || (n >= 30 && n <= 0));
*/
bool func_complex(int n)
{
    bool result1;
    bool result2;
    bool result;
    //@ assert (-40 <= (n) && (n) <= 40);
    result1 = (n >= 30 || n <= -10);
    //@ assert result1 == (n >= 30 || n <= -10);
    result2 = (n >= 30 && n <= 0);
    //@ assert result2 == (n >= 30 && n <= 0);
    result = result1 || result2;
    //@ assert result == ((n >= 30 || n <= -10) || (n >= 30 && n <= 0));
    return result;
}
