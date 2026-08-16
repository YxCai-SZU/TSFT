/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == 1 <==> (((a) == (b) && (a) != (c)) ||
        ((a) == (c) && (a) != (b)) ||
        ((b) == (c) && (a) != (b)));
    assigns \nothing;
 */
int func(int a, int b, int c)
{
    int count = 0;

    //@ assert count == 0;
    if (a == b)
    {
        count += 1;
    }
    //@ assert count == (a == b ? 1 : 0);
    if (a == c)
    {
        count += 1;
    }
    //@ assert count == (a == b ? 1 : 0) + (a == c ? 1 : 0);
    if (b == c)
    {
        count += 1;
    }
    //@ assert count == (a == b ? 1 : 0) + (a == c ? 1 : 0) + (b == c ? 1 : 0);
    //@ assert count == 1 ==> (((a) == (b) && (a) != (c)) ||         ((a) == (c) && (a) != (b)) ||         ((b) == (c) && (a) != (b)));
    return count == 1;
}
