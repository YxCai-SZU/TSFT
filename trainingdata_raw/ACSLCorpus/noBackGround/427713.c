#include <stdbool.h>

/*@
  requires \valid_read(v+(0..2));
  requires ((v[0]) >= -100 && (v[1]) <= 100 && (v[2]) >= 0 && (v[2]) <= 100);
  ensures \result == (v[0] <= v[2] && v[2] <= v[1]);
*/
bool func(const long *v)
{
    long l;
    long r;
    long x;
    bool result;

    l = v[0];
    r = v[1];
    x = v[2];

    //@ assert l >= -100;
    //@ assert r <= 100;
    //@ assert x >= 0;
    //@ assert x <= 100;

    result = (l <= x) && (x <= r);
    return result;
}
