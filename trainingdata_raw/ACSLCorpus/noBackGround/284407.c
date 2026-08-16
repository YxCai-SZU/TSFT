/*@
    requires (1 <= (A) && (A) <= 100) && (1 <= (B) && (B) <= 100);
    ensures \result >= 0 && \result <= A;
    ensures \result == A - (B * 2) || \result == 0;
*/
int func(int A, int B)
{
    int a;
    int result;

    //@ assert (1 <= (A) && (A) <= 100);
    //@ assert (1 <= (B) && (B) <= 100);
    
    a = A - (B * 2);
    
    //@ assert a == ((A) - ((B) * 2));
    
    if (a < 0) {
        //@ assert a < 0;
        //@ assert 0 <= A;
        result = 0;
    } else {
        //@ assert a >= 0;
        //@ assert a <= A;
        result = a;
    }
    
    //@ assert result >= 0;
    //@ assert result <= A;
    //@ assert result == A - (B * 2) || result == 0;
    
    return result;
}
