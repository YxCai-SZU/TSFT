#include <stdbool.h>
#include <stdint.h>

/*@ predicate all_in_range(int *s, integer len, integer min, integer max) =
      \forall integer i; 0 <= i < len ==> min <= s[i] && s[i] < max;
*/

/*@ predicate all_even(int *s, integer len) =
      \forall integer i; 0 <= i < len ==> s[i] % 2 == 0;
*/

/*@ lemma square_bound: \forall integer n; 1 <= n <= 9 ==> n * n <= 81; */

int main() {
    int v[3];
    v[0] = 2;
    v[1] = 4;
    v[2] = 6;
    
    //@ assert all_in_range(&v[0], 3, 1, 7);
    //@ assert all_even(&v[0], 3);
    
    return 0;
}

/*@ requires 1 <= n <= 9;
    ensures \result == n * n;
    assigns \nothing;
*/
uint32_t func(uint32_t n) {
    //@ assert 1 <= n && n <= 9;
    //@ assert n * n <= 81;
    return n * n;
}
