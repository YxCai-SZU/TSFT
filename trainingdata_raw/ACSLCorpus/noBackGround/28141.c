#include <stddef.h>
#include <stdint.h>

/*@
requires ((n) >= 1 && (n) <= 100 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall size_t i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000);
ensures \result >= 0 || \result == -1;
*/
int32_t func(size_t n, int32_t* a)
{
    size_t x = 1;
    int32_t count = 0;
    size_t index = 0;
    
    //@ assert ((index) >= 0 && (index) <= (n) &&       (n) >= 1 && (n) <= 100 &&       (x) >= 1 && (x) <= 1001 &&       (count) >= 0 && (count) <= (int32_t)(index) &&       \forall size_t i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000);
    
    /*@ loop invariant ((index) >= 0 && (index) <= (n) &&
      (n) >= 1 && (n) <= 100 &&
      (x) >= 1 && (x) <= 1001 &&
      (count) >= 0 && (count) <= (int32_t)(index) &&
      \forall size_t i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000);
        loop assigns index, x, count;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert index < n;
        if (x == a[index]) {
            x = x + 1;
        } else {
            count = count + 1;
        }
        index = index + 1;
        //@ assert ((index) >= 0 && (index) <= (n) &&       (n) >= 1 && (n) <= 100 &&       (x) >= 1 && (x) <= 1001 &&       (count) >= 0 && (count) <= (int32_t)(index) &&       \forall size_t i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000);
    }
    
    if (x == 1) {
        //@ assert count >= 0;
        return -1;
    } else {
        //@ assert count >= 0;
        return count;
    }
}
