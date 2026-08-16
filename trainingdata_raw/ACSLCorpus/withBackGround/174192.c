#include <stdbool.h>

/*@ predicate is_digit(char c) = '0' <= c && c <= '9'; */

/*@
  requires \valid(n+(0..2));
  requires \forall integer i; 0 <= i < 3 ==> is_digit(n[i]);
  requires n[0] != '0';
  ensures \result == (n[0] == n[2]);
*/
bool is_palindrome(char n[3]) {
    //@ assert n[0] >= '0' && n[0] <= '9';
    //@ assert n[2] >= '0' && n[2] <= '9';
    return n[0] == n[2];
}
