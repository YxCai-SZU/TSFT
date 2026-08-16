#include <stdbool.h>
#include <stddef.h>

/*@ requires ((length) >= 1 && (length) <= 200000 &&
    \forall integer i; 0 <= i < (length) ==> (numbers)[i] > 0 && (numbers)[i] <= 1000000);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= 200000;
*/
unsigned int func(const unsigned int* numbers, size_t length) {
    unsigned int count = 0;
    size_t i = 0;
    
    //@ assert ((length) >= 1 && (length) <= 200000 &&     \forall integer i; 0 <= i < (length) ==> (numbers)[i] > 0 && (numbers)[i] <= 1000000);
    
    /*@ loop invariant (0 <= (i) <= (length) &&
    (count) >= 0 &&
    (count) <= (i) &&
    (((length)) >= 1 && ((length)) <= 200000 &&
    \forall integer i; 0 <= i < ((length)) ==> ((numbers))[i] > 0 && ((numbers))[i] <= 1000000) &&
    \forall integer k; 0 <= k < (i) ==> ((numbers)[k] % 2 == 0) ==> (count) > 0);
        loop assigns i, count;
        loop variant length - i;
    */
    while (i < length) {
        unsigned int a = numbers[i];
        
        //@ assert a > 0 && a <= 1000000;
        
        if (a % 2 == 0) {
            //@ assert count >= 0;
            count += 1;
            //@ assert count > 0;
        }
        
        i += 1;
        //@ assert count <= i;
    }
    
    //@ assert count >= 0;
    //@ assert count <= 200000;
    return count;
}
