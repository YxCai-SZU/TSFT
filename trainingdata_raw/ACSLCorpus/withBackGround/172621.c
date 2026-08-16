#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/*@
    predicate valid_array(integer N, int64_t *p) =
        N >= 1 && N <= 200000 &&
        \valid(p + (0 .. N-1)) &&
        \forall integer i; 0 <= i < N ==> p[i] >= 1 && p[i] <= N &&
        \forall integer i, j; 0 <= i < j < N ==> p[i] != p[j];

    predicate count_invariant(integer index, integer count) =
        count >= 0 && count <= index - 1;
*/

/*@
    requires valid_array(N, p);
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(size_t N, const int64_t *p) {
    int64_t count = 0;
    size_t index = 1;

    /*@
        loop invariant 1 <= index <= N;
        loop invariant count_invariant((integer)index, (integer)count);
        loop assigns count, index;
        loop variant N - index;
    */
    while (index < N - 1) {
        int64_t p1 = p[index - 1];
        int64_t p2 = p[index];
        int64_t p3 = p[index + 1];

        //@ assert p1 != p2 && p2 != p3 && p1 != p3;
        
        if ((p1 < p2 && p2 < p3) || (p1 > p2 && p2 > p3)) {
            count += 1;
        }
        index += 1;
    }
    
    return count;
}
