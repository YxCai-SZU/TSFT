#include <stdbool.h>

/*@ predicate is_whitespace(char c) =
      c == ' ' || c == '\t' || c == '\n' || c == '\r';
*/

/*@ predicate is_eol(char c) =
      c == '\r' || c == '\n';
*/

/*@
  requires 1 <= n && n <= 100;
  requires 1 <= m && m <= 100;
  ensures \result == ((n - 1) / 2 >= m - 1);
*/
bool func(unsigned int n, unsigned int m)
{
    //@ assert n > 0 && n <= 100;
    //@ assert m > 0 && m <= 100;
    //@ assert (n - 1) / 2 <= 49;
    return (n - 1) / 2 >= m - 1;
}
