#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    requires (1 <= (x) && (x) <= 10000);
    requires n >= 1;
    requires \valid(numbers + (0..n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] && (numbers)[i] <= 100);
    ensures \result >= 0;
    ensures \result <= n;
*/
int func(int n, int x, int *numbers) {
    int count = 0;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] && (numbers)[i] <= 100);
        loop invariant (1 <= (n) && (n) <= 100);
        loop invariant (1 <= (x) && (x) <= 10000);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        int num = numbers[i];
        bool is_divisible = false;
        int temp = x;
        
        /*@
            loop invariant 0 <= temp <= x;
            loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] && (numbers)[i] <= 100);
            loop invariant (1 <= (n) && (n) <= 100);
            loop invariant (1 <= (x) && (x) <= 10000);
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= num) {
            temp -= num;
        }
        
        if (temp == 0) {
            is_divisible = true;
        }
        
        if (is_divisible) {
            count += 1;
        }
        
        i += 1;
    }
    
    return count;
}
