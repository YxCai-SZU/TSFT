/*@
    predicate inequality_strict(integer n, integer k) = n <= k ==> n <= k + 1;
    predicate inequality(integer n, integer k) = n < k ==> n < k + 1;
    
    lemma lemma_inequality_strict: \forall integer n, k; inequality_strict(n, k);
    lemma lemma_inequality: \forall integer n, k; inequality(n, k);
    lemma lemma_noleftshift_inequality: \forall integer n, k; inequality_strict(n, k);
    lemma lemma_noleftshift_inequality_strict: \forall integer n, k; inequality_strict(n, k);
*/

/*@
    requires \true;
    ensures \result == 0;
*/
int main() {
    //@ assert \true;
    return 0;
}
