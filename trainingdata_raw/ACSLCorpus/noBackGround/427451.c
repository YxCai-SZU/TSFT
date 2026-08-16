/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100);
    requires A == (long long)A && B == (long long)B;
    ensures \result == A * B;
    assigns \nothing;
*/
long long func(long long A, long long B) {
    //@ assert A * B <= 10000;
    //@ assert A * B >= 1;
    
    return A * B;
}
