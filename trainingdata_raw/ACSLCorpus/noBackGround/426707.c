/*@
    requires ((a) > 0) && ((b) > 0);
    requires ((a) <= 5) && ((b) <= 5);
    ensures \result >= 0;
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at scope top
    int ans;
    
    //@ assert ((a) > 0) && ((b) > 0);
    //@ assert ((a) <= 5) && ((b) <= 5);
    //@ assert ((a) * (b)) <= 25;
    
    ans = a * b;
    
    //@ assert ans >= 0;
    //@ assert ans == ((a) * (b));
    
    return ans;
}
