#include <stdbool.h>

/*@
    requires \valid_read(v + (0..2));
    requires v[0] >= -100 && v[0] <= 100;
    requires v[1] >= -100 && v[1] <= 100;
    requires v[2] >= -100 && v[2] <= 100;
    ensures \result == true <==> ((v[0]) < (v[1]) && (v[1]) < (v[2]));
*/
bool func(const long long *v)
{
    long long a;
    long long b;
    long long c;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert a == v[0];
    //@ assert b == v[1];
    //@ assert c == v[2];

    if (a < b && b < c)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == true <==> ((v[0]) < (v[1]) && (v[1]) < (v[2]));
    return result;
}
