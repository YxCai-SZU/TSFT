#include <limits.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        1 <= a && a <= 1000000000 &&
        1 <= b && b <= 1000000000 &&
        1 <= c && c <= 1000000000 &&
        1 <= k && k <= 1000000000 &&
        a + b + c >= k;

    logic integer compute_ans(integer a, integer b, integer c, integer k) =
        (k >= a ? k - a : 0) >= b ? 
        a - (c > (k >= a ? k - a : 0) - b ? (k >= a ? k - a : 0) - b : c) : 
        (k >= a ? a : k) - (c > 0 ? 0 : c);

    lemma ans_bounds: \forall integer a, b, c, k;
        valid_params(a, b, c, k) ==> 
        compute_ans(a, b, c, k) >= -c &&
        compute_ans(a, b, c, k) <= a;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result >= -c;
    ensures \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int a_var = a;
    int k_var = k;

    // takes A
    //@ assert a_var == a && k_var == k;
    if (k_var >= a_var)
    {
        //@ assert k_var >= a_var;
        k_var = k_var - a_var;
        //@ assert k_var == k - a;
    }
    else
    {
        //@ assert k_var < a_var;
        a_var = k_var;
        k_var = 0;
        //@ assert a_var == k && k_var == 0;
    }

    // takes B
    //@ assert a_var >= 0 && k_var >= 0;
    if (k_var >= b)
    {
        //@ assert k_var >= b;
        k_var = k_var - b;
        //@ assert k_var == k - a - b || k_var == 0;
    }
    else
    {
        //@ assert k_var < b;
        k_var = 0;
        //@ assert k_var == 0;
    }

    // takes C
    //@ assert k_var >= 0;
    int c_var;
    if (c > k_var)
    {
        //@ assert c > k_var;
        c_var = k_var;
        //@ assert c_var == k_var;
    }
    else
    {
        //@ assert c <= k_var;
        c_var = c;
        //@ assert c_var == c;
    }

    // Ensure no overflow/underflow for the expression `a_var - c_var`
    //@ assert a_var >= -c_var;
    //@ assert a_var - c_var <= a_var;

    int ans = a_var - c_var;
    //@ assert ans == compute_ans(a, b, c, k);
    return ans;
}
