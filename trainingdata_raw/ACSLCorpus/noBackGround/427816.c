#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 2 && (n) <= 100 &&
      \valid((numbers) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= 100);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(int n, int *numbers) {
    int a[100];
    int i = 0;
    int min = 100000;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant \forall integer j; 0 <= j < i ==> a[j] == numbers[j];
        loop assigns i, a[0 .. n-1];
        loop variant n - i;
    */
    while (i < n) {
        a[i] = numbers[i];
        i++;
    }
    
    i = 0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant \forall integer j; 0 <= j < n ==> a[j] == numbers[j];
        loop invariant min >= 0;
        loop assigns i, min;
        loop variant n - i;
    */
    while (i < n) {
        int num = a[i];
        int diff;
        
        if (num >= 2) {
            int x = num - 1;
            /*@ loop invariant x >= 0;
                loop assigns x;
                loop variant x;
            */
            while (x >= 2) {
                x -= 2;
            }
            diff = x;
        } else {
            diff = 0;
        }
        
        //@ assert diff >= 0;
        
        if (min > diff) {
            min = diff;
        }
        i++;
    }
    
    //@ assert min >= 0;
    return min;
}
