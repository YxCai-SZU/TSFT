/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == ((A) * (B)) || \result == ((C) * (D));
    ensures \result >= ((A) * (B)) && \result >= ((C) * (D));
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    int s1;
    int s2;
    int result;
    
    //@ assert (1 <= (A) <= 10000) && (1 <= (B) <= 10000);
    //@ assert 1 <= ((A) * (B)) <= 100000000;
    s1 = A * B;
    
    //@ assert (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    //@ assert 1 <= ((C) * (D)) <= 100000000;
    s2 = C * D;
    
    if (s1 > s2) {
        result = s1;
        //@ assert result == ((A) * (B));
    } else {
        result = s2;
        //@ assert result == ((C) * (D));
    }
    
    //@ assert result >= ((A) * (B)) && result >= ((C) * (D));
    return result;
}
