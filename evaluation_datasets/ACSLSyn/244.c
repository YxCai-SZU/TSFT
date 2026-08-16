#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/* ========== Original Function 1: func ========== */
/*@ predicate condition_holds(integer n, integer m) =
      (n - 1) / 2 >= m - 1;
*/

bool func(int n, int m)
{
    int i;
    
    //@ assert 1 <= n <= 100;
    //@ assert 1 <= m <= 100;
    
    i = 0;
    
    while (i < m - 1)
    {
        if (i >= (n - 1) / 2)
        {
            return false;
        }
        i = i + 1;
    }
    
    return true;
}

/* ========== Original Function 2: func2 ========== */
/*@
    predicate is_modulo_less_500(integer x) =
        (x / 100 * 100 + (100 - x % 100)) % 1000 < 500;

    predicate is_modulo_ge_500(integer x) =
        (x / 100 * 100 + (100 - x % 100)) % 1000 >= 500;

    logic integer compute_pay(integer x) =
        x / 100 * 100 + (100 - x % 100);
*/

int32_t func2(uint32_t x)
{
    int32_t pay;
    int32_t modulo;
    int32_t temp;

    pay = (int32_t)(x / 100 * 100 + (100 - x % 100));

    if (pay >= 0)
    {
        temp = pay;
        while (temp >= 1000)
        {
            temp -= 1000;
        }
        modulo = temp;
    }
    else
    {
        temp = pay;
        while (temp <= -1000)
        {
            temp += 1000;
        }
        modulo = temp;
    }

    if (modulo < 500)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* ========== Original Function 3: find_kth_element ========== */
/*@ predicate is_valid_index(int *arr, size_t len, size_t k) =
      len > 0 && 1 <= k && k <= len;
*/

/*@ logic integer element_at(int *arr, integer k) =
      arr[k];
*/

int find_kth_element(int *arr, size_t len, size_t k) {
    size_t index;
    int result = 0;
    size_t i = 0;
    
    index = k - 1;
    
    while (i < len) {
        if (i == index) {
            result = arr[i];
        }
        i++;
    }
    
    return result;
}

/* ========== Synthesized Complex Function: process_trade_data ========== */

int process_trade_data(int n, int m, uint32_t base_price, int *arr, size_t len, size_t k)
{
    bool eligible;
    int32_t rounding_decision;
    int kth_element;
    int combined_price;
    
    eligible = func(n, m);
    
    if (!eligible) {
        return -1;
    }
    
    kth_element = find_kth_element(arr, len, k);
    
    combined_price = kth_element + (int)base_price;
    
    if (combined_price < 1 || combined_price > 100000) {
        return -1;
    }
    
    rounding_decision = func2((uint32_t)combined_price);
    
    return (int)rounding_decision;
}
