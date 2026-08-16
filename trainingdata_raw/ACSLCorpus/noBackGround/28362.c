#include <stdbool.h>

/*@
    requires \valid(d1_seqs + (0..seq_len-1));
    requires \valid(d2_seqs + (0..seq_len-1));
    requires \valid(d1_sets + (0..set_len-1));
    requires \valid(d2_sets + (0..set_len-1));
    requires \forall integer i; 0 <= i < seq_len ==> d1_seqs[i] == d2_seqs[i];
    requires \forall integer i; 0 <= i < set_len ==> d1_sets[i] == d2_sets[i];
    ensures \result == true;
*/
bool f(int *d1_seqs, int *d2_seqs, int seq_len,
       int *d1_sets, int *d2_sets, int set_len)
{
    //@ assert \forall integer i; 0 <= i < seq_len ==> d1_seqs[i] == d2_seqs[i];
    //@ assert \forall integer i; 0 <= i < set_len ==> d1_sets[i] == d2_sets[i];
    //@ assert (\forall integer i; 0 <= i < (seq_len) ==> (d1_seqs)[i] == (d2_seqs)[i]) && (\forall integer i; 0 <= i < (set_len) ==> (d1_sets)[i] == (d2_sets)[i]);
    return true;
}
