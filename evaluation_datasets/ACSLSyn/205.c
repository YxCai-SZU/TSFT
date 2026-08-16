/* Scenario: Student Exam Score Filter Processor
 * 
 * The system processes exam score entries from a class of students.
 * Each entry contains a student ID (1-10000) and four test scores (each 1-10000).
 * The processor first extracts the last two digits of the student ID to determine
 * the student's group number, then filters the test scores to find the maximum
 * sum of any two scores, but only if the group number passes a threshold check
 * (group number * 21 >= 100, i.e., group number >= 5, since 5*21=105 >= 100).
 * If the group check fails, the function returns the maximum sum directly.
 */

#include <stdbool.h>
#include <stdint.h>

/*@
    predicate is_in_range(integer n) = 1 <= n <= 10000;
    
    logic integer div_100(integer n) = n / 100;
    logic integer mod_100(integer n) = n % 100;
    
    lemma div_mod_property:
        \forall integer n;
            is_in_range(n) ==>
            n == div_100(n) * 100 + mod_100(n) && 0 <= mod_100(n) < 100;
*/

bool func(int n)
{
    int n_div_100;
    int n_mod_100;
    int quotient = 0;
    int remainder = n;
    int n_div_100_direct;
    int n_mod_100_direct;
    int v;
    bool result;
    
    n_div_100 = n / 100;
    n_mod_100 = n % 100;
    
    while (remainder >= 100)
    {
        quotient = quotient + 1;
        remainder = remainder - 100;
    }
    
    n_div_100_direct = quotient;
    n_mod_100_direct = remainder;
    
    //@ assert n_div_100_direct == div_100(n);
    //@ assert n_mod_100_direct == mod_100(n);
    
    v = n_mod_100_direct * 21;
    result = v >= 100;
    
    return result;
}

#include <stdint.h>

/*@
    predicate is_valid_array(int64_t* arr, integer len) =
        len == 4 &&
        \valid(arr + (0 .. len-1)) &&
        arr[0] >= 1 && arr[0] <= 10000 &&
        arr[1] >= 1 && arr[1] <= 10000 &&
        arr[2] >= 1 && arr[2] <= 10000 &&
        arr[3] >= 1 && arr[3] <= 10000;

    logic integer sum_of_two(integer a, integer b) = a + b;

    lemma result_is_sum_of_two:
        \forall integer v0, v1, v2, v3, res;
        (v0 >= 1 && v0 <= 10000 && v1 >= 1 && v1 <= 10000 &&
         v2 >= 1 && v2 <= 10000 && v3 >= 1 && v3 <= 10000 &&
         (res == sum_of_two(v0, v1) || res == sum_of_two(v0, v2) ||
          res == sum_of_two(v0, v3) || res == sum_of_two(v1, v2) ||
          res == sum_of_two(v1, v3) || res == sum_of_two(v2, v3))) ==>
        res >= 0;
*/

int64_t func2(int64_t* v)
{
    int64_t res;

    //@ assert v[0] >= 1 && v[0] <= 10000;
    //@ assert v[1] >= 1 && v[1] <= 10000;
    //@ assert v[2] >= 1 && v[2] <= 10000;
    //@ assert v[3] >= 1 && v[3] <= 10000;

    res = v[0] + v[1];

    if (res < v[0] + v[2]) {
        res = v[0] + v[2];
    }
    //@ assert res == v[0] + v[1] || res == v[0] + v[2];

    if (res < v[0] + v[3]) {
        res = v[0] + v[3];
    }
    //@ assert res == v[0] + v[1] || res == v[0] + v[2] || res == v[0] + v[3];

    if (res < v[1] + v[2]) {
        res = v[1] + v[2];
    }
    //@ assert res == v[0] + v[1] || res == v[0] + v[2] || res == v[0] + v[3] || res == v[1] + v[2];

    if (res < v[1] + v[3]) {
        res = v[1] + v[3];
    }
    //@ assert res == v[0] + v[1] || res == v[0] + v[2] || res == v[0] + v[3] || res == v[1] + v[2] || res == v[1] + v[3];

    if (res < v[2] + v[3]) {
        res = v[2] + v[3];
    }
    //@ assert res == v[0] + v[1] || res == v[0] + v[2] || res == v[0] + v[3] || res == v[1] + v[2] || res == v[1] + v[3] || res == v[2] + v[3];

    //@ assert res >= 0;
    return res;
}

int64_t process_student_entry(int student_id, int64_t* scores)
{
    bool group_pass;
    int64_t max_sum;

    //@ assert is_in_range(student_id);
    //@ assert is_valid_array(scores, 4);

    group_pass = func(student_id);

    max_sum = func2(scores);

    /*@
        assert (group_pass == (mod_100(student_id) * 21 >= 100)) &&
               (max_sum == scores[0] + scores[1] || max_sum == scores[0] + scores[2] ||
                max_sum == scores[0] + scores[3] || max_sum == scores[1] + scores[2] ||
                max_sum == scores[1] + scores[3] || max_sum == scores[2] + scores[3]);
    */

    return max_sum;
}
