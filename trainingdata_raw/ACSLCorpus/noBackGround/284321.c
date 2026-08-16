/*@
    requires ((n) >= 0 && (n) <= 0x7fffffff);
    ensures ((\result) == (n) * 2);
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    // Variable declarations at top of scope
    unsigned int result;

    //@ assert n <= 0x7fffffff;
    result = n * 2;
    //@ assert result == n * 2;
    return result;
}
