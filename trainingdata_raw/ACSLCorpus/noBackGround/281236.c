#include <stdbool.h>

/*@
    requires (-40 <= (x) && (x) <= 40);
    ensures \result == (x >= 30);
*/
bool func(int x)
{
    bool result;
    //@ assert (-40 <= (x) && (x) <= 40);
    result = (x >= 30);
    return result;
}

/*@
    requires (-40 <= (a) && (a) <= 40) && (-40 <= (b) && (b) <= 40) && (-40 <= (c) && (c) <= 40);
    ensures \result == (a < b && b < c);
*/
bool func2(int a, int b, int c)
{
    bool result;
    //@ assert (-40 <= (a) && (a) <= 40) && (-40 <= (b) && (b) <= 40) && (-40 <= (c) && (c) <= 40);
    result = (a < b) && (b < c);
    return result;
}

/*@
    requires (1 <= (k) && (k) <= 100) && (1 <= (x) && (x) <= 100);
    ensures \result == (k >= x || (k < x && x - k <= 1));
*/
bool func3(int k, int x)
{
    bool result;
    int d;
    //@ assert (1 <= (k) && (k) <= 100);
    //@ assert (1 <= (x) && (x) <= 100);
    d = (k < x) ? k : x;
    result = (k >= x) || (k < x && x - k <= 1);
    return result;
}
