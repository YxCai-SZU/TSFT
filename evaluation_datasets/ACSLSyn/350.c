#include <stdbool.h>
#include <stdint.h>

/* Predicates from original functions */
/*@ predicate in_range(integer x) = -100 <= x <= 100; */
/*@ predicate a_in_range(integer a) = 1 <= a && a <= 100; */
/*@ predicate b_in_range(integer b) = 1 <= b && b <= 100; */
/*@ predicate product_in_range(integer p) = 1 <= p && p <= 10000; */
/*@ predicate valid_range(integer a) = 1 <= a && a <= 100; */
/*@ predicate is_even(integer n) = (n % 2) == 0; */
/*@ predicate is_multiple_of_3(integer n) = (n % 3) == 0; */

/* Lemma from second function */
/*@ lemma product_range: 
      \forall integer a, b; 
      a_in_range(a) && b_in_range(b) ==> product_in_range(a * b); */

/* Lemma from third function */
/*@ lemma multiplication_range: \forall integer a, b; valid_range(a) && valid_range(b) ==> 1 <= a * b <= 10000; */

/* Logic function from third function */
/*@ logic integer multiply(integer a, integer b) = a * b; */

/* Original function 1: checks if numbers[2] is between numbers[0] and numbers[1] */
bool func_between(const int numbers[3]) {
    bool result = false;
    int a = 0;
    int b = 0;
    int c = 0;

    //@ assert in_range(numbers[0]);
    a = numbers[0];
    //@ assert in_range(numbers[1]);
    b = numbers[1];
    //@ assert in_range(numbers[2]);
    c = numbers[2];

    if (a <= c && c <= b) {
        result = true;
    }
    return result;
}

/* Original function 2: computes floor(a*b/2) */
int32_t func_half_product(int32_t a, int32_t b) {
    int64_t product;
    int32_t result;
    int32_t i;
    int64_t sum;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    
    product = (int64_t)a * (int64_t)b;
    //@ assert product_in_range(product);
    
    result = 0;
    i = 0;
    sum = 0;
    
    while (sum + 2 <= product) {
        //@ assert sum + 2 <= product;
        sum += 2;
        result += 1;
        i += 1;
        //@ assert sum == 2 * i;
        //@ assert result == i;
    }
    
    //@ assert result >= 0;
    //@ assert result <= a * b;
    return result;
}

/* Original function 3: computes a * b */
int func_multiply(int a, int b)
{
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert 1 <= multiply(a, b) && multiply(a, b) <= 10000;
    return a * b;
}

/* Original function 4: checks if n is divisible by 6 */
int func_is_divisible_by_6(int n)
{
    bool is_even_bool;
    bool is_multiple_of_3_bool;
    int result;

    is_even_bool = (n % 2) == 0;
    is_multiple_of_3_bool = (n % 3) == 0;

    if (is_even_bool && is_multiple_of_3_bool)
    {
        //@ assert is_even_bool && is_multiple_of_3_bool;
        result = 1;
    }
    else
    {
        //@ assert !(is_even_bool && is_multiple_of_3_bool);
        result = 0;
    }

    return result;
}

/* 
 * Real-world scenario: Data validation and transformation pipeline
 * 
 * This function processes sensor data triplets from a monitoring system:
 * 1. Validates that a value (numbers[2]) falls within calibrated bounds (numbers[0], numbers[1])
 * 2. Computes half of the product of two sensor readings (a, b) for averaging
 * 3. Computes the full product of two parameters (a, b) for scaling
 * 4. Checks if a parameter (n) is divisible by 6 for periodic calibration checks
 * 
 * The function returns 1 if the value is within bounds AND the parameter is divisible by 6,
 * indicating a valid calibration state, 0 otherwise.
 */

int process_sensor_data(const int numbers[3], int32_t a, int32_t b, int n)
{
    bool within_bounds;
    int32_t half_product;
    int full_product;
    int divisible_by_6;
    int result;
    
    /* Step 1: Check if value is within calibrated bounds */
    within_bounds = func_between(numbers);
    
    /* Step 2: Compute half product for averaging */
    half_product = func_half_product(a, b);
    
    /* Step 3: Compute full product for scaling */
    full_product = func_multiply(a, b);
    
    /* Step 4: Check periodic calibration condition */
    divisible_by_6 = func_is_divisible_by_6(n);
    
    /* Combine results: valid calibration state */
    if (within_bounds && divisible_by_6) {
        result = 1;
    } else {
        result = 0;
    }
    
    return result;
}
