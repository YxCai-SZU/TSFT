#include <stdbool.h>
#include <stdint.h>

/* ====== Original Function 1: Arithmetic progression check ====== */

/*@
    predicate is_decreasing{L}(uint32_t *s, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> s[i] > s[j];

    predicate is_odd{L}(uint32_t *s, integer len) =
        \forall integer i; 0 <= i < len ==> s[i] % 2 != 0;

    predicate has_unique_elements{L}(uint32_t *s, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> s[i] != s[j];
*/

bool func1(uint32_t *a, uint32_t len)
{
    //@ assert len >= 3;
    //@ assert is_decreasing(a, len);
    //@ assert is_odd(a, len);
    //@ assert has_unique_elements(a, len);
    //@ assert a[0] > a[1];
    //@ assert a[1] > a[2];
    //@ assert a[0] % 2 != 0;
    //@ assert a[1] % 2 != 0;
    //@ assert a[2] % 2 != 0;
    //@ assert a[0] != a[1];
    //@ assert a[1] != a[2];
    //@ assert a[0] != a[2];
    
    return (a[0] - a[1] == a[1] - a[2]);
}

/* ====== Original Function 2: Mathematical computation ====== */

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;

    logic integer intermediate(integer a) = a * (1 + a);
    logic integer final_result(integer a) = a * (1 + intermediate(a));

    lemma intermediate_bounds: \forall integer a; a_in_range(a) ==> 1 <= intermediate(a) && intermediate(a) <= 100 * 101;
    lemma final_bounds: \forall integer a; a_in_range(a) ==> 1 <= final_result(a) && final_result(a) <= 100 * (1 + 100 * 101);
*/

int func2(int a)
{
    int result;
    int a_1;

    //@ assert a_in_range(a);
    //@ assert 1 <= 1 + a && 1 + a <= 101;
    //@ assert 1 <= a * (1 + a) && a * (1 + a) <= 100 * 101;
    
    a_1 = a * (1 + a);
    
    //@ assert 1 <= 1 + a_1 && 1 + a_1 <= 1 + 100 * 101;
    //@ assert 1 <= a * (1 + a_1) && a * (1 + a_1) <= 100 * (1 + 100 * 101);
    
    result = a * (1 + a_1);
    return result;
}

/* ====== Original Function 3: Count odd numbers ====== */

/*@ predicate is_valid_range(int n) = 2 <= n && n <= 200000; */

/*@ predicate array_bounds(int64_t* a, int n) = 
      \forall integer i; 0 <= i < n ==> 1 <= a[i] && a[i] <= 1000000000; */

/*@ lemma index_bound: 
      \forall int n; is_valid_range(n) ==> 0 <= n; */

/*@ logic integer count_odd(int64_t* a, integer n, integer idx) = 
      idx == 0 ? 0 : 
      ((a[idx-1] & 1) != 0 ? 1 : 0) + count_odd(a, n, idx-1); */

int func3(int n, int64_t* a) {
    int count = 0;
    int index = 0;
    
    while (index < n) {
        int64_t value = a[index];
        //@ assert 1 <= value <= 1000000000;
        if ((value & 1) != 0) {
            count += 1;
        }
        index += 1;
    }
    return count;
}

/* ====== Original Function 4: Decision function ====== */

/*@
    predicate ans_one(integer x, integer d) = x / 100 >= d;
    predicate ans_zero(integer x, integer d) = x / 100 < d;

    logic integer compute_d(integer x) = (x % 100 + (100 - x % 100) % 5) / 100;
*/

int32_t func4(uint32_t x)
{
    int32_t ans;
    uint32_t d;
    
    d = (x % 100 + (100 - x % 100) % 5) / 100;
    
    //@ assert d == compute_d(x);
    
    if (x / 100 >= d)
    {
        ans = 1;
        //@ assert ans_one(x, d);
    }
    else
    {
        ans = 0;
        //@ assert ans_zero(x, d);
    }
    
    return ans;
}

/* ====== Synthesized Complex Function: Data Quality Assessment ====== */

/*@
    predicate valid_sequence{L}(uint32_t *data, uint32_t len, int64_t *values, int n) =
        len >= 3 && n >= 2 &&
        is_decreasing(data, len) && is_odd(data, len) && has_unique_elements(data, len) &&
        is_valid_range(n) && array_bounds(values, n);
*/

int complex_function(uint32_t *data, uint32_t len, int64_t *values, int n, uint32_t x, int a)
{
    bool is_arithmetic = func1(data, len);
    int computed = func2(a);
    int odd_count = func3(n, values);
    int32_t decision = func4(x);
    
    //@ assert is_arithmetic == (data[0] - data[1] == data[1] - data[2]);
    //@ assert computed == a * (1 + a * (1 + a));
    //@ assert 0 <= odd_count <= n;
    //@ assert decision == 1 || decision == 0;
    
    int result = 0;
    
    if (is_arithmetic && computed >= 100 && odd_count > n/2 && decision == 1)
    {
        result = 1;
    }
    
    //@ assert (result == 1) ==> (is_arithmetic && computed >= 100 && odd_count > n/2 && decision == 1);
    //@ assert (result == 0) ==> (!is_arithmetic || computed < 100 || odd_count <= n/2 || decision == 0);
    
    return result;
}
