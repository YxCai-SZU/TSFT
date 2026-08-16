#include <stdint.h>

/*@
    predicate valid_range(integer n, integer a) =
        1 <= n <= 100 && 0 <= a <= n * n;

    lemma n_squared_bounds:
        \forall integer n; 1 <= n <= 100 ==> 1 <= n * n <= 10000;
*/

/*@
    requires valid_range(n, a);
    ensures \result == n * n - a;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t a)
{
    // Variable declarations at scope top
    int64_t result;

    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= a && a <= n * n;
    //@ assert n * n <= 10000;
    //@ assert n * n >= 1;

    result = n * n - a;
    return result;
}

#ifdef TEST
#include <assert.h>
int main()
{
    int64_t n = 5;
    int64_t a = 3;
    int64_t result = func(n, a);
    assert(result == 25 - 3);
    return 0;
}
#endif
