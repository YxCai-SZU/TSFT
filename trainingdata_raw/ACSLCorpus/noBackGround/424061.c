#include <stdbool.h>

/*@
    requires \valid(v+(0..2));
    requires ((3) >= 3 &&
        1 <= (v)[0] <= 100 &&
        1 <= (v)[1] <= 20 &&
        1 <= (v)[2] <= 2000);
    ensures \result <= v[2];
    ensures \result >= 0;
*/
int func(int *v) {
    int m;
    int i;
    
    m = 0;
    i = 0;
    
    /*@
        loop invariant (0 <= (i) <= (v)[1] &&
        1 <= (v)[0] <= 100 &&
        1 <= (v)[1] <= 20 &&
        (m) <= (v)[2] &&
        (m) >= 0 &&
        (3) >= 3 &&
        (m) <= (i) * 100);
        loop assigns m, i;
        loop variant v[1] - i;
    */
    while (i < v[1]) {
        //@ assert m <= v[2];
        if (m + v[0] < v[2]) {
            m += v[0];
        } else {
            break;
        }
        i += 1;
        //@ assert m <= i * 100;
    }
    
    return m;
}
