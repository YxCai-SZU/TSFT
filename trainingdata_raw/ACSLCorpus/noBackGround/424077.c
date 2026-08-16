#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (n) && (n) <= 100000);
    requires (1 <= (k) && (k) <= 500);
    requires \valid_read(h + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((h)[i]) && ((h)[i]) <= 500));
    ensures 0 <= \result <= n;
    assigns \nothing;
 */
int func(int n, int k, int *h) {
    int count = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= (size_t)n;
        loop invariant 0 <= count <= (int)index <= n;
        loop invariant index > 0 ==> count == (int)index - ((int)index - count);
        loop invariant \forall integer i; 0 <= i < index ==> (1 <= (h[i]) && (h[i]) <= 500);
        loop invariant (1 <= (n) && (n) <= 100000);
        loop invariant (1 <= (k) && (k) <= 500);
        loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((h)[i]) && ((h)[i]) <= 500));
        loop assigns count, index;
        loop variant n - index;
     */
    while (index < (size_t)n) {
        //@ assert 0 <= index < (size_t)n;
        if (h[index] >= k) {
            count += 1;
        }
        index += 1;
    }
    return count;
}
