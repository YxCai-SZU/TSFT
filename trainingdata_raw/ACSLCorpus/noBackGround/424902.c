#include <stddef.h>

/*@
    requires ((n) >= 0 && (n) <= 100 &&
    \valid((numbers) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= 100);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
size_t func(size_t n, int *numbers) {
    int min_value = 101;
    size_t count = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant ((n) >= 0 && (n) <= 100 &&
    \valid((numbers) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= 100);
        loop invariant min_value >= 1 && min_value <= 101;
        loop assigns index, count, min_value;
        loop variant n - index;
    */
    while (index < n) {
        int a = numbers[index];
        
        //@ assert 1 <= a <= 100;
        
        if (a % 2 == 0) {
            if (a < min_value) {
                min_value = a;
            }
        } else {
            count += 1;
        }
        index += 1;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
