#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_even(integer n) = n % 2 == 0; */

unsigned int func(const unsigned int* x, size_t len) {
    unsigned int max = 0;
    unsigned int max_even = 0;
    size_t i = 0;
    size_t j = 0;

    max = x[0];
    i = 1;
    while (i < len) {
        //@ assert 0 <= i < len;
        if (x[i] > max) {
            max = x[i];
        }
        i++;
    }

    j = 0;
    max_even = 0;
    while (j < len) {
        //@ assert 0 <= j < len;
        if (x[j] <= max && (x[j] % 2 == 0)) {
            if (x[j] > max_even) {
                max_even = x[j];
            }
        }
        j++;
    }

    return max_even;
}

/*@
    predicate is_valid_range(integer v) = 3 <= v && v <= 20;

    logic integer max_val(integer x, integer y) = (x > y) ? x : y;

    lemma max_val_property:
        \forall integer a, b;
            is_valid_range(a) && is_valid_range(b) ==>
            max_val(a, b) >= a && max_val(a, b) >= b;

    lemma result_property:
        \forall integer a, b, result;
            is_valid_range(a) && is_valid_range(b) &&
            (result == a + b || result == 2 * a - 1 || result == 2 * b - 1) ==>
            result >= 0;
*/

int func2(int a, int b) {
    int max;
    int result;

    //@ assert is_valid_range(a) && is_valid_range(b);
    
    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    
    //@ assert max == max_val(a, b);
    
    if (max > a + b - max) {
        //@ assert max > a + b - max;
        result = 2 * max - 1;
        //@ assert result == 2 * max - 1;
    } else {
        //@ assert a + b >= 0;
        result = a + b;
        //@ assert result == a + b;
    }
    
    //@ assert result == a + b || result == 2 * a - 1 || result == 2 * b - 1;
    //@ assert result >= 0;
    return result;
}


unsigned int combined_func(const unsigned int* x, size_t len, int a, int b) {
    unsigned int max_even = func(x, len);
    int adjustment = func2(a, b);
    
    //@ assert max_even >= 0 && max_even <= 1000;
    //@ assert adjustment >= 0;
    
    unsigned int result;
    if (max_even > (unsigned int)adjustment) {
        result = max_even;
    } else {
        result = (unsigned int)adjustment;
    }
    
    //@ assert result >= 0 && result <= 1000;
    return result;
}
