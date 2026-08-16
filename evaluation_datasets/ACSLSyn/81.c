#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* First function: determines the third value given two distinct values from {1,2,3} */
/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 3 && 1 <= b <= 3 && a != b;

    logic integer compute_result(integer a, integer b) = 6 - a - b;

    lemma result_bounds:
        \forall integer a, b;
            valid_range(a, b) ==>
                1 <= compute_result(a, b) <= 3;

    lemma sum_equation:
        \forall integer a, b;
            valid_range(a, b) ==>
                compute_result(a, b) + a + b == 6;
*/

int64_t func1(int64_t a, int64_t b)
{
    //@ assert 1 <= a + b <= 6;
    int64_t result = 6 - a - b;
    //@ assert result >= 1;
    //@ assert result <= 3;
    return result;
}

/* Second function: counts monotonic triples in an array */
/*@ predicate is_valid_index(integer i, integer n) = 0 <= i < n; */
/*@ predicate is_valid_value(integer v) = 0 < v <= 1000000000; */
/*@ predicate is_triple_monotonic(integer a, integer b, integer c) = 
      (a < b && b < c) || (a > b && b > c); */

/*@ lemma count_bounds: \forall integer i, integer n, integer count;
      0 <= i <= n && 0 <= count <= i ==> 0 <= count <= n; */

size_t func2(size_t n, const size_t a[]) {
    size_t count = 0;
    size_t i = 0;
    
    while (i < n) {
        //@ assert \forall integer j; 0 <= j < n ==> is_valid_value(a[j]);
        
        if (i + 1 < n && i + 2 < n) {
            size_t a1 = a[i];
            size_t a2 = a[i + 1];
            size_t a3 = a[i + 2];
            
            //@ assert is_valid_value(a1) && is_valid_value(a2) && is_valid_value(a3);
            
            if ((a1 < a2 && a2 < a3) || (a1 > a2 && a2 > a3)) {
                count += 1;
                //@ assert 0 <= count <= i+1;
            }
        }
        i += 1;
        //@ assert 0 <= count <= i;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}

/* Synthesized function: 
   Scenario: In a game state validation system, given an array of size values (each from {1,2,3}) and
   a separate array of token values, we count how many monotonic triples in the token array correspond to
   valid game moves (where the third size value completes the set {1,2,3}).
   
   The function takes:
   - n: number of elements in both arrays (must be same)
   - size_arr: array of size values (each 1, 2, or 3)
   - token_arr: array of token values (each positive <= 1e9)
   
   It counts monotonic triples in token_arr where the corresponding size values in size_arr
   at the same positions form a valid triplet (i.e., the third size value completes the set {1,2,3}).
   
   The high-level property: the count is bounded by the number of valid triples, which is at most n.
*/

size_t synthesized_func(size_t n, const int64_t size_arr[], const size_t token_arr[]) {
    size_t valid_move_count = 0;
    size_t i = 0;
    
    while (i < n) {
        if (i + 1 < n && i + 2 < n) {
            int64_t s1 = size_arr[i];
            int64_t s2 = size_arr[i+1];
            int64_t s3 = size_arr[i+2];
            size_t t1 = token_arr[i];
            size_t t2 = token_arr[i+1];
            size_t t3 = token_arr[i+2];
            
            //@ assert 1 <= s1 <= 3 && 1 <= s2 <= 3 && 1 <= s3 <= 3;
            //@ assert is_valid_value(t1) && is_valid_value(t2) && is_valid_value(t3);
            
            if ((t1 < t2 && t2 < t3) || (t1 > t2 && t2 > t3)) {
                if (s1 != s2 && s1 != s3 && s2 != s3) {
                    int64_t expected = func1(s1, s2);
                    //@ assert expected == s3;
                    //@ assert expected + s1 + s2 == 6;
                    valid_move_count++;
                    //@ assert 0 <= valid_move_count <= i+1;
                }
            }
        }
        i++;
        //@ assert 0 <= valid_move_count <= i;
    }
    
    //@ assert 0 <= valid_move_count <= n;
    return valid_move_count;
}
