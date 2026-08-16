/*@
    requires (1 <= (A) && (A) <= 12 &&
        1 <= (B) && (B) <= 31);
    ensures \result >= 0;
    ensures (A == 12 && B > 12) ==> \result == 0;
    ensures (A != 12 && B > 12) ==> \result == A;
    ensures (B <= 12) ==> \result == 0;
*/
long func(long A, long B)
{
    long ans;
    //@ assert (1 <= (A) && (A) <= 12 &&         1 <= (B) && (B) <= 31);
    
    if (A == 12 && B > 12) {
        ans = 0;
        //@ assert ans == 0;
    } else if (A != 12 && B > 12) {
        ans = A;
        //@ assert ans == A;
    } else {
        ans = 0;
        //@ assert ans == 0;
    }
    
    //@ assert ans >= 0;
    return ans;
}
