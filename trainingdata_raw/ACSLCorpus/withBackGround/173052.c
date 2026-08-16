#include <stdbool.h>
#include <stddef.h>

/*@ predicate palindrome_seq{L}(char *s, integer len) =
      \forall integer i; 0 <= i < len/2 ==> s[i] == s[len - 1 - i];
*/

/*@ lemma palindrome_preserved:
      \forall char *s, integer len, integer i;
        0 <= i <= len/2 &&
        (\forall integer j; 0 <= j < i ==> s[j] == s[len - 1 - j]) &&
        i < len/2 && s[i] == s[len - 1 - i] ==>
        (\forall integer j; 0 <= j < i+1 ==> s[j] == s[len - 1 - j]);
*/

/*@ requires 0 <= len < 0x80000000;
    ensures \result == 1 <==> palindrome_seq(s, len);
*/
bool is_palindrome(char *s, int len)
{
    int i = 0;
    /*@ loop invariant 0 <= i <= len/2;
        loop invariant \forall integer j; 0 <= j < i ==> s[j] == s[len - 1 - j];
        loop assigns i;
    */
    while (i < len / 2) {
        //@ assert i < len/2;
        if (s[i] != s[len - 1 - i]) {
            return false;
        }
        i++;
    }
    return true;
}

void test_vec3(void) {
    unsigned int v[5];
    v[0] = 0;
    v[1] = 10;
    v[2] = 21;
    v[3] = 30;
    v[4] = 40;
    //@ assert v[0] == 0;
}
