#include <stdbool.h>
#include <stddef.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= x <= 10000;
    requires \valid(numbers + (0 .. n-1));
    requires ((n) >= 1 && (n) <= 100 &&
    \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
    ensures \result >= 0;
    ensures \result <= n + 1;
    assigns \nothing;
*/
int func(int n, int x, int *numbers) {
    int sum = 0;
    int count = 0;
    int index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant 0 <= sum <= index * 100;
        loop invariant ((n) >= 1 && (n) <= 100 &&
    \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
        loop invariant x >= 1 && x <= 10000;
        loop assigns sum, count, index;
        loop variant n - index;
    */
    while (index < n) {
        int num = numbers[index];
        sum += num;
        if (sum <= x) {
            count += 1;
        }
        index += 1;
    }
    return count;
}
