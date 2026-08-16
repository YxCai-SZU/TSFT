/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    requires -100 <= d <= 100;
    ensures \result == a + b || \result == b + c || \result == c + d || \result == d + a;
    ensures \result >= a + b;
    ensures \result >= b + c;
    ensures \result >= c + d;
    ensures \result >= d + a;
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_bc;
    int max_cd;
    int max_ab_bc;
    int max_bc_cd;
    int max_ab_bc_cd;

    //@ assert (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);

    if (a + b > b + c) {
        max_ab = a + b;
    } else {
        max_ab = b + c;
    }

    if (b + c > c + d) {
        max_bc = b + c;
    } else {
        max_bc = c + d;
    }

    if (c + d > d + a) {
        max_cd = c + d;
    } else {
        max_cd = d + a;
    }

    if (max_ab > max_bc) {
        max_ab_bc = max_ab;
    } else {
        max_ab_bc = max_bc;
    }

    if (max_bc > max_cd) {
        max_bc_cd = max_bc;
    } else {
        max_bc_cd = max_cd;
    }

    if (max_ab_bc > max_bc_cd) {
        max_ab_bc_cd = max_ab_bc;
    } else {
        max_ab_bc_cd = max_bc_cd;
    }

    //@ assert max_ab_bc_cd >= a + b;
    //@ assert max_ab_bc_cd >= b + c;
    //@ assert max_ab_bc_cd >= c + d;
    //@ assert max_ab_bc_cd >= d + a;

    return max_ab_bc_cd;
}
