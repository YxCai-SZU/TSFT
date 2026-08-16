#include <stdbool.h>
#include <stdint.h>

/*@ requires \valid(list+(0..len-1));
    requires len <= 0xffffffff;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len ==> 
            (list[i] % 2 != 0) ==> \result >= 1;
    assigns \nothing;
 */
uint32_t count_odd(const uint32_t* list, uint32_t len) {
    uint32_t count = 0;
    uint32_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> 
                   (list[j] % 2 != 0) ==> count >= 1;
        loop assigns i, count;
        loop variant len - i;
     */
    while (i < len) {
        //@ assert i < len;
        if (list[i] % 2 != 0) {
            count = count + 1;
        }
        i = i + 1;
    }
    return count;
}

int main() {
    return 0;
}
