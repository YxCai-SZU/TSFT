/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == ((a) - 2 * (b)) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at scope top
    int x;
    int result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert ((a) - 2 * (b)) >= -199;

    x = a - 2 * b;

    if (x > 0)
    {
        //@ assert x == ((a) - 2 * (b));
        result = x;
    }
    else
    {
        //@ assert x == ((a) - 2 * (b));
        result = 0;
    }

    //@ assert result >= 0;
    return result;
}
