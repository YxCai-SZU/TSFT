/*@
    requires (1 <= (x) && (x) <= 9);
    ensures \result == ((x) > 0 ? (x) : 0);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    
    //@ assert (1 <= (x) && (x) <= 9);
    
    if (x > 0) {
        result = x;
    } else {
        result = 0;
    }
    
    //@ assert result == ((x) > 0 ? (x) : 0);
    
    return result;
}
