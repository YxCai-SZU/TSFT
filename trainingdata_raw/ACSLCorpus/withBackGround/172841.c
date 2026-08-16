#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_char_valid(char c) = c == '2' || c != '2';
    predicate vector_valid(char *s, integer len) = 
        \forall integer i; 0 <= i < len ==> is_char_valid(s[i]);
    logic integer count_2s(char *s, integer len, integer idx) =
        idx <= 0 ? 0 : (s[idx-1] == '2' ? 1 : 0) + count_2s(s, len, idx-1);
*/

/*@ requires \valid(s+(0..len-1));
    requires vector_valid(s, len);
    assigns \nothing;
    ensures \result <= len;
    ensures \result == count_2s(s, len, len);
*/
size_t count_2s_in_vec(char *s, size_t len) {
    size_t count = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= len;
        loop invariant 0 <= count <= index;
        loop invariant index <= len ==> vector_valid(s, len);
        loop invariant count == count_2s(s, len, index);
        loop assigns count, index;
        loop variant len - index;
    */
    while (index < len) {
        char c = s[index];
        if (c == '2') {
            //@ assert is_char_valid(c);
            count++;
        }
        index++;
    }
    return count;
}
