#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(int *a, integer len) =
        1 <= len <= 100000 &&
        \forall integer i; 0 <= i < len ==> 1 <= a[i] <= 1000000000;
*/

unsigned int count_odd_even(int *a, unsigned int len) {
    unsigned int count = 0;
    unsigned int b = 0;
    unsigned int i = 0;
    unsigned int min_val;

    while (i < len) {
        int value = a[i];
        //@ assert 1 <= value <= 1000000000;
        
        if (value & 1) {
            count = count + 1;
        } else {
            b = b + 1;
        }
        i = i + 1;
    }

    //@ assert count + b == len;
    
    if (count < b) {
        min_val = count;
    } else {
        min_val = b;
    }
    
    return min_val;
}

unsigned int mod3(unsigned int x)
{
    unsigned int quotient = 0;
    unsigned int remainder = x;

    while (remainder >= 3)
    {
        quotient = quotient + 1;
        remainder = remainder - 3;
    }

    return remainder;
}

unsigned int process_array_mod3_min(int *a, unsigned int len) {
    unsigned int min_count = count_odd_even(a, len);
    unsigned int result = mod3(min_count);
    return result;
}
