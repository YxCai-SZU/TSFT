#include <stdbool.h>

/*@ predicate max_is_ge(integer a, integer b, integer max_val) =
      (a > b ==> max_val == a) && (a <= b ==> max_val == b) && max_val >= a && max_val >= b;
*/

/*@ predicate min_is_le(integer a, integer b, integer min_val) =
      (a < b ==> min_val == a) && (a >= b ==> min_val == b) && min_val <= a && min_val <= b;
*/

/*@ predicate abs_diff(integer a, integer b, integer abs_val) =
      (a - b < 0 ==> abs_val == b - a) && (a - b >= 0 ==> abs_val == a - b) && abs_val >= 0;
*/

/*@ predicate equality_check(integer max_val, integer min_val, bool is_equal) =
      is_equal == (max_val - min_val == 0);
*/

/*@ lemma max_min_relation:
      \forall integer a, b, max_val, min_val;
      max_is_ge(a, b, max_val) && min_is_le(a, b, min_val) ==> max_val >= min_val;
*/

/*@ lemma abs_diff_relation:
      \forall integer a, b, max_val, min_val, abs_val;
      max_is_ge(a, b, max_val) && min_is_le(a, b, min_val) && abs_diff(a, b, abs_val) ==>
      abs_val == max_val - min_val;
*/

/*@ lemma equality_relation:
      \forall integer max_val, min_val;
      \forall bool is_equal;
      equality_check(max_val, min_val, is_equal) ==> is_equal == (max_val == min_val);
*/

/*@ requires 1 <= a <= 100;
    requires 0 <= b <= a;
    ensures \result == (a == b);
*/
bool func(long a, long b) {
    long max_val;
    long min_val;
    long abs_val;
    bool is_equal;

    // Calculate max_val
    if (a > b) {
        max_val = a;
    } else {
        max_val = b;
    }
    //@ assert max_is_ge(a, b, max_val);

    // Calculate min_val
    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }
    //@ assert min_is_le(a, b, min_val);

    // Calculate abs_val
    if (a - b < 0) {
        abs_val = b - a;
    } else {
        abs_val = a - b;
    }
    //@ assert abs_diff(a, b, abs_val);

    // Calculate is_equal
    if (max_val - min_val == 0) {
        is_equal = true;
    } else {
        is_equal = false;
    }
    //@ assert equality_check(max_val, min_val, is_equal);

    return is_equal;
}
