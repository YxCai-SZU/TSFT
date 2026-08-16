#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(a + (0 .. len-1));
  requires len > 0;
  assigns \nothing;
  ensures \result <= a[0];
  ensures \forall integer i; 0 <= i < len ==> \result <= a[i];
*/
int find_min(int *a, size_t len) {
    int min_val = a[0];
    size_t i = 1;
    /*@
      loop invariant 1 <= i <= len;
      loop invariant min_val <= a[0];
      loop invariant \forall integer k; 0 <= k < i ==> min_val <= a[k];
      loop assigns i, min_val;
      loop variant len - i;
    */
    while (i < len) {
        if (a[i] < min_val) {
            min_val = a[i];
        }
        i++;
    }
    return min_val;
}

/*@
  requires \valid_read(a + (0 .. a_len-1));
  requires \valid_read(b + (0 .. b_len-1));
  requires \valid_read(c + (0 .. c_len-1));
  requires a_len > 0 && b_len > 0 && c_len > 0;
  assigns \nothing;
  ensures \result == -1 ||
          (\result <= a[0] && \result <= b[0] && \result <= c[0]);
*/
int min_tuple(int *a, size_t a_len, int *b, size_t b_len, int *c, size_t c_len) {
    int min_a;
    int min_b;
    int min_c;
    int result;
    
    min_a = find_min(a, a_len);
    //@ assert min_a <= a[0];
    
    min_b = find_min(b, b_len);
    //@ assert min_b <= b[0];
    
    min_c = find_min(c, c_len);
    //@ assert min_c <= c[0];
    
    if (min_a < min_b) {
        if (min_a < min_c) {
            result = min_a;
        } else {
            result = min_c;
        }
    } else {
        if (min_b < min_c) {
            result = min_b;
        } else {
            result = min_c;
        }
    }
    
    //@ assert result <= a[0];
    //@ assert result <= b[0];
    //@ assert result <= c[0];
    return result;
}
