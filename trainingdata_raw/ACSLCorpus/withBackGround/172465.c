#include <stdbool.h>

/*@ predicate is_square(integer n) = n > 1; */

/*@ lemma test_exists_square: 
      \forall integer i; (\exists integer j; is_square(j) && j == i) ==> is_square(i); */

int main() {
    //@ assert \true;
    return 0;
}
