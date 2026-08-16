#include <stdbool.h>
#include <stddef.h>

/*@
    predicate is_palindrome{L}(unsigned int *l, size_t len) =
        \forall size_t i; 0 <= i < len ==> l[i] == l[len - 1 - i];
*/

/*@
    lemma test_is_palindrome:
        \forall unsigned int *l; \forall size_t len;
        len == 5 && l[0] == 1 && l[1] == 2 && l[2] == 3 && l[3] == 2 && l[4] == 1 ==> 
        is_palindrome(l, len);
*/

int main() {
    unsigned int l[5];
    size_t len;
    
    l[0] = 1;
    l[1] = 2;
    l[2] = 3;
    l[3] = 2;
    l[4] = 1;
    len = 5;
    
    //@ assert is_palindrome(&l[0], len);
    
    return 0;
}
