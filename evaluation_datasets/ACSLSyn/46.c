#include <stdbool.h>

/*@ predicate is_valid_range(integer x) = 1 <= x <= 9; */
/*@ logic integer compute_sum(integer a, integer b, integer c) = 
      a * 100 + b * 10 + c; */
/*@ lemma sum_nonnegative: 
      \forall integer a, b, c; 
      is_valid_range(a) && is_valid_range(b) && is_valid_range(c) ==> 
      compute_sum(a, b, c) >= 0; */
bool check_list(int lst[3]) {
    int sum;
    bool is_divisible;
    int abs_sum;
    int remainder;
    
    sum = lst[0] * 100 + lst[1] * 10 + lst[2];
    is_divisible = false;
    abs_sum = sum;
    
    //@ assert compute_sum(lst[0], lst[1], lst[2]) == sum;
    
    if (sum < 0) {
        abs_sum = -sum;
    }
    
    //@ assert abs_sum >= 0;
    
    remainder = abs_sum;
    
    while (remainder >= 4) {
        remainder -= 4;
    }
    
    if (remainder == 0) {
        is_divisible = true;
    }
    
    //@ assert is_divisible == (abs_sum % 4 == 0);
    //@ assert abs_sum % 4 == sum % 4;
    
    return is_divisible;
}

/*@ predicate in_range(integer n, integer m, integer k) =
        1 <= n && n <= 100000 &&
        1 <= m && m <= 100000 &&
        0 <= k && k <= n; */
/*@ predicate condition_holds(integer n, integer m, integer k) =
        (n - k) <= m && m <= n; */
/*@ lemma equivalence:
        \forall integer n, m, k;
        condition_holds(n, m, k) <==> (n - k) <= m <= n; */
bool range_check(unsigned int n, unsigned int m, unsigned int k)
{
    //@ assert condition_holds(n, m, k) <==> (n - k) <= m && m <= n;
    
    if ((n - k) <= m && m <= n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*@ predicate valid_vector(int *v) =
      \valid(v + (0..5)) &&
      1 <= v[0] <= 1000000000 &&
      1 <= v[1] <= 1000000000 &&
      1 <= v[2] <= 1000000000 &&
      1 <= v[3] <= 1000000000 &&
      1 <= v[4] <= 1000000000 &&
      1 <= v[5] <= 1000000000; */
/*@ predicate vector_condition_holds(int *v) =
      v[1] <= v[0] && v[3] <= v[2] && v[5] <= v[4]; */
/*@ lemma vector_length:
      \forall int *v; valid_vector(v) ==> \valid(v + (0..5)); */
bool vector_check(int *v) {
    //@ assert valid_vector(v);
    
    if (v[1] > v[0] || v[3] > v[2] || v[5] > v[4]) {
        return false;
    } else {
        return true;
    }
}

/*@ predicate valid_student_data(int *id_digits, int *credits, unsigned int n, unsigned int m, unsigned int k) =
      \valid(id_digits + (0..2)) &&
      is_valid_range(id_digits[0]) && is_valid_range(id_digits[1]) && is_valid_range(id_digits[2]) &&
      valid_vector(credits) &&
      in_range(n, m, k); */
/*@ predicate student_data_valid(int *id_digits, int *credits, unsigned int n, unsigned int m, unsigned int k) =
      compute_sum(id_digits[0], id_digits[1], id_digits[2]) % 4 == 0 &&
      (n - k) <= m && m <= n &&
      credits[1] <= credits[0] && credits[3] <= credits[2] && credits[5] <= credits[4]; */
bool validate_student_card(int *id_digits, int *credits, unsigned int n, unsigned int m, unsigned int k) {
    bool id_valid = check_list(id_digits);
    bool range_valid = range_check(n, m, k);
    bool vector_valid = vector_check(credits);
    
    bool result = id_valid && range_valid && vector_valid;
    
    //@ assert result == true <==> (compute_sum(id_digits[0], id_digits[1], id_digits[2]) % 4 == 0 && condition_holds(n, m, k) && vector_condition_holds(credits));
    
    return result;
}

int main() {
    return 0;
}
