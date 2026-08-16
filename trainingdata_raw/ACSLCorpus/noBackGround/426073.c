#include <stdbool.h>
#include <stddef.h>

/*@ requires 1 <= n <= 100000;
    requires 1 <= k <= 500;
    requires \valid(heights + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (heights)[i] <= 500);
    assigns \nothing;
    ensures 0 <= \result <= n;
    ensures \forall integer i; 0 <= i < n ==> (heights[i] >= k ==> \result > 0);
*/
int func(int n, int k, int *heights) {
    int cnt = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= cnt <= (int)index;
        loop invariant index > 0 ==> ((cnt) > 0 <==> (\exists integer i; 0 <= i < (index) && (heights)[i] >= (k)));
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (heights)[i] <= 500);
        loop assigns cnt, index;
        loop variant n - index;
    */
    while (index < (size_t)n) {
        int h = heights[index];
        if (h >= k) {
            cnt = cnt + 1;
        }
        index = index + 1;
    }
    return cnt;
}
