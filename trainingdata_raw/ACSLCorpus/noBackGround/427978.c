#include <limits.h>

/*@
    requires (0 <= (a) <= 1000000000 &&
        0 <= (b) <= 1000000000 &&
        0 <= (c) <= 1000000000 &&
        1 <= (k) <= 1000000000 &&
        (a) + (b) + (c) >= (k));
    ensures \result <= k;
    ensures 0 <= \result <= INT_MAX;
*/
int func(int a, int b, int c, int k)
{
    int min_a;
    int min_b;
    int min_c;
    int max_val;

    //@ assert 0 <= a <= 1000000000;
    //@ assert 0 <= b <= 1000000000;
    //@ assert 0 <= c <= 1000000000;
    //@ assert 1 <= k <= 1000000000;
    //@ assert a + b + c >= k;

    min_a = a < k ? a : k;
    //@ assert 0 <= min_a <= k;

    min_b = b < k - min_a ? b : k - min_a;
    //@ assert 0 <= min_b <= k - min_a;

    min_c = c < k - min_a - min_b ? c : k - min_a - min_b;
    //@ assert 0 <= min_c <= k - min_a - min_b;

    //@ assert 0 <= min_a <= INT_MAX;
    //@ assert 0 <= min_c <= INT_MAX;
    //@ assert min_a - min_c <= INT_MAX;

    max_val = min_a - min_c > 0 ? min_a - min_c : 0;
    //@ assert 0 <= max_val <= INT_MAX;
    //@ assert max_val <= k;

    return max_val;
}
