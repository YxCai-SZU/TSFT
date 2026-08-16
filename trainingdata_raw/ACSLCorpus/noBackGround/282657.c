/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (a + b == c || b + c == a || c + a == b);
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b, unsigned int c)
{
    int result = 0;

    if (a + b == c)
    {
        result = 1;
    }
    if (b + c == a)
    {
        result = 1;
    }
    if (c + a == b)
    {
        result = 1;
    }

    //@ assert result == (a + b == c || b + c == a || c + a == b);
    return result;
}
