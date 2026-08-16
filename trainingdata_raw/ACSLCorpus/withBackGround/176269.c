#include <limits.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a <= 20 && 1 <= b <= 20 && 1 <= c <= 20;

    logic integer abs_val(integer x) = x >= 0 ? x : -x;

    logic integer max_val(integer x, integer y) = x >= y ? x : y;

    lemma ans_nonnegative:
        \forall integer a, b, c, result, max_val;
        valid_input(a, b, c) && result >= 0 && max_val >= 0 && max_val >= result ==>
        max_val - result >= 0;
*/

/*@
    requires \valid(input + (0..2));
    requires 1 <= input[0] <= 20;
    requires 1 <= input[1] <= 20;
    requires 1 <= input[2] <= 20;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= input[0] + input[1] + input[2];
*/
int func(int input[3]) {
    int result;
    int a;
    int b;
    int c;
    int diff1;
    int diff2;
    int diff3;
    int max_val;
    int ans;

    result = INT_MAX;
    a = input[0];
    b = input[1];
    c = input[2];

    //@ assert valid_input(a, b, c);

    // Implementing abs manually
    if (a + b + 1 - c < 0) {
        diff1 = -(a + b + 1 - c);
    } else {
        diff1 = a + b + 1 - c;
    }
    //@ assert diff1 == abs_val(a + b + 1 - c);
    if (diff1 < result) {
        result = diff1;
    }

    // Implementing abs manually
    if (a + c + 1 - b < 0) {
        diff2 = -(a + c + 1 - b);
    } else {
        diff2 = a + c + 1 - b;
    }
    //@ assert diff2 == abs_val(a + c + 1 - b);
    if (diff2 < result) {
        result = diff2;
    }

    // Implementing abs manually
    if (b + c + 1 - a < 0) {
        diff3 = -(b + c + 1 - a);
    } else {
        diff3 = b + c + 1 - a;
    }
    //@ assert diff3 == abs_val(b + c + 1 - a);
    if (diff3 < result) {
        result = diff3;
    }

    //@ assert result >= 0;

    // Implementing max manually
    if (a + b + 1 > b + c + 1) {
        max_val = a + b + 1;
    } else {
        max_val = b + c + 1;
    }
    if (max_val > a + c + 1) {
        max_val = max_val;
    } else {
        max_val = a + c + 1;
    }

    //@ assert max_val >= 0;
    //@ assert max_val >= result;

    ans = max_val - result;

    //@ assert ans >= 0;
    //@ assert ans <= a + b + c;

    return ans;
}
