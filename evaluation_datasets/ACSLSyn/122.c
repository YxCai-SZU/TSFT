#include <stdbool.h>

/*@
    predicate is_valid_range(integer n) = 1 <= n && n <= 100;
    
    logic integer division_by_2(integer n) = n / 2;
    logic integer remainder_by_2(integer n) = n % 2;
    logic integer target_result(integer n) = division_by_2(n) + remainder_by_2(n);
*/

int func_len(int n)
{
    int result;
    int temp_n;
    int count;
    bool is_odd;
    
    result = 0;
    temp_n = n;
    count = 0;
    is_odd = false;
    
    while (temp_n >= 2)
    {
        //@ assert temp_n >= 2;
        temp_n -= 2;
        count += 1;
    }
    
    if (temp_n == 1)
    {
        is_odd = true;
    }
    
    if (is_odd)
    {
        result = count + 1;
    }
    else
    {
        result = count;
    }
    
    //@ assert result == target_result(n);
    return result;
}

/*@
    predicate ordered(integer a, integer b, integer c, integer d, integer e) =
        a < b && b < c && c < d && d < e;

    predicate in_range(integer x) = 0 <= x <= 123;

    lemma order_implies_positive_distance:
        \forall integer a, b, c, d, e;
            in_range(a) && in_range(b) && in_range(c) && in_range(d) && in_range(e) &&
            ordered(a, b, c, d, e) ==> e - a > 0;
*/

bool func_check(int a, int b, int c, int d, int e, int k)
{
    int dist;
    bool result;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert in_range(d);
    //@ assert in_range(e);
    //@ assert in_range(k);
    //@ assert ordered(a, b, c, d, e);
    
    dist = e - a;
    
    //@ assert dist > 0;
    
    if (k >= dist || k == -1) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}

bool process_packet(int n, int a, int b, int c, int d, int e, int k)
{
    int processed_len;
    bool header_valid;
    
    processed_len = func_len(n);
    header_valid = func_check(a, b, c, d, e, k);
    
    //@ assert processed_len == target_result(n);
    //@ assert header_valid == (k >= (e - a) || k == -1);
    
    return header_valid;
}
