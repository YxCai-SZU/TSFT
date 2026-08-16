#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_range(integer n) = 2 <= n && n <= 100; */
/*@ predicate valid_x(integer x) = 0 <= x && x <= 10000; */
/*@ predicate valid_array(int *arr, integer n) = 
      \forall integer i; 0 <= i < n ==> 0 <= arr[i] && arr[i] <= 100; */

int func1(int n, int x, int *numbers) {
    int count = 0;
    size_t i = 0;
    
    while (i < (size_t)n) {
        int a = numbers[i];
        //@ assert 0 <= a <= 100;
        if (x >= a) {
            count++;
        }
        i++;
    }
    //@ assert 0 <= count <= n;
    return count;
}

/*@
    predicate valid_input(integer a, integer b) =
        1 <= a && a <= 12 &&
        1 <= b && b <= 31;

    logic integer remainder(integer b, integer temp_b) =
        b - 2 * ((b - temp_b) / 2);
*/

int func2(unsigned int a, unsigned int b)
{
    int ans;
    bool is_even = false;
    unsigned int temp_b;
    int result;

    ans = (a <= 9) ? 1 : 0;
    temp_b = b;

    while (temp_b >= 2)
    {
        //@ assert temp_b >= 2;
        temp_b -= 2;
    }

    //@ assert temp_b == 0 || temp_b == 1;
    if (temp_b == 0)
    {
        is_even = true;
    }

    if (is_even)
    {
        result = ans;
    }
    else
    {
        if (a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12)
        {
            result = ans;
        }
        else
        {
            result = 1 - ans;
        }
    }

    //@ assert result == 0 || result == 1;
    return result;
}

/*@
    predicate valid_month(integer a) = 1 <= a && a <= 12;
    predicate valid_day(integer b) = 1 <= b && b <= 31;
    predicate valid_threshold(integer t) = 0 <= t && t <= 100;
*/

int process_daily_records(int n, int month, int day_threshold, int count_threshold, int *counts) {
    int favorable_count = func1(n, count_threshold, counts);
    int is_lucky_day = func2((unsigned int)month, (unsigned int)day_threshold);
    int result;
    
    if (is_lucky_day == 1 && favorable_count > 0) {
        result = favorable_count;
    } else {
        result = 0;
    }
    
    //@ assert 0 <= result <= n;
    return result;
}
