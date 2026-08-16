#include <stdbool.h>
/*@
    requires ((n) >= 1 && (n) <= 100000 &&
        (k) >= 1 && (k) <= 500);
    requires (\valid((h) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
    ensures \result >= 0 && \result <= n;
    ensures (\forall integer i; 0 <= i < (n) ==> ((h)[i] >= (k) ==> (\result) > 0));
    ensures (\forall integer i; 0 <= i < (n) ==> ((h)[i] < (k) ==> (\result) < (n)));
*/
int func(int n, int k, int *h) {
    int ans = 0;
    int index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant ans >= 0;
        loop invariant ans <= index;
        loop invariant \forall integer i; 0 <= i < index ==> (h[i] >= k ==> ans > 0);
        loop invariant \forall integer i; 0 <= i < index ==> (h[i] < k ==> ans < index);
        loop invariant (\valid((h) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
        loop invariant ((n) >= 1 && (n) <= 100000 &&
        (k) >= 1 && (k) <= 500);
        loop assigns ans, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        if (h[index] >= k) {
            ans += 1;
        }
        index += 1;
    }
    return ans;
}
