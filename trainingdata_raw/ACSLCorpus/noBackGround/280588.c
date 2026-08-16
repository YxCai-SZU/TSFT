#include <stdbool.h>
#include <stddef.h>

/*@
    requires (1 <= (n) <= 1000000);
    requires (\valid((v) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> 1 <= (v)[i] <= 1000000);
    ensures \result >= 0;
    ensures \result <= n;
*/
int func(int n, int *v) {
    int step = 0;
    int w = 0;
    int index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant step >= 0;
        loop invariant step <= index;
        loop invariant w >= 0;
        loop invariant \forall integer i; 0 <= i < index ==> 1 <= v[i] <= 1000000;
        loop invariant (1 <= (n) <= 1000000);
        loop invariant (\valid((v) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> 1 <= (v)[i] <= 1000000);
        loop assigns step, w, index;
        loop variant n - index;
    */
    while (index < n) {
        int x = v[index];
        if (w >= x) {
            w = w - x + 1;
            step += 1;
        } else {
            w = 0;
        }
        index += 1;
    }
    return step;
}
