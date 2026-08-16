#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* ========== Original functions (unchanged) ========== */

/* --- Function 1: func1 (min+max sum) --- */
/*@
    predicate sorted_three(integer a, integer b, integer c, integer x, integer y, integer z) =
        (a <= b && a <= c && ((b <= c && x == a && y == b && z == c) ||
                              (c <= b && x == a && y == c && z == b))) ||
        (b <= a && b <= c && ((a <= c && x == b && y == a && z == c) ||
                              (c <= a && x == b && y == c && z == a))) ||
        (c <= a && c <= b && ((a <= b && x == c && y == a && z == b) ||
                              (b <= a && x == c && y == b && z == a)));
*/

/*@
    lemma sorted_properties:
        \forall integer a, b, c, x, y, z;
            sorted_three(a, b, c, x, y, z) ==>
            (x == a || x == b || x == c) &&
            (z == a || z == b || z == c) &&
            x <= y && y <= z &&
            (x + z == a + b || x + z == b + c || x + z == c + a);
*/

long func1(long a, long b, long c) {
    long x;
    long y;
    long z;
    long first;
    long last;
    long result;

    if (a <= b && a <= c) {
        x = a;
        if (b <= c) {
            y = b;
            z = c;
        } else {
            y = c;
            z = b;
        }
    } else if (b <= a && b <= c) {
        x = b;
        if (a <= c) {
            y = a;
            z = c;
        } else {
            y = c;
            z = a;
        }
    } else {
        x = c;
        if (a <= b) {
            y = a;
            z = b;
        } else {
            y = b;
            z = a;
        }
    }

    first = x;
    last = z;

    //@ assert sorted_three(a, b, c, first, y, last);
    //@ assert first >= 1 && first <= 100;
    //@ assert last >= 1 && last <= 100;
    //@ assert first + last >= 2 && first + last <= 200;

    result = first + last;
    //@ assert result == a + b || result == b + c || result == c + a;

    return result;
}

/* --- Function 2: func2 (count odd at even indices) --- */
/*@ predicate valid_range(integer n) = 1 <= n && n <= 100; */
/*@ predicate valid_array(int *arr, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= arr[i] && arr[i] <= 100; */

/*@ lemma count_bounds:
      \forall integer n, integer count, integer num;
      valid_range(n) && 0 <= count && count <= num && 0 <= num && num <= n ==>
      0 <= count && count <= n; */

int func2(int n, int *a_vec) {
    int count = 0;
    int num = 0;
    size_t index = 0;

    while (num < n && index < (size_t)n) {
        int a = a_vec[index];
        
        //@ assert num % 2 == 0 ==> (num % 2 == 0 && a % 2 == 1) ==> a % 2 == 1;
        if (num % 2 == 0 && a % 2 == 1) {
            count += 1;
        }
        num += 1;
        index += 1;
    }
    return count;
}

/* --- Function 3: func3 (check y is even and between x*2 and x/2) --- */
/*@
    predicate y_is_even(integer y) = y % 2 == 0;
    predicate y_div_2_greater_than_x(integer x, integer y) = y / 2 >= x;
    predicate x_times_2_greater_than_y(integer x, integer y) = x * 2 >= y;
*/

bool func3(unsigned int x, unsigned int y)
{
    bool y_is_even;
    bool y_div_2_greater_than_x;
    bool x_times_2_greater_than_y;
    bool result;

    y_is_even = y % 2 == 0;
    //@ assert y_is_even == (y % 2 == 0);

    y_div_2_greater_than_x = y / 2 >= x;
    //@ assert y_div_2_greater_than_x == (y / 2 >= x);

    x_times_2_greater_than_y = x * 2 >= y;
    //@ assert x_times_2_greater_than_y == (x * 2 >= y);

    result = y_is_even && y_div_2_greater_than_x && x_times_2_greater_than_y;
    return result;
}

/* --- Function 4: func4 (compute constrained sum) --- */
/*@
    predicate valid_input(integer a, integer b, integer c) =
        0 <= a && a <= 100 &&
        0 <= b && b <= 100 &&
        0 <= c && c <= 100;

    logic integer func_result(integer a, integer b, integer c) =
        c > 0 ?
            (b < c ?
                b * 2 + 1 + (
                    (a > 1 ? a - 1 : 0) + 1 < c - (b + 1) ?
                    (a > 1 ? a - 1 : 0) + 1 :
                    c - (b + 1)
                )
                : c * 2
            )
            : 0;

    lemma result_bounds:
        \forall integer a, b, c;
        valid_input(a, b, c) ==>
            func_result(a, b, c) >= 0 &&
            func_result(a, b, c) <= a + b + c &&
            func_result(a, b, c) <= 200;
*/

int64_t func4(int64_t a, int64_t b, int64_t c)
{
    int64_t r = 0;
    int64_t c_temp;
    int64_t a_temp;

    //@ assert valid_input(a, b, c);

    if (c > 0)
    {
        if (b < c)
        {
            r += b * 2 + 1;
            c_temp = c - (b + 1);
            a_temp = (a > 1 ? a - 1 : 0);
            //@ assert a_temp >= 0;
            //@ assert c_temp >= 0;
            r += (a_temp + 1 < c_temp ? a_temp + 1 : c_temp);
        }
        else
        {
            r += c * 2;
        }
    }

    //@ assert r >= 0;
    //@ assert r <= a + b + c;
    //@ assert r <= 200;

    return r;
}

/* ========== Synthesized scenario: Packet processing with priority validation ========== */

int process_packet(
    long a1, long b1, long c1,
    int n, int *arr,
    unsigned int x, unsigned int y,
    int64_t a4, int64_t b4, int64_t c4
)
{
    int total = 0;

    long sum_minmax = func1(a1, b1, c1);
    //@ assert sum_minmax == a1 + b1 || sum_minmax == b1 + c1 || sum_minmax == c1 + a1;
    total += (int)sum_minmax;

    int odd_count = func2(n, arr);
    //@ assert 0 <= odd_count <= n;
    total += odd_count;

    bool priority_ok = func3(x, y);
    //@ assert priority_ok == (y % 2 == 0 && y / 2 >= x && x * 2 >= y);

    int64_t alloc = func4(a4, b4, c4);
    //@ assert alloc >= 0 && alloc <= a4 + b4 + c4 && alloc <= 200;

    if (priority_ok) {
        total += (int)alloc;
    }

    //@ assert total >= 0;
    //@ assert total <= 500;

    return total;
}
