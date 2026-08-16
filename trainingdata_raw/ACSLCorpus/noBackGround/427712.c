#include <stdbool.h>
/*@
    requires (1 <= (n) && (n) <= 20 &&
        1 <= (v) && (v) <= 50 &&
        \valid((c) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (c)[i] && (c)[i] <= 50);
    ensures 0 <= \result && \result <= n;
    assigns \nothing;
*/
int func(int n, int v, int *c) {
    int sum = 0;
    int index = 0;
    
    /*@
        loop invariant (0 <= (index) && (index) <= (n) &&
        (sum) >= 0 &&
        (sum) <= (index) &&
        (1 <= ((n)) && ((n)) <= 20 &&
        1 <= ((v)) && ((v)) <= 50 &&
        \valid(((c)) + (0 .. ((n))-1)) &&
        \forall integer i; 0 <= i < ((n)) ==> 1 <= ((c))[i] && ((c))[i] <= 50) &&
        (index) <= (n));
        loop assigns sum, index;
        loop variant n - index;
    */
    while (index < n) {
        int x = c[index];
        //@ assert 1 <= x && x <= 50;
        if (v < x) {
            sum += 1;
        }
        index += 1;
    }
    //@ assert sum >= 0;
    //@ assert sum <= n;
    return sum;
}
