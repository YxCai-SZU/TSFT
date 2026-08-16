/*@
    requires (3 <= (n) && (n) <= 100);
    ensures \result == (((n) - 2) * 180);
    assigns \nothing;
*/
long func(long n)
{
    // Variable declarations at the top
    long result;

    //@ assert (3 <= (n) && (n) <= 100);
    //@ assert n - 2 >= 1;
    //@ assert (((n) - 2) * 180) <= 98 * 180;
    
    result = (n - 2) * 180;
    return result;
}
