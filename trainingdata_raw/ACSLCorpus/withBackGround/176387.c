#include <stdbool.h>

/*@ predicate is_whitespace(char c) =
    c == ' ' || c == '\t' || c == '\n' || c == '\r';
*/

/*@ predicate is_eol(char c) =
    c == '\r' || c == '\n';
*/

/*@
    requires 1 <= n && n <= 100;
    requires 0 <= m && m <= n;
    ensures \result == (n == m);
*/
bool func(unsigned int n, unsigned int m) {
    //@ assert n == m ==> n == m;
    return n == m;
}

/*@
    logic integer char_at(integer i, char* s) = s[i];
*/

/*@
    requires \valid(s + (0..2));
    requires \valid(t + (0..2));
    requires \forall integer i; 0 <= i < 3 ==> ('A' <= s[i] && s[i] <= 'Z');
    requires \forall integer i; 0 <= i < 3 ==> ('A' <= t[i] && t[i] <= 'Z');
    ensures \result == (s[0] == t[2] && s[1] == t[1] && s[2] == t[0]);
*/
bool func2(char* s, char* t) {
    //@ assert s[0] == t[2] && s[1] == t[1] && s[2] == t[0] ==> (s[0] == t[2] && s[1] == t[1] && s[2] == t[0]);
    return s[0] == t[2] && s[1] == t[1] && s[2] == t[0];
}
