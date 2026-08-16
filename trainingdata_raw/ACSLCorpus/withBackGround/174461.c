#include <limits.h>

/*@
    predicate is_in_range(integer x) = -100 <= x <= 100;

    logic integer max_of_two(integer x, integer y) = (x > y) ? x : y;

    lemma max_ge_a:
        \forall integer a, b, c, d, max_ab, max_bc, max_cd, max_ab_bc, max_bc_cd, max_ab_bc_cd;
        is_in_range(a) && is_in_range(b) && is_in_range(c) && is_in_range(d) &&
        max_ab == max_of_two(a, b) &&
        max_bc == max_of_two(b, c) &&
        max_cd == max_of_two(c, d) &&
        max_ab_bc == max_of_two(max_ab, max_bc) &&
        max_bc_cd == max_of_two(max_bc, max_cd) &&
        max_ab_bc_cd == max_of_two(max_ab_bc, max_bc_cd) ==>
        max_ab_bc_cd >= a;

    lemma max_ge_b:
        \forall integer a, b, c, d, max_ab, max_bc, max_cd, max_ab_bc, max_bc_cd, max_ab_bc_cd;
        is_in_range(a) && is_in_range(b) && is_in_range(c) && is_in_range(d) &&
        max_ab == max_of_two(a, b) &&
        max_bc == max_of_two(b, c) &&
        max_cd == max_of_two(c, d) &&
        max_ab_bc == max_of_two(max_ab, max_bc) &&
        max_bc_cd == max_of_two(max_bc, max_cd) &&
        max_ab_bc_cd == max_of_two(max_ab_bc, max_bc_cd) ==>
        max_ab_bc_cd >= b;

    lemma max_ge_c:
        \forall integer a, b, c, d, max_ab, max_bc, max_cd, max_ab_bc, max_bc_cd, max_ab_bc_cd;
        is_in_range(a) && is_in_range(b) && is_in_range(c) && is_in_range(d) &&
        max_ab == max_of_two(a, b) &&
        max_bc == max_of_two(b, c) &&
        max_cd == max_of_two(c, d) &&
        max_ab_bc == max_of_two(max_ab, max_bc) &&
        max_bc_cd == max_of_two(max_bc, max_cd) &&
        max_ab_bc_cd == max_of_two(max_ab_bc, max_bc_cd) ==>
        max_ab_bc_cd >= c;

    lemma max_ge_d:
        \forall integer a, b, c, d, max_ab, max_bc, max_cd, max_ab_bc, max_bc_cd, max_ab_bc_cd;
        is_in_range(a) && is_in_range(b) && is_in_range(c) && is_in_range(d) &&
        max_ab == max_of_two(a, b) &&
        max_bc == max_of_two(b, c) &&
        max_cd == max_of_two(c, d) &&
        max_ab_bc == max_of_two(max_ab, max_bc) &&
        max_bc_cd == max_of_two(max_bc, max_cd) &&
        max_ab_bc_cd == max_of_two(max_ab_bc, max_bc_cd) ==>
        max_ab_bc_cd >= d;

    lemma max_is_one_of:
        \forall integer a, b, c, d, max_ab, max_bc, max_cd, max_ab_bc, max_bc_cd, max_ab_bc_cd;
        is_in_range(a) && is_in_range(b) && is_in_range(c) && is_in_range(d) &&
        max_ab == max_of_two(a, b) &&
        max_bc == max_of_two(b, c) &&
        max_cd == max_of_two(c, d) &&
        max_ab_bc == max_of_two(max_ab, max_bc) &&
        max_bc_cd == max_of_two(max_bc, max_cd) &&
        max_ab_bc_cd == max_of_two(max_ab_bc, max_bc_cd) ==>
        (max_ab_bc_cd == a || max_ab_bc_cd == b || max_ab_bc_cd == c || max_ab_bc_cd == d);
*/

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    requires -100 <= d <= 100;
    ensures \result == a || \result == b || \result == c || \result == d;
    ensures \result >= a && \result >= b && \result >= c && \result >= d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_bc;
    int max_cd;
    int max_ab_bc;
    int max_bc_cd;
    int max_ab_bc_cd;

    //@ assert is_in_range(a);
    //@ assert is_in_range(b);
    //@ assert is_in_range(c);
    //@ assert is_in_range(d);

    max_ab = (a > b) ? a : b;
    //@ assert max_ab == max_of_two(a, b);

    max_bc = (b > c) ? b : c;
    //@ assert max_bc == max_of_two(b, c);

    max_cd = (c > d) ? c : d;
    //@ assert max_cd == max_of_two(c, d);

    max_ab_bc = (max_ab > max_bc) ? max_ab : max_bc;
    //@ assert max_ab_bc == max_of_two(max_ab, max_bc);

    max_bc_cd = (max_bc > max_cd) ? max_bc : max_cd;
    //@ assert max_bc_cd == max_of_two(max_bc, max_cd);

    max_ab_bc_cd = (max_ab_bc > max_bc_cd) ? max_ab_bc : max_bc_cd;
    //@ assert max_ab_bc_cd == max_of_two(max_ab_bc, max_bc_cd);

    //@ assert max_ab_bc_cd >= a;
    //@ assert max_ab_bc_cd >= b;
    //@ assert max_ab_bc_cd >= c;
    //@ assert max_ab_bc_cd >= d;

    //@ assert max_ab_bc_cd == a || max_ab_bc_cd == b || max_ab_bc_cd == c || max_ab_bc_cd == d;

    return max_ab_bc_cd;
}
