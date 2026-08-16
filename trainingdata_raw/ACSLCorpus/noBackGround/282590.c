/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= 3);
    ensures \result >= -c;
    ensures \result <= a + b;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int result;
    int remaining;

    result = 0;
    remaining = k;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         1 <= (c) && (c) <= 100 &&         1 <= (k) && (k) <= 3);

    if (remaining > a)
    {
        result += a;
        remaining -= a;
    }
    else
    {
        result += remaining;
        remaining = 0;
    }

    //@ assert result >= 0 && result <= a;

    if (remaining > b)
    {
        remaining -= b;
    }
    else
    {
        remaining = 0;
    }

    //@ assert remaining >= 0 && remaining <= k;

    if (remaining > c)
    {
        result -= c;
    }
    else
    {
        result -= remaining;
    }

    //@ assert result >= -c;
    //@ assert result <= a + b;

    return result;
}
