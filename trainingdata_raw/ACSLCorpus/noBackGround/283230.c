#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid(list + (0..len-1));
    assigns \nothing;
    ensures \result <= len;
    ensures len == 0 ==> \result == 0;
*/
size_t count_elements(const int* list, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant i <= len;
        loop invariant count == i;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert count == i;
        count += 1;
        i += 1;
    }
    return count;
}

int main() {
    return 0;
}
