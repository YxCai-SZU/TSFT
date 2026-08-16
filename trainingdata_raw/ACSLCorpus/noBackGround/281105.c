#include <stdbool.h>

/*@
    requires (1 <= (n) <= 1000000 &&
        1 <= (m) <= 10000 &&
        \valid((numbers) + (0 .. (m)-1)) &&
        \forall integer i; 0 <= i < (m) ==> (numbers)[i] >= 1 && (numbers)[i] <= 10000);
    ensures \result >= -1 && \result <= n;
    assigns \nothing;
*/
int func(int n, int m, int *numbers) {
    int v = 0;
    int index = 0;
    
    /*@
        loop invariant (0 <= (index) <= (m) &&
        (v) >= 0 &&
        ((index) > 0 ==> \forall integer j; 0 <= j < (index) ==> (v) >= (numbers)[j]) &&
        (v) <= (n) + 10000);
        loop assigns v, index;
        loop variant m - index;
    */
    while (index < m && v <= n) {
        //@ assert 0 <= index < m;
        v += numbers[index];
        index++;
    }
    
    if (v <= n) {
        return n - v;
    } else {
        return -1;
    }
}
