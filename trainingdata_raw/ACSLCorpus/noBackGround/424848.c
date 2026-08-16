/*@
    requires 0 <= x <= 100 && 0 <= y <= 100;
    ensures \result == (x * y <= 2000);
    assigns \nothing;
*/
int func(unsigned int x, unsigned int y)
{
    // Variable declarations at scope top
    int res;

    //@ assert 0 <= x <= 100 && 0 <= y <= 100;
    //@ assert x * y <= 10000;
    
    res = (x * y <= 2000);
    return res;
}
