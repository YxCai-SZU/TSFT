#include <limits.h>

/*@
    requires (-100 <= (a) && (a) <= 100) && (-100 <= (b) && (b) <= 100) && (-100 <= (c) && (c) <= 100) && (-100 <= (d) && (d) <= 100);
    ensures \result == a + b || \result == b + c || \result == c + d || \result == d + a;
    ensures \result == b + c || \result == c + d || \result == d + a || \result == a + b;
    ensures \result == a + b || \result == c + d || \result == d + a || \result == b + c;
    ensures \result == a + b || \result == b + c || \result == d + a || \result == c + d;
*/
int func(int a, int b, int c, int d)
{
    int min_ab;
    int min_bc;
    int min_cd;
    int min_da;
    int min_ab_bc;
    int min_cd_da;
    int ans;

    //@ assert (-100 <= (a) && (a) <= 100) && (-100 <= (b) && (b) <= 100) && (-100 <= (c) && (c) <= 100) && (-100 <= (d) && (d) <= 100);

    //@ assert INT_MIN <= a + b && a + b <= INT_MAX;
    //@ assert INT_MIN <= b + c && b + c <= INT_MAX;
    //@ assert INT_MIN <= c + d && c + d <= INT_MAX;
    //@ assert INT_MIN <= d + a && d + a <= INT_MAX;

    min_ab = (a + b < b + c) ? (a + b) : (b + c);
    //@ assert min_ab == a + b || min_ab == b + c;

    min_bc = (b + c < c + d) ? (b + c) : (c + d);
    //@ assert min_bc == b + c || min_bc == c + d;

    min_cd = (c + d < d + a) ? (c + d) : (d + a);
    //@ assert min_cd == c + d || min_cd == d + a;

    min_da = (d + a < a + b) ? (d + a) : (a + b);
    //@ assert min_da == d + a || min_da == a + b;

    min_ab_bc = (min_ab < min_bc) ? min_ab : min_bc;
    //@ assert min_ab_bc == a + b || min_ab_bc == b + c || min_ab_bc == c + d;

    min_cd_da = (min_cd < min_da) ? min_cd : min_da;
    //@ assert min_cd_da == c + d || min_cd_da == d + a || min_cd_da == a + b;

    ans = (min_ab_bc < min_cd_da) ? min_ab_bc : min_cd_da;
    //@ assert ans == a + b || ans == b + c || ans == c + d || ans == d + a;

    return ans;
}
