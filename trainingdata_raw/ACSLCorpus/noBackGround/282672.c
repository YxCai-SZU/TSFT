/*@
    requires (1 <= (n) <= 1000000);
    ensures \result == (((n) - 1) / 2);
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    // Variable declarations at top of scope
    unsigned int result;

    //@ assert 1 <= n <= 1000000;
    //@ assert (n - 1) / 2 <= 499999;
    
    result = (n - 1) / 2;
    return result;
}
