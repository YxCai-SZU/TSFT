#include <stdbool.h>

/*@ requires A_len > 0 && B_len > 0;
    requires \valid(A + (0 .. A_len-1));
    requires \valid(B + (0 .. B_len-1));
    ensures \result == true ==> (\exists integer i, j; 0 <= i < (A_len) && 0 <= j < (B_len) && (A)[i] == (B)[j]);
    ensures \result == false ==> (\forall integer i, j; 0 <= i < (A_len) && 0 <= j < (B_len) ==> (A)[i] != (B)[j]);
    assigns \nothing;
*/
bool check_sub_array(int *A, int A_len, int *B, int B_len)
{
    int i = 0;
    //@ assert 0 <= i <= A_len;
    /*@ loop invariant 0 <= i <= A_len;
        loop invariant \forall integer ii, jj; 0 <= ii < i && 0 <= jj < B_len ==> A[ii] != B[jj];
        loop assigns i;
        loop variant A_len - i;
    */
    while (i < A_len) {
        int j = 0;
        //@ assert 0 <= j <= B_len;
        /*@ loop invariant 0 <= j <= B_len;
            loop invariant \forall integer jj; 0 <= jj < j ==> A[i] != B[jj];
            loop assigns j;
            loop variant B_len - j;
        */
        while (j < B_len) {
            if (A[i] == B[j]) {
                //@ assert (\exists integer i, j; 0 <= i < (A_len) && 0 <= j < (B_len) && (A)[i] == (B)[j]);
                return true;
            }
            j += 1;
        }
        i += 1;
    }
    //@ assert (\forall integer i, j; 0 <= i < (A_len) && 0 <= j < (B_len) ==> (A)[i] != (B)[j]);
    return false;
}
