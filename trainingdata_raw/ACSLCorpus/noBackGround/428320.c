#include <stddef.h>
#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (x) <= 10000 &&
        \valid((l) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (l)[i] <= 100);
    ensures 1 <= \result <= n + 1;
    assigns \nothing;
*/
int func(int64_t n, int64_t x, int64_t *l) {
    int64_t d = 0;
    int64_t count = 1;
    size_t index = 0;

    /*@
        loop invariant (0 <= (index) <= (n) &&
        1 <= (count) <= (index) + 1 &&
        (d) <= (x) &&
        ((index) > 0 ==> (d) <= (x) + 100));
        loop assigns d, count, index;
        loop variant n - index;
    */
    while (index < (size_t)n && d + l[index] <= x) {
        //@ assert 0 <= index < n;
        d += l[index];
        count += 1;
        index += 1;
    }

    //@ assert 1 <= count <= n + 1;
    return (int)count;
}
