/*@
    requires (1 <= (d) <= 10000);
    requires (1 <= (t) <= 10000);
    requires (1 <= (s) <= 10000);
    ensures ((\result) == ((d) <= (t) * (s)));
*/
int func(long long d, long long t, long long s)
{
    // Variable declarations at top of scope
    long long product;
    int result;

    //@ assert 1 <= t <= 10000;
    //@ assert 1 <= s <= 10000;
    product = t * s;
    //@ assert product <= 10000 * 10000;
    result = d <= product;
    //@ assert result == (d <= t * s);
    return result;
}

#ifdef TEST
#include <assert.h>
int main()
{
    long long d = 10000;
    long long t = 10;
    long long s = 1000;
    int result = func(d, t, s);
    assert(result);
    return 0;
}
#endif
