#include <limits.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;
    
    logic integer safe_product(integer a, integer b) = a * b;
    
    lemma product_bounds: \forall integer a, b; 
        valid_range(a, b) ==> 1 <= safe_product(a, b) <= 10000;
*/

/*@
    requires valid_range(a, b);
    ensures \result == safe_product(a, b);
    assigns \nothing;
*/
int func(int a, int b) {
    //@ assert valid_range(a, b);
    //@ assert 1 <= safe_product(a, b) <= 10000;
    
    int result;
    result = a * b;
    
    //@ assert result == safe_product(a, b);
    return result;
}

#ifdef TESTING
#include <assert.h>

int main() {
    int result;
    
    result = func(1, 1);
    //@ assert result == 1;
    assert(result == 1);
    
    result = func(10, 10);
    //@ assert result == 100;
    assert(result == 100);
    
    result = func(100, 100);
    //@ assert result == 10000;
    assert(result == 10000);
    
    result = func(2, 3);
    //@ assert result == 6;
    assert(result == 6);
    
    result = func(5, 5);
    //@ assert result == 25;
    assert(result == 25);
    
    return 0;
}
#endif
