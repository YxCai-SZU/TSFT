#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
    requires \valid_read(A + (0 .. 4)) && \valid_read(B + (0 .. 4));
    requires ((5) == 5 &&
        \forall integer i; 0 <= i < (5) ==> 1 <= (A)[i] && (A)[i] <= 5) && ((5) == 5 &&
        \forall integer i; 0 <= i < (5) ==> 1 <= (B)[i] && (B)[i] <= 5);
    assigns \nothing;
    ensures 0 <= \result <= 5;
*/
int64_t func(int64_t* A, int64_t* B) {
    int64_t ans = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant 0 <= ans <= i;
        loop invariant \forall integer j; 0 <= j < i ==> 1 <= A[j] <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> 1 <= B[j] <= 5;
        loop assigns ans, i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (A[i] > B[i]) {
            ans += 1;
        }
        i += 1;
    }
    //@ assert ans >= 0 && ans <= 5;
    return ans;
}
