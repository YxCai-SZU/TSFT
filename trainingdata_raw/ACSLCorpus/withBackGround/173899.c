#include <stdbool.h>
/*@
    predicate is_valid_range(integer N) = 1 <= N <= 100;
    predicate is_valid_array(int *a, integer N) = 
        \forall integer i; 0 <= i < N ==> 1 <= a[i] <= 100;
    logic integer loop_count(integer idx, integer cnt) = cnt;
    lemma count_bounds: 
        \forall integer N, integer idx, integer cnt; 
        is_valid_range(N) && 0 <= idx <= N && 0 <= cnt <= idx ==> 0 <= cnt <= N;
*/

/*@
    requires is_valid_range(N);
    requires \valid(a + (0..N-1));
    requires is_valid_array(a, N);
    assigns \nothing;
    ensures 0 <= \result <= N;
*/
int func(int N, int *a) {
    int count = 0;
    int num = 1;
    int index = 0;
    
    /*@
        loop invariant 0 <= index <= N;
        loop invariant 1 <= num <= N + 1;
        loop invariant 0 <= count <= index;
        loop invariant is_valid_range(N);
        loop invariant is_valid_array(a, N);
        loop assigns count, num, index;
        loop variant N - index;
    */
    while (index < N && num <= N) {
        int a_val = a[index];
        //@ assert 1 <= a_val <= 100;
        if ((a_val & 1) == 1 && (num & 1) == 1) {
            count += 1;
        }
        num += 1;
        index += 1;
    }
    //@ assert 0 <= count <= N;
    return count;
}
