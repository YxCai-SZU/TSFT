#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_whitespace(char c) =
      c == ' ' || c == '\t' || c == '\n' || c == '\r';
*/

/*@ predicate is_eol(char c) =
      c == '\r' || c == '\n';
*/

/*@ logic integer vec_at{L}(int *arr, integer i) =
      arr[i];
*/

/*@ predicate valid_array(int *arr, integer n) =
      n > 0 && n <= 100 &&
      \forall integer i; 0 <= i < n ==> 1 <= arr[i] <= 100;
*/

/*@ lemma index_bound:
      \forall integer n; n > 0 ==> 0 <= n - 1 < n;
*/

/*@ requires n > 0 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 100;
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(size_t n, int *a) {
    int count = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant valid_array(a, n);
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n) {
        int value = a[index];
        
        //@ assert ((index + 1) & 1) != 0 ==> ((index + 1) % 2 == 1);
        //@ assert (value & 1) != 0 ==> (value % 2 == 1);
        
        if (((index + 1) & 1) != 0 && (value & 1) != 0) {
            count += 1;
        }
        index += 1;
    }
    return count;
}

int main() {
    return 0;
}
