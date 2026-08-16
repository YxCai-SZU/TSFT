#include <stdbool.h>

/*@ logic integer my_mod(integer x, integer y) = x % y; */

/*@ lemma test_mod: 
      my_mod(17, 5) == 2 && my_mod(10, 3) == 1; */

/*@ lemma mod_property: 
      \forall integer x, y; y > 0 ==> my_mod(x, y) < y; */

/*@ logic integer my_max(integer x, integer y) = 
      (x > y) ? x : y; */

/*@ lemma test_max: 
      my_max(17, 5) == 17 && my_max(10, 3) == 10; */

/*@ lemma max_property: 
      \forall integer x, y; 
      (x >= y || y >= x) ==> 
      (my_max(x, y) >= x && my_max(x, y) >= y); */

int main() {
    return 0;
}
