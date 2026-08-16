/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == ((a) + (b) + (c) + (d) - 3 * (((a)) > ((b)) ? ((a)) : ((b))) - 3 * (((c)) > ((d)) ? ((c)) : ((d))));
*/
int func(int a, int b, int c, int d)
{
    int min_ab;
    int min_cd;
    int min_all;
    int ans;
    int max_ab;
    int max_cd;

    min_ab = a < b ? a : b;
    min_cd = c < d ? c : d;
    min_all = min_ab < min_cd ? min_ab : min_cd;

    max_ab = a > b ? a : b;
    max_cd = c > d ? c : d;

    ans = a + b + c + d - 3 * max_ab - 3 * max_cd;

    //@ assert (((a) > (b) ==> (max_ab) == (a)) && ((a) <= (b) ==> (max_ab) == (b)));
    //@ assert (((c) > (d) ==> (max_cd) == (c)) && ((c) <= (d) ==> (max_cd) == (d)));
    //@ assert ans == ((a) + (b) + (c) + (d) - 3 * (((a)) > ((b)) ? ((a)) : ((b))) - 3 * (((c)) > ((d)) ? ((c)) : ((d))));

    return ans;
}
