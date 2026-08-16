#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 100000 &&
    \valid((numbers) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 1000000000);
    ensures \result <= n;
    ensures ((n) >= 1 && (n) <= 100000 &&
    \valid((numbers) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 1000000000);
*/
size_t func(size_t n, size_t *numbers) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant ((n) >= 1 && (n) <= 100000 &&
    \valid((numbers) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 1000000000);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        size_t a = numbers[i];
        
        if (a % 2 == 0) {
            if (a % 3 == 0 || a % 5 == 0) {
                count += 1;
            }
        } else {
            count += 1;
        }
        
        i += 1;
    }
    
    return count;
}
