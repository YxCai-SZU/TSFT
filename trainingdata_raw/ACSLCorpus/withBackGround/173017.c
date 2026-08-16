/*@
    predicate is_valid_n(integer n) = 0 <= n <= 65535;
    
    logic integer triangular_num(integer n) = (n * (n + 1)) / 2;
    
    lemma triangular_bound: \forall integer n; is_valid_n(n) ==> triangular_num(n) <= 2147483647;
*/

/*@
    requires is_valid_n(n);
    ensures \result == triangular_num(n);
    ensures \result <= 2147483647;
*/
unsigned int find_triangular_num(unsigned int n) {
    //@ assert n <= 65535;
    
    unsigned int result;
    result = n * (n + 1) / 2;
    
    //@ assert result == triangular_num(n);
    //@ assert result <= 2147483647;
    
    return result;
}

int main() {
    return 0;
}
