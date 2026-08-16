/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == ( (a * b) % 2 == 0 );
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int c;
    int res;

    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= b && b <= 10000;
    //@ assert a * b <= 100000000;

    c = a * b;
    res = (c % 2 == 0);
    return res;
}
