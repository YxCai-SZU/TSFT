#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 1;
    requires \valid(numbers + (0 .. n-1));
    requires ((n) >= 1 &&
      \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 1000);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(int n, int* numbers) {
    int highest;
    int count;
    size_t index;
    int num;

    highest = 0;
    count = 0;
    index = 0;

    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant ((n) >= 1 &&
      \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 1000);
        loop assigns highest, count, index, num;
        loop variant n - index;
    */
    while (index < (size_t)n) {
        num = numbers[index];
        if (highest <= num) {
            highest = num;
            count = count + 1;
        }
        index = index + 1;
    }
    return count;
}
