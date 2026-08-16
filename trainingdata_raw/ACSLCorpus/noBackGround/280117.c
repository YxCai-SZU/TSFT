/*@
    requires 1 <= a <= 10;
    ensures \result == a * (1 + a * (1 + a));
    assigns \nothing;
*/
int func(int a)
{
    //@ assert 1 <= a && a <= 10;
    
    int intermediate;
    intermediate = a * (1 + a);
    
    //@ assert 1 <= intermediate <= 110;
    
    //@ assert 1 + intermediate <= 1110;
    
    int result;
    result = a * (1 + intermediate);
    
    //@ assert 1 <= result <= 11100;
    
    return result;
}
