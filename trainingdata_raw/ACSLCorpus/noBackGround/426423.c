#include <stddef.h>

/*@ requires len > 0;
    requires \valid(hs + (0 .. len-1));
    requires (\forall size_t i; 0 <= i < (len) ==> (hs)[i] > 0);
    assigns \nothing;
    ensures \result >= 0 && \result <= len;
*/
size_t func(size_t* hs, size_t len) {
    size_t cur_h = 0;
    size_t cnt = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= len;
        loop invariant cnt <= index;
        loop invariant index == 0 ==> cur_h == 0 && cnt == 0;
        loop invariant index > 0 ==> cnt <= index;
        loop invariant (\forall size_t i; 0 <= i < (len) ==> (hs)[i] > 0);
        loop assigns cur_h, cnt, index;
        loop variant len - index;
    */
    while (index < len) {
        size_t h = hs[index];
        if (h >= cur_h) {
            cnt += 1;
            cur_h = h;
        }
        index += 1;
        
        //@ assert cnt <= index;
    }
    
    //@ assert cnt <= len;
    return cnt;
}
