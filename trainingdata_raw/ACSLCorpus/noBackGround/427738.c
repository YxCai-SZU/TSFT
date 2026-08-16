#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    ensures \result == a || \result == b || \result == c || \result == d;
    ensures \result >= a || \result >= b || \result >= c || \result >= d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_cd;
    int res;

    max_ab = (a > b) ? a : b;
    max_cd = (c > d) ? c : d;
    res = (max_ab > max_cd) ? max_ab : max_cd;

    //@ assert max_ab >= a && max_ab >= b;
    //@ assert max_cd >= c && max_cd >= d;
    //@ assert max_ab == a || max_ab == b;
    //@ assert max_cd == c || max_cd == d;
    //@ assert max_ab >= a || max_ab >= b;
    //@ assert max_cd >= c || max_cd >= d;
    //@ assert max_ab >= a && max_ab >= b;
    //@ assert max_cd >= c && max_cd >= d;

    return res;
}

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    ensures \result == a || \result == b || \result == c || \result == d;
    ensures \result >= a || \result >= b || \result >= c || \result >= d;
    assigns \nothing;
*/
int func2(int a, int b, int c, int d)
{
    int max_ab;
    int max_cd;
    int res;

    max_ab = (a > b) ? a : b;
    max_cd = (c > d) ? c : d;
    res = (max_ab > max_cd) ? max_ab : max_cd;

    //@ assert max_ab >= a && max_ab >= b;
    //@ assert max_cd >= c && max_cd >= d;
    //@ assert max_ab == a || max_ab == b;
    //@ assert max_cd == c || max_cd == d;

    return res;
}

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    ensures \result == a || \result == b || \result == c || \result == d;
    ensures \result >= a || \result >= b || \result >= c || \result >= d;
    assigns \nothing;
*/
int func3(int a, int b, int c, int d)
{
    int max_ab;
    int max_cd;
    int res;

    max_ab = (a > b) ? a : b;
    max_cd = (c > d) ? c : d;
    res = (max_ab > max_cd) ? max_ab : max_cd;

    //@ assert max_ab >= a && max_ab >= b;
    //@ assert max_cd >= c && max_cd >= d;
    //@ assert max_ab == a || max_ab == b;
    //@ assert max_cd == c || max_cd == d;
    //@ assert max_ab >= a || max_ab >= b;
    //@ assert max_cd >= c || max_cd >= d;

    return res;
}

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    ensures \result == a || \result == b || \result == c || \result == d;
    ensures \result >= a || \result >= b || \result >= c || \result >= d;
    assigns \nothing;
*/
int func4(int a, int b, int c, int d)
{
    int max_ab;
    int max_cd;
    int res;

    max_ab = (a > b) ? a : b;
    max_cd = (c > d) ? c : d;
    res = (max_ab > max_cd) ? max_ab : max_cd;

    //@ assert max_ab >= a && max_ab >= b;
    //@ assert max_cd >= c && max_cd >= d;
    //@ assert max_ab == a || max_ab == b;
    //@ assert max_cd == c || max_cd == d;
    //@ assert max_ab >= a || max_ab >= b;
    //@ assert max_cd >= c || max_cd >= d;
    //@ assert max_ab >= a && max_ab >= b;
    //@ assert max_cd >= c && max_cd >= d;

    return res;
}
