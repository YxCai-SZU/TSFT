#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* ========== Original Function 1: XOR array and count zero-xor segments ========== */
/*@ predicate valid_range(integer N) = 1 <= N <= 200000; */
/*@ predicate valid_number(integer x) = 1 <= x <= 1000000000; */
/*@ predicate valid_array(integer N, unsigned int *arr) = 
      \valid(arr + (0 .. N-1)) && 
      \forall integer i; 0 <= i < N ==> valid_number(arr[i]); */

int xor_count_zero_segments(size_t N, unsigned int *numbers) {
    unsigned int tmp;
    size_t index;
    int ans;
    
    tmp = 0;
    index = 0;
    
    while (index < N) {
        //@ assert 0 <= index < N;
        tmp ^= numbers[index];
        index += 1;
    }
    
    if (tmp > 0) {
        return -1;
    } else {
        ans = 0;
        tmp = 0;
        index = 0;
        
        while (index < N) {
            //@ assert 0 <= index < N;
            tmp ^= numbers[index];
            index += 1;
            if (tmp == 0) {
                ans += 1;
            }
        }
        return ans;
    }
}

/* ========== Original Function 2: Compute bound for value + discount ========== */
/*@
    predicate valid_inputs(integer a, integer b) =
        0 <= a <= 100000000000000 &&
        0 <= b < 1000;

    logic integer compute_bound(integer a, integer b) =
        a + (b / 100) * 100 + ((b % 100) / 5) * 5;

    lemma bound_lemma:
        \forall integer a, b;
        valid_inputs(a, b) ==> compute_bound(a, b) <= a + b;
*/

uint64_t discount_bound(uint64_t a, uint64_t b) {
    uint64_t result;
    uint64_t r;
    uint64_t temp_b;
    uint64_t quotient;
    
    result = a + (b / 100) * 100 + ((b % 100) / 5) * 5;
    r = 0;
    temp_b = b;
    quotient = 0;
    
    while (temp_b >= 100) {
        //@ assert temp_b >= 100;
        temp_b -= 100;
        quotient += 1;
    }
    r += quotient * 100;
    
    quotient = 0;
    while (temp_b >= 5) {
        //@ assert temp_b >= 5;
        temp_b -= 5;
        quotient += 1;
    }
    r += quotient * 5;
    
    r += a;
    
    //@ assert r <= compute_bound(a, b);
    return r;
}

/* ========== Original Function 3: Compute absolute difference of max pairs ========== */
/*@
    predicate valid_input(int *v) =
        \valid(v + (0..3)) &&
        v[0] >= 1 && v[0] <= 10000 &&
        v[1] >= 1 && v[1] <= 10000 &&
        v[2] >= 1 && v[2] <= 10000 &&
        v[3] >= 1 && v[3] <= 10000;

    logic integer max(integer a, integer b) = a > b ? a : b;

    lemma max_bounds:
        \forall integer a, b;
        (a >= 1 && a <= 10000 && b >= 1 && b <= 10000) ==>
        max(a, b) >= 1 && max(a, b) <= 10000;

    lemma diff_bounds:
        \forall integer m1, m2;
        (m1 >= 1 && m1 <= 10000 && m2 >= 1 && m2 <= 10000) ==>
        m1 - m2 >= -9999 && m1 - m2 <= 9999;
*/

int max_abs_diff(int *v)
{
    int a;
    int b;
    int c;
    int d;
    int max1;
    int max2;
    int diff;
    int result;

    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];

    //@ assert a >= 1 && a <= 10000;
    //@ assert b >= 1 && b <= 10000;
    //@ assert c >= 1 && c <= 10000;
    //@ assert d >= 1 && d <= 10000;

    max1 = a > b ? a : b;
    max2 = c > d ? c : d;

    //@ assert max1 >= 1 && max1 <= 10000;
    //@ assert max2 >= 1 && max2 <= 10000;

    diff = max1 - max2;

    //@ assert diff >= -9999 && diff <= 9999;

    result = diff < 0 ? -diff : diff;

    //@ assert result >= 0;
    return result;
}

/* ========== Original Function 4: Find minimum element in array ========== */
/*@ predicate element_exists{L}(unsigned char *arr, integer len, unsigned char val) =
      \exists integer i; 0 <= i < len && arr[i] == val;
*/

/*@ predicate is_minimum{L}(unsigned char *arr, integer len, unsigned char val) =
      \forall integer i; 0 <= i < len ==> val <= arr[i];
*/

/*@ lemma min_preservation:
      \forall unsigned char *arr, integer len, integer idx, unsigned char min;
      element_exists(arr, idx, min) &&
      is_minimum(arr, idx, min) &&
      0 <= idx < len &&
      min <= arr[idx] ==>
      element_exists(arr, idx+1, min) &&
      is_minimum(arr, idx+1, min);
*/

/*@ lemma min_update:
      \forall unsigned char *arr, integer len, integer idx, unsigned char min;
      element_exists(arr, idx, min) &&
      is_minimum(arr, idx, min) &&
      0 <= idx < len &&
      arr[idx] < min ==>
      element_exists(arr, idx+1, arr[idx]) &&
      is_minimum(arr, idx+1, arr[idx]);
*/

unsigned char min_element(const unsigned char *arr, size_t len)
{
  unsigned char min;
  size_t i;
  
  min = arr[0];
  i = 1;
  
  while (i < len) {
    //@ assert element_exists(arr, i, min);
    
    if (arr[i] < min) {
      min = arr[i];
    }
    
    i++;
  }
  
  return min;
}

/* ========== Synthesized Complex Function: Process packet segments and compute quality metric ========== */

int process_packet_quality(
    size_t N, unsigned int *numbers,
    int *v,
    const unsigned char *arr, size_t len,
    uint64_t a, uint64_t b
)
{
    int seg_count;
    uint64_t bound_val;
    int diff_val;
    unsigned char min_val;
    int result;
    
    seg_count = xor_count_zero_segments(N, numbers);
    
    bound_val = discount_bound(a, b);
    
    diff_val = max_abs_diff(v);
    
    min_val = min_element(arr, len);
    
    if (seg_count >= 0 && bound_val > 0 && diff_val >= 0 && min_val <= 255) {
        result = seg_count + (int)(bound_val % 1000) + diff_val + (int)min_val;
    } else {
        result = -1;
    }
    
    //@ assert result >= -1;
    return result;
}
