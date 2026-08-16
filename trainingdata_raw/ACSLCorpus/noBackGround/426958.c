#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(A + (0 .. a_len-1));
  requires \valid_read(B + (0 .. b_len-1));
  requires ((a_len) > 0);
  requires ((b_len) > 0);
  assigns \nothing;
  ensures \result == (a_len < b_len);
*/
bool check_subarray(int *A, size_t a_len, int *B, size_t b_len) {
    //@ assert ((a_len) > 0);
    //@ assert ((b_len) > 0);
    return a_len < b_len;
}
