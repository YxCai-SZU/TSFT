#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(int *arr, integer len) =
        len >= 3 && len <= 10 &&
        \forall integer i; 0 <= i < len ==> 1 <= *(arr + i) <= 100;

    predicate is_arithmetic_progression(int *arr) =
        *(arr + 1) - *(arr + 0) == *(arr + 2) - *(arr + 1);

    predicate in_range(integer x) = 1 <= x <= 9;
    
    logic integer absolute(integer x) = x < 0 ? -x : x;
    
    lemma remainder_preserved:
        \forall integer x; x >= 4 ==> (x - 4) % 4 == x % 4;
*/

bool check_arithmetic_progression(int *arr, size_t len) {
    bool result;

    //@ assert valid_array(arr, len);
    //@ assert len >= 3 && len <= 10;
    //@ assert \forall integer i; 0 <= i < len ==> 1 <= *(arr + i) <= 100;

    result = (*(arr + 1) - *(arr + 0) == *(arr + 2) - *(arr + 1));
    return result;
}

bool check_color_divisible_by_4(int r, int g, int b) {
    int sum;
    bool is_divisible_by_4;
    int remainder;
    
    sum = r * 100 + g * 10 + b;
    is_divisible_by_4 = false;
    //@ assert sum == r * 100 + g * 10 + b;
    
    remainder = sum >= 0 ? sum : -sum;
    //@ assert remainder == absolute(sum);
    
    while (remainder >= 4) {
        remainder -= 4;
    }
    
    if (remainder == 0) {
        is_divisible_by_4 = true;
    }
    
    //@ assert is_divisible_by_4 == (absolute(sum) % 4 == 0);
    //@ assert absolute(sum) % 4 == sum % 4;
    return is_divisible_by_4;
}

/*@
    predicate color_is_valid(int *arr, int r, int g, int b) =
        valid_array(arr, 3) && in_range(r) && in_range(g) && in_range(b) &&
        is_arithmetic_progression(arr);

    predicate pattern_matches(int *arr, int r, int g, int b) =
        (*(arr + 0) == r && *(arr + 1) == g && *(arr + 2) == b) ||
        (is_arithmetic_progression(arr) && 
         ((r * 100 + g * 10 + b) % 4 == 0));
*/

bool validate_color_pattern(int *arr, int r, int g, int b) {
    bool is_arithmetic;
    bool is_divisible;
    bool result;

    is_arithmetic = check_arithmetic_progression(arr, 3);

    is_divisible = check_color_divisible_by_4(r, g, b);

    if (*(arr + 0) == r && *(arr + 1) == g && *(arr + 2) == b) {
        result = true;
    } else {
        result = is_arithmetic && is_divisible;
    }

    //@ assert result == true <==> pattern_matches(arr, r, g, b);
    return result;
}
