#include <stdbool.h>

/*@ requires 1 <= n <= 1000000;
    requires 1 <= m <= 10000;
    requires (\forall integer i; 0 <= i < (len) ==> 1 <= (a)[i] <= 10000);
    requires len >= 0;
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result <= n;
*/
int func(int n, int m, int* a, int len) {
    int sum = 0;
    int i = 0;
    int result;
    
    /*@ loop invariant (0 <= (i) <= (len) &&
        (sum) >= 0 &&
        \forall integer j; 0 <= j < (i) ==> 1 <= (a)[j] <= 10000 &&
        1 <= (n) <= 1000000 &&
        1 <= (m) <= 10000 &&
        (sum) <= (n) + 10000);
        loop assigns sum, i;
        loop variant len - i;
    */
    while (i < len && sum <= n) {
        //@ assert 0 <= i < len;
        sum += a[i];
        i++;
    }
    
    if (sum <= n) {
        //@ assert n - sum >= 0;
        result = n - sum;
    } else {
        result = -1;
    }
    
    return result;
}
