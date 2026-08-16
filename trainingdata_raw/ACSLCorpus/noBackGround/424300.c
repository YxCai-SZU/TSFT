/*@
    requires \valid(seq1+(0..len-1)) && \valid(seq2+(0..len-1));
    requires len >= 0;
    requires (\forall integer k; 0 <= k < (len) ==> (seq1)[k] == (seq2)[k]);
    ensures (\forall integer k; 0 <= k < (len) ==> (seq1)[k] == (seq2)[k]);
*/
void main_seq(int *seq1, int *seq2, int len) {
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer k; 0 <= k < i ==> seq1[k] == seq2[k];
        loop assigns i;
    */
    for (int i = 0; i < len; ++i) {
        //@ assert seq1[i] == seq2[i];
    }
}
