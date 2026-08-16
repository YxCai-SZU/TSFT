#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid_read(A+(0..len-1));
    requires len <= 0x80000000;
    assigns \nothing;
    ensures \result == true ==> (\forall integer i; 0 <= i < (len)/2 ==> (A)[i] == (A)[(len) - i - 1]);
    ensures \result == false ==> (\exists integer i; 0 <= i < (len)/2 && (A)[i] != (A)[(len) - i - 1]);
*/
bool is_palindrome_c(int *A, size_t len) {
    size_t i = 0;
    size_t half_len = len / 2;
    
    /*@ loop invariant 0 <= i <= half_len;
        loop invariant half_len == len / 2;
        loop invariant \forall integer j; 0 <= j < i ==> A[j] == A[len - j - 1];
        loop assigns i;
        loop variant half_len - i;
    */
    while (i < half_len) {
        //@ assert 0 <= i < half_len;
        if (A[i] != A[len - i - 1]) {
            //@ assert (\exists integer i; 0 <= i < (len)/2 && (A)[i] != (A)[(len) - i - 1]);
            return false;
        }
        i++;
    }
    
    //@ assert (\forall integer i; 0 <= i < (len)/2 ==> (A)[i] == (A)[(len) - i - 1]);
    return true;
}
