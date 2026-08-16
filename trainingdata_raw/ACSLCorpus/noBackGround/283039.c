#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    ensures (((\result) == (a) || (\result) == (b) || (\result) == (c) || (\result) == (d)) &&
        ((\result) >= (a) && (\result) >= (b) && (\result) >= (c) && (\result) >= (d)));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max1;
    int max2;
    int max_val;

    max1 = (a > b) ? a : b;
    //@ assert max1 == a || max1 == b;
    //@ assert max1 >= a && max1 >= b;

    max2 = (c > d) ? c : d;
    //@ assert max2 == c || max2 == d;
    //@ assert max2 >= c && max2 >= d;

    max_val = (max1 > max2) ? max1 : max2;
    //@ assert max_val == max1 || max_val == max2;
    //@ assert max_val >= max1 && max_val >= max2;

    return max_val;
}

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    ensures (((\result) == (a) || (\result) == (b) || (\result) == (c) || (\result) == (d)) &&
        ((\result) <= (a) && (\result) <= (b) && (\result) <= (c) && (\result) <= (d)));
    assigns \nothing;
*/
int func_min(int a, int b, int c, int d)
{
    int min1;
    int min2;
    int min_val;

    min1 = (a < b) ? a : b;
    //@ assert min1 == a || min1 == b;
    //@ assert min1 <= a && min1 <= b;

    min2 = (c < d) ? c : d;
    //@ assert min2 == c || min2 == d;
    //@ assert min2 <= c && min2 <= d;

    min_val = (min1 < min2) ? min1 : min2;
    //@ assert min_val == min1 || min_val == min2;
    //@ assert min_val <= min1 && min_val <= min2;

    return min_val;
}

/*@
    requires (-100 <= (n) <= 100);
    ensures ((\result) == (n) * (n) && (\result) >= 0);
    assigns \nothing;
*/
int func_square(int n)
{
    int ans;

    //@ assert -100 <= n && n <= 100;
    //@ assert n * n >= 0 && n * n <= 10000;
    ans = n * n;
    return ans;
}
