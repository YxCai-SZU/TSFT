#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((a_len) >= 1 && (a_len) <= 10 && \valid((a) + (0 .. (a_len)-1)));
  requires ((b_len) >= 1 && (b_len) <= 10 && \valid((b) + (0 .. (b_len)-1)));
  requires ((c_len) >= 1 && (c_len) <= 10 && \valid((c) + (0 .. (c_len)-1)));
  ensures \result == ((((a_len) > 0) ? (integer)(a)[(a_len)-1] : 0) == (((b_len) > 0) ? (integer)(b)[0] : 0) && (((b_len) > 0) ? (integer)(b)[(b_len)-1] : 0) == (((c_len) > 0) ? (integer)(c)[0] : 0));
*/
bool func(char *a, size_t a_len, char *b, size_t b_len, char *c, size_t c_len)
{
    //@ assert a_len >= 1 && a_len <= 10;
    //@ assert b_len >= 1 && b_len <= 10;
    //@ assert c_len >= 1 && c_len <= 10;
    
    return a[a_len - 1] == b[0] && b[b_len - 1] == c[0];
}
