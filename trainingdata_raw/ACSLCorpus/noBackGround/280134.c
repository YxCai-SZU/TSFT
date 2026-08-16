#include <limits.h>

/*@
    requires ((((a)) >= 0) && (((b)) >= 0) && (((c)) >= 0) &&
        (k) >= 1 && (k) <= (a) + (b) + (c) && (a) + (b) + (c) <= 2000000000);
    ensures \result <= a + b + c;
    ensures \result >= k - b - c;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int min_a;
    int k_remaining;
    int min_b;
    int min_c;
    int min_sum;

    //@ assert ((a) >= 0);
    //@ assert ((b) >= 0);
    //@ assert ((c) >= 0);
    //@ assert k >= 1 && k <= a + b + c;

    min_a = (a < k) ? a : k;
    k_remaining = k - min_a;
    //@ assert k_remaining >= 0;

    min_b = (b < k_remaining) ? b : k_remaining;
    //@ assert min_b >= 0;

    min_c = (c < k_remaining - min_b) ? c : (k_remaining - min_b);
    //@ assert min_c >= 0;

    //@ assert k_remaining - min_b - min_c >= 0;
    min_sum = min_a - (k_remaining - min_b - min_c);

    //@ assert min_sum <= a + b + c;
    //@ assert min_sum >= k - b - c;

    return min_sum;
}
