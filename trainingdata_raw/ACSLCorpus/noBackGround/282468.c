#include <stddef.h>
#include <stdbool.h>

/*@
    requires n >= 3 && n <= 200000;
    requires \valid(numbers + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (0 <= (i) < ((n))) && (1 <= ((numbers)[i]) <= 1000000000));
    assigns \nothing;
    ensures (0 <= (\result) <= (n)-2);
*/
size_t func(size_t n, const int* numbers) {
    size_t count = 0;
    size_t index = 1;
    
    /*@
        loop invariant 1 <= index <= n-1;
        loop invariant count <= index-1;
        loop invariant (\forall integer i; 0 <= i < (n) ==> (0 <= (i) < ((n))) && (1 <= ((numbers)[i]) <= 1000000000));
        loop invariant n >= 3 && n <= 200000;
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n - 1) {
        int a = numbers[index - 1];
        int b = numbers[index];
        int c = numbers[index + 1];
        
        //@ assert (1 <= (a) <= 1000000000) && (1 <= (b) <= 1000000000) && (1 <= (c) <= 1000000000);
        
        if ((a < b && b < c) || (a > b && b > c)) {
            //@ assert count + 1 <= index;
            count += 1;
        }
        
        //@ assert index + 1 <= n-1;
        index += 1;
    }
    
    //@ assert (0 <= (count) <= (n)-2);
    return count;
}
