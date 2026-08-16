#include <stdbool.h>
#include <stddef.h>

/*@ predicate in_range(integer v, integer low, integer high) =
      low <= v && v <= high;
*/

bool func1(unsigned long a, unsigned long b, unsigned long x)
{
    unsigned long min;
    unsigned long max;
    bool result;

    min = b;
    max = a + b;

    //@ assert min == b;
    //@ assert max == a + b;

    result = (x >= min) && (x <= max);
    return result;
}

/*@
    logic integer triangle_number(integer n) = (n * (n + 1)) / 2;

    lemma test_triangle_number:
        triangle_number(1) == 1 &&
        triangle_number(2) == 3 &&
        triangle_number(3) == 6 &&
        triangle_number(10) == 55;

    lemma triangle_number_uninterpreted:
        \forall integer i; 0 <= i && i <= 10 ==> triangle_number(i) == (i * (i + 1)) / 2;
*/

int func2() {
    int result;
    
    //@ assert triangle_number(10) == 55;
    result = (10 * (10 + 1)) / 2;
    
    return result;
}

/*@ predicate valid_range(integer a, integer b, integer c) =
      1 <= a <= 100 &&
      1 <= b <= 100 &&
      1 <= c <= 200;
*/

/*@ predicate result_condition(integer a, integer b, integer c) =
      a <= c && a + b >= c;
*/

bool func3(const unsigned int abc[3])
{
    bool result;

    //@ assert 1 <= abc[0] <= 100;
    //@ assert 1 <= abc[1] <= 100;
    //@ assert 1 <= abc[2] <= 200;

    result = abc[0] <= abc[2] && abc[0] + abc[1] >= abc[2];
    return result;
}

/*@ predicate is_palindrome(size_t len, int *s) =
      \forall integer i; 0 <= i < len / 2 ==> s[i] == s[(int)len - 1 - i];
*/

/*@ predicate is_all_even(size_t len, int *s) =
      \forall integer i; 0 <= i < len ==> s[i] % 2 == 0;
*/

/*@ predicate is_all_odd(size_t len, int *s) =
      \forall integer i; 0 <= i < len ==> s[i] % 2 != 0;
*/

/*@ predicate has_at_least_one_even(size_t len, int *s) =
      \exists integer i; 0 <= i < len && s[i] % 2 == 0;
*/

/*@ predicate has_at_least_one_odd(size_t len, int *s) =
      \exists integer i; 0 <= i < len && s[i] % 2 != 0;
*/

/*@ predicate is_sorted(size_t len, int *s) =
      \forall integer i, j; 0 <= i <= j < len ==> s[i] <= s[j];
*/

/*@ predicate has_no_consecutive_repeats(size_t len, int *s) =
      \forall integer i; 0 <= i < len - 1 ==> s[i] != s[i + 1];
*/

/*@ predicate is_range_sorted(size_t len, int *s) =
      \forall integer i; 0 <= i < len ==> 1 <= s[i] && s[i] <= 9;
*/

/*@ predicate has_sum_of_nine(size_t len, int *s) =
      \exists integer i, j; 0 <= i < j < len && s[i] + s[j] == 9;
*/


bool func4(size_t len, const int v[])
{
    bool has_even = false;
    bool has_odd = false;
    size_t i = 0;
    
    while (i < len) {
        if (v[i] % 2 == 0) {
            has_even = true;
            //@ assert has_even ==> \exists integer j; 0 <= j < i+1 && v[j] % 2 == 0;
        } else {
            has_odd = true;
            //@ assert has_odd ==> \exists integer j; 0 <= j < i+1 && v[j] % 2 != 0;
        }
        
        //@ assert \forall integer j; 0 <= j < i+1 ==> (v[j] % 2 == 0 ==> has_even);
        //@ assert \forall integer j; 0 <= j < i+1 ==> (v[j] % 2 != 0 ==> has_odd);
        
        i++;
    }
    
    //@ assert has_even && has_odd ==> has_at_least_one_even(len, v);
    //@ assert has_even && has_odd ==> has_at_least_one_odd(len, v);
    
    return has_even && has_odd;
}

/*@
  predicate valid_data_set(integer a, integer b, integer c, size_t len, int *v) =
    valid_range(a, b, c) && len > 0 && \valid(v + (0..len-1)) &&
    \forall integer i; 0 <= i < len ==> 1 <= v[i] && v[i] <= 9;
*/

bool validate_game_state(const unsigned int abc[3], size_t len, const int v[])
{
    bool range_result = func3(abc);
    
    bool parity_result = false;
    if (range_result) {
        parity_result = func4(len, v);
    }
    
    int triangle = func2();
    
    unsigned long a = (unsigned long)abc[0];
    unsigned long b = (unsigned long)abc[1];
    unsigned long c = (unsigned long)abc[2];
    
    bool final_check = false;
    if (range_result && parity_result) {
        final_check = func1(a, b, c);
    }
    
    //@ assert final_check ==> (result_condition(abc[0], abc[1], abc[2]) && has_at_least_one_even(len, v) && has_at_least_one_odd(len, v));
    
    return final_check;
}
