#include <stddef.h>

/*@ requires ((1 <= (n) <= 100) && (1 <= (m) <= 100) && (1 <= (x) <= (n) - 1));
    requires \valid(a + (0 .. m-1));
    requires (\forall integer i; 0 <= i < (m) ==> 
        (1 <= (a)[i] <= (n)) && ((a)[i] != (x)));
    ensures \result <= m;
*/
size_t func(size_t n, size_t m, size_t x, int* a) {
    size_t ans_n = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= m;
        loop invariant 0 <= ans_n <= i;
        loop invariant ((1 <= (n) <= 100) && (1 <= (m) <= 100) && (1 <= (x) <= (n) - 1));
        loop invariant (\forall integer i; 0 <= i < (m) ==> 
        (1 <= (a)[i] <= (n)) && ((a)[i] != (x)));
        loop invariant \forall integer k; 0 <= k < i ==> 
            (a[k] < x && x < n) ==> ans_n >= 1;
        loop assigns i, ans_n;
        loop variant m - i;
    */
    while (i < m) {
        int value = a[i];
        if (value < (int)x && (int)x < (int)n) {
            ans_n++;
        }
        i++;
    }
    
    size_t ans_0 = m - ans_n;
    return (ans_n < ans_0) ? ans_n : ans_0;
}
