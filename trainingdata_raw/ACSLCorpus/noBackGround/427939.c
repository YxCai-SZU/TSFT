/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (c - b == b - a);
*/
int func(int a, int b, int c)
{
    int is_arithmetic_progression;

    is_arithmetic_progression = 0;

    if (c - b == b - a)
    {
        is_arithmetic_progression = 1;
    }

    //@ assert is_arithmetic_progression == (c - b == b - a);

    return is_arithmetic_progression;
}
