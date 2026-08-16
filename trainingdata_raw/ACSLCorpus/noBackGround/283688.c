#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 1 && n <= 1000000;
    requires m >= 1 && m <= 10000;
    requires \valid(array + (0 .. m-1));
    requires ((m) >= 1 && (m) <= 10000 &&
      \forall integer i; 0 <= i < (m) ==> (array)[i] >= 1 && (array)[i] <= 10000);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result <= n;
*/
int func(int n, int m, int *array) {
    int v = 0;
    size_t index = 0;
    
    /*@ loop invariant (0 <= (index) <= (m) &&
      (v) >= 0 &&
      (v) <= (index) * 10000 &&
      \forall integer i; 0 <= i < (index) ==> (array)[i] >= 1 && (array)[i] <= 10000 &&
      (((m)) >= 1 && ((m)) <= 10000 &&
      \forall integer i; 0 <= i < ((m)) ==> ((array))[i] >= 1 && ((array))[i] <= 10000));
        loop assigns v, index;
        loop variant m - index;
    */
    while (index < (size_t)m) {
        //@ assert array[index] >= 1 && array[index] <= 10000;
        v += array[index];
        index++;
    }
    
    int result;
    if (n - v >= 0) {
        result = n - v;
        //@ assert result >= 0;
    } else {
        result = -1;
    }
    //@ assert result >= 0 || result == -1;
    return result;
}
