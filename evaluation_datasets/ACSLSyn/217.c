#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_zero_or_one(integer x) = x == 0 || x == 1; */

/*@ predicate vector_props(int* v, integer len) =
        len == 3 &&
        \forall integer i; 0 <= i < len ==> is_zero_or_one(v[i]); */

/*@ lemma cnt_relation:
        \forall int* v, integer i, integer cnt;
        vector_props(v, 3) && 0 <= i <= 3 && 0 <= cnt <= i &&
        (i == 0 ==> cnt == 0) &&
        (i == 1 ==> cnt == v[0]) &&
        (i == 2 ==> cnt == v[0] + v[1]) &&
        (i == 3 ==> cnt == v[0] + v[1] + v[2]) ==>
        cnt == (i == 0 ? 0 : (i == 1 ? v[0] : (i == 2 ? v[0] + v[1] : v[0] + v[1] + v[2]))); */

bool func1(int* v) {
    int cnt = 0;
    int i = 0;
    
    while (i < 3) {
        //@ assert vector_props(v, 3);
        cnt += v[i];
        i++;
    }
    
    //@ assert cnt == v[0] + v[1] + v[2];
    return cnt < 3;
}

/*@
    predicate valid_input(integer a, integer b, integer c) =
        0 <= a && a <= 50 &&
        0 <= b && b <= 50 &&
        0 <= c && c <= 50 &&
        a + b + 1 <= c;

    logic integer compute_result(integer a, integer b, integer c) =
        c - (a + b + 1);
*/

int64_t func2(int64_t a, int64_t b, int64_t c)
{
    //@ assert a + b + 1 <= c;
    return c - (a + b + 1);
}

/* 
 * Scenario: Network packet buffer validation
 * Description: This function validates a network packet buffer represented as a vector of 3 binary flags,
 * and then computes the available payload space based on header sizes.
 * The buffer flags indicate packet priority (0 or 1 each), and the function ensures:
 * - The buffer contains valid binary flags (handled by func1)
 * - The priority sum is less than 3 (at least one non-priority flag)
 * - The header sizes (a=header1, b=header2) are within valid range and leave room for payload (c)
 * The final assertion verifies that the computed payload space is non-negative.
 */

int64_t synthesized_func(int* v, int64_t a, int64_t b, int64_t c) {
    bool has_zero = func1(v);
    //@ assert has_zero == (v[0] == 0 || v[1] == 0 || v[2] == 0);
    
    if (has_zero) {
        int64_t payload = func2(a, b, c);
        //@ assert payload == c - (a + b + 1);
        //@ assert payload >= 0;
        return payload;
    } else {
        int64_t payload = func2(a, b, c);
        //@ assert payload == c - (a + b + 1);
        //@ assert payload >= 0;
        return payload;
    }
}
