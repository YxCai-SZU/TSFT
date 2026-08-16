#include <stddef.h>

/*@
    requires \valid(s + (0 .. len-1));
    requires 1 <= len <= 200;
    requires \forall integer i; 0 <= i < len ==> 1 <= s[i] <= 200;
    ensures 1 <= \result <= 200;
    assigns \nothing;
*/
size_t func(size_t *s, size_t len) {
    size_t max_num = 0;
    size_t res = 1;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= len;
        loop invariant 1 <= res <= 200;
        loop invariant max_num == 0 || \exists integer j; 0 <= j < index && s[j] == max_num;
        loop invariant \forall integer k; 0 <= k < index ==> s[k] <= max_num;
        loop assigns index, max_num, res;
        loop variant len - index;
    */
    while (index < len) {
        size_t current = s[index];
        //@ assert 1 <= current <= 200;
        if (max_num <= current) {
            max_num = current;
            res = index + 1;
        }
        //@ assert res >= 1 && res <= 200;
        index++;
    }
    return res;
}
