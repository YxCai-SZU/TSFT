#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid_read(numbers + (0 .. len-1));
    requires len > 0;
    requires (\forall integer j; 0 <= j < (len) ==> (((numbers)[j]) >= 1 && ((numbers)[j]) <= 1000000000));
    ensures \result >= 0;
    ensures \result <= 1000000000;
    ensures \result == 0 || \result > 0;
*/
int func(int *numbers, size_t len) {
    int a;
    size_t i;
    
    a = numbers[0];
    i = 1;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant a >= 1 && a <= 1000000000;
        loop invariant \forall integer j; 0 <= j < i ==> ((numbers[j]) >= 1 && (numbers[j]) <= 1000000000);
        loop invariant \forall integer k; 0 <= k < len ==> ((numbers[k]) >= 1 && (numbers[k]) <= 1000000000);
        loop invariant len > 0;
        loop assigns a, i;
        loop variant len - i;
    */
    while (i < len) {
        int b;
        
        b = numbers[i];
        //@ assert ((b) >= 1 && (b) <= 1000000000);
        
        if (a < b) {
            a = a;
        } else {
            a = b;
        }
        //@ assert a >= 1 && a <= 1000000000;
        
        i = i + 1;
    }
    
    //@ assert a >= 0 && a <= 1000000000;
    //@ assert a == 0 || a > 0;
    return a;
}
