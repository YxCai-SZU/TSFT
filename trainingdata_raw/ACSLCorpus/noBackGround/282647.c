/*@
    requires (1 <= (A) && (A) <= 20) && (1 <= (B) && (B) <= 20);
    ensures (\result == A * B && A < 10 && B < 10) || \result == -1;
    assigns \nothing;
*/
int func(int A, int B)
{
    int max_val;
    int result;
    
    //@ assert (1 <= (A) && (A) <= 20) && (1 <= (B) && (B) <= 20);
    
    if (A > B) {
        max_val = A;
    } else {
        max_val = B;
    }
    
    if (max_val < 10) {
        //@ assert (1 <= (A) && (A) <= 9) && (1 <= (B) && (B) <= 9);
        //@ assert A * B <= 81;
        result = A * B;
    } else {
        result = -1;
    }
    
    return result;
}
