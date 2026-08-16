#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(lst+(0..len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len ==> (lst[i] ==> \result > 0);
*/
size_t count(bool *lst, size_t len) {
    size_t count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> (lst[j] ==> count > 0);
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        if (lst[i]) {
            count += 1;
        }
        i += 1;
    }

    //@ assert count <= len;
    return count;
}

int main() {
    return 0;
}
