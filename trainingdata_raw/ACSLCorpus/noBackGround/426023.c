/*@
    requires a >= 0 && b >= 0 && c >= 0;
    requires 1 <= k && k <= a + b + c;
    ensures \result == ((k) <= (a) ? (k) :
        (k) <= (a) + (b) ? (a) :
        (a) - ((k) - ((a) + (b))));
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int k_remaining;
    int res;

    k_remaining = k;
    res = 0;

    if (k_remaining > a)
    {
        res += a;
        k_remaining -= a;
    }
    else
    {
        res += k_remaining;
        k_remaining = 0;
    }

    //@ assert k <= a ==> res == k;
    //@ assert k > a && k <= a + b ==> res == a;

    if (k_remaining > b)
    {
        k_remaining -= b;
    }
    else
    {
        k_remaining = 0;
    }

    res -= k_remaining;

    //@ assert k > a + b && k <= a + b + c ==> res == a - (k - (a + b));
    //@ assert res == ((k) <= (a) ? (k) :         (k) <= (a) + (b) ? (a) :         (a) - ((k) - ((a) + (b))));

    return res;
}
