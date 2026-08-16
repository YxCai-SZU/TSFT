#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

/* ===== Original function 1: monotonic sequence check ===== */
/*@
    predicate strictly_increasing(integer a, integer b, integer c) =
        a < b && b < c;
    predicate strictly_decreasing(integer a, integer b, integer c) =
        a > b && b > c;
    predicate monotonic_sequence(integer a, integer b, integer c) =
        strictly_increasing(a, b, c) || strictly_decreasing(a, b, c);
*/

bool check_monotonic(unsigned long long a, unsigned long long b, unsigned long long c)
{
    bool result;

    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;

    if ((a < b && b < c) || (a > b && b > c))
    {
        //@ assert strictly_increasing(a, b, c) || strictly_decreasing(a, b, c);
        result = true;
    }
    else
    {
        //@ assert !(strictly_increasing(a, b, c) || strictly_decreasing(a, b, c));
        result = false;
    }

    return result;
}

/* ===== Original function 2: even check ===== */
/*@ predicate is_even(integer a) = a % 2 == 0; */

bool check_even(unsigned long long a)
{
    bool result;
    unsigned long long temp_a;
    bool is_even_var = false;

    if (a % 2 == 0) {
        result = true;
        return result;
    } else {
        temp_a = a;
        while (temp_a >= 2) {
            //@ assert temp_a >= 2;
            temp_a -= 2;
        }

        if (temp_a == 0) {
            is_even_var = true;
        }

        //@ assert is_even_var == (a % 2 == 0);
        result = is_even_var;
        return result;
    }
}

/* ===== Original function 3: array initialization ===== */
/*@ predicate is_valid_params(size_t n, size_t k, size_t s) =
      (1 <= n <= 100000) &&
      (0 <= k <= n) &&
      (1 <= s <= 100000000);
*/

/*@ predicate first_k_elements_equal(size_t *arr, size_t k, size_t s) =
      \forall integer i; 0 <= i < k ==> arr[i] == s;
*/

/*@ predicate remaining_elements_correct(size_t *arr, size_t n, size_t k, size_t s) =
      \forall integer i; k <= i < n ==> 
        (s < 1000000000 ==> arr[i] == s + 1) &&
        (s >= 1000000000 ==> arr[i] == s - 1);
*/

/*@ lemma s_range_lemma: 
      \forall integer s; 1 <= s <= 100000000 ==> s < 1000000000;
*/

void init_array(size_t n, size_t k, size_t s, size_t *ans) {
    size_t i;
    size_t j;
    
    i = 0;
    while (i < k) {
        //@ assert i < k;
        ans[i] = s;
        i = i + 1;
    }
    
    if (s < 1000000000) {
        j = 0;
        while (j < n - k) {
            //@ assert j < n - k;
            ans[k + j] = s + 1;
            j = j + 1;
        }
    } else {
        j = 0;
        while (j < n - k) {
            //@ assert j < n - k;
            ans[k + j] = s - 1;
            j = j + 1;
        }
    }
}

/* ===== Synthesized function: validate_and_init_array ===== */

void validate_and_init_array(size_t n, size_t k, size_t s, size_t *ans) {
    init_array(n, k, s, ans);
    
    //@ assert first_k_elements_equal(ans, k, s);
    //@ assert remaining_elements_correct(ans, n, k, s);
    
    //@ assert \forall integer i; 0 <= i < n ==> 1 <= ans[i] <= 1000000001;
}

int main() {
    return 0;
}
