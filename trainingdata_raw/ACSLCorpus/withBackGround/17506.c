#include <stdbool.h>

/*@
    predicate valid_array(int *a) =
        \valid(a) && \valid(a+1) && \valid(a+2) &&
        1 <= a[0] <= 100 &&
        1 <= a[1] <= 100 &&
        1 <= a[2] <= 100;

    logic integer array_max(integer i, int *a) =
        i == 0 ? a[0] : (a[i] > array_max(i-1, a) ? a[i] : array_max(i-1, a));

    logic integer array_min(integer i, int *a) =
        i == 0 ? a[0] : (a[i] < array_min(i-1, a) ? a[i] : array_min(i-1, a));

    lemma max_min_relation:
        \forall int *a; valid_array(a) ==> array_max(2, a) >= array_min(2, a);

    lemma max_min_range:
        \forall int *a; valid_array(a) ==> 
            1 <= array_min(2, a) <= 100 && 1 <= array_max(2, a) <= 100;

    lemma difference_bound:
        \forall int *a; valid_array(a) ==> 
            array_max(2, a) - array_min(2, a) <= 99;
*/

/*@
    requires valid_array(a);
    ensures \result >= 0;
    ensures \result <= 198;
    assigns \nothing;
*/
int func(int *a) {
    int max_val;
    int min_val;
    int i;

    max_val = a[0];
    min_val = a[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 3;
        loop invariant max_val >= min_val;
        loop invariant \forall integer k; 0 <= k < i ==> max_val >= a[k] && min_val <= a[k];
        loop invariant 1 <= min_val <= 100;
        loop invariant 1 <= max_val <= 100;
        loop assigns max_val, min_val, i;
        loop variant 3 - i;
    */
    while (i < 3) {
        if (a[i] > max_val) {
            max_val = a[i];
        }
        if (a[i] < min_val) {
            min_val = a[i];
        }
        i += 1;
    }

    //@ assert max_val - min_val <= 99;
    return max_val - min_val;
}

int main() {
    return 0;
}
