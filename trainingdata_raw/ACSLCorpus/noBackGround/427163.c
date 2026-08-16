#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (n) <= 200000);
    requires n == len;
    requires \valid_read(arr + (0 .. n-1));
    requires (\forall size_t i; 0 <= i < (n) ==> (1 <= ((arr)[i]) <= 1000000000));
    ensures \result >= -1;
    ensures \result <= (int)n;
*/
int func(size_t n, const unsigned long long* arr, size_t len) {
    int count = 0;
    size_t index = 0;
    bool is_even_index = true;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant count >= 0;
        loop invariant count <= (int)index;
        loop invariant index > 0 ==> \forall size_t i; 0 <= i < index ==> (1 <= (arr[i]) <= 1000000000);
        loop assigns index, is_even_index, count;
        loop variant n - index;
    */
    while (index < n) {
        unsigned long long value = arr[index];
        
        //@ assert (1 <= (value) <= 1000000000);
        
        if ((is_even_index && value % 2 == 0) || (!is_even_index && value % 2 != 0)) {
            return -1;
        }
        
        is_even_index = !is_even_index;
        index += 1;
    }
    
    int result;
    if (count > 0) {
        result = count;
        //@ assert result >= 0;
    } else {
        result = -1;
        //@ assert result == -1;
    }
    
    //@ assert result >= -1;
    //@ assert result <= (int)n;
    return result;
}
