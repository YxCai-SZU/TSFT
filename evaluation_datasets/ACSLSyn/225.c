#include <stdbool.h>

/* First function: checks a specific condition between a and b */
/*@
    predicate condition_holds(integer a, integer b) =
        a * 2 <= b && b * 8 <= a;
 */

bool check_condition(unsigned long long a, unsigned long long b)
{
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    
    if (a * 2 <= b && b * 8 <= a) {
        //@ assert condition_holds(a, b);
        return true;
    } else {
        //@ assert !condition_holds(a, b);
        return false;
    }
}

/* Second function: counts elements in ranges and returns min count */
/*@
    predicate valid_params(integer n, integer a, integer b) =
        3 <= n && n <= 100 &&
        1 <= a && a < b && b < 20;

    predicate valid_array(int *p, integer n) =
        \forall integer i; 0 <= i < n ==> 1 <= p[i] && p[i] <= 20;

    predicate count_bounds(integer c0, integer c1, integer c2, integer i) =
        c0 >= 0 && c1 >= 0 && c2 >= 0 &&
        c0 <= i && c1 <= i && c2 <= i;
*/

/*@
    logic integer min_three(integer x, integer y, integer z) =
        (x <= y && x <= z) ? x : ((y <= z) ? y : z);
*/

/*@
    lemma count_non_negative:
        \forall integer c0, c1, c2, i;
        count_bounds(c0, c1, c2, i) ==> c0 >= 0 && c1 >= 0 && c2 >= 0;
*/

/*@
    lemma count_le_i:
        \forall integer c0, c1, c2, i;
        count_bounds(c0, c1, c2, i) ==> c0 <= i && c1 <= i && c2 <= i;
*/

/*@
    lemma min_non_negative:
        \forall integer x, y, z;
        x >= 0 && y >= 0 && z >= 0 ==> min_three(x, y, z) >= 0;
*/

/*@
    lemma min_le_n:
        \forall integer x, y, z, n;
        x <= n && y <= n && z <= n ==> min_three(x, y, z) <= n;
*/

int compute_min_count(int n, int a, int b, int *p)
{
    int count[3];
    int i;
    
    count[0] = 0;
    count[1] = 0;
    count[2] = 0;
    
    for (i = 0; i < n; ++i) {
        int value = p[i];
        //@ assert 1 <= value && value <= 20;
        if (value <= a) {
            //@ assert value <= a;
            count[0] = count[0] + 1;
        } else if (value <= b) {
            //@ assert a < value && value <= b;
            count[1] = count[1] + 1;
        } else {
            //@ assert b < value;
            count[2] = count[2] + 1;
        }
        //@ assert count_bounds(count[0], count[1], count[2], i+1);
    }

    int min_value;
    if (count[0] < count[1]) {
        if (count[0] < count[2]) {
            min_value = count[0];
        } else {
            min_value = count[2];
        }
    } else if (count[1] < count[2]) {
        min_value = count[1];
    } else {
        min_value = count[2];
    }
    //@ assert min_value == min_three(count[0], count[1], count[2]);
    //@ assert min_value >= 0;
    //@ assert min_value <= n;
    return min_value;
}

/* Synthesized function: Data quality analysis with constraint validation */
/*@
    predicate valid_thresholds(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100 && a * 2 <= b && b * 8 <= a;
    
    predicate analysis_result(integer result, integer n) =
        0 <= result <= n;
*/

int analyze_sensor_data(int n, int a, int b, int *p)
{
    bool thresholds_ok = check_condition(a, b);
    //@ assert thresholds_ok == true <==> condition_holds(a, b);
    
    //@ assert thresholds_ok ==> (a * 2 <= b && b * 8 <= a);
    
    int result = compute_min_count(n, a, b, p);
    //@ assert result >= 0 && result <= n;
    
    return result;
}
