#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

/* ========== Original functions (adapted with ACSL) ========== */

/* --- func1: find first index where b[i]==0 and return a[i] --- */
/*@ predicate a_valid(int *a, integer len) =
    len == 5 &&
    \forall integer i; 0 <= i < 5 ==> a[i] == i + 1;
*/
/*@ predicate b_valid(int *b, integer len) =
    len == 5 &&
    \forall integer i; 0 <= i < 5 ==> (b[i] == 0 || b[i] == 1) &&
    \exists integer i; 0 <= i < 5 && b[i] == 0;
*/
/*@ lemma zero_exists: \forall int *b, integer len;
    b_valid(b, len) ==> \exists integer i; 0 <= i < 5 && b[i] == 0;
*/
int func1(int *a, int *b) {
    size_t i;
    i = 0;
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (b[i] == 0) {
            //@ assert b[i] == 0;
            //@ assert a[i] == i + 1;
            //@ assert i + 1 >= 1 && i + 1 <= 5;
            return (int)(a[i]);
        }
        i = i + 1;
    }
    return -1;
}

/* --- func2: multiply two numbers if both <10, else -1 --- */
/*@
    predicate is_small(integer v) = 1 <= v <= 9;
    predicate both_small(integer a, integer b) = is_small(a) && is_small(b);
    logic integer safe_product(integer a, integer b) = a * b;
*/
int func2(int n, int m) {
    int x;
    int y;
    int result;
    x = (n < 10) ? n : -1;
    y = (m < 10) ? m : -1;
    if (x < 0 || y < 0) {
        //@ assert x < 0 || y < 0;
        return -1;
    }
    //@ assert x >= 1 && x <= 9;
    //@ assert y >= 1 && y <= 9;
    //@ assert x * y <= 81;
    result = x * y;
    return result;
}

/* --- func3: check if all elements of arr are divisible by k --- */
/*@ predicate all_divisible(integer n, integer k, int *arr) =
      \forall integer x; 0 <= x < n ==> arr[x] % k == 0;
*/
bool func3(unsigned int n, unsigned int k, int *arr) {
    bool flag = true;
    unsigned int i = 0;
    while (i < n) {
        //@ assert 0 <= i < n;
        if (arr[i] % k != 0) {
            flag = false;
            break;
        }
        i++;
    }
    //@ assert flag == true <==> all_divisible(n, k, arr);
    return flag;
}

/* --- func4: check if two-element vector has equal elements --- */
/*@
    predicate valid_vector(int *v, integer len) =
        len == 2 &&
        \forall integer i; 0 <= i < len ==> v[i] <= 100;
*/
/*@
    predicate elements_equal(int *v) =
        v[0] == v[1];
*/
bool func4(int *v) {
    //@ assert valid_vector(v, 2);
    if (v[0] == v[1]) {
        //@ assert elements_equal(v);
        return true;
    } else {
        //@ assert !elements_equal(v);
        return false;
    }
}

/* ========== Synthesized complex function ========== */

/* Scenario: In a data validation pipeline, we have:
   - an array 'a' with values 1..5,
   - an array 'b' of flags (0/1) with at least one 0,
   - a candidate product pair (n,m) from data fields,
   - a set of divisors 'arr' to validate,
   - a two-element vector 'v' representing a status pair.
   We combine them to produce a final validation code:
   - If func1 returns a value, use it as a multiplier for func2's result.
   - Then check if that product divides all elements of arr.
   - Finally verify that vector v has equal elements as a consistency check.
   The final result is 0 if all checks pass, or -1 if any fails.
*/

int synthesized_func(int *a, int *b, int n, int m, unsigned int n_arr, unsigned int k, int *arr, int *v) {
    int step1 = func1(a, b);
    //@ assert step1 >= 1 && step1 <= 5 && b[step1 - 1] == 0;
    
    int step2 = func2(n, m);
    //@ assert (n < 10 && m < 10 ==> step2 == n * m) && (n >= 10 || m >= 10 ==> step2 == -1);
    
    if (step2 == -1) {
        //@ assert step2 == -1;
        return -1;
    }
    //@ assert step2 >= 1 && step2 <= 81;
    
    int product = step1 * step2;
    //@ assert product >= 1 && product <= 405;
    
    bool divisible = func3(n_arr, (unsigned int)product, arr);
    //@ assert divisible == true <==> all_divisible(n_arr, product, arr);
    
    if (!divisible) {
        //@ assert !divisible;
        return -1;
    }
    //@ assert divisible == true;
    
    bool equal = func4(v);
    //@ assert equal == 1 <==> elements_equal(v);
    
    if (!equal) {
        //@ assert !equal;
        return -1;
    }
    //@ assert equal == true;
    
    /* High-level property: all validation steps passed,
       meaning product > 0, arr divisible by product, and vector elements equal.
       The final result 0 indicates successful validation. */
    //@ assert product > 0 && all_divisible(n_arr, product, arr) && elements_equal(v);
    return 0;
}
