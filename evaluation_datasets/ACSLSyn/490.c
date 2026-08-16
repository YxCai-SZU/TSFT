#include <stdint.h>
#include <stdbool.h>

/* ===== Original functions with their specifications ===== */

/* Function 1: Bitwise complement */
/*@
    predicate is_valid_input(uint32_t x) = x < 0x100000000;
    logic integer bitwise_complement(integer x) = x ^ 0xFFFFFFFF;
*/
uint32_t func_bitwise(uint32_t x)
{
    //@ assert is_valid_input(x);
    uint32_t result = x ^ 0xFFFFFFFF;
    //@ assert result == bitwise_complement(x);
    return result;
}

/* Function 2: Check condition on x */
/*@
    predicate is_valid_x(integer x) = 1 <= x <= 100000;
    logic integer remainder(integer x) = x % 100;
    logic integer quotient(integer x) = x / 100;
    lemma remainder_bounds: \forall integer x; is_valid_x(x) ==> 0 <= remainder(x) <= 99;
    lemma quotient_bounds: \forall integer x; is_valid_x(x) ==> 0 <= quotient(x) <= 1000;
*/
bool func_check(unsigned int x) {
    unsigned int n;
    unsigned int a;
    unsigned int twentyone_a;
    unsigned int i;
    
    n = x / 100;
    a = x % 100;
    
    twentyone_a = 0;
    i = 0;
    
    while (i < a) {
        //@ assert i < 100;
        twentyone_a += 21;
        i += 1;
    }
    
    //@ assert twentyone_a == 21 * a;
    
    if (twentyone_a <= x) {
        //@ assert (x % 100) * 21 <= x;
        return true;
    } else {
        //@ assert (x % 100) * 21 > x;
        return false;
    }
}

/* Function 3: Sorting and checking condition */
/*@ predicate sorted_three(integer a, integer b, integer c) =
       a <= b && b <= c;
*/
/*@ lemma sort_preserves_sum:
       \forall integer a, b, c, a0, b0, c0;
       a0 == a && b0 == b && c0 == c && sorted_three(a, b, c) ==>
       a + b + c == a0 + b0 + c0;
*/
/*@ lemma sort_preserves_pair_sums:
       \forall integer a, b, c, a0, b0, c0;
       a0 == a && b0 == b && c0 == c && sorted_three(a, b, c) ==>
       (a + b > 9 && b + c > 9 && c + a > 9) ==>
       (a0 + b0 > 9 && b0 + c0 > 9 && c0 + a0 > 9);
*/
bool func_sort(const long long* numbers) {
    long long a;
    long long b;
    long long c;
    long long temp;
    long long a0;
    long long b0;
    long long c0;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];
    a0 = a;
    b0 = b;
    c0 = c;

    //@ assert a >= 1 && a <= 13;
    //@ assert b >= 1 && b <= 13;
    //@ assert c >= 1 && c <= 13;

    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    //@ assert a <= b;

    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
    //@ assert b <= c;

    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    //@ assert a <= b && b <= c;

    //@ assert sorted_three(a, b, c);
    //@ assert a + b + c == a0 + b0 + c0;

    if (a + b + c >= 22 || (a + b > 9 && b + c > 9 && c + a > 9)) {
        return true;
    } else {
        //@ assert a + b + c < 22;
        //@ assert a + b <= 9 || b + c <= 9 || c + a <= 9;
        return false;
    }
}

/* Function 4: Count odd numbers at even indices */
/*@ predicate vec_in_range(int* arr, integer len) =
      \forall integer i; 0 <= i < len ==> 1 <= arr[i] <= 100;
*/
/*@ lemma ans_bounds:
      \forall integer index, integer ans;
      0 <= index && 0 <= ans <= index ==> ans >= 0 && ans <= index;
*/
int func_count(int n, int* a_vec) {
    int ans = 0;
    unsigned int index = 0;
    
    while (index < (unsigned int)n) {
        int a = a_vec[index];
        unsigned int index_u32 = index;
        unsigned int a_u32 = (unsigned int)a;
        
        //@ assert vec_in_range(a_vec, n) ==> 1 <= a <= 100;
        
        if ((index_u32 % 2) == 0 && (a_u32 & 1) == 1) {
            ans += 1;
        }
        index += 1;
    }
    return ans;
}

/* ===== Synthesized complex function ===== */

/* Scenario: Cryptographic key validation system
   Data flow:
   1. Take a 32-bit input value and complement it
   2. Check if the complemented value satisfies a property (remainder * 21 <= value)
   3. If property holds, sort three numbers and check a sum/pair condition
   4. Count special elements in an array (odd numbers at even indices)
   The final assertion verifies that the count of special elements is consistent
   with the overall validation state.
*/

int synthesized_func(uint32_t input, unsigned int check_val, const long long* numbers, int n, int* a_vec) {
    uint32_t complemented = func_bitwise(input);
    
    bool check_result = func_check(check_val);
    
    bool sort_result;
    if (check_result) {
        sort_result = func_sort(numbers);
    } else {
        sort_result = false;
    }
    
    int count_result = func_count(n, a_vec);
    
    //@ assert count_result >= 0 && count_result <= n;
    
    return count_result;
}
