#include <stdbool.h>
#include <stddef.h>

/* ACSL predicates from original functions */
/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate is_odd(integer x) = x % 2 == 1;
*/

/*@
    predicate zero_exists(long *x) =
      x[0] == 0 || x[1] == 0 || x[2] == 0 || x[3] == 0 || x[4] == 0;
*/

/*@
    predicate valid_range(integer n) = 1 <= n <= 20;
*/

/*@
    predicate valid_array(int* arr, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= arr[i] <= 50;
*/

/* Original function 1: computes a*b+1 or -1 based on parity */
int func1(unsigned int a, unsigned int b)
{
    unsigned int product;
    bool is_even_bool;
    bool is_odd_bool;
    int result;

    product = a * b;
    is_even_bool = (a % 2 == 0);
    is_odd_bool = (b % 2 == 1);

    if (is_even_bool && is_odd_bool)
    {
        result = -1;
    }
    else
    {
        result = (int)(product + 1);
    }

    return result;
}

/* Original function 2: finds first zero in array of 5 longs */
long func2(long *x)
{
    long ans = -1;
    size_t i = 0;
    
    while (i < 5) {
        if (x[i] == 0) {
            ans = (long)i + 1;
            break;
        }
        i++;
    }
    
    //@ assert ans >= 1 && ans <= 5;
    //@ assert x[ans-1] == 0;
    
    return ans;
}

/* Original function 3: computes sum of positive differences v[i]-c[i] */
int func3(int n, int* v, int* c) {
    int sum = 0;
    size_t i = 0;
    
    //@ assert valid_range(n);
    //@ assert valid_array(v, n);
    //@ assert valid_array(c, n);
    
    while (i < (size_t)n) {
        if (v[i] - c[i] > 0) {
            sum += v[i] - c[i];
        }
        i++;
    }
    
    //@ assert sum >= 0;
    return sum;
}

/* 
 * Synthesized function: "Medical Test Result Processing"
 * 
 * Real-world scenario: A medical lab processes test results. 
 * - func1 determines if a sample pair (a,b) is valid (returns -1) or produces a result code (a*b+1)
 * - func2 finds which test position (1-5) has a zero reading (indicating a control sample)
 * - func3 computes the total positive deviation from expected values
 * 
 * The synthesized function validates that if the test result is valid (not -1), 
 * the total positive deviation sum is non-negative, ensuring data integrity.
 */
int synthesized_func(unsigned int a, unsigned int b, long *x, int n, int* v, int* c)
{
    int result1 = func1(a, b);
    long result2 = func2(x);
    int result3 = func3(n, v, c);
    
    //@ assert result2 >= 1 && result2 <= 5;
    //@ assert x[result2-1] == 0;
    
    //@ assert result3 >= 0;
    
    return result3;
}
