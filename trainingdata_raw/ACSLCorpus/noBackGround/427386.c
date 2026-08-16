#include <stdbool.h>

/*@ requires (1 <= (n) <= 200000);
    requires \valid(numbers + (0..n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000000));
    ensures 0 <= \result <= n;
*/
int func(int n, int *numbers) {
    int count = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant \valid(numbers + (0..n-1));
        loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000000));
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        int x = numbers[i];
        bool is_divisible = true;
        int j = 0;
        
        /*@ loop invariant 0 <= j <= n;
            loop invariant \valid(numbers + (0..n-1));
            loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000000));
            loop invariant is_divisible == true || is_divisible == false;
            loop assigns j, is_divisible;
            loop variant n - j;
        */
        while (j < n) {
            if (i != j) {
                int remainder = x;
                
                /*@ loop invariant remainder >= 0;
                    loop assigns remainder;
                    loop variant remainder;
                */
                while (remainder >= numbers[j]) {
                    remainder -= numbers[j];
                }
                
                if (remainder != 0) {
                    is_divisible = false;
                }
            }
            j++;
        }
        
        if (is_divisible) {
            count++;
        }
        i++;
    }
    return count;
}
