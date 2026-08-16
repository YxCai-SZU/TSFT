#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer min(integer x, integer y) = (x < y) ? x : y;
    logic integer max(integer x, integer y) = (x > y) ? x : y;

    lemma max_non_negative:
        \forall integer a, b, c, d;
            valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
            max(max(max(a - min(a,b), b - min(a,b)), c - min(c,d)), d - min(c,d)) >= 0;

    lemma max_bound:
        \forall integer a, b, c, d;
            valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
            max(max(max(a - min(a,b), b - min(a,b)), c - min(c,d)), d - min(c,d)) <= a + b + c + d;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result >= 0;
    ensures \result <= a + b + c + d;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t a_copy;
    int64_t b_copy;
    int64_t c_copy;
    int64_t d_copy;
    int64_t min_val;
    int64_t max_val;
    int64_t result;

    a_copy = a;
    b_copy = b;
    c_copy = c;
    d_copy = d;

    //@ assert valid_range(a_copy) && valid_range(b_copy) && valid_range(c_copy) && valid_range(d_copy);

    min_val = (a_copy < b_copy) ? a_copy : b_copy;
    a_copy = a_copy - min_val;
    b_copy = b_copy - min_val;

    //@ assert a_copy >= 0 && b_copy >= 0;

    min_val = (c_copy < d_copy) ? c_copy : d_copy;
    c_copy = c_copy - min_val;
    d_copy = d_copy - min_val;

    //@ assert c_copy >= 0 && d_copy >= 0;

    max_val = (a_copy > b_copy) ? a_copy : b_copy;
    max_val = (max_val > c_copy) ? max_val : c_copy;
    max_val = (max_val > d_copy) ? max_val : d_copy;

    //@ assert max_val >= 0;
    //@ assert max_val <= a + b + c + d;

    result = min_val + max_val;
    //@ assert result >= 0;
    //@ assert result <= a + b + c + d;

    return result;
}
