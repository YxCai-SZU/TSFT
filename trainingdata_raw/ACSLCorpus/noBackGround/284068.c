#include <stdbool.h>
/*@
    requires \valid(numbers + (0 .. len-1));
    requires len > 0;
    requires (\forall integer i; 0 <= i < (len) ==> (numbers)[i] > 0);
    ensures \result >= 0;
    ensures \exists integer i; 0 <= i < len && \result == numbers[i];
*/
int func(int *numbers, int len) {
    int max_value;
    int i;
    /*@ assert len > 0; */
    max_value = numbers[0];
    i = 1;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer i; 0 <= i < (len) ==> (numbers)[i] > 0);
        loop invariant (\forall integer k; 0 <= k < (i) ==> (max_value) >= (numbers)[k]);
        loop invariant (\exists integer k; 0 <= k < (i) && (max_value) == (numbers)[k]);
        loop assigns i, max_value;
    */
    while (i < len) {
        if (numbers[i] > max_value) {
            max_value = numbers[i];
        }
        i = i + 1;
    }
    /*@ assert max_value >= 0; */
    return max_value;
}
