/*@
    requires ((n) >= 1 && (n) <= 10 && (n) * (n) * (n) <= 2147483647);
    ensures \result == ((n) * (n) * (n));
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at top of scope
    int nn;
    int result;

    //@ assert n >= 1 && n <= 10;
    //@ assert n * n >= 1 && n * n <= 100;
    //@ assert n * n * n >= 1 && n * n * n <= 1000;

    nn = n * n;
    result = nn * n;
    return result;
}
