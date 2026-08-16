#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 1 && (n) <= 100 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
    assigns \nothing;
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result < n;
*/
int func(size_t n, int *a) {
    int ret = -1;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant ((n) >= 1 && (n) <= 100 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
        loop invariant (((ret) == -1) || ((ret) >= 0 && (ret) < (index) && (ret) < (n)));
        loop assigns ret, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        if (a[index] % 2 == 0) {
            break;
        }
        //@ assert 0 <= index < n;
        if (a[index] % 3 == 0) {
            break;
        }
        //@ assert 0 <= index < n;
        if (a[index] % 5 == 0) {
            break;
        }
        //@ assert 0 <= index < n;
        ret = (int)index;
        index++;
    }
    return ret;
}
