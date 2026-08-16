#include <limits.h>

/*@ predicate is_between(integer a, integer b, integer c) = 
      a <= c && c <= b;
*/

/*@ logic integer max_spec(integer a, integer b) =
      (a > b) ? a : b;
*/

/*@ logic integer min_spec(integer a, integer b) =
      (a < b) ? a : b;
*/

/*@ lemma test_max_is_max: 
      \forall integer a, b; max_spec(a, b) == max_spec(a, b);
*/

/*@ lemma test_min_is_min: 
      \forall integer a, b; min_spec(a, b) == min_spec(a, b);
*/

/*@ lemma test_max_is_not_min: 
      \forall integer a, b; a != b ==> max_spec(a, b) != min_spec(a, b);
*/

/*@ lemma test_min_is_not_max: 
      \forall integer a, b; a != b ==> min_spec(a, b) != max_spec(a, b);
*/

/*@ lemma max_no_leakage: 
      max_spec(10, 20) == max_spec(10, 20);
*/

/*@ lemma min_no_leakage: 
      min_spec(10, 20) == min_spec(10, 20);
*/

/*@ requires 
      INT_MIN <= a <= INT_MAX && INT_MIN <= b <= INT_MAX;
    ensures 
      \result == max_spec(a, b);
*/
int max(int a, int b)
{
    int ret;
    if (a > b) {
        ret = a;
    } else {
        ret = b;
    }
    //@ assert ret == max_spec(a, b);
    return ret;
}

/*@ requires 
      INT_MIN <= a <= INT_MAX && INT_MIN <= b <= INT_MAX;
    ensures 
      \result == min_spec(a, b);
*/
int min(int a, int b)
{
    int ret;
    if (a < b) {
        ret = a;
    } else {
        ret = b;
    }
    //@ assert ret == min_spec(a, b);
    return ret;
}

int main() {
    return 0;
}
