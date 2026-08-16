#include <stdbool.h>
#include <stddef.h>

/*@
    predicate is_even_length{L}(unsigned int *s, size_t len) =
        len % 2 == 0;

    predicate all_elements_nonzero{L}(unsigned int *s, size_t len) =
        \forall size_t i; 0 <= i < len ==> s[i] != 0;
*/

/*@
    lemma even_length_implies_even_length:
        \forall unsigned int *s, size_t len;
        is_even_length(s, len) ==> len % 2 == 0;
*/

/*@
    requires \valid_read(arr + (0..len-1));
    requires \forall size_t i; 0 <= i < len ==> arr[i] % 2 == 0;
    requires is_even_length(arr, len);
    requires all_elements_nonzero(arr, len);
    ensures \result == true;
    assigns \nothing;
*/
bool is_all_even(unsigned int *arr, size_t len) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall size_t j; 0 <= j < i ==> arr[j] % 2 == 0;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] % 2 != 0) {
            return false;
        }
        i++;
    }
    return true;
}

/*@
    assigns \nothing;
*/
int main() {
    unsigned int v[4] = {2, 4, 6, 8};
    size_t v_len = 4;
    
    //@ assert is_even_length(&v[0], v_len);
    //@ assert all_elements_nonzero(&v[0], v_len);
    
    bool result = is_all_even(&v[0], v_len);
    //@ assert result == true;
    
    return 0;
}
