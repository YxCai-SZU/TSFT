/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer max_of_two(integer x, integer y) = x > y ? x : y;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result >= a && \result >= b && \result >= c && \result >= d;
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_bc;
    int max_cd;
    int max_ac;
    int max_bd;
    int max_ab_cd;
    int max_ac_bd;
    int result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);

    max_ab = a > b ? a : b;
    max_bc = b > c ? b : c;
    max_cd = c > d ? c : d;
    max_ac = a > c ? a : c;
    max_bd = b > d ? b : d;
    max_ab_cd = max_ab > max_cd ? max_ab : max_cd;
    max_ac_bd = max_ac > max_bd ? max_ac : max_bd;

    //@ assert max_ab_cd >= a && max_ab_cd >= b && max_ab_cd >= c && max_ab_cd >= d;
    //@ assert max_ac_bd >= a && max_ac_bd >= b && max_ac_bd >= c && max_ac_bd >= d;

    result = max_ab_cd > max_ac_bd ? max_ab_cd : max_ac_bd;
    return result;
}
