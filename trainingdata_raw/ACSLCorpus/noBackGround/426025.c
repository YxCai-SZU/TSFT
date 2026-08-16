#include <stdbool.h>

/*@
    requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    ensures \result == (k * 500 >= x);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x) {
    unsigned int sum = 0;
    unsigned int i = 0;
    
    /*@
        loop invariant 0 <= i <= k;
        loop invariant sum == ((i) * 500);
        loop invariant 1 <= k <= 100;
        loop invariant 1 <= x <= 100000;
        loop invariant sum <= 50000;
        loop assigns sum, i;
        loop variant k - i;
    */
    while (i < k) {
        unsigned int temp_sum = sum;
        unsigned int count = 0;
        
        /*@
            loop invariant 0 <= count <= 500;
            loop invariant temp_sum == sum + count;
            loop invariant 0 <= i <= k;
            loop invariant 1 <= k <= 100;
            loop invariant 1 <= x <= 100000;
            loop invariant temp_sum <= 50000;
            loop assigns temp_sum, count;
            loop variant 500 - count;
        */
        while (count < 500) {
            temp_sum = temp_sum + 1;
            count = count + 1;
        }
        
        sum = temp_sum;
        i = i + 1;
    }
    
    bool result = (sum >= x);
    return result;
}
