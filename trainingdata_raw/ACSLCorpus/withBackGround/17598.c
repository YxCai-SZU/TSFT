#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_range(integer a) = 1 <= a && a <= 13; */

/*@ predicate all_even_range(unsigned int *arr, integer len) =
      \forall integer i; 0 <= i < len ==> arr[i] % 2 == 0; */

/*@ predicate positive_bounded(unsigned int *arr, integer len) =
      \forall integer i; 0 <= i < len ==> 1 <= arr[i] && arr[i] <= 1000; */

/*@ lemma sum_lt_22_property:
      \forall integer a, b, c;
        is_valid_range(a) && is_valid_range(b) && is_valid_range(c) ==>
        (a + b + c < 22) == ((a + b + c) < 22); */

/*@ requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    ensures \result == ((a + b + c) < 22); */
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert a + b + c >= 3;
    
    if ((a + b + c) >= 22) {
        //@ assert !((a + b + c) < 22);
        return false;
    } else {
        //@ assert (a + b + c) < 22;
        return true;
    }
}

/*@ requires positive_bounded(A, len);
    ensures \result ==> all_even_range(A, len); */
bool all_even(unsigned int *A, size_t len)
{
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> A[j] % 2 == 0;
        loop assigns i;
        loop variant len - i; */
    while (i < len) {
        //@ assert 0 <= i < len;
        
        if (A[i] % 2 != 0) {
            //@ assert !all_even_range(A, len);
            return false;
        }
        
        i++;
    }
    
    //@ assert all_even_range(A, len);
    return true;
}
