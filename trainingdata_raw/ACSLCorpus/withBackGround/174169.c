#include <limits.h>
#include <stdbool.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 100;

    logic integer max_int = \max(0, (integer)LLONG_MAX);

    predicate no_overflow_xy_z(integer x, integer y, integer z) =
        x * y <= max_int - z;

    predicate no_overflow_xz_y(integer x, integer y, integer z) =
        x * z <= max_int - y;

    predicate no_overflow_yz_x(integer x, integer y, integer z) =
        y * z <= max_int - x;

    lemma overflow_lemma_1:
        \forall integer x, y, z;
            in_range(x) && in_range(y) && in_range(z) &&
            no_overflow_xy_z(x, y, z) &&
            no_overflow_xz_y(x, y, z) &&
            no_overflow_yz_x(x, y, z) ==>
            x * y + y * z + z * x <= max_int;

    lemma overflow_lemma_2:
        \forall integer x, y, z;
            in_range(x) && in_range(y) && in_range(z) &&
            no_overflow_xy_z(x, y, z) &&
            no_overflow_xz_y(x, y, z) &&
            no_overflow_yz_x(x, y, z) ==>
            2 * x * y * z <= max_int;
*/

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    requires 1 <= z <= 100;
    requires x * y <= \max(0, (integer)LLONG_MAX) - z;
    requires x * z <= \max(0, (integer)LLONG_MAX) - y;
    requires y * z <= \max(0, (integer)LLONG_MAX) - x;
    ensures \result == (x * y + y * z + z * x >= 2 * x * y * z);
*/
bool func(long long x, long long y, long long z)
{
    // Variable declarations at top of scope
    long long xy;
    long long yz;
    long long zx;
    long long sum;
    long long product;
    bool result;

    //@ assert 1 <= x <= 100;
    //@ assert 1 <= y <= 100;
    //@ assert 1 <= z <= 100;

    //@ assert x * y <= \max(0, (integer)LLONG_MAX) - z;
    //@ assert x * z <= \max(0, (integer)LLONG_MAX) - y;
    //@ assert y * z <= \max(0, (integer)LLONG_MAX) - x;

    //@ assert x * y + y * z + z * x <= \max(0, (integer)LLONG_MAX);
    //@ assert 2 * x * y * z <= \max(0, (integer)LLONG_MAX);

    xy = x * y;
    yz = y * z;
    zx = z * x;
    sum = xy + yz + zx;
    product = 2 * x * y * z;
    result = (sum >= product);

    return result;
}
