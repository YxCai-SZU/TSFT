/*@
    predicate is_even(integer x) = x % 2 == 0;
    logic integer subtract_loop(integer b, integer count) = b - 2 * count;
*/

/*@
    requires 0 <= a <= 100;
    requires 2 <= b <= 1000;
    requires is_even(b);
    ensures \result == b || \result == b - 1 || \result == b - 2;
    ensures \result >= 0;
*/
int func(int a, int b)
{
    int result;
    int temp_b;
    int count;
    int is_odd;

    result = 0;
    temp_b = b;
    count = 0;

    /*@
        loop invariant 0 <= temp_b <= b;
        loop invariant 0 <= count <= b / 2;
        loop invariant temp_b == subtract_loop(b, count);
        loop assigns temp_b, count;
    */
    while (temp_b >= 2)
    {
        temp_b -= 2;
        count += 1;
    }

    //@ assert temp_b == 0 || temp_b == 1;
    is_odd = (temp_b == 1) ? 1 : 0;

    if (a >= 13)
    {
        result = b;
    }
    else if (a >= 6)
    {
        result = b - 1;
    }
    else
    {
        result = b - 2;
    }

    //@ assert result == b || result == b - 1 || result == b - 2;
    if (is_odd == 1)
    {
        result -= 1;
    }

    //@ assert result == b || result == b - 1 || result == b - 2;
    //@ assert result >= 0;
    return result;
}
