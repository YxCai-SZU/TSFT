#include <stdbool.h>
#include <stddef.h>

/*@ predicate r_in_range(integer r) = 1 <= r && r <= 100; */

/*@ lemma square_bound: 
      \forall integer r; r_in_range(r) ==> r * r <= 10000; */

/*@
    requires r_in_range(r);
    ensures \result == r * r;
    assigns \nothing;
*/
unsigned int func(unsigned int r) {
    unsigned int res;
    
    //@ assert 1 <= r && r <= 100;
    //@ assert r * r <= 10000;
    
    res = r * r;
    return res;
}

/*@ assigns \nothing; */
char input_char(void) {
    return ' ';
}

/*@ assigns \nothing; */
unsigned int input_number(void) {
    return 0;
}
