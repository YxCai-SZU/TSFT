#include <stdbool.h>
#include <limits.h>

/*@ predicate is_valid_value(integer v, integer a, integer b) =
      v == a * 2 - 1 || v == a * 2 || v == a * 2 + 1 ||
      v == b * 2 - 1 || v == b * 2 || v == b * 2 + 1;
*/

/*@ lemma min_val_non_negative:
      \forall integer a, b, min_val;
      3 <= a <= 20 && 3 <= b <= 20 &&
      (min_val == a * 2 - 1 || min_val == a * 2 || min_val == a * 2 + 1 ||
       min_val == b * 2 - 1 || min_val == b * 2 || min_val == b * 2 + 1) ==>
      min_val >= 0;
*/

/*@ requires 3 <= a <= 20;
    requires 3 <= b <= 20;
    ensures \result >= 0;
    ensures is_valid_value(\result, a, b);
*/
int func(int a, int b) {
    int x[6];
    int i;
    int j;
    int min_val;

    // First loop: initialize array with zeros
    i = 0;
    /*@ loop invariant 0 <= i <= 6;
        loop invariant \forall integer k; 0 <= k < i ==> x[k] == 0;
        loop assigns i, x[0..5];
        loop variant 6 - i;
    */
    while (i < 6) {
        //@ assert i >= 0 && i < 6;
        x[i] = 0;
        i = i + 1;
    }

    // Second loop: fill array with specific values
    i = 0;
    /*@ loop invariant 0 <= i <= 6;
        loop invariant \forall integer k; 0 <= k < i ==> is_valid_value(x[k], a, b);
        loop invariant \forall integer k; i <= k < 6 ==> x[k] == 0;
        loop assigns i, x[0..5];
        loop variant 6 - i;
    */
    while (i < 6) {
        //@ assert i >= 0 && i < 6;
        if (i == 0) {
            x[i] = a * 2 - 1;
        } else if (i == 1) {
            x[i] = a * 2;
        } else if (i == 2) {
            x[i] = a * 2 + 1;
        } else if (i == 3) {
            x[i] = b * 2 - 1;
        } else if (i == 4) {
            x[i] = b * 2;
        } else if (i == 5) {
            x[i] = b * 2 + 1;
        }
        i = i + 1;
    }

    // Third loop: find minimum value
    min_val = x[0];
    j = 1;
    /*@ loop invariant 1 <= j <= 6;
        loop invariant \forall integer k; 0 <= k < j ==> min_val <= x[k];
        loop invariant \exists integer k; 0 <= k < 6 && min_val == x[k];
        loop invariant min_val >= 0;
        loop assigns j, min_val;
        loop variant 6 - j;
    */
    while (j < 6) {
        //@ assert j >= 1 && j < 6;
        if (x[j] < min_val) {
            min_val = x[j];
        }
        j = j + 1;
    }

    //@ assert is_valid_value(min_val, a, b);
    return min_val;
}
