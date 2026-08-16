#include <stdbool.h>

/*@
    requires ((n) >= 1 && (n) <= 100000 &&
        (k) >= 1 && (k) <= 500);
    requires \valid(heights + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 
            (heights)[i] >= 1 && (heights)[i] <= 500);
    ensures \result >= 0 && \result <= n;
*/
int func(int n, int k, int *heights) {
    int cnt = 0;
    int index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= cnt <= index;
        loop invariant index > 0 ==> (\forall integer i; 0 <= i < (index) ==> 
            (heights)[i] >= 1 && (heights)[i] <= 500);
        loop invariant ((n) >= 1 && (n) <= 100000 &&
        (k) >= 1 && (k) <= 500);
        loop invariant (\forall integer i; 0 <= i < (n) ==> 
            (heights)[i] >= 1 && (heights)[i] <= 500);
        loop assigns cnt, index;
        loop variant n - index;
    */
    while (index < n) {
        int h = heights[index];
        if (h >= k) {
            cnt += 1;
        }
        index += 1;
        //@ assert index <= n;
    }
    return cnt;
}
