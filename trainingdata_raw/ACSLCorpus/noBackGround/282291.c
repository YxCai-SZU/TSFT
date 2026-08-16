#include <stdbool.h>

/*@
    requires n >= 1 && n <= 20;
    requires \valid(h + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= h[i] <= 100;
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int *h) {
    int max = 0;
    int count = 0;
    int i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant max >= 0 && max <= i;
        loop invariant ((n) >= 1 && (n) <= 20 &&
        \valid((h) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (h)[i] <= 100);
        loop assigns i, count, max;
        loop variant n - i;
    */
    while (i < n) {
        bool f = true;
        int j = 0;
        /*@
            loop invariant 0 <= j <= i;
            loop invariant f == true ==> 
                \forall integer k; 0 <= k < j ==> h[i] >= h[k];
            loop invariant ((n) >= 1 && (n) <= 20 &&
        \valid((h) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (h)[i] <= 100);
            loop assigns j, f;
            loop variant i - j;
        */
        while (j < i) {
            //@ assert 0 <= i < n && 0 <= j < i;
            if (h[i] < h[j]) {
                f = false;
                break;
            }
            j++;
        }
        if (f) {
            count++;
            //@ assert count >= 1;
            max = (max > count) ? max : count;
            //@ assert max >= count;
        } else {
            count = 0;
        }
        //@ assert max >= 0 && max <= i+1;
        i++;
    }
    //@ assert max >= 0 && max <= n;
    return max;
}
