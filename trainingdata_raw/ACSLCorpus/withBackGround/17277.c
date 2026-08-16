/*@
    predicate is_empty_seq{L}(int *arr, integer len) = len == 0;
    
    logic integer seq_len{L}(int *arr, integer len) = len;
    
    lemma calc_example_5:
        \forall int *s1, *s2, *s3; \forall integer len1, len2, len3;
        seq_len(s1, len1) + seq_len(s2, len2) + seq_len(s3, len3) == 
        seq_len(s1, len1) + seq_len(s2, len2) + seq_len(s3, len3);
    
    lemma lemma_noop:
        \forall int *L; \forall integer len;
        seq_len(L, len) == seq_len(L, len);
    
    lemma lemma_always_true: \true;
    
    lemma lemma_always_false: \false ==> \true;
    
    lemma lemma_id:
        \forall int *L; \forall integer len;
        seq_len(L, len) == seq_len(L, len);
    
    lemma lemma_and_id: \true;
    
    lemma lemma_or_id: \true;
*/

/*@
    requires \true;
    ensures \result == 0;
*/
int main() {
    int result = 0;
    //@ assert \true;
    return result;
}
