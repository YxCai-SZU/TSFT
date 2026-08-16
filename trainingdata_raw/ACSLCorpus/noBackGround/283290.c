#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) > 0 && (n) <= 200000 &&
        \valid((p) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= (n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(size_t n, int *p) {
    int result = 0;
    int max;
    int min;
    size_t i = 0;
    
    //@ assert n > 0;
    max = p[0];
    min = p[0];

    /*@
        loop invariant (0 <= (i) <= (n) &&
        (result) >= 0 &&
        (((n)) > 0 && ((n)) <= 200000 &&
        \valid(((p)) + (0 .. ((n))-1)) &&
        \forall integer i; 0 <= i < ((n)) ==> 1 <= ((p))[i] <= ((n)) &&
        \forall integer i, j; 0 <= i < j < ((n)) ==> ((p))[i] != ((p))[j]) &&
        ((i) > 0 ==> \forall integer k; 0 <= k < (i) ==> (max) >= (p)[k]) &&
        ((i) > 0 ==> \forall integer k; 0 <= k < (i) ==> (min) <= (p)[k]) &&
        (result) <= (i));
        loop assigns i, result, max, min;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        
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
