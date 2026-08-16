#include <stdbool.h>

/*@ requires (\valid((a)) && \valid((a)+1) && \valid((a)+2) &&
      1 <= (a)[0] <= 100 && 1 <= (a)[1] <= 100 && 1 <= (a)[2] <= 100);
    ensures \result == (((a[0]) > (a[1])) ? ((a[0]) - (a[1])) : ((a[1]) - (a[0]))) || 
            \result == (((a[0]) > (a[2])) ? ((a[0]) - (a[2])) : ((a[2]) - (a[0]))) ||
            \result == (((a[1]) > (a[2])) ? ((a[1]) - (a[2])) : ((a[2]) - (a[1])));
    assigns \nothing;
 */
int func(int* a) {
    int min_val;
    int max_val;
    int i;
    
    min_val = a[0];
    max_val = a[0];
    i = 1;
    
    /*@ loop invariant 0 <= i <= 3;
        loop invariant (\valid((a)) && \valid((a)+1) && \valid((a)+2) &&
      1 <= (a)[0] <= 100 && 1 <= (a)[1] <= 100 && 1 <= (a)[2] <= 100);
        loop invariant \exists integer x; 0 <= x < i && max_val == a[x];
        loop invariant \exists integer y; 0 <= y < i && min_val == a[y];
        loop invariant \forall integer j; 0 <= j < i ==> min_val <= a[j];
        loop invariant \forall integer j; 0 <= j < i ==> max_val >= a[j];
        loop invariant 1 <= min_val <= 100;
        loop invariant 1 <= max_val <= 100;
        loop assigns min_val, max_val, i;
        loop variant 3 - i;
     */
    while (i < 3) {
        if (a[i] < min_val) {
            min_val = a[i];
        }
        if (a[i] > max_val) {
            max_val = a[i];
        }
        i = i + 1;
    }
    
    //@ assert max_val - min_val == (((a[0]) > (a[1])) ? ((a[0]) - (a[1])) : ((a[1]) - (a[0]))) || max_val - min_val == (((a[0]) > (a[2])) ? ((a[0]) - (a[2])) : ((a[2]) - (a[0]))) || max_val - min_val == (((a[1]) > (a[2])) ? ((a[1]) - (a[2])) : ((a[2]) - (a[1])));
    
    return max_val - min_val;
}
