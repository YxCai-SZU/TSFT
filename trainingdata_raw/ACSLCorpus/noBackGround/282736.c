#include <stddef.h>
#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (x) && (x) <= 10000 &&
        \valid((l) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (l)[i] && (l)[i] <= 100);
    ensures \result <= n + 1;
    ensures \result >= 0;
    assigns \nothing;
*/
size_t func(size_t n, int x, int *l) {
    int d = 0;
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant (0 <= (i) <= (n) &&
        0 <= (count) <= (i) &&
        (d) >= 0 &&
        (d) <= (i) * 100 &&
        (count) <= (n) + 1 &&
        (1 <= ((n)) && ((n)) <= 100 &&
        1 <= ((x)) && ((x)) <= 10000 &&
        \valid(((l)) + (0 .. ((n))-1)) &&
        \forall integer i; 0 <= i < ((n)) ==> 1 <= ((l))[i] && ((l))[i] <= 100));
        loop assigns d, count, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        d += l[i];
        count += 1;
        if (d > x) {
            //@ assert count <= n + 1;
            return count;
        }
        i += 1;
    }
    //@ assert count <= n + 1;
    return count;
}
