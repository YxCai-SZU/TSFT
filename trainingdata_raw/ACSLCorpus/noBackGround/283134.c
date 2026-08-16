/*@
    requires x >= 0 && y > 0;
    ensures \result * y <= x && x < (\result + 1) * y;
    assigns \nothing;
*/
int div_example_4(int x, int y)
{
    int q;
    int tmp;

    //@ assert x >= 0;
    //@ assert y > 0;
    q = x / y;
    tmp = q * y;
    //@ assert tmp <= x;
    return q;
}
