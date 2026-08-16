#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) > 0 && (n) <= 100 &&
      \forall size_t i; 0 <= i < (n) ==> 1 <= (a)[i] <= 100);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(size_t n, int *a) {
    int res = 100000;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant res >= 0;
        loop invariant ((n) > 0 && (n) <= 100 &&
      \forall size_t i; 0 <= i < (n) ==> 1 <= (a)[i] <= 100);
        loop invariant i <= n;
        loop assigns i, res;
        loop variant n - i;
    */
    while (i < n) {
        int temp = a[i];
        //@ assert 1 <= temp <= 100;
        if (temp >= 2 && temp < res) {
            res = temp;
        }
        i++;
    }
    return res;
}
