#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/*@ predicate is_equal(integer n, integer m) = n == m; */

bool eq_func(uint32_t n, uint32_t m) {
    bool result;
    result = (n == m);
    return result;
}

uint32_t* read_vec(void) {
    uint32_t* vec = ((void*)0);
    return vec;
}

/*@
    predicate valid_input(integer a, integer b) =
        2 <= a && a <= 100 &&
        2 <= b && b <= 100;

    logic integer compute_result(integer a, integer b) =
        (a - 1) * (b - 1);

    lemma arithmetic_bounds:
        \forall integer a, b;
        valid_input(a, b) ==>
        1 <= a - 1 && 1 <= b - 1 &&
        compute_result(a, b) <= 9801;
*/

uint32_t compute_func(uint32_t a, uint32_t b)
{
    uint32_t result;
    result = (a - 1) * (b - 1);
    return result;
}

/*@
    predicate valid_vec_of_vec(int **lst, size_t outer_len, size_t *inner_lens) =
        \forall size_t i; 0 <= i < outer_len ==> 
            \valid(lst + i) && \valid_read(lst[i] + (0 .. inner_lens[i]-1));
*/

/*@
    logic integer list_length(int **lst, size_t outer_len) = (integer)outer_len;
*/

/*@
    lemma length_non_negative: 
        \forall int **lst, size_t outer_len, size_t *inner_lens; 
            valid_vec_of_vec(lst, outer_len, inner_lens) ==> list_length(lst, outer_len) >= 0;
*/

size_t count_lists(int **lst, size_t outer_len, size_t *inner_lens) {
    size_t count = 0;
    size_t i = 0;
    
    while (i < outer_len) {
        count += 1;
        i += 1;
    }
    return count;
}

bool process_data(int **lst, size_t outer_len, size_t *inner_lens, 
                  uint32_t a, uint32_t b, uint32_t n, uint32_t m)
{
    size_t list_cnt;
    uint32_t comp_val;
    bool eq_val;
    bool final_result;
    
    list_cnt = count_lists(lst, outer_len, inner_lens);
    
    comp_val = compute_func(a, b);
    
    eq_val = eq_func(n, m);
    
    final_result = (list_cnt == 0) || (comp_val > 0 && eq_val);
    
    return final_result;
}
