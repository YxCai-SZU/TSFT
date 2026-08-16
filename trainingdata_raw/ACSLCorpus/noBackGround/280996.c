/*@
    requires 1 <= a <= 5000;
    requires 1 <= b <= 5000;
    requires 1 <= c <= 5000;
    requires 1 <= d <= 5000;
    ensures \result >= (a < b ? a : b);
    ensures \result >= (c < d ? c : d);
    ensures \result <= a + c;
    ensures \result <= b + d;
*/
int func(int a, int b, int c, int d)
{
    int res;
    int tmp1;
    int tmp2;

    tmp1 = (a < b) ? a : b;
    tmp2 = (c < d) ? c : d;
    res = tmp1 + tmp2;

    //@ assert res >= (a < b ? a : b);
    //@ assert res >= (c < d ? c : d);
    //@ assert res <= a + c;
    //@ assert res <= b + d;

    return res;
}
