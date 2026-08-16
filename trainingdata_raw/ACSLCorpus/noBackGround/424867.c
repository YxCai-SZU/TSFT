/*@
    requires (1 <= (m) && (m) <= 23);
    ensures \result == (48 - (m));
    assigns \nothing;
*/
int func(int m)
{
    int result;
    
    //@ assert 48 - m == 48 - m;
    result = 48 - m;
    return result;
}
