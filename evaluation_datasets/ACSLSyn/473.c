#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 5000 &&
        1 <= b && b <= 5000 &&
        1 <= c && c <= 10000;

    logic integer compute_diff(integer a, integer b, integer c) =
        a + b >= c ? (a + b) - c : c - (a + b);

    lemma diff_definition:
        \forall integer a, b, c;
        valid_input(a, b, c) ==>
        compute_diff(a, b, c) == (a + b >= c ? (a + b) - c : c - (a + b));
*/

bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int diff;
    bool result;

    //@ assert valid_input(a, b, c);
    
    if (a + b >= c) {
        diff = (a + b) - c;
    } else {
        diff = c - (a + b);
    }
    
    //@ assert diff == compute_diff(a, b, c);
    //@ assert diff == (a + b >= c ? (a + b) - c : c - (a + b));
    
    result = (a + b >= c);
    //@ assert result == (a + b >= c);
    
    return result;
}

/*@ logic integer max(integer x, integer y) = (x > y) ? x : y; */
/*@ logic integer min(integer x, integer y) = (x < y) ? x : y; */
/*@ logic integer abs_diff(integer x, integer y) = (x > y) ? (x - y) : (y - x); */

/*@ lemma max_lemma: \forall integer x, y; x <= y ==> max(x, y) == y; */
/*@ lemma min_lemma: \forall integer x, y; x <= y ==> min(x, y) == x; */
/*@ lemma abs_diff_lemma: \forall integer x, y; x <= y ==> abs_diff(x, y) == (y - x); */

bool func_strict_order(int a, int b, int c) {
    bool result;
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    
    if (a < b && b < c) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == (a < b && b < c);
    return result;
}

bool func_or(int a, int b, int c) {
    bool result;
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    
    if (a < b || b < c) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == (a < b || b < c);
    return result;
}

bool combined_check(unsigned int a, unsigned int b, unsigned int c, int x, int y, int z) {
    bool diff_result;
    bool order_result;
    
    diff_result = func(a, b, c);
    //@ assert diff_result == (a + b >= c);
    
    order_result = func_strict_order(x, y, z);
    //@ assert order_result == (x < y && y < z);
    
    bool final_result = diff_result && order_result;
    
    //@ assert final_result == ( (a + b >= c) && (x < y && y < z) );
    //@ assert final_result ==> (valid_input(a, b, c) && 1 <= x <= 100 && 1 <= y <= 100 && 1 <= z <= 100);
    
    return final_result;
}
