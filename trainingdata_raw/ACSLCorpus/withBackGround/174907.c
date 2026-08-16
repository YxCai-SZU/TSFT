#include <stdint.h>

/*@
    predicate in_range(integer x) = -1000000000 <= x <= 1000000000;
    predicate product_in_range(integer a, integer b) = -1000000000000000000 <= a * b <= 1000000000000000000;
    logic integer max(integer a, integer b) = a > b ? a : b;
*/

/*@
    requires \valid_read(v + (0..3));
    requires in_range(v[0]) && in_range(v[1]) && in_range(v[2]) && in_range(v[3]);
    ensures \result == v[0] * v[2] || \result == v[0] * v[3] || \result == v[1] * v[2] || \result == v[1] * v[3];
    assigns \nothing;
*/
int64_t func(const int64_t v[4])
{
    int64_t ans;
    //@ assert in_range(v[0]);
    //@ assert in_range(v[2]);
    //@ assert product_in_range(v[0], v[2]);
    ans = v[0] * v[2];
    
    //@ assert in_range(v[0]);
    //@ assert in_range(v[3]);
    //@ assert product_in_range(v[0], v[3]);
    if (v[0] * v[3] > ans) {
        ans = v[0] * v[3];
    }
    
    //@ assert in_range(v[1]);
    //@ assert in_range(v[2]);
    //@ assert product_in_range(v[1], v[2]);
    if (v[1] * v[2] > ans) {
        ans = v[1] * v[2];
    }
    
    //@ assert in_range(v[1]);
    //@ assert in_range(v[3]);
    //@ assert product_in_range(v[1], v[3]);
    if (v[1] * v[3] > ans) {
        ans = v[1] * v[3];
    }
    
    return ans;
}
