#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 100000 &&
        (k) >= 1 && (k) <= 500);
    requires (\valid((h) + (0 .. (n)-1)) &&
        \forall integer j; 0 <= j < (n) ==> (h)[j] >= 1 && (h)[j] <= 500);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(size_t n, int k, int *h) {
    int num = 0;
    size_t i = 0;
    
    /*@
        loop invariant (0 <= (i) <= (n) &&
        0 <= (num) <= (i) &&
        (((n)) >= 1 && ((n)) <= 100000 &&
        (500) >= 1 && (500) <= 500) &&
        (\valid(((h)) + (0 .. ((n))-1)) &&
        \forall integer j; 0 <= j < ((n)) ==> ((h))[j] >= 1 && ((h))[j] <= 500));
        loop invariant i <= n;
        loop assigns i, num;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (h[i] >= k) {
            num = num + 1;
        }
        i = i + 1;
    }
    return num;
}
