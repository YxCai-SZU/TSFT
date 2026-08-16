#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000);
    requires (1 <= (t) <= 10000);
    requires (1 <= (s) <= 10000);
    ensures \result == (t * s >= d);
*/
bool func(int d, int t, int s)
{
    // Variable declarations at scope top
    bool result;

    // Precondition assertions to prevent overflow
    //@ assert 1 <= t * s <= 100000000;

    //@ assert 1 <= t * s;

    result = (t * s >= d);
    return result;
}

int main()
{
    // Variable declarations at scope top
    int d;
    int t;
    int s;
    bool result;

    d = 100;
    t = 3;
    s = 60;
    result = func(d, t, s);
    return 0;
}
