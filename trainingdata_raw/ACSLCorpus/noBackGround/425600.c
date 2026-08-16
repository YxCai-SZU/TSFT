/*@
    requires (3 <= (n) && (n) <= 100);
    ensures \result == (180 * ((n) - 2));
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at top of scope
    int result;
    
    //@ assert 3 <= n && n <= 100;
    //@ assert 1 <= (n - 2) && (n - 2) <= 98;
    //@ assert 180 <= 180 * (n - 2) && 180 * (n - 2) <= 17640;
    //@ assert n - 2 >= 1;
    //@ assert 180 * (n - 2) <= 180 * 98;
    
    result = 180 * (n - 2);
    return result;
}
