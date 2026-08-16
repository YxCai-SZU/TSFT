#include <stdbool.h>

/*@ requires 2 <= n && n <= 1000000;
    requires \valid(numbers + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (((numbers)[i]) > 0 && ((numbers)[i]) <= 1000000000));
    ensures \result >= 0;
*/
int func(int n, int *numbers) {
    int max = 0;
    int tmp = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 2 <= n <= 1000000;
        loop invariant \valid(numbers + (0 .. n-1));
        loop invariant (\forall integer i; 0 <= i < (n) ==> (((numbers)[i]) > 0 && ((numbers)[i]) <= 1000000000));
        loop invariant max >= 0;
        loop invariant tmp >= 0;
        loop assigns i, max, tmp;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i && i < n ==> (0 <= (i) && (i) < (n));
        
        if (i == 0) {
            tmp = numbers[i];
        } else {
            if (tmp > numbers[i]) {
                tmp = tmp;
            } else {
                tmp = numbers[i];
            }
        }
        
        //@ assert tmp >= 0;
        
        if (max > tmp) {
            max = tmp;
        }
        
        //@ assert max >= 0;
        
        i += 1;
    }
    
    //@ assert max >= 0;
    return max;
}
