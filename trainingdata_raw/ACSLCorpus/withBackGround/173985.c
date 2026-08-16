/*@
    predicate is_in_range(integer x) = -100 <= x && x <= 100;
    predicate is_one_of(integer res, integer a, integer b, integer c, integer d) =
        res == a || res == b || res == c || res == d;
    predicate is_ge_one_of(integer res, integer a, integer b, integer c, integer d) =
        res >= a || res >= b || res >= c || res >= d;
    lemma max_property:
        \forall integer a,b,c,d, max_ab, max_bc, max_cd, max_ac, max_bd,
            max_max_ab_bc, max_max_cd_ac, max_max_bd;
            is_in_range(a) && is_in_range(b) && is_in_range(c) && is_in_range(d) &&
            max_ab == (a > b ? a : b) &&
            max_bc == (b > c ? b : c) &&
            max_cd == (c > d ? c : d) &&
            max_ac == (a > c ? a : c) &&
            max_bd == (b > d ? b : d) &&
            max_max_ab_bc == (max_ab > max_bc ? max_ab : max_bc) &&
            max_max_cd_ac == (max_cd > max_ac ? max_cd : max_ac) &&
            max_max_bd == (max_bd > max_max_cd_ac ? max_bd : max_max_cd_ac) ==>
            is_one_of(max_max_ab_bc, a, b, c, d) &&
            is_ge_one_of(max_max_ab_bc, a, b, c, d) &&
            is_one_of(max_max_cd_ac, a, b, c, d) &&
            is_ge_one_of(max_max_cd_ac, a, b, c, d) &&
            is_one_of(max_max_bd, a, b, c, d) &&
            is_ge_one_of(max_max_bd, a, b, c, d);
*/

/*@
    requires is_in_range(a) && is_in_range(b) && is_in_range(c) && is_in_range(d);
    ensures is_one_of(\result, a, b, c, d);
    ensures is_ge_one_of(\result, a, b, c, d);
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_bc;
    int max_cd;
    int max_ac;
    int max_bd;
    int max_max_ab_bc;
    int max_max_cd_ac;
    int max_max_bd;
    int result;

    max_ab = (a > b) ? a : b;
    max_bc = (b > c) ? b : c;
    max_cd = (c > d) ? c : d;
    max_ac = (a > c) ? a : c;
    max_bd = (b > d) ? b : d;
    max_max_ab_bc = (max_ab > max_bc) ? max_ab : max_bc;
    max_max_cd_ac = (max_cd > max_ac) ? max_cd : max_ac;
    max_max_bd = (max_bd > max_max_cd_ac) ? max_bd : max_max_cd_ac;

    //@ assert is_one_of(max_max_ab_bc, a, b, c, d);
    //@ assert is_ge_one_of(max_max_ab_bc, a, b, c, d);
    //@ assert is_one_of(max_max_cd_ac, a, b, c, d);
    //@ assert is_ge_one_of(max_max_cd_ac, a, b, c, d);
    //@ assert is_one_of(max_max_bd, a, b, c, d);
    //@ assert is_ge_one_of(max_max_bd, a, b, c, d);

    result = (max_ab > max_max_bd) ? max_ab : max_max_bd;
    return result;
}
