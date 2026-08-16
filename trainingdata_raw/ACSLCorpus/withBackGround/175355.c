#include <stdbool.h>

/*@
    predicate is_ordered(integer a, integer b, integer c, integer d, integer e) =
        (0 <= a) && (a < b) && (b < c) && (c < d) && (d < e) && (e <= 123);
    predicate k_in_range(integer k) = (0 <= k) && (k <= 123);
    logic integer diff_e_a(integer e, integer a) = e - a;
    logic integer diff_b_a(integer b, integer a) = b - a;
    logic integer diff_c_a(integer c, integer a) = c - a;
    logic integer diff_d_a(integer d, integer a) = d - a;
    predicate result_condition(integer k, integer e, integer a, integer b, integer c, integer d) =
        (k >= diff_e_a(e, a)) ||
        (diff_b_a(b, a) <= k) ||
        (diff_c_a(c, a) <= k) ||
        (diff_d_a(d, a) <= k) ||
        (diff_e_a(e, a) <= k);
    lemma diff_bounds:
        \forall integer a, b, c, d, e, k;
        is_ordered(a, b, c, d, e) && k_in_range(k) ==>
        (diff_e_a(e, a) <= 123) &&
        (diff_b_a(b, a) <= 123) &&
        (diff_c_a(c, a) <= 123) &&
        (diff_d_a(d, a) <= 123);
*/

/*@ requires
        is_ordered(a, b, c, d, e) && k_in_range(k);
    ensures
        \result == true <==> result_condition(k, e, a, b, c, d);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c,
          unsigned long long d, unsigned long long e, unsigned long long k)
{
    // Variable declarations
    bool result = false;
    unsigned long long diff_ea = 0;
    unsigned long long diff_ba = 0;
    unsigned long long diff_ca = 0;
    unsigned long long diff_da = 0;

    // Precondition bounds verification
    //@ assert diff_e_a(e, a) <= 123;
    diff_ea = e - a;
    //@ assert diff_b_a(b, a) <= 123;
    diff_ba = b - a;
    //@ assert diff_c_a(c, a) <= 123;
    diff_ca = c - a;
    //@ assert diff_d_a(d, a) <= 123;
    diff_da = d - a;

    if (k >= diff_ea) {
        result = true;
        //@ assert result_condition(k, e, a, b, c, d);
        return result;
    }
    if (diff_ba <= k) {
        result = true;
        //@ assert result_condition(k, e, a, b, c, d);
        return result;
    }
    if (diff_ca <= k) {
        result = true;
        //@ assert result_condition(k, e, a, b, c, d);
        return result;
    }
    if (diff_da <= k) {
        result = true;
        //@ assert result_condition(k, e, a, b, c, d);
        return result;
    }
    if (diff_ea <= k) {
        result = true;
        //@ assert result_condition(k, e, a, b, c, d);
        return result;
    }

    // Final case verification
    //@ assert k < diff_e_a(e, a) && k < diff_b_a(b, a) && k < diff_c_a(c, a) && k < diff_d_a(d, a);
    result = false;
    //@ assert !result_condition(k, e, a, b, c, d);
    return result;
}
