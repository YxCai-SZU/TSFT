#include <stdbool.h>
#include <limits.h>

/*@
    predicate in_range(integer x) = 0 <= x && x <= 100;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_bound:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> product(a, b) <= 10000;
    
    lemma product_comparison:
        \forall integer a, b, c, d;
            in_range(a) && in_range(b) && in_range(c) && in_range(d) ==>
            (product(a, b) <= product(c, d) <==> (a * b) <= (c * d));
*/

bool func1(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    long long left;
    long long right;
    bool result;
    
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert product(a, b) <= 10000;
    
    //@ assert in_range(c);
    //@ assert in_range(d);
    //@ assert product(c, d) <= 10000;
    
    //@ assert product(a, b) <= product(c, d) <==> (a * b) <= (c * d);
    
    left = (long long)a * (long long)b;
    right = (long long)c * (long long)d;
    
    result = left <= right;
    
    //@ assert result == (a * b <= c * d);
    return result;
}

/*@
    predicate valid_time(integer h, integer m) =
        0 <= h && h <= 23 &&
        0 <= m && m <= 59;

    predicate valid_k(integer k) =
        0 <= k && k <= 23 * 60;

    logic integer time_diff(integer h1, integer m1, integer h2, integer m2) =
        (h2 - h1) * 60 + (m2 - m1);

    lemma diff_nonnegative:
        \forall integer h1, m1, h2, m2;
        valid_time(h1, m1) && valid_time(h2, m2) && h2 >= h1 && m2 >= m1 ==>
        time_diff(h1, m1, h2, m2) >= 0;
*/

int func2(int h1, int m1, int h2, int m2, int k) {
    int waking_hours;
    int result;

    //@ assert valid_time(h1, m1);
    //@ assert valid_time(h2, m2);
    //@ assert valid_k(k);

    waking_hours = (h2 - h1) * 60 + (m2 - m1);
    //@ assert waking_hours == time_diff(h1, m1, h2, m2);

    result = waking_hours - k;
    //@ assert result == time_diff(h1, m1, h2, m2) - k;

    return result;
}

/*@
    predicate valid_schedule(integer a, integer b, integer c, integer d,
                             integer h1, integer m1, integer h2, integer m2, integer k) =
        in_range(a) && in_range(b) && in_range(c) && in_range(d) &&
        valid_time(h1, m1) && valid_time(h2, m2) && valid_k(k) &&
        (h2 > h1 || (h2 == h1 && m2 >= m1));

    predicate task_completion_valid(integer a, integer b, integer c, integer d,
                                     integer h1, integer m1, integer h2, integer m2, integer k) =
        (a * b <= c * d) == ((h2 - h1) * 60 + (m2 - m1) >= k);
*/

bool check_task_completion(unsigned int a, unsigned int b, unsigned int c, unsigned int d,
                           int h1, int m1, int h2, int m2, int k)
{
    bool product_compare;
    int time_available;
    bool result;
    
    //@ assert in_range(a) && in_range(b) && in_range(c) && in_range(d);
    //@ assert valid_time(h1, m1) && valid_time(h2, m2) && valid_k(k);
    //@ assert h2 > h1 || (h2 == h1 && m2 >= m1);
    
    product_compare = func1(a, b, c, d);
    //@ assert product_compare == (a * b <= c * d);
    
    time_available = func2(h1, m1, h2, m2, k);
    //@ assert time_available == (h2 - h1) * 60 + (m2 - m1) - k;
    //@ assert time_available >= 0 ==> (h2 - h1) * 60 + (m2 - m1) >= k;
    //@ assert time_available < 0 ==> (h2 - h1) * 60 + (m2 - m1) < k;
    
    result = product_compare == (time_available >= 0);
    
    //@ assert result == ((a * b <= c * d) == ((h2 - h1) * 60 + (m2 - m1) >= k));
    return result;
}
