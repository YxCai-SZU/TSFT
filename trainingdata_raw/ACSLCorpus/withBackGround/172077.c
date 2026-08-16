#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_range(int n) = 2 <= n <= 200000; */
/*@ predicate valid_length(int n, size_t len) = len == (size_t)n; */
/*@ predicate valid_element(unsigned int* p, integer i, int n) = p[i] >= 1 && p[i] <= n; */
/*@ predicate distinct_elements(unsigned int* p, integer i, integer j) = p[i] != p[j]; */

/*@
  requires valid_range(n);
  requires valid_length(n, len);
  requires \forall integer i; 0 <= i < len ==> valid_element(p, i, n);
  requires \forall integer i, j; 0 <= i < j < len ==> distinct_elements(p, i, j);
  ensures \result <= n;
*/
unsigned int func(int n, unsigned int* p, size_t len) {
    unsigned int cnt = 0;
    size_t idx = 1;

    /*@
      loop invariant 1 <= idx <= (size_t)n - 1;
      loop invariant cnt <= idx;
      loop invariant valid_length(n, len);
      loop invariant \forall integer i; 0 <= i < len ==> valid_element(p, i, n);
      loop invariant \forall integer i, j; 0 <= i < j < len ==> distinct_elements(p, i, j);
      loop assigns cnt, idx;
    */
    while (idx < (size_t)n - 1) {
        //@ assert p[idx - 1] < p[idx] && p[idx] < p[idx + 1] ==> cnt + 1 <= idx + 1;
        if (p[idx - 1] < p[idx] && p[idx] < p[idx + 1]) {
            cnt = cnt + 1;
        }
        //@ assert p[idx - 1] > p[idx] && p[idx] > p[idx + 1] ==> cnt + 1 <= idx + 1;
        if (p[idx - 1] > p[idx] && p[idx] > p[idx + 1]) {
            cnt = cnt + 1;
        }
        idx += 1;
    }

    return cnt;
}
