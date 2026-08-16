#include <stddef.h>
#include <stdbool.h>

/*@ requires ((n) > 0 && (n) <= 100 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 100);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(size_t n, int *a) {
    int count = 0;
    size_t num = 0;
    
    /*@ loop invariant 0 <= num <= n;
        loop invariant 0 <= count <= num;
        loop invariant ((n) > 0 && (n) <= 100 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 100);
        loop invariant count <= num;
        loop assigns count, num;
        loop variant n - num;
    */
    while (num < n) {
        int value = a[num];
        if (value == (int)(num + 1)) {
            count += 1;
        }
        num += 1;
    }
    
    //@ assert count <= n;
    return count;
}
