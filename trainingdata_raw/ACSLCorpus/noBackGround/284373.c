/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result == ((a) + (b)) || \result == (2 * (a) - 1) || \result == (2 * (b) - 1);
    ensures \result >= 0;
*/
int func(int a, int b)
{
    int max_val;

    //@ assert a + b >= 0;
    //@ assert 2 * a - 1 >= 0;
    //@ assert 2 * b - 1 >= 0;
    //@ assert a + b <= 40;
    //@ assert 2 * a - 1 <= 39;
    //@ assert 2 * b - 1 <= 39;

    if (a + b > 2 * a - 1)
    {
        if (a + b > 2 * b - 1)
        {
            max_val = a + b;
        }
        else
        {
            max_val = 2 * b - 1;
        }
    }
    else
    {
        if (2 * a - 1 > 2 * b - 1)
        {
            max_val = 2 * a - 1;
        }
        else
        {
            max_val = 2 * b - 1;
        }
    }

    return max_val;
}
