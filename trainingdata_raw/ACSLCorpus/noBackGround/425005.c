#include <stdbool.h>
#include <limits.h>

/*@ requires (1 <= (n) <= 100);
    requires \valid(numbers + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= 100);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(int n, int *numbers) {
    int min = INT_MAX;
    int count = 0;
    int index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant ((min) <= INT_MAX);
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= 100);
        loop invariant index <= n;
        loop assigns min, count, index;
        loop variant n - index;
    */
    while (index < n) {
        int a = numbers[index];
        
        //@ assert 1 <= a <= 100;
        
        if (min > a) {
            min = a;
            count = count + 1;
        }
        
        //@ assert (0 <= (index + 1) <= (n) && 0 <= (count) <= (index + 1));
        index = index + 1;
    }
    
    //@ assert count >= 0;
    //@ assert count <= n;
    return count;
}
