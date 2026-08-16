#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 1 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 100;
    ensures \result >= 0;
*/
int func(int n, int *a) {
    int count = 0;
    size_t index = 0;
    
    /*@ loop invariant ((index) >= 0 && (index) <= (n) &&
      (count) >= 0 && (count) <= (index) &&
      (((n)) >= 1 && ((n)) <= 100 &&
      \valid(((a)) + (0 .. ((n))-1)) &&
      \forall integer i; 0 <= i < ((n)) ==> ((a))[i] >= 1 && ((a))[i] <= 100));
        loop assigns index, count;
        loop variant n - index;
    */
    while (index < (size_t)n) {
        int i = a[index];
        //@ assert i >= 1 && i <= 100;
        if (i & 1) {
            count++;
        }
        index++;
    }
    
    //@ assert count >= 0 && count <= n;
    
    index = 0;
    int result = 0;
    
    /*@ loop invariant ((index) >= 0 && (index) <= (count) &&
      (result) >= 0 && (result) <= (index) &&
      (((n)) >= 1 && ((n)) <= 100 &&
      \valid(((a)) + (0 .. ((n))-1)) &&
      \forall integer i; 0 <= i < ((n)) ==> ((a))[i] >= 1 && ((a))[i] <= 100) &&
      (count) <= (n));
        loop assigns index, result;
        loop variant count - index;
    */
    while (index < (size_t)count) {
        //@ assert index * 2 + 1 >= 1;
        result++;
        index++;
    }
    
    //@ assert result >= 0;
    return result;
}
