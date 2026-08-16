/*@
    requires (1 <= (n) <= 20 &&
        1 <= (a) <= 100 &&
        1 <= (b) <= 2000);
    ensures \result == n * a || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    // Variable declarations at scope top
    int result;

    //@ assert (1 <= (n) <= 20 &&         1 <= (a) <= 100 &&         1 <= (b) <= 2000);
    //@ assert ((n) * (a)) <= 2000;

    if (n * a < b)
    {
        result = n * a;
    }
    else
    {
        result = b;
    }

    //@ assert result == n * a || result == b;
    //@ assert result <= b;
    return result;
}
