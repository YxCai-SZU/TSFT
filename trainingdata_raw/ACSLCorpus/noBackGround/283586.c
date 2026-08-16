#include <stddef.h>
#include <stdbool.h>

/*@
    requires (0 <= (len) <= 0x80000000 &&
        \valid((list) + (0 .. (len)-1)));
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len ==> (\result == 0 || (list[i] == element ==> \result > 0));
    assigns \nothing;
*/
size_t count_occurrences(int *list, size_t len, int element) {
    size_t count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> (list[j] == element ==> count > 0);
        loop invariant (0 <= (len) <= 0x80000000 &&
        \valid((list) + (0 .. (len)-1)));
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (list[i] == element) {
            //@ assert list[i] == element;
            count++;
            //@ assert count > 0;
        }
        i++;
    }
    //@ assert i == len;
    //@ assert count <= len;
    return count;
}
