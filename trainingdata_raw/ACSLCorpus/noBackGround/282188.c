#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 100000 &&
        (k) >= 1 && (k) <= 500);
    requires \valid(h + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
    assigns \nothing;
    ensures 0 <= \result <= n;
    ensures \forall integer i; 0 <= i < n ==> (h[i] >= k ==> \result > 0);
*/
int func(int n, int k, int *h) {
    int count = 0;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant \forall integer j; 0 <= j < index ==> (h[j] >= k ==> count > 0);
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < (size_t)n) {
        //@ assert 0 <= index < n;
        if (h[index] >= k) {
            //@ assert h[index] >= k;
            count++;
        }
        index++;
    }
    return count;
}
