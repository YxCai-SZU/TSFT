/*@
    requires (1 <= (A) && (A) <= 100) && (1 <= (B) && (B) <= 100);
    ensures \result == ((A) > 2 * (B) ? (A) - 2 * (B) : 0);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int A, int B)
{
    int result;
    
    //@ assert (1 <= (A) && (A) <= 100) && (1 <= (B) && (B) <= 100);
    
    if (A > 2 * B) {
        //@ assert A > 2 * B;
        //@ assert A - 2 * B >= 0;
        result = A - 2 * B;
    } else {
        result = 0;
    }
    
    //@ assert result == ((A) > 2 * (B) ? (A) - 2 * (B) : 0);
    //@ assert result >= 0;
    
    return result;
}
