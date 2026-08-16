#include <limits.h>

/*@ predicate is_valid_index(integer idx) = 0 <= idx && idx < 4; */

/*@ predicate value_in_range(integer x) = 1 <= x && x <= 10000; */

/*@ predicate is_valid_array(int *arr) = 
      \valid(arr + (0..3)) &&
      value_in_range(arr[0]) &&
      value_in_range(arr[1]) &&
      value_in_range(arr[2]) &&
      value_in_range(arr[3]); */

/*@ logic integer sum_pair(integer a, integer b) = a + b; */

/*@ lemma sum_bounds: 
      \forall integer a, b; 
      value_in_range(a) && value_in_range(b) ==> 
      2 <= sum_pair(a, b) && sum_pair(a, b) <= 20000; */

/*@ lemma result_candidate: 
      \forall int *arr; 
      is_valid_array(arr) ==> 
      (sum_pair(arr[0], arr[3]) >= 0) &&
      (sum_pair(arr[1], arr[2]) >= 0) &&
      (sum_pair(arr[0], arr[2]) >= 0) &&
      (sum_pair(arr[1], arr[3]) >= 0); */

/*@ requires is_valid_array(v);
    ensures \result >= 0;
    ensures \result == sum_pair(v[0], v[3]) || 
            \result == sum_pair(v[1], v[2]) || 
            \result == sum_pair(v[0], v[2]) || 
            \result == sum_pair(v[1], v[3]);
    assigns \nothing;
 */
int func(int *v)
{
    int answer;
    int tmp1;
    int tmp2;
    int tmp3;
    int tmp4;

    answer = INT_MAX;

    //@ assert answer == INT_MAX;

    tmp1 = v[0] + v[3];
    //@ assert tmp1 == sum_pair(v[0], v[3]);
    //@ assert tmp1 >= 2 && tmp1 <= 20000;
    answer = (answer < tmp1) ? answer : tmp1;
    //@ assert answer == tmp1;

    tmp2 = v[1] + v[2];
    //@ assert tmp2 == sum_pair(v[1], v[2]);
    //@ assert tmp2 >= 2 && tmp2 <= 20000;
    answer = (answer < tmp2) ? answer : tmp2;
    //@ assert answer == tmp1 || answer == tmp2;

    tmp3 = v[0] + v[2];
    //@ assert tmp3 == sum_pair(v[0], v[2]);
    //@ assert tmp3 >= 2 && tmp3 <= 20000;
    answer = (answer < tmp3) ? answer : tmp3;
    //@ assert answer == tmp1 || answer == tmp2 || answer == tmp3;

    tmp4 = v[1] + v[3];
    //@ assert tmp4 == sum_pair(v[1], v[3]);
    //@ assert tmp4 >= 2 && tmp4 <= 20000;
    answer = (answer < tmp4) ? answer : tmp4;
    //@ assert answer == tmp1 || answer == tmp2 || answer == tmp3 || answer == tmp4;

    //@ assert answer >= 0;
    return answer;
}
