/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result <= a;
    ensures \result == ((a) <= 2 * (b) ? 0 : (a) - 2 * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    
    if (a <= 2 * b) {
        result = 0;
    } else {
        //@ assert a > 2 * b;
        result = a - 2 * b;
    }
    
    //@ assert result >= 0;
    //@ assert result <= a;
    //@ assert result == ((a) <= 2 * (b) ? 0 : (a) - 2 * (b));
    
    return result;
}
