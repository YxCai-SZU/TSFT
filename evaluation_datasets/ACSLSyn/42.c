#include <stdint.h>
#include <stdbool.h>

/* ====== Function 1: Square calculation (as given) ====== */
/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    predicate result_in_range(integer r, integer result) = result == r * r;
*/

int32_t square_func(int32_t r)
{
    //@ assert 1 <= r && r <= 100;
    //@ assert 1 <= r * r && r * r <= 10000;
    return r * r;
}

/* ====== Function 2: Weighted average check (adapted) ====== */
/*@ predicate is_valid_range(integer a) = 0 <= a && a <= 100; */

/*@ logic integer weighted_sum(integer a, integer b) = a * 3 + b; */

/*@ lemma avg_calculation: 
      \forall integer a, b; 
      is_valid_range(a) && is_valid_range(b) ==> 
      weighted_sum(a, b) / 2 == (a * 3 + b) / 2; */

bool avg_check_func(int v[2])
{
    int sum;
    int avg;
    
    //@ assert is_valid_range(v[0]);
    //@ assert is_valid_range(v[1]);
    
    sum = v[0] * 3 + v[1];
    //@ assert sum == weighted_sum(v[0], v[1]);
    
    avg = sum / 2;
    //@ assert avg == weighted_sum(v[0], v[1]) / 2;
    
    return avg >= 40;
}

/* ====== Function 3: Accumulation (adapted as a helper) ====== */
/*@ logic integer multiply(integer x, integer y) = x * y; */

/*@ lemma check_multiply: multiply(4, 5) == multiply(5, 4); */

/*@ logic integer sum(integer x, integer y) = x + y; */

/*@ lemma check_sum: sum(4, 5) == sum(5, 4); */

/*@ lemma verify_complex_logic: 
      multiply(4, 5) == 20 && 
      multiply(5, 4) == 20 && 
      sum(4, 5) == 9 && 
      sum(5, 4) == 9; */

int accumulate_func(int n)
{
    int i;
    int total;
    
    total = 0;
    
    for (i = 0; i < n; i++) {
        total = total + 1;
        //@ assert total == i + 1;
    }
    
    //@ assert total == n;
    //@ assert multiply(total, 2) == 2 * n;
    
    return total;
}

/* ====== Synthesized Complex Function ====== */

bool process_data(int32_t r, int v[2])
{
    int32_t squared;
    bool avg_result;
    int accumulated;
    int combined_array[2];
    
    squared = square_func(r);
    //@ assert squared == r * r;
    
    accumulated = accumulate_func(r);
    //@ assert accumulated == r;
    
    combined_array[0] = (int)squared;  // squared is 1..100
    combined_array[1] = v[1];
    
    //@ assert combined_array[0] >= 1 && combined_array[0] <= 100;
    //@ assert combined_array[1] >= 0 && combined_array[1] <= 100;
    
    avg_result = avg_check_func(combined_array);
    
    //@ assert avg_result == ((squared * 3 + v[1]) / 2 >= 40);
    
    //@ assert (avg_result == ((r * r * 3 + v[1]) / 2 >= 40)) && (accumulated == r);
    
    return avg_result;
}
