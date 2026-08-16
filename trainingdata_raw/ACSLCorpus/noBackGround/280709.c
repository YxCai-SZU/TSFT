#include <stdbool.h>
#include <stddef.h>

/*@
    requires n > 0 && n <= 200;
    requires \valid(numbers + (0 .. n-1));
    requires ((n) > 0 && (n) <= 200 &&
        \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 1000000000);
    assigns \nothing;
    ensures \result >= 0 && \result <= 200;
*/
int func(int n, int *numbers) {
    int min = 200;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant min >= 0 && min <= 200;
        loop invariant \forall integer k; 0 <= k < i ==> 
            ((numbers[k]) / 2) >= 0 && ((numbers[k]) / 2) <= 500000000;
        loop assigns i, min;
        loop variant n - i;
    */
    while (i < n) {
        int num = numbers[i];
        int count = 0;
        int temp = num;
        
        /*@
            loop invariant temp >= 0 && temp <= num;
            loop invariant count >= 0;
            loop invariant count == (num - temp) / 2;
            loop invariant temp == num - 2 * count;
            loop assigns temp, count;
            loop variant temp;
        */
        while (temp >= 2) {
            temp -= 2;
            count += 1;
        }
        
        //@ assert count == ((num) / 2);
        
        if (count < min) {
            min = count;
        }
        
        i += 1;
    }
    
    return min;
}
