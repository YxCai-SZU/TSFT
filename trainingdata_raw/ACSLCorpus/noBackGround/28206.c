/*@
    requires (0 <= (n) < 0x80000000);
    ensures \result == n / 2;
    ensures (0 <= (\result) < 0x80000000);
*/
unsigned int func(unsigned int n)
{
    // Variable declarations at the top
    unsigned int result;

    //@ assert (0 <= (n) < 0x80000000);
    //@ assert (0 <= (n / 2) < 0x80000000);

    result = n / 2;
    return result;
}
