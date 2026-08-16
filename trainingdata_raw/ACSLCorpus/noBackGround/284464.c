/*@
    requires (1 <= (n) && (n) <= 100 &&
        0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100);
    ensures \result == ((a) * (n)) || \result == b;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    int result;

    //@ assert 0 <= ((a) * (n)) <= 10000;

    if (a * n > b)
    {
        result = a * n;
    }
    else
    {
        result = b;
    }

    //@ assert result == ((a) * (n)) || result == b;
    //@ assert result >= 0;

    return result;
}
