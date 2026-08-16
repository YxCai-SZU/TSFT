#include <limits.h>

/* ================= Provided functions (adapted with ACSL specs) ================= */

/*@
    predicate in_range(integer x) = 1 <= x <= 100;
    
    logic integer abs_diff(integer x, integer y) = 
        x >= y ? x - y : y - x;
*/

int func(int a, int b, int c) {
    int min;
    int diff_ab;
    int diff_ac;
    int diff_bc;
    
    //@ assert in_range(a) && in_range(b) && in_range(c);
    
    if (a < b) {
        min = a;
    } else {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    
    diff_ab = b - a;
    diff_ac = c - a;
    diff_bc = c - b;
    
    if (diff_ab < 0) {
        diff_ab = -diff_ab;
    }
    if (diff_ac < 0) {
        diff_ac = -diff_ac;
    }
    if (diff_bc < 0) {
        diff_bc = -diff_bc;
    }
    
    //@ assert diff_ab == abs_diff(a, b);
    //@ assert diff_ac == abs_diff(a, c);
    //@ assert diff_bc == abs_diff(b, c);
    
    if (diff_ab + diff_ac == diff_bc || 
        diff_ac + diff_bc == diff_ab || 
        diff_ab + diff_bc == diff_ac) {
        //@ assert diff_ab + diff_ac == diff_bc || diff_ac + diff_bc == diff_ab || diff_ab + diff_bc == diff_ac;
        return 1;
    } else {
        //@ assert diff_ab + diff_ac != diff_bc && diff_ac + diff_bc != diff_ab && diff_ab + diff_bc != diff_ac;
        return 2;
    }
}

/*@
    predicate max(integer x, integer y, integer result) =
        (x >= y ==> result == x) && (x < y ==> result == y);
    
    lemma max_ge_x:
        \forall integer x, y, m; max(x, y, m) ==> m >= x;
    
    lemma max_ge_y:
        \forall integer x, y, m; max(x, y, m) ==> m >= y;
    
    lemma max_is_x_or_y:
        \forall integer x, y, m; max(x, y, m) ==> (m == x || m == y);
    
    predicate greater_than_threshold(integer x, integer threshold) =
        x > threshold;
*/

void proof_greater_than_threshold(int x, int threshold) {
    //@ assert x > threshold;
}

/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate in_range2(integer x) = 1 <= x && x <= 1000000000;
    predicate res_props(integer r, integer a) = 
        is_even(r) && r >= a && r <= 2 * a;
*/

unsigned long func2(unsigned long a) {
    unsigned long res;
    unsigned long i;
    
    //@ assert in_range2(a);
    
    res = a;
    if (a % 2 != 0) {
        res = a * 2;
    }
    
    //@ assert res_props(res, a);
    
    i = 1;
    while (i < a) {
        if (a % 2 == 0 && i % 2 != 0) {
            if (res < i) {
                res = i;
            }
        }
        i += 1;
        //@ assert res_props(res, a);
    }
    
    //@ assert res_props(res, a);
    return res;
}


/* ================= Synthesized complex function ================= */

unsigned long process_triple(int x, int y, int z) {
    int max_val;
    unsigned long adjusted;

    //@ assert in_range(x) && in_range(y) && in_range(z);
    int collinear = func(x, y, z);
    //@ assert collinear == 1 || collinear == 2;

    if (x >= y) {
        if (x >= z) {
            max_val = x;
        } else {
            max_val = z;
        }
    } else {
        if (y >= z) {
            max_val = y;
        } else {
            max_val = z;
        }
    }
    //@ assert max_val >= x && max_val >= y && max_val >= z;

    proof_greater_than_threshold(max_val, 50);
    //@ assert max_val > 50;

    //@ assert in_range2((unsigned long)max_val);
    adjusted = func2((unsigned long)max_val);
    //@ assert is_even(adjusted);
    //@ assert adjusted >= (unsigned long)max_val && adjusted <= 2 * (unsigned long)max_val;

    //@ assert is_even(adjusted) && adjusted >= (unsigned long)max_val && adjusted <= 2 * (unsigned long)max_val;
    return adjusted;
}
