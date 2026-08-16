#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_range(integer a) = 1 <= a <= 10000;
    
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_bounds: \forall integer a, b; 
        valid_range(a) && valid_range(b) ==> 
        1 <= product(a, b) <= 100000000;
*/

bool parity_check(int a, int b)
{
    int product_val;
    bool is_odd;
    int abs_product;
    int remainder;
    
    //@ assert valid_range(a) && valid_range(b);
    //@ assert 1 <= product(a, b) <= 100000000;
    
    product_val = a * b;
    
    abs_product = product_val;
    if (product_val < 0) {
        abs_product = -product_val;
    }
    
    is_odd = false;
    remainder = abs_product;
    
    while (remainder >= 2) {
        remainder -= 2;
    }
    
    if (remainder == 1) {
        is_odd = true;
    }
    
    //@ assert is_odd == (product(a, b) % 2 != 0);
    
    return is_odd;
}

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    predicate is_valid_k(integer k) = 1 <= k && k <= 100;
*/

int divisibility_indicator(size_t n, size_t k) {
    int result;
    
    if (n % k == 0) {
        result = 0;
    } else {
        result = 1;
    }
    
    //@ assert result == 0 || result == 1;
    return result;
}

/*@
    predicate valid_data_size(integer n) = 1 <= n && n <= 100;
    predicate valid_block_size(integer k) = 1 <= k && k <= 100;
    predicate valid_id_range(integer id) = 1 <= id && id <= 10000;
    
    logic integer packet_product(integer id, integer size) = id * size;
*/

int check_stream_integrity(size_t n, size_t k, int id) {
    int div_result;
    bool parity_result;
    int final_status;
    
    div_result = divisibility_indicator(n, k);
    //@ assert div_result == 0 || div_result == 1;
    
    parity_result = parity_check(id, (int)n);
    //@ assert parity_result == (product(id, (int)n) % 2 != 0);
    
    if (div_result == 0 && !parity_result) {
        final_status = 0;
    } else {
        final_status = 1;
    }
    
    //@ assert final_status == 0 || final_status == 1;
    
    return final_status;
}
