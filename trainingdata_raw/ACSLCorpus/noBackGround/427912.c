#include <stdbool.h>
#include <stddef.h>

/*@ requires n > 0 && n <= 100;
    requires \valid(numbers + (0 .. n-1));
    requires ((n) > 0 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(int n, int* numbers) {
    int positive_count = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= positive_count <= index;
        loop invariant ((n) > 0 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
        loop invariant (0 <= (index) <= (n) &&
      0 <= (positive_count) <= (index) &&
      \forall integer k; 0 <= k < (index) ==> ((numbers)[k] > 0 ==> (positive_count) >= 1));
        loop assigns positive_count, index;
        loop variant n - index;
    */
    while (index < (size_t)n) {
        int x = numbers[index];
        //@ assert x >= 1 && x <= 100;
        if (x > 0) {
            positive_count += 1;
        }
        index += 1;
    }
    return positive_count;
}
