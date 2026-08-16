/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result == a * 2 || \result == a * 2 - 1 || \result == b * 2 - 1;
    assigns \nothing;
*/
int func(int a, int b)
{
    int min_val;
    int result;

    //@ assert (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    min_val = (a < b) ? a : b;
    //@ assert (3 <= (min_val) && (min_val) <= 20);
    result = min_val * 2 - 1;

    if (a == b)
    {
        //@ assert result == a * 2 - 1 || result == b * 2 - 1;
        return result;
    }
    else if (a == min_val)
    {
        //@ assert result == a * 2 - 1 || result == b * 2 - 1;
        return a * 2;
    }
    else
    {
        //@ assert result == a * 2 - 1 || result == b * 2 - 1;
        return b * 2 - 1;
    }
}
