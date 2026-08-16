#include <stdbool.h>

/*@
    predicate seq_eq{L1,L2}(int **s1, int **s2, integer len1, integer len2) =
        len1 == len2 &&
        \forall integer i; 0 <= i < len1 ==> \at(s1[i], L1) == \at(s2[i], L2);

    predicate set_eq{L1,L2}(int **s1, int **s2, integer len1, integer len2) =
        len1 == len2 &&
        \forall integer i; 0 <= i < len1 ==> \at(s1[i], L1) == \at(s2[i], L2);

    predicate complex_data_eq{L1,L2}(int **seq1, int **seq2, int **set1, int **set2,
                                     integer seq_len1, integer seq_len2,
                                     integer set_len1, integer set_len2) =
        seq_eq{L1,L2}(seq1, seq2, seq_len1, seq_len2) &&
        set_eq{L1,L2}(set1, set2, set_len1, set_len2);
*/

/*@
    lemma compare_complex_data_lemma{L1,L2}:
        \forall int **seq1, int **seq2, int **set1, int **set2;
        \forall integer seq_len1, seq_len2, set_len1, set_len2;
        seq_eq{L1,L2}(seq1, seq2, seq_len1, seq_len2) &&
        set_eq{L1,L2}(set1, set2, set_len1, set_len2) ==>
        complex_data_eq{L1,L2}(seq1, seq2, set1, set2, seq_len1, seq_len2, set_len1, set_len2);
*/

/*@
    requires seq_len1 == seq_len2 && set_len1 == set_len2;
    requires \valid(seq1+(0..seq_len1-1)) && \valid(seq2+(0..seq_len2-1));
    requires \valid(set1+(0..set_len1-1)) && \valid(set2+(0..set_len2-1));
    requires \forall integer i; 0 <= i < seq_len1 ==> seq1[i] == seq2[i];
    requires \forall integer i; 0 <= i < set_len1 ==> set1[i] == set2[i];
    ensures \forall integer i; 0 <= i < seq_len1 ==> seq1[i] == seq2[i];
*/
void compare_complex_data(int **seq1, int **seq2, int **set1, int **set2,
                          int seq_len1, int seq_len2,
                          int set_len1, int set_len2)
{
    //@ assert seq_len1 == seq_len2;
    //@ assert \forall integer i; 0 <= i < seq_len1 ==> seq1[i] == seq2[i];
    //@ assert set_len1 == set_len2;
    //@ assert \forall integer i; 0 <= i < set_len1 ==> set1[i] == set2[i];
    //@ assert complex_data_eq{Here,Here}(seq1, seq2, set1, set2, seq_len1, seq_len2, set_len1, set_len2);
}

int main() {
    return 0;
}
