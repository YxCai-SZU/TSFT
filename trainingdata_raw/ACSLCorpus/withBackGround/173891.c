#include <stdbool.h>

/*@ predicate is_even(integer x) = x % 2 == 0; */
/*@ predicate is_odd(integer x) = x % 2 != 0; */

/*@ lemma test_is_even: is_even(10) && !is_even(11); */
/*@ lemma test_is_odd: is_odd(11) && !is_odd(10); */

/*@ lemma even_plus_odd_is_odd: \forall integer x, y; 
      is_even(x) && is_odd(y) ==> is_odd(x + y); */

/*@ lemma odd_plus_even_is_odd: \forall integer x, y; 
      is_odd(x) && is_even(y) ==> is_odd(x + y); */

int main() {
    return 0;
}
