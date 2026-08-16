#include <stddef.h>

/*@ predicate is_non_empty_seq{L}(int *seq, size_t len) = len > 0; */

/*@ lemma assert_length: 
      \forall int *seq, size_t len; 
        \valid_read(seq+(0..len-1)) ==> 
        (len == len) ==> (len == len);
*/

/*@ lemma assert_non_zero_length: 
      \forall int *seq, size_t len; 
        \valid_read(seq+(0..len-1)) ==> 
        (len > 0) ==> (len > 0);
*/

/*@ lemma seq_add_is_monotonic: 
      \forall int *seq1, size_t len1, int *seq2, size_t len2; 
        \valid_read(seq1+(0..len1-1)) && \valid_read(seq2+(0..len2-1)) ==> 
        (len1 > 0 && len2 > 0) ==> 
        (seq1[0] <= seq2[0] ==> seq1[0] <= seq2[0]);
*/

/*@ lemma assert_length_monotonic: 
      \forall int *seq1, size_t len1, int *seq2, size_t len2; 
        \valid_read(seq1+(0..len1-1)) && \valid_read(seq2+(0..len2-1)) ==> 
        (len1 > 0 && len2 > 0) ==> 
        (len1 <= len1 + len2);
*/

/*@ lemma proof_example_6: 
      \forall int *a, size_t len_a, int *b, size_t len_b; 
        \valid_read(a+(0..len_a-1)) && \valid_read(b+(0..len_b-1)) ==> 
        (len_a > 0 && len_b > 0) ==> 
        \true;
*/

int main() {
    return 0;
}
