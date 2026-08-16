#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid(list+(0..len-1));
    requires len >= 0;
    ensures \result <= len;
    ensures (\forall size_t i; i < len && list[i] == val ==> \result > 0);
    ensures \result == len ==> (\forall size_t i; i < len ==> list[i] == val);
*/
size_t count_val(int *list, size_t len, int val) {
    size_t count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant count <= i;
        loop invariant \forall size_t j; j < i ==> (list[j] == val ==> count > 0);
        loop invariant count == i ==> (\forall size_t j; j < i ==> list[j] == val);
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert ((i) <= (len) &&         (count) <= (i) &&         (\forall size_t j; j < (i) ==> ((list)[j] == (val) ==> (count) > 0)) &&         ((count) == (i) ==> (\forall size_t j; j < (i) ==> (list)[j] == (val))));
        
        if (list[i] == val) {
            count++;
        }
        i++;
        
        //@ assert ((i) <= (len) &&         (count) <= (i) &&         (\forall size_t j; j < (i) ==> ((list)[j] == (val) ==> (count) > 0)) &&         ((count) == (i) ==> (\forall size_t j; j < (i) ==> (list)[j] == (val))));
    }
    
    //@ assert count <= len;
    //@ assert \forall size_t j; j < len && list[j] == val ==> count > 0;
    //@ assert count == len ==> (\forall size_t j; j < len ==> list[j] == val);
    
    return count;
}

int main() {
    return 0;
}
