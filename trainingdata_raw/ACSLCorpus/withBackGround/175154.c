#include <stddef.h>

/*@
    predicate is_in_range(integer n) = 1 <= n && n <= 10000;

    logic integer compute_result(integer n) = (n + 999) / 1000 * 1000;

    lemma result_lemma:
        \forall integer n; is_in_range(n) ==> compute_result(n) == ((n + 999) / 1000) * 1000;
*/

/*@
    requires 1 <= n && n <= 10000;
    ensures \result == ((n + 999) / 1000) * 1000;
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t result;
    //@ assert is_in_range(n);
    result = (n + 999) / 1000;
    //@ assert result == (n + 999) / 1000;
    result = result * 1000;
    //@ assert result == compute_result(n);
    return result;
}

/*@
    predicate map_empty(int *keys, int *values, integer size) = size == 0;

    lemma test_map_remove_key_lemma:
        \forall int *keys, *values, integer size;
        map_empty(keys, values, size) ==> size == 0;
*/

int main(void)
{
    // Test func
    size_t n = 500;
    size_t res = func(n);
    //@ assert res == ((n + 999) / 1000) * 1000;
    
    // Test map properties
    int *keys = 0;
    int *values = 0;
    int size = 0;
    //@ assert map_empty(keys, values, size);
    //@ assert size == 0;
    
    return 0;
}
