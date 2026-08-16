#include <stdbool.h>

/*@ predicate all_equal(char *n, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> n[i] == n[j];
*/

/*@
  requires \valid_read(n+(0..2));
  requires \forall integer i; 0 <= i < 3 ==> ('0' <= n[i] && n[i] <= '9');
  requires n[0] != '0';
  ensures \result == (n[0] == n[2]);
*/
bool is_palindrome(char *n) {
    //@ assert n[0] != '0';
    return n[0] == n[2];
}

/*@
  requires \valid_read(n+(0..2));
  requires \forall integer i; 0 <= i < 3 ==> ('0' <= n[i] && n[i] <= '9');
  requires n[0] != '0';
  ensures \result <==> all_equal(n, 3);
*/
bool all_identical(char *n) {
    //@ assert \forall integer i; 0 <= i < 3 ==> ('0' <= n[i] && n[i] <= '9');
    return n[0] == n[1] && n[1] == n[2];
}
