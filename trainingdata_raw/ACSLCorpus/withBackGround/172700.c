#include <stdbool.h>

/*@
    predicate valid_range(integer a) = 1 <= a <= 100;

    logic integer multiply(integer a, integer b) = a * b;

    lemma product_range: 
        \forall integer a, b; 
        valid_range(a) && valid_range(b) ==> 1 <= multiply(a, b) <= 10000;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    ensures \result == multiply(a, b);
*/
int func(int a, int b) {
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert 1 <= a * b <= 10000;
    
    int answer = a * b;
    return answer;
}
