#include <stdbool.h>
#include <stddef.h>

/* --- Underlying function 1 (adapted from snippet 1) --- */
/*@ predicate is_at_least_ten_elements(integer len) = len >= 10; */
bool is_within_range(int n, int min, int max) {
    //@ assert min <= max;
    return n >= min && n <= max;
}

/* --- Underlying function 2 (adapted from snippet 2) --- */
/*@ predicate is_valid_range(int* a, integer len) =
      len == 5 &&
      \forall integer i; 0 <= i < len ==> 0 <= a[i] <= 123 &&
      a[0] < a[1] && a[1] < a[2] && a[2] < a[3] && a[3] < a[4];
*/
/*@ predicate result_condition_func2(int* a, integer k) =
      a[4] - a[0] <= k;
*/
bool func2(int* a, int k) {
    int v[5];
    int i = 0;
    while (i < 5) {
        v[i] = a[i];
        i = i + 1;
    }
    //@ assert v[0] == a[0] && v[1] == a[1] && v[2] == a[2] && v[3] == a[3] && v[4] == a[4];
    int m = v[4] - v[0];
    //@ assert m == a[4] - a[0];
    return m <= k;
}

/* --- Underlying function 3 (adapted from snippet 3) --- */
/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate result_condition_func3(integer a, integer b, bool result) =
        result == ((a * a >= 2 * b && a * a % 2 == 0) || (b * b >= 2 * a && b * b % 2 == 0));
*/
bool func3(unsigned long long a, unsigned long long b) {
    unsigned long long a_square;
    unsigned long long b_square;
    bool a_condition;
    bool b_condition;
    bool result;
    //@ assert a * a <= 10000;
    //@ assert b * b <= 10000;
    a_square = a * a;
    b_square = b * b;
    a_condition = (a_square >= 2 * b) && (a_square % 2 == 0);
    b_condition = (b_square >= 2 * a) && (b_square % 2 == 0);
    result = a_condition || b_condition;
    return result;
}

/* --- Underlying function 4 (adapted from snippet 4) --- */
/*@ predicate valid_index_range(integer i) = 0 <= i < 3;
    predicate valid_number_value(integer v) = 1 <= v <= 13;
    predicate numbers_valid(int *arr, integer len) =
        len >= 3 &&
        \forall integer i; 0 <= i < 3 ==> valid_number_value(arr[i]);
    logic integer element_at(int *arr, integer i) = arr[i];
    logic integer partial_sum(int *arr, integer i) =
        i == 0 ? 0 :
        i == 1 ? element_at(arr, 0) :
        i == 2 ? element_at(arr, 0) + element_at(arr, 1) :
        element_at(arr, 0) + element_at(arr, 1) + element_at(arr, 2);
    lemma partial_sum_bounds: \forall int *arr, integer i;
        numbers_valid(arr, 3) && 0 <= i <= 3 ==> 0 <= partial_sum(arr, i) <= i * 13;
    lemma partial_sum_monotonic: \forall int *arr, integer i, integer j;
        numbers_valid(arr, 3) && 0 <= i <= j <= 3 ==> partial_sum(arr, i) <= partial_sum(arr, j);
*/
bool func4(const int *numbers) {
    bool answer = false;
    int sum = 0;
    int i = 0;
    while (i < 3) {
        //@ assert valid_index_range(i);
        sum += numbers[i];
        i++;
    }
    //@ assert sum == partial_sum(numbers, 3);
    if (sum >= 22) {
        answer = true;
    }
    return answer;
}

/* --- Synthesized complex function: validate_triangle_data ---
   Real-world scenario: In a geometry processing system, we validate triangle data.
   Input: an array 'data' of 5 integers representing triangle side lengths (first 3) plus two scores (last 2).
   Steps:
   1. Check data length >= 10 (using is_within_range on length).
   2. Validate the first 5 elements form a valid sorted range (using func2).
   3. Compute a quality metric from the first 3 values (using func4) and a score from the last 2 (using func3).
   4. Combine results to determine if data is valid.
   The final assertion: if the function returns true, then the sum of the first 3 elements is >= 22 and the range of the first 5 elements' max-min <= 100.
*/
bool validate_triangle_data(int* data, int len) {
    bool step1, step2, step3, step4, final_result;

    //@ assert 10 <= len;
    step1 = is_within_range(len, 10, len);
    //@ assert step1 == (len >= 10 && len <= len);
    //@ assert step1 == (len >= 10);

    step2 = func2(data, 100);
    //@ assert step2 == (data[4] - data[0] <= 100);

    step3 = func4(data);
    //@ assert step3 == (data[0] + data[1] + data[2] >= 22);

    step4 = func3(data[3], data[4]);

    final_result = step1 && step2 && step3 && step4;

    //@ assert final_result ==> (data[0] + data[1] + data[2] >= 22 && data[4] - data[0] <= 100);

    return final_result;
}
