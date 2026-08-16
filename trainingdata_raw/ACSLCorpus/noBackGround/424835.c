/*@
    requires ((a) < 1000000000);
    ensures \result == (a & 0x3FFFFFFF);
    assigns \nothing;
*/
unsigned int func(unsigned int a)
{
    // Variable declarations at top of scope
    unsigned int result;

    //@ assert ((a) < 1000000000);

    result = a & 0x3FFFFFFF;

    //@ assert result == (a & 0x3FFFFFFF);

    return result;
}
