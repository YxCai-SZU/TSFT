/*@
    predicate is_valid_param(integer v) = 1 <= v && v <= 10000;
    predicate max_ab_is_a_or_b(integer a, integer b, integer max_ab) =
        max_ab == a || max_ab == b;
    predicate max_cd_is_c_or_d(integer c, integer d, integer max_cd) =
        max_cd == c || max_cd == d;
    predicate result_valid(integer a, integer b, integer c, integer d, integer result) =
        result == a + c || result == a + d || result == b + c || result == b + d;
*/

/*@
    requires is_valid_param(a) && is_valid_param(b) && is_valid_param(c) && is_valid_param(d);
    ensures result_valid(a, b, c, d, \result);
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_cd;
    int result;

    max_ab = (a > b) ? a : b;
    max_cd = (c > d) ? c : d;

    //@ assert max_ab_is_a_or_b(a, b, max_ab);
    //@ assert max_cd_is_c_or_d(c, d, max_cd);

    result = max_ab + max_cd;
    return result;
}

/*@
    requires is_valid_param(a) && is_valid_param(b) && is_valid_param(c) && is_valid_param(d);
    ensures result_valid(a, b, c, d, \result);
*/
int func_for(int a, int b, int c, int d)
{
    int max_ab;
    int max_cd;
    int result;

    max_ab = a;
    if (b > max_ab) {
        max_ab = b;
    }

    max_cd = c;
    if (d > max_cd) {
        max_cd = d;
    }

    //@ assert max_ab_is_a_or_b(a, b, max_ab);
    //@ assert max_cd_is_c_or_d(c, d, max_cd);

    result = max_ab + max_cd;
    return result;
}
