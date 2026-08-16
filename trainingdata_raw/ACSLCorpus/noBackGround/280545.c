/*@
    requires a > -2147483648 && a < 2147483647;
    requires b > -2147483648 && b < 2147483647;
    requires c > -2147483648 && c < 2147483647;
    ensures \result == (a < b && b < c);
*/
int func(int a, int b, int c)
{
    int less;

    less = a < b;
    if (less)
    {
        less = b < c;
    }

    //@ assert less == (a < b && b < c);

    return less;
}
