#include <stddef.h>
#include <stdbool.h>

/*@ requires ((k) >= 1 && (k) <= 100000 &&
    \valid((h) + (0 .. (k)-1)) &&
    \forall integer i; 0 <= i < (k) ==> (h)[i] >= 1 && (h)[i] <= 500);
    assigns \nothing;
    ensures 0 <= \result <= (int)k;
*/
int func(size_t k, int *h) {
    int num = 0;
    size_t i = 0;
    
    /*@ loop invariant (0 <= (i) <= (k) &&
    0 <= (num) <= (int)(i) &&
    \valid((h) + (0 .. (k)-1)) &&
    \forall integer j; 0 <= j < (k) ==> (h)[j] >= 1 && (h)[j] <= 500);
        loop assigns i, num;
        loop variant k - i;
    */
    while (i < k) {
        //@ assert h[i] >= 1 && h[i] <= 500;
        if (h[i] >= 300) {
            num = num + 1;
        }
        i = i + 1;
    }
    
    //@ assert num <= (int)k;
    return num;
}
