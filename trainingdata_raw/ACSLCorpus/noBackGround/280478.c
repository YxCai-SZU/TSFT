#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> ((b) - (a) == (c) - (b));
*/
bool func(int a, int b, int c)
{
    int m;
    int n;
    bool result;

    m = b - a;
    n = c - b;

    //@ assert m == b - a;
    //@ assert n == c - b;

    result = (m == n);
    return result;
}

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> ((b) - (a) == (c) - (b));
*/
bool func2(int a, int b, int c)
{
    int m;
    int n;
    bool result;

    m = b - a;
    n = c - b;

    //@ assert m == b - a;
    //@ assert n == c - b;
    //@ assert m == n || m != n;

    result = (m == n);
    return result;
}
