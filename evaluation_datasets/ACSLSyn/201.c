#include <stdint.h>
#include <stdbool.h>

/* First function: check if a number satisfies a property based on modulo 100 */
/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100000;

    logic integer n_mod_100(integer n) = n % 100;
    logic integer n_div_100(integer n) = n / 100;

    logic integer compute_a(integer n) = n_mod_100(n) * 21;
    logic integer compute_b(integer n) = n_div_100(n) * 100 + n_mod_100(n) * 21;
    logic integer compute_c(integer n) =
        n_mod_100(n) <= 100 - 21 ?
        (n_div_100(n) + 1) * 100 :
        (n_div_100(n) + 1) * 100 + 21;

    lemma mod_bound: \forall integer n; n_mod_100(n) == n % 100;
    lemma div_bound: \forall integer n; n_div_100(n) == n / 100;
    lemma a_bound: \forall integer n; is_valid_n(n) ==> compute_a(n) <= 2100;
*/

int32_t func(uint32_t n)
{
    uint32_t n_mod_100;
    uint32_t n_div_100;
    uint32_t a;
    uint32_t b;
    uint32_t c;

    n_mod_100 = n % 100;
    n_div_100 = n / 100;

    a = n_mod_100 * 21;
    b = n_div_100 * 100 + n_mod_100 * 21;

    //@ assert n_mod_100 < 100;
    //@ assert a <= 2100;

    if (n_mod_100 <= 100 - 21)
    {
        c = (n_div_100 + 1) * 100;
    }
    else
    {
        c = (n_div_100 + 1) * 100 + 21;
    }

    if (n_mod_100 * 21 <= n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Second function: check if an array is strictly increasing */
/*@
    predicate increasing_sequence{L}(int *arr, integer len) =
        \forall integer i; 0 <= i < len - 1 ==> arr[i] < arr[i + 1];
*/

bool is_increasing_sequence(int *arr, int len) {
    int i;
    i = 0;
    while (i < len - 1) {
        //@ assert 0 <= i < len - 1;
        if (arr[i] >= arr[i + 1]) {
            return false;
        }
        i = i + 1;
    }
    return true;
}

/* Helper predicate to avoid using func in ACSL annotations */
/*@
    predicate special_number(integer n) = 
        is_valid_n(n) && (n_mod_100(n) * 21 <= n);
    
    predicate valid_special_sequence{L}(int *arr, integer len) =
        len >= 1 && 
        \forall integer i; 0 <= i < len ==> special_number((uint32_t)arr[i]) &&
        increasing_sequence(arr, len);
*/

bool validate_special_increasing_sequence(int *arr, int len) {
    int i;
    
    for (i = 0; i < len; i++) {
        //@ assert is_valid_n((uint32_t)arr[i]);
        if (func((uint32_t)arr[i]) == 0) {
            return false;
        }
        //@ assert special_number((uint32_t)arr[i]);
    }
    
    if (!is_increasing_sequence(arr, len)) {
        return false;
    }
    
    //@ assert increasing_sequence(arr, len);
    //@ assert \forall integer i; 0 <= i < len ==> special_number((uint32_t)arr[i]);
    
    return true;
}
