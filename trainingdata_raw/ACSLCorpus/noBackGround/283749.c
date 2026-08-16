#include <stddef.h>

/*@
    assigns \nothing;
*/
void example7(void) {
    // Declarations
    int seq1[6];
    int seq2[3];
    int seq3[2];
    int seq4[2];
    int seq5[3];
    int seq6[3];
    int seq7[9];
    int seq8[5];
    int i;
    
    // Initialize seq1
    //@ ghost int len_seq1 = 6;
    /*@
        loop invariant 0 <= i <= 6;
        loop invariant \forall integer j; 0 <= j < i ==> seq1[j] == j * 5 + 1;
        loop assigns i, seq1[0..5];
    */
    for (i = 0; i < 6; i++) {
        seq1[i] = i * 5 + 1;
    }
    //@ assert ((len_seq1) == (6));
    //@ assert ((len_seq1) > 0 ==> (&seq1[0])[0] == (1));
    
    // Create seq2 as subrange of seq1
    //@ ghost int len_seq2 = 3;
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer j; 0 <= j < i ==> seq2[j] == seq1[j + 1];
        loop assigns i, seq2[0..2];
    */
    for (i = 0; i < 3; i++) {
        seq2[i] = seq1[i + 1];
    }
    //@ assert ((len_seq2) == (3));
    //@ assert ((len_seq2) > 0 ==> (&seq2[0])[0] == (6));
    
    // Create seq3 by taking first 2 elements of seq2
    //@ ghost int len_seq3 = 2;
    /*@
        loop invariant 0 <= i <= 2;
        loop invariant \forall integer j; 0 <= j < i ==> seq3[j] == seq2[j];
        loop assigns i, seq3[0..1];
    */
    for (i = 0; i < 2; i++) {
        seq3[i] = seq2[i];
    }
    //@ assert ((len_seq3) == (2));
    //@ assert ((len_seq3) > 0 ==> (&seq3[0])[(len_seq3)-1] == (11));
    
    // Create seq4 by reversing seq3
    //@ ghost int len_seq4 = 2;
    /*@
        loop invariant 0 <= i <= 2;
        loop invariant \forall integer j; 0 <= j < i ==> seq4[j] == seq3[1 - j];
        loop assigns i, seq4[0..1];
    */
    for (i = 0; i < 2; i++) {
        seq4[i] = seq3[1 - i];
    }
    //@ assert ((len_seq4) == (2));
    //@ assert ((len_seq4) > 0 ==> (&seq4[0])[0] == (11));
    
    // Create seq5 by pushing 12 to seq4
    //@ ghost int len_seq5 = 3;
    /*@
        loop invariant 0 <= i <= 2;
        loop invariant \forall integer j; 0 <= j < i ==> seq5[j] == seq4[j];
        loop assigns i, seq5[0..2];
    */
    for (i = 0; i < 2; i++) {
        seq5[i] = seq4[i];
    }
    seq5[2] = 12;
    //@ assert ((len_seq5) == (3));
    //@ assert ((len_seq5) > 0 ==> (&seq5[0])[(len_seq5)-1] == (12));
    
    // Create seq6 by updating element at index 1
    //@ ghost int len_seq6 = 3;
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer j; 0 <= j < i ==> seq6[j] == seq5[j];
        loop assigns i, seq6[0..2];
    */
    for (i = 0; i < 3; i++) {
        seq6[i] = seq5[i];
    }
    seq6[1] = 10;
    //@ assert ((len_seq6) == (3));
    //@ assert ((&seq6[0])[(1)] == (10));
    
    // Create seq7 by concatenating seq6 and seq1
    //@ ghost int len_seq7 = 9;
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer j; 0 <= j < i ==> seq7[j] == seq6[j];
        loop assigns i, seq7[0..8];
    */
    for (i = 0; i < 3; i++) {
        seq7[i] = seq6[i];
    }
    /*@
        loop invariant 0 <= i <= 6;
        loop invariant \forall integer j; 0 <= j < i ==> seq7[j + 3] == seq1[j];
        loop assigns i, seq7[3..8];
    */
    for (i = 0; i < 6; i++) {
        seq7[i + 3] = seq1[i];
    }
    //@ assert ((len_seq7) == (9));
    //@ assert ((&seq7[0])[(3)] == (1));
    
    // Create seq8 as subrange of seq7
    //@ ghost int len_seq8 = 5;
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> seq8[j] == seq7[j];
        loop assigns i, seq8[0..4];
    */
    for (i = 0; i < 5; i++) {
        seq8[i] = seq7[i];
    }
    //@ assert ((len_seq8) == (5));
    //@ assert ((&seq8[0])[(4)] == (seq7[4]));
}
