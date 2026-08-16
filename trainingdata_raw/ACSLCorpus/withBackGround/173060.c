#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_seq(int *s, size_t len, int key) =
        \forall integer i; 0 <= i < len ==> s[i] == i * key;

    predicate valid_struct(int key, size_t len, int *s) =
        valid_seq(s, len, key);

    lemma two_equal_struct:
        \forall int key1, key2, size_t len1, len2, int *s1, *s2;
        key1 == key2 && len1 == len2 &&
        valid_struct(key1, len1, s1) &&
        valid_struct(key2, len2, s2) ==>
        (\forall integer i; 0 <= i < len1 ==> s1[i] == s2[i]);
*/

int main() {
    // Variable declarations
    int result = 0;
    
    //@ assert 0 * 2 == 0;
    //@ assert 1 * 2 == 2;
    //@ assert 2 * 2 == 4;
    //@ assert 3 * 2 == 6;
    //@ assert 4 * 2 == 8;
    //@ assert 5 * 2 == 10;
    
    return result;
}
