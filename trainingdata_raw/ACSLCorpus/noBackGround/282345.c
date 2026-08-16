/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == x * y;
    ensures 1 <= \result <= 10000;
    assigns \nothing;
*/
long func(long x, long y)
{
    // Variable declarations at top
    long result;

    //@ assert (1 <= (x) && (x) <= 100 &&         1 <= (y) && (y) <= 100);
    //@ assert 1 <= x * y && x * y <= 10000;

    result = x * y;
    return result;
}

int main()
{
    return 0;
}
