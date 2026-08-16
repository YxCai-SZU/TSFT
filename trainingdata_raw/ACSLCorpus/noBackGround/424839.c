#include <stdbool.h>

int main()
{
    int seq1_a[10];
    int seq1_b[10];
    int seq2_a[5];
    int seq2_b[5];
    int i;
    
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant \forall integer j; 0 <= j < i ==> seq1_a[j] == seq1_b[j];
        loop assigns i, seq1_a[0..9], seq1_b[0..9];
    */
    for (i = 0; i < 10; i++)
    {
        seq1_a[i] = i;
        seq1_b[i] = i;
    }
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> seq2_a[j] == seq2_b[j];
        loop assigns i, seq2_a[0..4], seq2_b[0..4];
    */
    for (i = 0; i < 5; i++)
    {
        seq2_a[i] = i * 2;
        seq2_b[i] = i * 2;
    }
    
    /*@ assert (\forall integer i; 0 <= i < (10) ==> (&seq1_a[0])[i] == (&seq1_b[0])[i]); */
    /*@ assert (\forall integer i; 0 <= i < (5) ==> (&seq2_a[0])[i] == (&seq2_b[0])[i]); */
    /*@ assert ((\forall integer i; 0 <= i < ((10)) ==> ((&seq1_a[0]))[i] == ((&seq1_b[0]))[i]) &&
        (\forall integer i; 0 <= i < ((5)) ==> ((&seq2_a[0]))[i] == ((&seq2_b[0]))[i])); */
    
    return 0;
}
