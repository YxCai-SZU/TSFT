#include <stdbool.h>

/*@ predicate is_in_range(integer num, integer min_val, integer max_val) =
      num >= min_val && num <= max_val;
*/

/*@ lemma is_in_range_properties:
      \forall integer num, min_val, max_val;
      is_in_range(num, min_val, max_val) <==> (num >= min_val && num <= max_val);
*/

/*@ lemma is_in_range_out_of_range:
      \forall integer num, min_val, max_val;
      (num < min_val || num > max_val) ==> !is_in_range(num, min_val, max_val);
*/

/*@ lemma is_in_range_within_range:
      \forall integer num, min_val, max_val;
      (num >= min_val && num <= max_val) ==> is_in_range(num, min_val, max_val);
*/

/*@ lemma is_in_range_min_val_less_or_equal_max_val:
      \forall integer min_val, max_val;
      min_val <= max_val ==> is_in_range(min_val, min_val, max_val);
*/

/*@ lemma is_in_range_min_val_greater_than_max_val:
      \forall integer min_val, max_val;
      min_val > max_val ==> !is_in_range(min_val, min_val, max_val);
*/

int main() {
    return 0;
}
