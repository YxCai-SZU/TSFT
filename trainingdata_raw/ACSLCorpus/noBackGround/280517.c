#include <stdbool.h>

/*@
    requires k >= 0 && k <= 1000000000;
    requires \valid(A + (0..4));
    requires ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> (1 <= (A)[i] && (A)[i] <= 123) &&
    \forall integer i, j; 0 <= i < j < (5) ==> (A)[i] != (A)[j]);
    ensures 0 <= \result <= 5;
    assigns \nothing;
*/
int count_k(int* A, int k) {
    int count = 0;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> (1 <= A[j] && A[j] <= 123);
        loop invariant \forall integer j, l; 0 <= j < l < i ==> A[j] != A[l];
        loop invariant k >= 0 && k <= 1000000000;
        loop invariant ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> (1 <= (A)[i] && (A)[i] <= 123) &&
    \forall integer i, j; 0 <= i < j < (5) ==> (A)[i] != (A)[j]);
        loop assigns i, count;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (A[i] < k) {
            count = count + 1;
        }
        i = i + 1;
    }
    return count;
}
