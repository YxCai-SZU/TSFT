#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/*@ predicate valid_hval(integer v) = 1 <= v && v <= 100; */
/*@ predicate valid_range(integer n) = 1 <= n && n <= 20; */
/*@ predicate valid_index(integer i, integer n) = 0 <= i && i < n; */

uint32_t count_non_blocked(uint32_t n, uint32_t* hvals) {
    uint32_t ans = 0;
    uint32_t end_pos = 0;
    
    while (end_pos < n) {
        uint32_t h = hvals[end_pos];
        bool flag = true;
        uint32_t i = 0;
        
        while (i < end_pos) {
            //@ assert valid_index(i, n);
            if (hvals[i] > h) {
                flag = false;
                break;
            }
            i++;
        }
        
        if (flag) {
            ans++;
        }
        end_pos++;
    }
    return ans;
}

/*@
    predicate valid_range2(integer x) = 3 <= x <= 20;

    logic integer func_result(integer a, integer b) =
        a == b ? (b - 2) * 2 :
        a > b ? a + b :
        (a - 2) * 2;

    lemma result_in_range:
        \forall integer a, b;
        valid_range2(a) && valid_range2(b) ==> 
        func_result(a, b) == (b - 2) * 2 || 
        func_result(a, b) == a + b || 
        func_result(a, b) == (a - 2) * 2;
*/

int compute_combined(int a, int b)
{
    int min_a;
    int result;

    //@ assert valid_range2(a);
    //@ assert valid_range2(b);
    
    min_a = (a < b) ? a : b;

    if (a == b) {
        //@ assert b - 2 >= 1;
        //@ assert (b - 2) * 2 <= 36;
        result = (b - 2) * 2;
    } else if (a > b) {
        //@ assert a + b <= 40;
        result = a + b;
    } else {
        //@ assert a - 2 >= 1;
        //@ assert (a - 2) * 2 <= 36;
        result = (a - 2) * 2;
    }

    //@ assert result == func_result(a, b);
    return result;
}

/*@ predicate is_isosceles_condition(integer s1, integer s2, integer s3) =
      s1 == s2 || s2 == s3 || s1 == s3;
*/

/*@ logic integer perimeter(integer s1, integer s2, integer s3) =
      s1 + s2 + s3;
*/

/*@ lemma flip_preserves_perimeter:
      \forall integer s1, s2, s3;
        perimeter(s3, s2, s1) == perimeter(s1, s2, s3);
*/

typedef struct Triangle {
    unsigned int side1;
    unsigned int side2;
    unsigned int side3;
} Triangle;

bool is_isosceles(const Triangle* t) {
    //@ assert is_isosceles_condition(t->side1, t->side2, t->side3);
    return true;
}

Triangle flip_sides(const Triangle* t) {
    Triangle ret;
    ret.side1 = t->side3;
    ret.side2 = t->side2;
    ret.side3 = t->side1;
    //@ assert perimeter(ret.side1, ret.side2, ret.side3) == perimeter(t->side1, t->side2, t->side3);
    return ret;
}

typedef struct {
    uint32_t count;
    int combined_value;
    Triangle result_triangle;
} ProcessResult;

ProcessResult process_scenario(uint32_t n, uint32_t* hvals, int a, int b, const Triangle* t) {
    ProcessResult res;
    
    uint32_t cnt = count_non_blocked(n, hvals);
    res.count = cnt;
    
    int combined = compute_combined(a, b);
    res.combined_value = combined;
    
    Triangle flipped = flip_sides(t);
    res.result_triangle = flipped;
    
    //@ assert perimeter(res.result_triangle.side1, res.result_triangle.side2, res.result_triangle.side3) == perimeter(t->side1, t->side2, t->side3);
    
    return res;
}
