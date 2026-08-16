#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_even(integer n) = n % 2 == 0; */
/*@ predicate is_odd(integer n) = n % 2 != 0; */

/*@ lemma even_odd_contradiction: 
      \forall integer n; is_even(n) && is_odd(n) ==> \false; */

/*@ requires 2 <= n && n <= 100000;
    requires \valid_read(a + (0..n-1));
    requires \forall integer i; 0 <= i < n ==> a[i] > 1 && a[i] <= 1000000000;
    assigns \nothing;
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result <= n;
*/
int func(size_t n, const unsigned long* a) {
    int count = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= (int)index;
        loop invariant \forall integer i; 0 <= i < n ==> a[i] > 1 && a[i] <= 1000000000;
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n) {
        unsigned long value = a[index];
        
        //@ assert value > 1 && value <= 1000000000;
        
        if (value % 2 == 0) {
            //@ assert is_even(value);
            
            if (value % 2 != 0) {
                //@ assert is_odd(value);
                return -1;
            }
            count += 1;
        }
        index += 1;
    }
    return count;
}
