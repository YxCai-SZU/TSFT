/*@
    requires (1 <= (N) <= 20 && 1 <= (A) <= 50 && 1 <= (B) <= 50);
    ensures \result == ((N) * (A)) || \result == B;
    ensures \result <= B;
    assigns \nothing;
*/
int func(int N, int A, int B) {
    int product;
    int min_value;
    
    //@ assert 1 <= N <= 20;
    //@ assert 1 <= A <= 50;
    //@ assert 1 <= B <= 50;
    
    product = N * A;
    
    if (product < B) {
        min_value = product;
    } else {
        min_value = B;
    }
    
    //@ assert min_value == product || min_value == B;
    //@ assert min_value <= B;
    
    return min_value;
}
