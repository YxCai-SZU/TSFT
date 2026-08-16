/*@
    requires 0 <= a < 124;
    requires 0 <= b < 124;
    requires 0 <= c < 124;
    requires 0 <= d < 124;
    requires 0 <= e < 124;
    requires 0 <= k <= 124;
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (e - a <= k);
    assigns \nothing;
*/
int func(int a, int b, int c, int d, int e, int k)
{
    int dist;
    //@ assert a < e;
    dist = e - a;
    //@ assert dist == e - a;
    return dist <= k;
}
