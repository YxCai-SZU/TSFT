#include <stdbool.h>

/*@
    predicate valid_input(int *x, integer len) =
        len == 2 &&
        1 <= x[0] <= 100 &&
        1 <= x[1] <= 100;
*/

/*@
    logic integer first_element(int *x) = x[0];
    logic integer second_element(int *x) = x[1];
*/

/*@
    lemma bounds_lemma:
        \forall int *x; \forall integer len;
        valid_input(x, len) ==> 
        (1 <= first_element(x) <= 100 && 1 <= second_element(x) <= 100);
*/

/*@
    requires \valid(x+(0..1));
    requires valid_input(x, 2);
    ensures \result == true <==> x[0] < x[1];
    assigns \nothing;
*/
bool func(int *x) {
    int s;
    int w;
    
    //@ assert valid_input(x, 2);
    s = x[0];
    w = x[1];
    
    //@ assert 1 <= s <= 100;
    //@ assert 1 <= w <= 100;
    
    if (s < w) {
        //@ assert s < w;
        return true;
    } else {
        //@ assert !(s < w);
        return false;
    }
}
