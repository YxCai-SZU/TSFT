#include <stdbool.h>
#include <stddef.h>

/*@ requires 
      ((len) < 0x80000000 && \valid((arr) + (0 .. (len)-1)));
    ensures
      \result >= 0 && \result <= (int)len;
    ensures
      len == 0 ==> \result == 0;
    ensures
      \forall integer i; 0 <= i < len ==> 
        (arr[i] == num ==> \result > 0);
*/
int count_occurrences(int *arr, size_t len, int num)
{
    int count = 0;
    size_t i = 0;
    
    /*@ loop invariant 
          0 <= i <= len;
        loop invariant
          count >= 0;
        loop invariant
          count <= (int)i;
        loop invariant
          \forall integer j; 0 <= j < i ==> 
            (arr[j] == num ==> count > 0);
        loop invariant
          len < 0x80000000;
        loop assigns
          count, i;
        loop variant
          len - i;
    */
    while (i < len) {
        //@ assert i < len;
        if (arr[i] == num) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
