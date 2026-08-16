#include <stddef.h>
#include <stdint.h>

/*@
    requires (1 <= (a) <= 1000000000 &&
        1 <= (b) <= 1000000000 &&
        1 <= (k) <= 1000000000);
    requires \valid_read(arr + (0 .. k-1));
    requires (\forall integer i; 0 <= i < (k) ==> 1 <= (arr)[i] <= 1000000000);
    assigns \nothing;
    ensures 0 <= \result <= k;
*/
size_t func(size_t a, size_t b, size_t k, const size_t arr[]) {
    size_t ret = 0;
    size_t index = 0;
    
    /*@
        loop invariant (0 <= (index) <= (k) &&
        (ret) >= 0 &&
        (ret) <= (index) &&
        (\forall integer i; 0 <= i < ((k)) ==> 1 <= ((arr))[i] <= 1000000000));
        loop assigns index, ret;
        loop variant k - index;
    */
    while (index < k) {
        size_t a_mod = arr[index] % a;
        size_t b_mod = arr[index] % b;
        
        //@ assert a_mod == arr[index] % a;
        
        if ((a_mod == 0 && b_mod == 0) || (a_mod == 0 && b_mod != 0)) {
            ret += 1;
        }
        
        index += 1;
    }
    
    //@ assert 0 <= ret <= k;
    return ret;
}
