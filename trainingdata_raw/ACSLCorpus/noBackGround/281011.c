#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((len) >= 0 && \valid((list) + (0 .. (len)-1)));
    assigns \nothing;
    ensures 0 <= \result <= len;
*/
size_t count_elements(int *list, size_t len) {
    size_t i = 0;
    size_t counter = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant 0 <= counter <= i;
        loop invariant counter <= len;
        loop assigns i, counter;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert counter < len;
        counter += 1;
        i += 1;
    }
    
    //@ assert 0 <= counter <= len;
    return counter;
}

int main() {
    return 0;
}
