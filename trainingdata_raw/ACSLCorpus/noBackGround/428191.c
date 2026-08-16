#include <stddef.h>
#include <stdint.h>

/*@
    requires ((len) < 0x80000000 &&
        \valid((tuplex) + (0 .. (len)-1)));
    ensures \result == (int32_t)len;
    assigns \nothing;
*/
int32_t count_tuple3(int32_t *tuplex, size_t len) {
    // Variable declarations at top of scope
    int32_t count;
    size_t i;
    
    count = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant count == (int32_t)i;
        loop invariant ((len) < 0x80000000 &&
        \valid((tuplex) + (0 .. (len)-1)));
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert i < len;
        count += 1;
        i += 1;
    }
    
    //@ assert count == (int32_t)len;
    
    return count;
}
