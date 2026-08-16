#include <stdbool.h>
/*@
    requires ((n) >= 1 && (n) <= 100 &&
        (x) >= 1 && (x) <= 10000);
    requires \valid_read(numbers + (0 .. n-1));
    requires ((n) == (n) &&
        \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int x, int *numbers) {
    int sum = 0;
    int count = 0;
    int index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant sum >= 0;
        loop invariant sum <= ((index) * 100);
        loop invariant ((n) >= 1 && (n) <= 100 &&
        (x) >= 1 && (x) <= 10000);
        loop invariant ((n) == (n) &&
        \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
        loop assigns sum, count, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert numbers[index] >= 1 && numbers[index] <= 100;
        sum += numbers[index];
        //@ assert sum >= 0;
        //@ assert sum <= ((index + 1) * 100);
        if (sum <= x) {
            count += 1;
        }
        index += 1;
    }
    return count;
}
