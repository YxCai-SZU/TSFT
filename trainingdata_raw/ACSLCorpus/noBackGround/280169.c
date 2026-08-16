#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (n) && (n) <= 200000);
    requires \valid_read(an + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= ((unsigned long long *)an)[i] && ((unsigned long long *)an)[i] <= 1000000000);
    assigns \nothing;
    ensures 0 <= \result <= (int)n;
*/
int func(size_t n, const unsigned long long *an) {
    unsigned long long *before = NULL;
    int count = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant (0 <= (count) && (count) <= (index));
        loop invariant before == NULL || (before == (unsigned long long *)&an[index-1] && index > 0);
        loop assigns index, count, before;
    */
    while (index < n) {
        unsigned long long a = an[index];
        
        if (before != NULL) {
            //@ assert *before == an[index-1];
            if (a <= *before) {
                count = count + 1;
            }
        }
        
        before = (unsigned long long *)&an[index];
        index = index + 1;
    }
    
    return count;
}
