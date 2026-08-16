/*@
    predicate is_evenly_divisible(integer x, integer y) = y % x == 0;
    
    lemma test_exists_divisible:
        \forall integer n;
            n > 0 && (\exists integer j; is_evenly_divisible(n, j)) ==>
            is_evenly_divisible(n, n);
*/

/*@
    requires n > 0;
    requires \exists integer j; is_evenly_divisible(n, j);
    ensures is_evenly_divisible(n, n);
*/
void test_exists_divisible_proof(int n) {
    //@ assert n > 0;
    //@ assert \exists integer j; is_evenly_divisible(n, j);
    //@ assert is_evenly_divisible(n, n);
}

int main() {
    return 0;
}
