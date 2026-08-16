#include <stdbool.h>
#include <stdint.h>

/*@
    requires ((n) > 0 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= 1000);
    ensures \result == true <==> (\forall integer i; 0 <= i < (n) && (numbers)[i] % 2 == 0 ==> 
        ((numbers)[i] % 3 == 0 || (numbers)[i] % 5 == 0));
    assigns \nothing;
*/
bool func(uint32_t n, uint32_t numbers[]) {
    bool ans = true;
    uint32_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant ((n) > 0 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= 1000);
        loop invariant ans == true <==> 
            (\forall integer j; 0 <= j < i && numbers[j] % 2 == 0 ==> 
             numbers[j] % 3 == 0 || numbers[j] % 5 == 0);
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        uint32_t x = numbers[i];
        if (x % 2 == 0) {
            //@ assert x % 2 == 0;
            if (!(x % 3 == 0 || x % 5 == 0)) {
                ans = false;
            }
        }
        i++;
    }
    return ans;
}
