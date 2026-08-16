#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid_read(s + (0 .. len-1));
    requires len >= 0;
    assigns \nothing;
    ensures \result <= len;
    ensures (\forall integer j; 0 <= j < (len) ==> 
            ((s)[j] == (value) ==> (\result) > 0));
*/
size_t count_occurrences(const int *s, size_t len, int value) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> 
            (s[j] == value ==> count > 0);
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (s[i] == value) {
            count++;
        }
        i++;
    }
    //@ assert (0 <= (count) <= (len));
    return count;
}
