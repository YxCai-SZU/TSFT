#include <stdbool.h>

/*@ predicate is_less_than(integer x, integer k) = k < x; */

/*@ predicate is_greater_than(integer x, integer k) = k > x; */

/*@ predicate is_in_range(integer l, integer r, integer k) = 
      l <= k && k <= r; */

/*@ lemma test_is_less_than:
      is_less_than(10, 5) &&
      !is_less_than(10, 10) &&
      !is_less_than(10, 15); */

/*@ lemma test_is_greater_than:
      !is_greater_than(10, 5) &&
      !is_greater_than(10, 10) &&
      is_greater_than(10, 15); */

/*@ lemma test_is_in_range:
      !is_in_range(5, 10, 3) &&
      is_in_range(5, 10, 5) &&
      is_in_range(5, 10, 7) &&
      is_in_range(5, 10, 10) &&
      !is_in_range(5, 10, 12); */

/*@ lemma is_in_range_monotonic:
      \forall integer l, r, k;
        l <= r ==> 
        (is_in_range(l, r, k) <==> (l <= k && k <= r)); */

int main() {
    return 0;
}
