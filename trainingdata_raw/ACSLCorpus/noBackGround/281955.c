#include <stddef.h>
#include <stdbool.h>

/*@ requires ((n) > 0 && (n) <= 100 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 100);
    ensures 0 <= \result && \result <= (int)n;
    assigns \nothing;
*/
int func(size_t n, int *a) {
    int count = 0;
    size_t index = 0;
    
    /*@ loop invariant ((((n)) > 0 && ((n)) <= 100 &&
      \valid(((a)) + (0 .. ((n))-1)) &&
      \forall integer i; 0 <= i < ((n)) ==> 1 <= ((a))[i] && ((a))[i] <= 100) &&
      0 <= (index) && (index) <= (n) &&
      0 <= (count) && (count) <= (int)(index));
        loop assigns index, count;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index && index < n;
        int value = a[index];
        if (value == (int)(index + 1)) {
            count += 1;
        }
        index += 1;
    }
    return count;
}
