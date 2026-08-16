#include <stdint.h>
#include <stddef.h>

/*@
    requires len < 0x80000000;
    requires \valid(numbers + (0..len-1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= len;
*/
int32_t count_occurrences(const int64_t* numbers, size_t len, int64_t target) {
    int32_t count = 0;
    size_t index = 0;
    
    /*@
        loop invariant index <= len;
        loop invariant ((count) >= 0 && (count) <= (index) && (index) <= (len));
        loop invariant len < 0x80000000;
        loop assigns count, index;
        loop variant len - index;
    */
    while (index < len) {
        //@ assert ((count) >= 0 && (count) <= (index) && (index) <= (len));
        if (numbers[index] == target) {
            count = count + 1;
        }
        index = index + 1;
    }
    //@ assert ((count) >= 0 && (count) <= (index) && (index) <= (len));
    return count;
}
