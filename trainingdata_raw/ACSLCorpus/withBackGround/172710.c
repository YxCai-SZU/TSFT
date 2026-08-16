#include <stdbool.h>
#include <stddef.h>

/*@
    predicate is_even_spec(integer n, bool ret) =
        ret == (n % 2 == 0);
*/

/*@
    requires \valid_read(numbers + (0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \exists integer i; 0 <= i < len && \result == numbers[i];
    ensures \forall integer j; 0 <= j < len ==> \result >= numbers[j];
*/
unsigned int find_max(const unsigned int* numbers, size_t len) {
    unsigned int max_value;
    size_t i;
    
    max_value = numbers[0];
    i = 1;
    
    /*@
        loop invariant i <= len;
        loop invariant \exists integer j; 0 <= j < i && max_value == numbers[j];
        loop invariant \forall integer j; 0 <= j < i ==> max_value >= numbers[j];
        loop assigns max_value, i;
        loop variant len - i;
    */
    while (i < len) {
        if (numbers[i] > max_value) {
            max_value = numbers[i];
        }
        i++;
    }
    
    return max_value;
}

/*@
    requires n >= 0;
    assigns \nothing;
    ensures is_even_spec(n, \result);
*/
bool is_even(unsigned int n) {
    bool ret;
    
    ret = (n % 2 == 0);
    
    //@ assert ret == (n % 2 == 0);
    
    return ret;
}
