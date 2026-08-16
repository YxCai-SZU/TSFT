/*@
    requires (1 <= (k) && (k) <= 100 && 1 <= (x) && (x) <= 100000);
    ensures ((\result) == ((500 * ((k))) >= (x) ? 1 : 0));
    assigns \nothing;
*/
int func(long k, long x)
{
    // Variable declarations at top
    int result;
    
    //@ assert (500 * (k)) >= x ==> (500 * (k)) >= x;
    
    result = (500 * k >= x);
    return result;
}
