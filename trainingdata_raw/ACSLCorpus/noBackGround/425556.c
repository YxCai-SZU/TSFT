#include <stdbool.h>
/*@
    requires ((n) > 0 && (n) <= 200);
    requires \valid_read(numbers + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
    ensures 0 <= \result <= n;
*/
int func(int n, int *numbers) {
    int minv = 101;
    int index = 0;
    int result = 0;
    
    /*@
        loop invariant (0 <= (index) && (index) <= (n));
        loop invariant (0 <= (result) && (result) <= (index));
        loop invariant index > 0 ==> (\forall integer i; 0 <= i < (index) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
        loop invariant (\forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
        loop invariant n > 0 && n <= 200;
        loop invariant index <= n;
        loop assigns minv, index, result;
        loop variant n - index;
    */
    while (index < n) {
        int a = numbers[index];
        //@ assert a >= 1 && a <= 100;
        
        if (minv >= a) {
            minv = a;
            result += 1;
        }
        //@ assert (0 <= (result) && (result) <= (index+1));
        index += 1;
    }
    return result;
}
