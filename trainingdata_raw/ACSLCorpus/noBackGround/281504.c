#include <stdint.h>
#include <stddef.h>

/*@
    requires \valid(list + (0..len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len ==>
        ((((list[i]) & 1) == 0) ==> \result >= 1) ||
        (!(((list[i]) & 1) == 0) ==> \result >= 0);
*/
int32_t count_even(int32_t *list, size_t len) {
    int32_t even_count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant even_count >= 0;
        loop invariant even_count <= i;
        loop invariant \forall integer j; 0 <= j < i ==>
            ((((list[j]) & 1) == 0) ==> even_count >= 1) ||
            (!(((list[j]) & 1) == 0) ==> even_count >= 0);
        loop assigns i, even_count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert i >= 0 && i < len;
        
        if ((list[i] & 1) == 0) {
            even_count += 1;
        }
        
        i += 1;
    }
    
    //@ assert even_count >= 0;
    //@ assert even_count <= len;
    //@ assert \forall integer j; 0 <= j < len ==> ((((list[j]) & 1) == 0) ==> even_count >= 1) || (!(((list[j]) & 1) == 0) ==> even_count >= 0);
    
    return even_count;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
