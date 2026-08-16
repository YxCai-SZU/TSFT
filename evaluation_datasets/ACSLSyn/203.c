#include <stdbool.h>

/*@ predicate contains_zero(int *arr, integer len) =
      \exists integer i; 0 <= i < len && *(arr + i) == 0;
*/

/*@ predicate all_positive(int *arr, integer len) =
      \forall integer i; 0 <= i < len ==> *(arr + i) > 0;
*/

int compute_area(int r)
{
    //@ assert 1 <= r <= 100;
    //@ assert 3 * r * r <= 3 * 100 * 100;
    return 3 * r * r;
}

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 10000;
    predicate b_in_range(integer b) = 1 <= b && b <= 10000;
    predicate c_in_range(integer c) = 1 <= c && c <= 10000;
    predicate d_in_range(integer d) = 1 <= d && d <= 10000;
    
    logic integer condition_value(integer a, integer b, integer c, integer d) =
        a <= b ? 1 : (a - b < d ? 1 : (c > a - b - d ? 1 : 0));
    
    lemma condition_lemma:
        \forall integer a, b, c, d;
        a_in_range(a) && b_in_range(b) && c_in_range(c) && d_in_range(d) ==>
        (condition_value(a, b, c, d) == 1) == 
        (a <= b || a - b < d || c > a - b - d);
*/

bool check_condition(int a, int b, int c, int d)
{
    bool result;
    
    if (a <= b) {
        //@ assert condition_value(a, b, c, d) == 1;
        result = true;
    } else {
        if (a - b < d) {
            //@ assert condition_value(a, b, c, d) == 1;
            result = true;
        } else {
            if (c > a - b - d) {
                //@ assert condition_value(a, b, c, d) == 1;
                result = true;
            } else {
                //@ assert a > b;
                //@ assert a - b >= d;
                //@ assert c <= a - b - d;
                //@ assert condition_value(a, b, c, d) == 0;
                result = false;
            }
        }
    }
    
    return result;
}

int process_condition_and_area(int r, int a, int b, int c, int d)
{
    int area = compute_area(r);
    bool cond = check_condition(a, b, c, d);
    int result;
    
    if (cond) {
        result = area;
    } else {
        result = 0;
    }
    
    //@ assert (cond == (condition_value(a, b, c, d) == 1)) && (result == (cond ? (3 * r * r) : 0));
    return result;
}
