/*@
    requires 1 <= a && a <= 10;
    requires 1 <= b && b <= 10;
    requires 1 <= c && c <= 10;
    ensures \result == 1 <==> ((a) == (b) && (b) == (c) && (c) == (a));
    ensures \result == 0 <==> !((a) == (b) && (b) == (c) && (c) == (a));
 */
int func(unsigned int a, unsigned int b, unsigned int c)
{
    int result;

    result = 1;

    if (a != b)
    {
        result = 0;
    }

    if (b != c)
    {
        result = 0;
    }

    if (a != c)
    {
        result = 0;
    }

    //@ assert result == 1 <==> ((a) == (b) && (b) == (c) && (c) == (a));

    return result;
}
