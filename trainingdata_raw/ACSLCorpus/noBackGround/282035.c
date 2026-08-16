/*@
    requires (1 <= (l) && (l) <= 1000);
    ensures \result == (((l) * (l) * (l)) / 27);
    assigns \nothing;
*/
unsigned int func(unsigned int l)
{
    unsigned int l2;
    unsigned int ans;
    
    //@ assert 1 <= l && l <= 1000;
    //@ assert l * l <= 1000000;
    //@ assert l * l * l <= 1000000000;
    
    l2 = l * l;
    ans = l2 * l / 27;
    
    return ans;
}
