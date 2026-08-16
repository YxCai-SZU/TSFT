#include <stdbool.h>

/*@ predicate is_one_of(integer val, integer A, integer B, integer C, integer D) =
      val == A + C || val == A + D || val == B + C || val == B + D;
*/

/*@ predicate in_range(integer val) = -200 <= val <= 200; */

/*@ lemma sum_in_range: 
      \forall integer A, B, C, D; 
      -100 <= A <= 100 && -100 <= B <= 100 && -100 <= C <= 100 && -100 <= D <= 100 ==> 
      in_range(A + C) && in_range(A + D) && in_range(B + C) && in_range(B + D);
*/

/*@ requires -100 <= A <= 100;
    requires -100 <= B <= 100;
    requires -100 <= C <= 100;
    requires -100 <= D <= 100;
    ensures \result == A + C || \result == A + D || \result == B + C || \result == B + D;
    ensures in_range(\result);
*/
int func(int A, int B, int C, int D) {
    int xs[4];
    int max_val;
    int i;
    
    xs[0] = A + C;
    xs[1] = A + D;
    xs[2] = B + C;
    xs[3] = B + D;
    
    max_val = xs[0];
    i = 1;
    
    /*@ loop invariant 0 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_val == xs[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_val >= xs[j];
        loop invariant \forall integer k; 0 <= k < 4 ==> is_one_of(xs[k], A, B, C, D);
        loop invariant \forall integer k; 0 <= k < 4 ==> in_range(xs[k]);
        loop invariant in_range(max_val);
        loop assigns i, max_val;
        loop variant 4 - i;
    */
    while (i < 4) {
        //@ assert 0 <= i < 4;
        if (xs[i] > max_val) {
            max_val = xs[i];
        }
        i += 1;
    }
    
    //@ assert is_one_of(max_val, A, B, C, D);
    return max_val;
}
