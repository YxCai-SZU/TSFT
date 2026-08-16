#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(list + (0..len-1));
    requires len < 100;
    requires \forall integer i; 0 <= i < len ==> list[i] < 10000;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len ==> 
            (list[i] % 2 != 0 ==> \result >= 1);
    assigns \nothing;
*/
unsigned int find_odd_count(unsigned int* list, size_t len) {
    unsigned int count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant count <= len;
        loop invariant \forall integer k; 0 <= k < i ==> list[k] < 10000;
        loop invariant \forall integer k; 0 <= k < len ==> list[k] < 10000;
        loop invariant len < 100;
        loop invariant \forall integer k; 0 <= k < i ==> 
                (list[k] % 2 != 0 ==> count >= 1);
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        unsigned int x = list[i];
        if (x % 2 != 0) {
            count += 1;
        }
        i += 1;
        //@ assert count <= len;
    }
    return count;
}
