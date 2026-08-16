#include <stdbool.h>

/*@ requires (1 <= (n) <= 100);
    requires (1 <= (x) <= 10000);
    requires \valid(numbers + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 100));
    ensures \result >= 0;
    ensures \result <= n + 1;
    assigns \nothing;
*/
int func(int n, int x, int *numbers) {
    int sum = 0;
    int count = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant sum >= 0;
        loop invariant sum <= i * 100;
        loop invariant count >= 0;
        loop invariant count <= i;
        loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 100));
        loop invariant \forall integer k; 0 <= k < i ==> sum >= numbers[k];
        loop invariant i > 0 ==> (sum <= x ==> count == i);
        loop invariant i > 0 ==> (sum > x ==> count == i - 1);
        loop invariant i == 0 ==> count == 0;
        loop assigns sum, count, i;
        loop variant n - i;
    */
    while (i < n) {
        int old_sum = sum;
        int old_count = count;
        int old_i = i;
        
        sum += numbers[i];
        count += 1;
        
        //@ assert sum == old_sum + numbers[i];
        
        if (sum <= x) {
            //@ assert sum <= x;
        } else {
            //@ assert sum > x;
            return count;
        }
        
        i += 1;
    }
    
    return count;
}
