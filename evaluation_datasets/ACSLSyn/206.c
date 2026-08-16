#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@ predicate valid_array(int *arr, integer len) =
    len >= 1 && len <= 10000 &&
    \forall integer i; 0 <= i < len ==> arr[i] >= 1 && arr[i] <= 10000;
*/

/*@ predicate loop_inv(integer i, integer len, integer sum) =
    0 <= i <= len && sum >= 0 && sum <= i * 10000;
*/

/*@ lemma sum_bound: \forall integer i, integer len, integer sum;
    loop_inv(i, len, sum) ==> sum >= 0;
*/

/*@ lemma index_bound: \forall integer i, integer len, integer sum;
    loop_inv(i, len, sum) ==> i <= len;
*/

int func(int n, int *a_vec, size_t a_len) {
    int sum = 0;
    size_t i = 0;
    
    //@ assert n >= 1 && n <= 1000000;
    //@ assert valid_array(a_vec, a_len);
    
    while (i < a_len) {
        //@ assert 0 <= i < a_len;
        //@ assert a_vec[i] >= 1 && a_vec[i] <= 10000;
        sum += a_vec[i];
        i++;
        //@ assert sum >= 0;
    }
    
    //@ assert sum >= 0;
    
    if (n > sum) {
        int result = n - sum;
        //@ assert result >= 0;
        //@ assert result <= n;
        return result;
    } else {
        //@ assert 0 >= 0;
        //@ assert 0 <= n;
        return 0;
    }
}

/*@
    predicate is_in_range(integer x) = 1 <= x <= 100000;

    logic integer compute_a(integer x) = x / 100;
    logic integer compute_b(integer x) = x % 100;

    predicate condition_a(integer a) = a >= 10 && (a == 10 || a == 11 || a == 12 || a == 13 || a == 14 || a == 15 || a == 16 || a == 17 || a == 18 || a == 19);
    predicate condition_b(integer b) = b >= 10 && (b == 10 || b == 11 || b == 12 || b == 13 || b == 14 || b == 15 || b == 16 || b == 17 || b == 18 || b == 19);
    predicate condition_ab(integer a, integer b) = a >= 10 && b >= 10 && a + b >= 20;

    lemma a_in_range: \forall integer x; is_in_range(x) ==> 0 <= compute_a(x) <= 1000;
    lemma b_in_range: \forall integer x; is_in_range(x) ==> 0 <= compute_b(x) <= 99;
*/

int32_t func2(uint32_t x)
{
    uint32_t a;
    uint32_t b;
    int32_t result;

    //@ assert is_in_range(x);
    a = x / 100;
    b = x % 100;

    //@ assert a == compute_a(x);
    //@ assert b == compute_b(x);

    if (a >= 10 && (a == 10 || a == 11 || a == 12 || a == 13 || a == 14 || a == 15 || a == 16 || a == 17 || a == 18 || a == 19)) {
        //@ assert condition_a(a);
        result = 1;
        return result;
    }
    if (b >= 10 && (b == 10 || b == 11 || b == 12 || b == 13 || b == 14 || b == 15 || b == 16 || b == 17 || b == 18 || b == 19)) {
        //@ assert condition_b(b);
        result = 1;
        return result;
    }
    if (a >= 10 && b >= 10 && a + b >= 20) {
        //@ assert condition_ab(a, b);
        result = 1;
        return result;
    }
    //@ assert !condition_a(a) && !condition_b(b) && !condition_ab(a, b);
    result = 0;
    return result;
}

int process_packet(int n, int *a_vec, size_t a_len, uint32_t packet_code) {
    int available = func(n, a_vec, a_len);
    //@ assert available >= 0 && available <= n;
    
    int32_t code_valid = func2(packet_code);
    //@ assert code_valid == 0 || code_valid == 1;
    
    int result;
    if (code_valid == 0) {
        result = 0;
    } else {
        result = available;
    }
    
    //@ assert result >= 0 && result <= n;
    //@ assert result >= 0 && result <= n;
    return result;
}
