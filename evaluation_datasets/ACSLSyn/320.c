#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/* ====== First snippet: func (sum of min(diff, b[i])) ====== */

/*@ predicate valid_array(int64_t* arr, integer n) =
        \forall integer i; 0 <= i < n ==> 1 <= arr[i] <= 50;
*/

/*@ predicate a_max_property(int64_t* a, integer n, integer i, int64_t a_max) =
        \forall integer k; 0 <= k < i ==> a_max >= a[k];
*/

int64_t func1(int64_t n, int64_t* a, int64_t* b) {
    int64_t a_max;
    size_t i;
    int64_t sum;

    a_max = a[0];
    i = 1;

    while (i < (size_t)n) {
        //@ assert 0 <= i < n;
        if (a[i] > a_max) {
            a_max = a[i];
        }
        i++;
    }

    sum = 0;
    i = 0;

    while (i < (size_t)n) {
        int64_t diff;
        //@ assert 0 <= i < n;
        diff = a_max - a[i];
        if (diff < b[i]) {
            sum += diff;
        } else {
            sum += b[i];
        }
        i++;
    }

    return sum;
}

/* ====== Second snippet: is_even and func2 (result >= 0, bounded) ====== */

/*@
    predicate is_even_prop(integer x, bool result) =
        x >= 0 ==> result == (x % 2 == 0);
*/

bool is_even(int x)
{
    bool is_result = false;
    int temp = x;

    while (temp >= 2)
    {
        temp = temp - 2;
    }

    if (temp == 0)
    {
        is_result = true;
    }

    //@ assert is_even_prop(x, is_result);
    return is_result;
}

int func2(int A, int B)
{
    //@ assert 1 <= A - 1 <= 99;
    //@ assert 1 <= B - 1 <= 99;
    //@ assert (A - 1) * (B - 1) <= 99 * 99;

    int result = (A - 1) * (B - 1);
    int temp = result;

    while (temp >= 2)
    {
        temp = temp - 2;
    }

    if (temp == 0)
    {
        result = result - 2;
    }

    if (result < 0)
    {
        result = 0;
    }

    //@ assert result >= 0;
    //@ assert (A - 1) * (B - 1) >= result;
    return result;
}

/* ====== Third snippet: func3 (validates array size condition) ====== */

/*@ predicate valid_array_size(size_t n, unsigned long long *a) =
    n >= 2 && n <= 100000 &&
    \valid(a + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 1000000000;
*/

/*@ predicate result_condition(size_t n) = n == 1 || n > 2; */

bool func3(size_t n, const unsigned long long *a) {
    bool result;
    
    if (n == 1) {
        //@ assert result_condition(n);
        result = true;
    } else {
        //@ assert n > 1;
        result = (n > 2);
    }
    
    return result;
}

/* ====== Synthesized Complex Function ====== */

int64_t complex_function(int64_t n, int64_t* a, int64_t* b, int A, int B) {
    int64_t sum1 = func1(n, a, b);
    
    int result2 = func2(A, B);
    
    int64_t final_result;
    if ((int64_t)result2 >= sum1) {
        final_result = sum1;
    } else {
        final_result = (int64_t)result2;
    }
    
    //@ assert final_result >= 0 && (A - 1) * (B - 1) >= final_result;
    return final_result;
}
