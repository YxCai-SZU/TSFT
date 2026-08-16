#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (n) <= 1000000 && 1 <= (m) <= 10000);
    requires \valid(a + (0 .. m-1));
    requires (\forall integer i; 0 <= i < (m) ==> 1 <= (a)[i] <= 10000);
    ensures \result >= -1;
    ensures \result >= 0 ==> \result <= n;
*/
int func(int n, int m, int *a) {
    int sum = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= m;
        loop invariant sum >= 0;
        loop invariant sum <= index * 10000;
        loop assigns sum, index;
        loop variant m - index;
    */
    while (index < (size_t)m) {
        //@ assert 0 <= index < m;
        sum += a[index];
        index++;
    }
    
    if (sum <= n) {
        //@ assert sum >= 0;
        return n - sum;
    } else {
        return -1;
    }
}
