/*@
    predicate triangular_pos(integer k) = k > 0 ==> (k * (k + 1)) / 2 > 0;
    
    lemma triangular_pos_lemma:
        \forall integer k; k > 0 ==> (k * (k + 1)) / 2 > 0;
    
    lemma triangular_monotonic_lemma:
        \forall integer k; k > 0 ==> (k * (k + 1)) / 2 >= (k - 1) * k / 2;
    
    lemma triangular_nonneg_lemma:
        \forall integer k; k > 0 ==> (k * (k + 1)) / 2 >= 0;
*/

/*@
    requires k > 0;
    ensures \result > 0;
    ensures \result == (k * (k + 1)) / 2;
*/
int triangular_num(int k) {
    //@ assert k > 0;
    
    int result;
    result = (k * (k + 1)) / 2;
    
    //@ assert result > 0;
    //@ assert result == (k * (k + 1)) / 2;
    
    return result;
}

/*@
    requires k > 0;
    ensures \result >= 0;
    ensures \result == (k * (k + 1)) / 2;
*/
int triangular_num_nonneg(int k) {
    //@ assert k > 0;
    
    int result;
    result = (k * (k + 1)) / 2;
    
    //@ assert result >= 0;
    //@ assert result == (k * (k + 1)) / 2;
    
    return result;
}

/*@
    requires k > 0;
    ensures \result >= ((k - 1) * k) / 2;
    ensures \result == (k * (k + 1)) / 2;
*/
int triangular_num_monotonic(int k) {
    //@ assert k > 0;
    
    int result;
    result = (k * (k + 1)) / 2;
    
    //@ assert result >= ((k - 1) * k) / 2;
    //@ assert result == (k * (k + 1)) / 2;
    
    return result;
}

int main() {
    int k;
    int result;
    
    k = 5;
    //@ assert k > 0;
    
    result = triangular_num(k);
    //@ assert result > 0;
    
    result = triangular_num_nonneg(k);
    //@ assert result >= 0;
    
    result = triangular_num_monotonic(k);
    //@ assert result >= ((k - 1) * k) / 2;
    
    return 0;
}
