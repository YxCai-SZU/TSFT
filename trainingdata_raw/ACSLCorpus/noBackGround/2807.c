#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((a_len) > 0 && (a_len) <= 10 &&
        \valid((a) + (0 .. (a_len)-1)));
    requires ((b_len) > 0 && (b_len) <= 10 &&
        \valid((b) + (0 .. (b_len)-1)));
    requires ((c_len) > 0 && (c_len) <= 10 &&
        \valid((c) + (0 .. (c_len)-1)));
    assigns \nothing;
    ensures \result == (a[a_len-1] == b[0] && b[b_len-1] == c[0]);
*/
bool func(char *a, size_t a_len, char *b, size_t b_len, char *c, size_t c_len) {
    char a_last;
    char b_first;
    char b_last;
    char c_first;
    bool result;

    //@ assert a_len > 0;
    //@ assert b_len > 0;
    //@ assert c_len > 0;

    a_last = a[a_len - 1];
    b_first = b[0];
    b_last = b[b_len - 1];
    c_first = c[0];

    result = (a_last == b_first && b_last == c_first);
    return result;
}
