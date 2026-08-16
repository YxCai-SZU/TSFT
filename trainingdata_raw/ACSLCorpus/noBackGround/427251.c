/*@
    requires (1 <= (x) && (x) <= 100);
    ensures \result == ((x) * (x));
    assigns \nothing;
*/
int func(int x)
{
    // Variable declarations at scope top
    int result;

    //@ assert (1 <= (x) && (x) <= 100);
    //@ assert ((x) * (x)) <= 10000;
    
    result = x * x;
    
    //@ assert result == ((x) * (x));
    return result;
}
