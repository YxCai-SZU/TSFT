/*@
    predicate is_unique{L}(int *s, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> s[i] != s[j];

    predicate at_least_k_unique{L}(int *s, integer len, integer k) =
        k <= len &&
        \forall integer i, j; 0 <= i < j < k ==> s[i] != s[j];

    lemma unique_implies_at_least_k:
        \forall int *s, integer len, integer k;
        is_unique(s, len) && k <= len ==> at_least_k_unique(s, len, k);
*/

/*@
    requires \valid_read(v + (0 .. len-1));
    requires k <= len;
    requires is_unique(v, len);
    ensures \result == 1;
    assigns \nothing;
*/
int func(int *v, unsigned int len, unsigned int k) {
    //@ assert k <= len;
    return 1;
}
