#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 2 && (n) <= 100000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= (n) && (a)[i] != i + 1);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result <= n-1;
    assigns \nothing;
*/
int func(int n, int *a) {
    int ret = -1;
    int index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant ((n) >= 2 && (n) <= 100000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= (n) && (a)[i] != i + 1);
        loop invariant ret >= -1;
        loop invariant ret <= index;
        loop invariant ret >= 0 ==> ret <= n-1;
        loop assigns index, ret;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= a[index]-1 < n;
        if (a[a[index] - 1] == index + 1) {
            ret = index;
            break;
        }
        index++;
    }
    
    return ret;
}
