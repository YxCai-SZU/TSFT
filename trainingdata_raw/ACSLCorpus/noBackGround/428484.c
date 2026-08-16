#include <stdbool.h>

/*@
    requires \valid_read(v + (0..2));
    requires ((v[0]) >= 0 && (v[1]) >= 0 && (v[2]) >= 0);
    requires ((v[0]) + (v[1]) + (v[2]) <= 100);
    ensures \result == (v[0] + v[2] >= v[1]);
*/
bool func(long *v)
{
    long a;
    long b;
    long c;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert ((a) >= 0 && (b) >= 0 && (c) >= 0);
    //@ assert ((a) + (b) + (c) <= 100);
    //@ assert a >= 0 && b >= 0 && c >= 0;
    //@ assert a + b + c <= 100;

    result = (a + c >= b);
    //@ assert result == (a + c >= b);
    return result;
}
