/*@
    requires (1 <= (n) && (n) <= 100 &&
        0 <= (a) && (a) <= (n) * (n));
    ensures \result == ((n) * (n) - (a));
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int a)
{
    // Variable declarations at scope top
    unsigned int result;

    // Precondition verification
    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= a && a <= n * n;

    // Critical verification property
    //@ assert n * n <= 10000;

    result = n * n - a;

    // Postcondition verification
    //@ assert result == n * n - a;

    return result;
}
