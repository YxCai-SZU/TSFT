#include <stddef.h>
#include <stdint.h>

/*@
    requires (0 <= (\at(lists_len, Pre)) < 0x80000000);
    ensures \result == \at(lists_len, Pre);
    assigns \nothing;
*/
size_t count_100_lists(size_t lists_len) {
    size_t count = 0;
    size_t i = 0;
    
    //@ ghost size_t original_len = lists_len;
    
    /*@
        loop invariant 0 <= i <= lists_len;
        loop invariant count == i;
        loop invariant (0 <= (lists_len) < 0x80000000);
        loop invariant count <= lists_len;
        loop invariant lists_len == original_len;
        loop assigns i, count;
        loop variant lists_len - i;
    */
    while (i < lists_len) {
        //@ assert count == i;
        count += 1;
        i += 1;
        //@ assert count == i;
    }
    
    //@ assert count == original_len;
    return count;
}

int main() {
    return 0;
}
