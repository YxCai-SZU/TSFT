/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires a == (long long)a;
    requires b == (long long)b;
    ensures \result >= 0;
    ensures ((\result) == (a) - 2 * (b) || (\result) == 0);
*/
long long func(long long a, long long b)
{
    long long ans;
    long long res;

    ans = a - 2 * b;

    //@ assert ans <= 0 || ans > 0;

    if (ans <= 0)
    {
        //@ assert ans <= 0;
        res = 0;
    }
    else
    {
        //@ assert ans > 0;
        res = ans;
    }

    //@ assert ((res) >= 0);
    //@ assert ((res) == (a) - 2 * (b) || (res) == 0);
    return res;
}
