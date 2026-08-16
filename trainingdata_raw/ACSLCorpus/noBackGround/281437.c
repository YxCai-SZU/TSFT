#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (n) <= 100000 &&
      1 <= (m) <= 100000 &&
      \forall integer i; 0 <= i < (m) ==> (input_numbers)[i] >= 1 && (input_numbers)[i] <= 100000);
    requires \valid_read(input_numbers + (0 .. m-1));
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result <= m;
*/
int func(int n, int m, int *input_numbers) {
    int count = 0;
    size_t index = 0;
    
    /*@ loop invariant (0 <= (index) <= (m) &&
      0 <= (count) <= (index) &&
      \forall integer i; 0 <= i < (index) ==> (input_numbers)[i] >= 1 && (input_numbers)[i] <= 100000);
        loop assigns count, index;
        loop variant m - index;
    */
    while (index < (size_t)m) {
        int a = input_numbers[index];
        //@ assert a >= 1 && a <= 100000;
        if (a == n) {
            count++;
        }
        index++;
    }
    
    if (count == 0) {
        return -1;
    } else {
        //@ assert count >= 1 && count <= m;
        return count;
    }
}
