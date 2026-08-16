#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_range(integer N) = 3 <= N <= 20; */

/*@ predicate is_valid_array(int *p, integer N) =
      \forall integer i; 0 <= i < N ==> 1 <= p[i] <= N; */

/*@ predicate all_distinct(int *p, integer N) =
      \forall integer i, j; 0 <= i < j < N ==> p[i] != p[j]; */

/*@ lemma count_bounds:
      \forall integer N, integer index, integer count;
      is_valid_range(N) && 1 <= index <= N-1 && 0 <= count <= index-1 ==> 0 <= count <= N-2; */

/*@ requires is_valid_range(N);
    requires \valid(p + (0 .. N-1));
    requires is_valid_array(p, N);
    requires all_distinct(p, N);
    assigns \nothing;
    ensures 0 <= \result <= N-2;
*/
int func(int N, int *p) {
    int count = 0;
    size_t index = 1;

    /*@ loop invariant 1 <= index <= N-1;
        loop invariant 0 <= count <= (int)index - 1;
        loop invariant is_valid_array(p, N);
        loop invariant all_distinct(p, N);
        loop invariant is_valid_range(N);
        loop assigns count, index;
        loop variant N - index;
    */
    while (index < (size_t)(N - 1)) {
        int p1 = p[index - 1];
        int p2 = p[index];
        int p3 = p[index + 1];

        //@ assert p1 != p2 && p2 != p3 && p1 != p3;
        if ((p1 < p2 && p2 < p3) || (p1 > p2 && p2 > p3)) {
            count += 1;
        }

        index += 1;
    }

    //@ assert 0 <= count <= N-2;
    return count;
}
