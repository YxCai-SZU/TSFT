#include <stdbool.h>
/*@
    requires ((n) >= 1 && (n) <= 100000 &&
        (k) >= 1 && (k) <= 500);
    requires \valid(heights + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (heights)[i] >= 1 && (heights)[i] <= 500);
    assigns \nothing;
    ensures ((\result) >= 0 && (\result) <= (n) &&
        \forall integer i; 0 <= i < (n) ==> ((heights)[i] >= (k) ==> (\result) > 0));
*/
int func(int n, int k, int *heights) {
    int cnt = 0;
    int a = 0;
    unsigned int index = 0;

    /*@
        loop invariant 0 <= a <= n;
        loop invariant index == (unsigned int)a;
        loop invariant cnt >= 0 && cnt <= a;
        loop invariant \forall integer i; 0 <= i < a ==> (heights[i] >= k ==> cnt >= 1);
        loop invariant (\forall integer i; 0 <= i < (n) ==> (heights)[i] >= 1 && (heights)[i] <= 500);
        loop assigns cnt, a, index;
    */
    while (a < n) {
        int hi = heights[index];
        //@ assert hi >= 1 && hi <= 500;
        
        if (hi >= k) {
            cnt += 1;
        }
        a += 1;
        index += 1;
    }
    //@ assert cnt <= n;
    return cnt;
}
