#include <stdbool.h>
/*@
    requires 1 <= n <= 100000;
    requires 1 <= k <= 500;
    requires \valid(heights + (0..n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (heights)[i] <= 500);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int find_min_length(int n, int k, int *heights) {
    int answer = 0;
    int index = 0;
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= answer <= index;
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (heights)[i] <= 500);
        loop invariant (\forall integer j; 0 <= j < (index) ==> ((heights)[j] >= (k) ==> (answer) > 0));
        loop assigns answer, index;
        loop variant n - index;
    */
    while (index < n) {
        int height = heights[index];
        if (height >= k) {
            answer += 1;
        }
        index += 1;
        //@ assert (\forall integer j; 0 <= j < (index) ==> ((heights)[j] >= (k) ==> (answer) > 0));
    }
    return answer;
}
