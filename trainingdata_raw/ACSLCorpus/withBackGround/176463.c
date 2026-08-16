#include <stdbool.h>

/*@
    predicate is_in_range(integer n) =
        1 <= n && n <= 10000;

    predicate is_in_range_a(integer a) =
        0 <= a && a < 1000;

    predicate is_in_range_b(integer b) =
        0 <= b && b < 1000;

    logic integer abs_val(integer n) =
        n < 0 ? -n : n;

    logic integer min_val(integer x, integer y) =
        x < y ? x : y;

    logic integer max_val(integer x, integer y) =
        x > y ? x : y;
*/

/*@
    requires is_in_range(n);
    requires is_in_range_a(a);
    requires is_in_range_b(b);
    ensures \result == ((n - 1) >= a && a >= 0);
*/
bool func(int n, int a, int b)
{
    int x;
    int min_val;
    int max_val;
    bool result;

    //@ assert is_in_range(n);
    //@ assert is_in_range_a(a);
    //@ assert is_in_range_b(b);

    // Implementing abs manually
    if (n - 1 < 0) {
        x = -(n - 1);
    } else {
        x = n - 1;
    }

    //@ assert x == abs_val(n - 1);

    // Implementing min manually
    if (x < b) {
        min_val = x;
    } else {
        min_val = b;
    }

    //@ assert min_val == min_val(x, b);

    // Implementing max manually
    if (min_val > a) {
        max_val = min_val;
    } else {
        max_val = a;
    }

    //@ assert max_val == max_val(min_val, a);

    result = (n - 1) >= a && a >= 0;

    //@ assert result == ((n - 1) >= a && a >= 0);
    return result;
}
