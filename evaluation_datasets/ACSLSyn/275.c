#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

/* ========== First underlying function (from snippet 1) ========== */
/*@
    predicate r_in_range(integer r) = 1 <= r <= 100;
    
    logic integer expected_result(integer r) = 3 * r * r;
    
    lemma no_overflow_lemma:
        \forall integer r; r_in_range(r) ==> 3 * r * r <= 3 * 100 * 100;
*/

int func1(int r) {
    int result;
    
    //@ assert r_in_range(r);
    //@ assert 3 * r <= 300;
    
    result = 3 * r * r;
    
    if (result > INT_MAX) {
        //@ assert result > INT_MAX;
        return INT_MAX;
    } else {
        //@ assert result <= INT_MAX;
        return result;
    }
}

/* ========== Second underlying function (from snippet 2) ========== */
/*@
    predicate sorted(int *arr, integer len) =
        len == 3 ==> arr[0] < arr[1] && arr[1] < arr[2];

    logic integer plus_two(integer b) = b + 2;

    lemma calc_example_8: \forall integer a, b; a < b ==> a < plus_two(b);
    lemma greater_than_ten: \forall integer a; a > 10 ==> a > 10;
    lemma is_sorted: \forall int *arr, integer len; len == 3 && arr[0] < arr[1] && arr[1] < arr[2] ==> sorted(arr, len);
*/

bool calc_example_8_impl(int a, int b) {
    //@ assert a < b;
    //@ assert a < b + 1;
    //@ assert a < b + 2;
    return true;
}

bool greater_than_ten_impl(int a) {
    //@ assert a > 10;
    return true;
}

bool is_sorted_impl(int *arr) {
    //@ assert arr[0] < arr[1] && arr[1] < arr[2];
    return true;
}

/* ========== Third underlying function (from snippet 3) ========== */
/*@
    predicate valid_numbers(unsigned int *arr, integer len) =
        len == 2 &&
        \forall integer i; 0 <= i < len ==> arr[i] <= 1000000000;

    logic integer array_len(unsigned int *arr) = 2;

    logic integer array_access(unsigned int *arr, integer i) = arr[i];

    lemma ans_bounds:
        \forall unsigned int a, b;
        (a <= 1000000000 && b <= 1000000000) ==>
        (a <= b ==> (integer)(b - a) >= 0 && (integer)(b - a) <= 1000000000) &&
        (a > b ==> -1 >= -1 && -1 <= 1000000000);
*/

int func2(unsigned int *numbers)
{
    int ans;
    unsigned int a;
    unsigned int b;

    ans = -1;
    //@ assert valid_numbers(numbers, 2);
    a = numbers[0];
    b = numbers[1];

    if (a <= b)
    {
        ans = (int)(b - a);
        //@ assert ans >= 0 && ans <= 1000000000;
        //@ assert numbers[0] <= numbers[1];
        //@ assert ans == (int)(numbers[1] - numbers[0]);
    }
    else
    {
        //@ assert numbers[0] > numbers[1];
        //@ assert ans == -1;
    }

    return ans;
}

/* ========== Synthesized complex function ========== */
/* Scenario: Compute a transformation score for a data array.
   Data flow:
   1. func1 computes a base score from a parameter r (e.g., a quality metric).
   2. The base score is used to validate ordering properties via calc_example_8_impl and greater_than_ten_impl.
   3. func2 computes a difference-based adjustment from an unsigned int array.
   4. The final score is the sum of the base result and the adjustment, and we assert that the output
      satisfies a high-level property: the final score is non-negative and bounded by a reasonable maximum.
*/

int synthesize_function(int r, unsigned int *numbers) {
    int base_score;
    int adjustment;
    int final_score;
    
    base_score = func1(r);
    //@ assert base_score == expected_result(r);
    //@ assert base_score <= INT_MAX;
    
    if (base_score > 10) {
        //@ assert base_score > 10;
        bool check1 = greater_than_ten_impl(base_score);
        //@ assert check1 == true;
        
        int arr[3];
        arr[0] = base_score - 2;
        arr[1] = base_score - 1;
        arr[2] = base_score;
        //@ assert arr[0] < arr[1] && arr[1] < arr[2];
        
        bool check2 = is_sorted_impl(arr);
        //@ assert check2 == true;
        
        bool check3 = calc_example_8_impl(arr[0], arr[2]);
        //@ assert check3 == true;
    }
    
    adjustment = func2(numbers);
    //@ assert adjustment >= -1;
    //@ assert adjustment <= 1000000000;
    
    final_score = base_score + adjustment;
    
    //@ assert final_score >= -1 && final_score <= 1010000000;
    
    return final_score;
}
