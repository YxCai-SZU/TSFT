#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_range(int *v, size_t n) =
      n >= 3 && n <= 200000 &&
      \forall size_t i; 0 <= i < n ==> v[i] >= 1 && v[i] <= 1000000000;
*/

/*@ predicate is_monotonic_triplet(int a, int b, int c) =
      (a < b && b < c) || (a > b && b > c);
*/

/*@ lemma count_bound:
      \forall size_t n, count; n >= 3 && count <= n - 2 ==> count <= n - 2;
*/

/*@ requires n >= 3 && n <= 200000;
    requires \valid(v + (0 .. n-1));
    requires \forall size_t i; 0 <= i < n ==> v[i] >= 1 && v[i] <= 1000000000;
    assigns \nothing;
    ensures \result <= n - 2;
*/
size_t func(size_t n, int *v) {
    size_t count = 0;
    size_t i = 0;
    int a = 0;
    int b = 0;
    int c = 0;

    /*@ loop invariant 0 <= i <= n - 2;
        loop invariant count <= i;
        loop invariant count <= n - 2;
        loop invariant is_valid_range(v, n);
        loop assigns i, count, a, b, c;
        loop variant n - 2 - i;
    */
    while (i < n - 2) {
        a = v[i];
        b = v[i + 1];
        c = v[i + 2];

        //@ assert \valid(v + (i .. i+2));
        //@ assert a == v[i] && b == v[i+1] && c == v[i+2];
        
        if ((a < b && b < c) || (a > b && b > c)) {
            //@ assert is_monotonic_triplet(a, b, c);
            count++;
        }
        i++;
    }
    
    //@ assert count <= n - 2;
    return count;
}
