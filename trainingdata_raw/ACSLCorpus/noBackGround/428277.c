#include <limits.h>
#include <stdbool.h>

/*@ requires (1 <= (n) <= 200000);
    requires n >= 1;
    requires \valid_read(numbers + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000000000));
    ensures 0 <= \result <= n;
    assigns \nothing;
 */
int func(int n, int *numbers) {
    int count = 0;
    int before = INT_MAX;
    int index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant index > 0 ==> (\forall integer i; 0 <= i < (index) ==> (1 <= ((numbers)[i]) <= 1000000000));
        loop invariant (1 <= (n) <= 200000);
        loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000000000));
        loop assigns count, before, index;
        loop variant n - index;
     */
    while (index < n) {
        int number = numbers[index];
        //@ assert (1 <= (number) <= 1000000000);
        if (number < before) {
            count += 1;
            before = number;
        }
        index += 1;
    }
    //@ assert 0 <= count <= n;
    return count;
}
