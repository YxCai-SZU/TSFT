#include <stdbool.h>
#include <stddef.h>

/*@
    requires (2 <= (n) <= 200000);
    requires (1 <= (x) <= 1000000000);
    requires \valid(numbers + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000000000));
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int x, int *numbers) {
    int p = 1;
    int result = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= (size_t)n;
        loop invariant 1 <= p <= (int)index + 1;
        loop invariant 0 <= result <= (int)index;
        loop assigns p, result, index;
        loop variant n - index;
    */
    while (index < (size_t)n) {
        int a = numbers[index];
        
        //@ assert (1 <= (a) <= 1000000000);
        
        if (p >= a) {
            //@ assert p - a + 1 >= 1;
            p = p - a + 1;
        } else {
            //@ assert result + 1 >= 0;
            result = result + 1;
            p = 1;
        }
        
        //@ assert p >= 1;
        index++;
    }
    
    return result;
}
