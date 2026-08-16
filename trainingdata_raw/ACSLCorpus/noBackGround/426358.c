#include <stdbool.h>
#include <stddef.h>

/*@
    requires len < 0x80000000;
    requires \valid(list + (0 .. len-1));
    ensures \result >= 0;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len ==> 
        ((((list[i]) & 1) == 1) ==> \result > 0);
    ensures \forall integer i; 0 <= i < len ==> 
        ((((list[i]) & 1) == 0) ==> \result >= 0);
*/
int count_odd(const int *list, size_t len) {
    int count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant count >= 0;
        loop invariant count <= (int)i;
        loop invariant \forall integer k; 0 <= k < i ==> 
            ((((list[k]) & 1) == 1) ==> count > 0);
        loop invariant \forall integer k; 0 <= k < i ==> 
            ((((list[k]) & 1) == 0) ==> count >= 0);
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        
        if ((list[i] & 1) == 1) {
            count += 1;
        }
        i += 1;
        
        //@ assert \forall integer k; 0 <= k < i ==> ((((list[k]) & 1) == 1) ==> count > 0);
        //@ assert \forall integer k; 0 <= k < i ==> ((((list[k]) & 1) == 0) ==> count >= 0);
    }
    
    return count;
}

int main() {
    return 0;
}
