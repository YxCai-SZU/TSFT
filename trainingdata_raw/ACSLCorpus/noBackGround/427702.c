/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * (r) * (3));
    assigns \nothing;
*/
int func(int r)
{
    int pi;
    int ans;
    
    pi = 3;
    
    //@ assert (1 <= (r) && (r) <= 100);
    
    ans = 2 * r * pi;
    
    return ans;
}
