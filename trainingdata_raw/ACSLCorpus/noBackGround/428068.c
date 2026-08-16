/*@
    requires ((n) >= 1 && (n) <= 100 && (m) >= 0 && (m) <= (n) * (n));
    ensures \result == ((n) * (n) - (m));
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at scope top
    int result;

    //@ assert n >= 1 && n <= 100;
    //@ assert m >= 0 && m <= n * n;
    //@ assert n * n <= 10000;

    result = n * n - m;
    return result;
}

#ifdef TESTING
#include <assert.h>

void test_input(void)
{
    int n = 5;
    int m = 7;
    int result = func(n, m);
    assert(result == 18);
}

int main(void)
{
    test_input();
    return 0;
}
#endif
