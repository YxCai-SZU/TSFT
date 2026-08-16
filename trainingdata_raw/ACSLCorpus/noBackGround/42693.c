#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 1 && n <= 100000;
    requires k >= 1 && k <= 500;
    requires \valid(h + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 500;
    assigns \nothing;
    ensures \result >= 0 && \result <= n;
*/
unsigned long func(unsigned long n, unsigned long k, unsigned long *h) {
    unsigned long num = 0;
    unsigned long index = 0;
    
    //@ assert ((index) >= 0 && (index) <= (n) &&     (num) >= 0 && (num) <= (index) &&     (((n)) >= 1 && ((n)) <= 100000 &&     ((k)) >= 1 && ((k)) <= 500 &&     \valid(((h)) + (0 .. ((n))-1)) &&     \forall integer i; 0 <= i < ((n)) ==> ((h))[i] >= 1 && ((h))[i] <= 500));
    
    /*@ loop invariant ((index) >= 0 && (index) <= (n) &&
    (num) >= 0 && (num) <= (index) &&
    (((n)) >= 1 && ((n)) <= 100000 &&
    ((k)) >= 1 && ((k)) <= 500 &&
    \valid(((h)) + (0 .. ((n))-1)) &&
    \forall integer i; 0 <= i < ((n)) ==> ((h))[i] >= 1 && ((h))[i] <= 500));
        loop assigns index, num;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert h[index] >= 1 && h[index] <= 500;
        
        if (h[index] >= k) {
            num = num + 1;
        }
        
        index = index + 1;
        //@ assert num <= index;
    }
    
    //@ assert num >= 0 && num <= n;
    return num;
}
