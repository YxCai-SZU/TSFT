#include <stdbool.h>
#include <stdint.h>

/*@ requires (1 <= (N) <= 100 &&
      1 <= (M) <= 100 &&
      1 <= (x) <= (N) - 1);
    requires \valid(A + (0 .. M-1));
    requires (\forall integer i; 0 <= i < (M) ==> 
        1 <= (A)[i] <= (N) && (A)[i] != (x));
    assigns \nothing;
    ensures \result <= M;
*/
int32_t func(int32_t N, int32_t M, int32_t x, int32_t* A) {
    int32_t ans = 0;
    int32_t i = 0;
    
    /*@ loop invariant 0 <= i <= M;
        loop invariant 0 <= ans <= i;
        loop invariant (\forall integer i; 0 <= i < (M) ==> 
        1 <= (A)[i] <= (N) && (A)[i] != (x));
        loop invariant (1 <= (N) <= 100 &&
      1 <= (M) <= 100 &&
      1 <= (x) <= (N) - 1);
        loop assigns ans, i;
        loop variant M - i;
    */
    while (i < M) {
        int32_t value = A[i];
        //@ assert 1 <= value <= N && value != x;
        if (value < x) {
            ans = ans + 1;
        }
        i = i + 1;
    }
    
    int32_t final_ans;
    if (ans < M - ans) {
        final_ans = ans;
    } else {
        final_ans = M - ans;
    }
    //@ assert final_ans <= M;
    return final_ans;
}
