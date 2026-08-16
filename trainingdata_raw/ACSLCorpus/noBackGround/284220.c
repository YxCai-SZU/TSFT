/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures \result == ((((n)) * 2 + 1) * (((m)) * 2 + 1));
    assigns \nothing;
*/
int func(int n, int m)
{
    int o;
    int p;
    int result;
    
    //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20);
    //@ assert ((n) * 2 + 1) <= 41;
    //@ assert ((m) * 2 + 1) <= 41;
    //@ assert ((((n)) * 2 + 1) * (((m)) * 2 + 1)) <= 1681;
    
    o = n * 2 + 1;
    p = m * 2 + 1;
    result = o * p;
    
    //@ assert result == ((((n)) * 2 + 1) * (((m)) * 2 + 1));
    return result;
}
