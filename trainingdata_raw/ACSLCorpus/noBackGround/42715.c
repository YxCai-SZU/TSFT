#include <stdbool.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (d) >= 0 && (e) >= 0 &&
        (a) <= 123 && (b) <= 123 && (c) <= 123 && (d) <= 123 && (e) <= 123);
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (e - a <= k);
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long dist;
    bool result;

    dist = e - a;
    //@ assert dist == e - a;

    if (dist > k)
    {
        result = false;
        //@ assert !(e - a <= k);
    }
    else
    {
        //@ assert dist <= k;
        //@ assert e - a <= k;
        result = true;
    }

    return result;
}

#ifdef TEST
#include <assert.h>
int main()
{
    bool res = func(1, 2, 3, 4, 5, 5);
    assert(res == true);
    return 0;
}
#endif
