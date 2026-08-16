#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((numbers) + (0 .. (n)-1)) &&
        \forall integer k; 0 <= k < (n) ==> (numbers)[k] >= 1 && (numbers)[k] <= 1000000000);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(size_t n, const unsigned int *numbers) {
    int count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant ((n) >= 1 && (n) <= 200000 &&
        \valid(((unsigned int*)numbers) + (0 .. (n)-1)) &&
        \forall integer k; 0 <= k < (n) ==> ((unsigned int*)numbers)[k] >= 1 && ((unsigned int*)numbers)[k] <= 1000000000);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        bool is_divisible = false;
        size_t j = 1;
        
        /*@
            loop invariant 1 <= j <= n;
            loop invariant is_divisible == false ==> 
                \forall integer k; 1 <= k < j && k != i ==> numbers[i] % numbers[k] != 0;
            loop invariant is_divisible == true ==> 
                \exists integer k; 1 <= k < j && k != i && numbers[i] % numbers[k] == 0;
            loop invariant ((n) >= 1 && (n) <= 200000 &&
        \valid(((unsigned int*)numbers) + (0 .. (n)-1)) &&
        \forall integer k; 0 <= k < (n) ==> ((unsigned int*)numbers)[k] >= 1 && ((unsigned int*)numbers)[k] <= 1000000000);
            loop assigns j, is_divisible;
            loop variant n - j;
        */
        while (j < n) {
            if (i != j && numbers[i] % numbers[j] == 0) {
                is_divisible = true;
                break;
            }
            j++;
        }
        
        if (!is_divisible) {
            //@ assert \forall integer k; 1 <= k < n && k != i ==> numbers[i] % numbers[k] != 0;
            count++;
        }
        
        //@ assert ((i+1) >= 0 && (i+1) <= (n) && (count) >= 0 && (count) <= (i+1));
        i++;
    }
    
    //@ assert ((n) >= 0 && (n) <= (n) && (count) >= 0 && (count) <= (n));
    return count;
}
