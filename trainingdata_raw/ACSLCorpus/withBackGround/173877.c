#include <stdbool.h>

/*@ predicate all_positive(integer len, int *arr) =
      \forall integer i; 0 <= i < len ==> arr[i] > 0;
*/

/*@ predicate all_less_than_100(integer len, int *arr) =
      \forall integer i; 0 <= i < len ==> arr[i] < 100;
*/

/*@ lemma both_conditions:
      \forall integer len, int *arr;
      all_positive(len, arr) && all_less_than_100(len, arr) ==>
      (\forall integer i; 0 <= i < len ==> arr[i] > 0 && arr[i] < 100);
*/

/*@ requires \valid(v+(0..4)) &&
             all_positive(5, v) && all_less_than_100(5, v);
    ensures \result == true;
*/
bool test_func(int v[5])
{
    /*@ assert v[0] > 0 && v[0] < 100; */
    /*@ assert v[1] > 0 && v[1] < 100; */
    /*@ assert v[2] > 0 && v[2] < 100; */
    /*@ assert v[3] > 0 && v[3] < 100; */
    /*@ assert v[4] > 0 && v[4] < 100; */
    return true;
}
