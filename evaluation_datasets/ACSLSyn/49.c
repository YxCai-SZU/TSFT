#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/* ===================== ORIGINAL FUNCTIONS (adapted for context) ===================== */

/*@ predicate is_valid_range(integer a) = 1 <= a <= 10000; */
/*@ logic integer multiply_mod2(integer a, integer b) = (a * b) % 2; */
/*@ lemma multiplication_bound: 
      \forall integer a, b; 
      is_valid_range(a) && is_valid_range(b) ==> a * b <= 100000000; */
/*@ lemma mod2_property: 
      \forall integer a, b; 
      multiply_mod2(a, b) == 0 ==> (a * b) % 2 == 0; */
bool func_product_even(int a, int b)
{
  //@ assert a * b <= 100000000;
  return (a * b) % 2 == 0;
}

/*@ predicate valid_range(integer n) = 1 <= n <= 200000; */
/*@ predicate valid_number(integer x) = 1 <= x <= 1000000; */
/*@ predicate valid_array(int *arr, integer n) = 
      \forall integer i; 0 <= i < n ==> valid_number(arr[i]); */
/*@ lemma count_bounds: 
      \forall integer index, integer count; 
      0 <= index && 0 <= count <= index ==> 0 <= count; */
int func_count_non_divisible(int n, int *numbers) {
    int count = 0;
    int index = 0;
    int num_size = n;
    while (index < num_size) {
        int ai = numbers[index];
        bool is_divisible = false;
        unsigned int i = 1;
        while (i < 10) {
            if (ai % i == 0) {
                is_divisible = true;
                break;
            }
            i++;
        }
        if (!is_divisible) {
            count++;
        }
        index++;
    }
    return count;
}

/*@ predicate is_uint32(integer x) = 0 <= x <= 0xFFFFFFFF; */
bool func_uint32_less_than_threshold(uint32_t v)
{
    return v < 0x0F0F0F0F;
}

/*@ predicate is_valid_index(integer i, integer len) =
      0 <= i && i < len; */
/*@ predicate element_is_valid(int *a, integer len, integer i) =
      is_valid_index(i, len) ==>
      (*(a + i) == i + 1 || *(a + i) == 0); */
/*@ predicate exists_zero(int *a, integer len, integer start) =
      \exists integer j; start <= j && j < len && *(a + j) == 0; */
/*@ predicate all_nonzero_up_to(int *a, integer i) =
      \forall integer j; 0 <= j && j < i ==> *(a + j) != 0; */
/*@ lemma zero_exists_in_range:
      \forall int *a, integer len, integer start;
      exists_zero(a, len, start) ==>
      \exists integer j; start <= j && j < len && *(a + j) == 0; */
int func_find_first_zero(int *a) {
    size_t i = 0;
    while (i < 5) {
        if (*(a + i) == 0) {
            return (int)(i + 1);
        }
        i++;
    }
    return -1;
}

/* ===================== SYNTHESIZED COMPLEX FUNCTION ===================== */


int process_transaction_batch(
    int amount1, int amount2,
    int num_ids, int *transaction_ids,
    uint32_t session_token,
    int *config_array
) {
    bool parity_ok = func_product_even(amount1, amount2);
    
    int prime_like_count = func_count_non_divisible(num_ids, transaction_ids);
    
    bool token_valid = func_uint32_less_than_threshold(session_token);
    
    int first_invalid_pos = func_find_first_zero(config_array);
    
    
    return (parity_ok && token_valid && prime_like_count > 0 && first_invalid_pos >= 1 && first_invalid_pos <= 5) ? 1 : 0;
}
