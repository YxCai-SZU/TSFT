#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 1 && (n) <= 100 &&
    (x) >= 1 && (x) <= 10000 &&
    \valid((l_vec) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (l_vec)[i] >= 1 && (l_vec)[i] <= 100);
    assigns \nothing;
    ensures \result >= 0 && \result <= n+1;
*/
int func(int n, int x, int *l_vec) {
    int d = 0;
    int num = 0;
    int i = 0;
    
    /*@ loop invariant (0 <= (i) && (i) <= (n) &&
    0 <= (d) && (d) <= (i) * 100 &&
    0 <= (num) && (num) <= (i) &&
    \valid((l_vec) + (0 .. (n)-1)));
        loop assigns d, num, i;
        loop variant n - i;
    */
    while (i < n) {
        int next_d = d + l_vec[i];
        if (next_d <= x) {
            d = next_d;
            num += 1;
        } else {
            break;
        }
        i += 1;
    }
    
    //@ assert num >= 0;
    return num;
}
