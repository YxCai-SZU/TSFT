#include <limits.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 1000;

    logic integer sum_ab(integer a, integer b) = a + b;
    logic integer sum_bc(integer a, integer b, integer c) = b + c;
    logic integer sum_cd(integer b, integer c, integer d) = c + d;
    logic integer sum_da(integer a, integer c, integer d) = d + a;

    predicate is_result(integer r, integer a, integer b, integer c, integer d) =
        r == sum_ab(a, b) ||
        r == sum_bc(a, b, c) ||
        r == sum_cd(b, c, d) ||
        r == sum_da(a, c, d);
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures is_result(\result, a, b, c, d);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int ab;
    int bc;
    int cd;
    int da;
    int max_ab_bc;
    int max_bc_cd;
    int max_cd_da;
    int max_da_ab;
    int max_ab_bc_cd;
    int max_bc_cd_da;
    int max_cd_da_ab;
    int max_da_ab_bc;
    int max;
    int result;

    ab = a + b;
    bc = b + c;
    cd = c + d;
    da = d + a;

    //@ assert ab == sum_ab(a, b);
    //@ assert bc == sum_bc(a, b, c);
    //@ assert cd == sum_cd(b, c, d);
    //@ assert da == sum_da(a, c, d);

    if (ab > bc) {
        max_ab_bc = ab;
    } else {
        max_ab_bc = bc;
    }

    if (bc > cd) {
        max_bc_cd = bc;
    } else {
        max_bc_cd = cd;
    }

    if (cd > da) {
        max_cd_da = cd;
    } else {
        max_cd_da = da;
    }

    if (da > ab) {
        max_da_ab = da;
    } else {
        max_da_ab = ab;
    }

    //@ assert max_ab_bc == ab || max_ab_bc == bc;
    //@ assert max_bc_cd == bc || max_bc_cd == cd;
    //@ assert max_cd_da == cd || max_cd_da == da;
    //@ assert max_da_ab == da || max_da_ab == ab;

    if (max_ab_bc > max_bc_cd) {
        max_ab_bc_cd = max_ab_bc;
    } else {
        max_ab_bc_cd = max_bc_cd;
    }

    if (max_bc_cd > max_cd_da) {
        max_bc_cd_da = max_bc_cd;
    } else {
        max_bc_cd_da = max_cd_da;
    }

    if (max_cd_da > max_da_ab) {
        max_cd_da_ab = max_cd_da;
    } else {
        max_cd_da_ab = max_da_ab;
    }

    if (max_da_ab > max_ab_bc) {
        max_da_ab_bc = max_da_ab;
    } else {
        max_da_ab_bc = max_ab_bc;
    }

    //@ assert max_ab_bc_cd == ab || max_ab_bc_cd == bc || max_ab_bc_cd == cd;
    //@ assert max_bc_cd_da == bc || max_bc_cd_da == cd || max_bc_cd_da == da;
    //@ assert max_cd_da_ab == cd || max_cd_da_ab == da || max_cd_da_ab == ab;
    //@ assert max_da_ab_bc == da || max_da_ab_bc == ab || max_da_ab_bc == bc;

    if (max_ab_bc_cd > max_bc_cd_da) {
        max = max_ab_bc_cd;
    } else {
        max = max_bc_cd_da;
    }

    //@ assert max == ab || max == bc || max == cd || max == da;

    if (max == max_cd_da_ab || max == max_da_ab_bc) {
        //@ assert max == ab || max == bc || max == cd || max == da;
        result = max;
    } else if (max_ab_bc == max) {
        //@ assert max_ab_bc == ab || max_ab_bc == bc;
        result = ab;
    } else if (max_bc_cd == max) {
        //@ assert max_bc_cd == bc || max_bc_cd == cd;
        result = bc;
    } else if (max_cd_da == max) {
        //@ assert max_cd_da == cd || max_cd_da == da;
        result = cd;
    } else {
        //@ assert max_da_ab == da || max_da_ab == ab;
        result = da;
    }

    //@ assert is_result(result, a, b, c, d);
    //@ assert result >= 0;
    return result;
}
