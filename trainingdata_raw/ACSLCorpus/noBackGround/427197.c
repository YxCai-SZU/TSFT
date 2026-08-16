#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) > 0 && (n) <= 200000 &&
      \valid((p) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= (int)(n) &&
      \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    ensures 0 <= \result <= (int)n - 1;
    assigns \nothing;
*/
int func(size_t n, int *p) {
    int result = 0;
    int max = p[0];
    int min = p[0];
    size_t i = 1;

    /*@ loop invariant (1 <= (i) <= (n) &&
      0 <= (result) <= (i) - 1 &&
      \forall integer k; 0 <= k < (i) ==> (min) <= (p)[k] <= (max) &&
      \exists integer k; 0 <= k < (i) && (p)[k] == (max) &&
      \exists integer k; 0 <= k < (i) && (p)[k] == (min));
        loop assigns i, result, max, min;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert i < n;
        if (p[i] <= max && p[i] <= min) {
            result += 1;
        }
        if (p[i] > max) {
            max = p[i];
        }
        if (p[i] < min) {
            min = p[i];
        }
        i += 1;
    }
    return result;
}
