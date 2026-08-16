#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer expected_result(integer a, integer b) =
        (a + b + 1) / 2;

    lemma division_property:
        \forall integer sum, count, temp_sum;
        sum >= 0 && count >= 0 && temp_sum >= 0 && 
        sum == temp_sum + 2*count && temp_sum < 2 ==>
        count == sum/2;
*/

int func1(int a, int b) {
    int sum;
    int avg;
    int temp_sum;
    int count;
    
    sum = a + b;
    avg = 0;
    temp_sum = sum;
    count = 0;
    
    while (temp_sum >= 2) {
        temp_sum -= 2;
        count += 1;
    }
    
    if (temp_sum > 0 && sum > 0) {
        count += 1;
    }
    
    avg = count;
    
    //@ assert avg == (sum + 1) / 2;
    
    return avg;
}

/*@
    predicate is_zero_axis(integer x, integer y) =
        (x == 0 && -100 <= y && y <= 100) ||
        (y == 0 && -100 <= x && x <= 100);
 */

/*@
    lemma abs_range:
        \forall integer v; -100 <= v <= 100 ==> 0 <= (v < 0 ? -v : v) <= 100;
 */

bool func2(int x, int y)
{
    int abs_x;
    int abs_y;
    bool result;

    //@ assert -100 <= x <= 100;
    //@ assert -100 <= y <= 100;

    abs_x = (x < 0) ? -x : x;
    abs_y = (y < 0) ? -y : y;

    //@ assert 0 <= abs_x <= 100;
    //@ assert 0 <= abs_y <= 100;

    if (x == 0)
    {
        //@ assert abs_y <= 100;
        result = (abs_y <= 100);
        return result;
    }
    else if (y == 0)
    {
        //@ assert abs_x <= 100;
        result = (abs_x <= 100);
        return result;
    }
    else
    {
        result = false;
        return result;
    }
}

bool synthesized_func(int a, int b) {
    int avg;
    bool on_axis;

    avg = func1(a, b);

    on_axis = func2(avg, avg);

    //@ assert on_axis == true <==> (avg == 0 && -100 <= avg <= 100) || (avg == 0 && -100 <= avg <= 100);
    //@ assert on_axis == true <==> avg == 0;

    return on_axis;
}
