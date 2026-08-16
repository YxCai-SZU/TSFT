/*@
    requires a > -2147483648 && a < 2147483647;
    requires b > -2147483648 && b < 2147483647;
    requires c > -2147483648 && c < 2147483647;
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
_Bool func(int a, int b, int c)
{
    _Bool is_increasing;
    is_increasing = 1;

    // Check if the first pair of adjacent elements is in increasing order
    if (a >= b)
    {
        is_increasing = 0;
    }

    // Check if the second pair of adjacent elements is in increasing order
    if (b >= c)
    {
        is_increasing = 0;
    }

    //@ assert is_increasing == (a < b && b < c);

    return is_increasing;
}
