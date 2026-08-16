#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

/* ========== Original func from snippet 1 ========== */
/*@
    predicate valid_n(integer n) = 1 <= n && n <= 10000;

    logic integer mod_result(integer n) = n % 1000;

    logic integer func_result(integer n) =
        mod_result(n) == 0 ? 0 : 1000 - mod_result(n);
*/

int func(int n)
{
    unsigned int n_unsigned;
    unsigned int r_unsigned;
    int result;

    //@ assert valid_n(n);
    if (n < 0) {
        //@ assert n < 0;
        n_unsigned = (unsigned int)(-n);
    } else {
        //@ assert n >= 0;
        n_unsigned = (unsigned int)n;
    }

    r_unsigned = n_unsigned % 1000;

    if (r_unsigned == 0) {
        //@ assert r_unsigned == 0;
        result = 0;
    } else {
        //@ assert r_unsigned != 0;
        //@ assert 1000 - r_unsigned <= 1000;
        //@ assert 1000 - r_unsigned >= 0;
        result = (int)(1000 - r_unsigned);
    }

    //@ assert result == func_result(n);
    return result;
}

/* ========== Original functions from snippet 2 ========== */
/*@ predicate can_distribute(integer a, integer b, integer c) =
      a + b == c || a + c == b || b + c == a;
*/

bool can_distribute_evenly(unsigned int a, unsigned int b, unsigned int c) {
    bool result;
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    
    if (a + b == c || a + c == b || b + c == a) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == (a + b == c || a + c == b || b + c == a);
    return result;
}

/*@ predicate two_equal(integer a, integer b, integer c) =
      a == b || b == c || a == c;
*/

/*@ predicate all_equal(integer a, integer b, integer c) =
      a == b && b == c;
*/

/*@ lemma max_two_ops: \forall integer a,b,c;
        1 <= a && a <= 100 && 1 <= b && b <= 100 && 1 <= c && c <= 100 ==>
        (all_equal(a,b,c) ==> 0 <= 2) &&
        (!all_equal(a,b,c) && two_equal(a,b,c) ==> 1 <= 2) &&
        (!all_equal(a,b,c) && !two_equal(a,b,c) ==> 2 <= 2);
*/

unsigned int min_num_operations(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int min_operations;
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    
    if (a == b && b == c) {
        min_operations = 0;
        //@ assert min_operations <= 2;
    } else if (a == b || b == c || a == c) {
        min_operations = 1;
        //@ assert min_operations <= 2;
    } else {
        //@ assert a != b && b != c && a != c;
        min_operations = 2;
        //@ assert min_operations <= 2;
    }
    
    return min_operations;
}

/* ========== Original func from snippet 3 (renamed to avoid conflict) ========== */
/*@
    predicate is_small(integer a, integer b) = (1 <= a <= 9) && (1 <= b <= 9);
    predicate is_valid_range(integer a, integer b) = (1 <= a <= 20) && (1 <= b <= 20);
    
    lemma small_product_bounds: 
        \forall integer a, b; is_small(a, b) ==> (1 <= a * b <= 81);
    lemma not_small_condition: 
        \forall integer a, b; is_valid_range(a, b) && !is_small(a, b) ==> (a > 9 || b > 9);
*/

int32_t packing_factor(uint32_t a, uint32_t b)
{
    //@ assert is_valid_range(a, b);
    
    if (a <= 9 && b <= 9) {
        //@ assert is_small(a, b);
        //@ assert 1 <= a * b <= 81;
        return (int32_t)(a * b);
    } else {
        //@ assert !is_small(a, b);
        //@ assert a > 9 || b > 9;
        return -1;
    }
}

/* ========== Synthesized complex function ========== */
/* Scenario: In a warehouse inventory system, we need to check if a batch of items 
   (identified by a batch ID) can be evenly redistributed into smaller boxes.
   The batch ID is used to compute a "rounding gap" (func) that indicates how many 
   extra items are needed to fill a full pallet. Then, based on the dimensions 
   (a, b, c) of the boxes, we check if redistribution is possible and compute 
   the minimum number of operations needed. Finally, the product of two small 
   dimensions (if applicable) is used as a packing efficiency factor.
   
   Data flow:
   1. Compute gap = func(batch_id)  --> gap is the number of items needed to round up to next 1000.
   2. Use gap as one of the box dimensions (a) along with b, c to check if redistribution is possible.
   3. If redistribution is possible, compute min_operations needed.
   4. Then, compute packing efficiency factor using packing_factor on two small dimensions.
   5. The final result is a packing score that must be >= 0 and <= 1000 (high-level invariant).
*/

int inventory_packing_score(int batch_id, unsigned int b, unsigned int c, uint32_t d, uint32_t e) {
    int gap;
    unsigned int a;
    bool can_distribute;
    unsigned int ops;
    int32_t factor;
    int score;
    
    gap = func(batch_id);
    //@ assert gap == func_result(batch_id);
    //@ assert 0 <= gap <= 999;
    
    if (gap == 0) {
        a = 1;
    } else if (gap > 100) {
        a = 100;
    } else {
        a = (unsigned int)gap;
    }
    //@ assert 1 <= a && a <= 100;
    
    can_distribute = can_distribute_evenly(a, b, c);
    //@ assert can_distribute == (a + b == c || a + c == b || b + c == a);
    
    if (can_distribute) {
        ops = min_num_operations(a, b, c);
        //@ assert ops <= 2;
    } else {
        ops = 3; // sentinel value indicating not possible
    }
    
    factor = packing_factor(d, e);
    //@ assert (is_small(d, e) ==> factor == (int32_t)(d * e));
    //@ assert (!is_small(d, e) ==> factor == -1);
    
    if (can_distribute && factor != -1) {
        if (ops == 0) {
            score = (int)factor * 12; // max 81*12 = 972
        } else if (ops == 1) {
            score = (int)factor * 8;  // max 81*8 = 648
        } else {
            score = (int)factor * 4;  // max 81*4 = 324
        }
        if (score < 0) score = 0;
        if (score > 1000) score = 1000;
    } else if (can_distribute && factor == -1) {
        if (ops == 0) {
            score = 500;
        } else if (ops == 1) {
            score = 300;
        } else {
            score = 100;
        }
    } else if (!can_distribute && factor != -1) {
        score = (int)factor; // factor is at most 81
    } else {
        score = 0;
    }
    
    //@ assert score >= 0 && score <= 1000;
    return score;
}
