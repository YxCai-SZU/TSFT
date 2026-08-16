#include <stdbool.h>

/*@
    predicate has_seven(integer n) =
        n / 100 == 7 || (n / 10) % 10 == 7 || n % 10 == 7;
*/

/*@
    predicate diff_in_range(integer a, integer b, integer c, integer d, integer e) =
        0 <= a < b < c < d < e <= 123;

    logic integer abs_diff(integer x, integer y) =
        x > y ? x - y : y - x;

    logic integer max_of_four(integer d1, integer d2, integer d3, integer d4) =
        (d1 >= d2 && d1 >= d3 && d1 >= d4) ? d1 :
        (d2 >= d3 && d2 >= d4) ? d2 :
        (d3 >= d4) ? d3 : d4;

    lemma max_is_one_of:
        \forall integer d1, d2, d3, d4;
        max_of_four(d1,d2,d3,d4) == d1 ||
        max_of_four(d1,d2,d3,d4) == d2 ||
        max_of_four(d1,d2,d3,d4) == d3 ||
        max_of_four(d1,d2,d3,d4) == d4;
*/

bool func1(int n)
{
    int a0;
    int a1;
    int a2;
    
    //@ assert 100 <= n <= 999;
    
    a0 = n / 100;
    a1 = (n / 10) % 10;
    a2 = n % 10;
    
    //@ assert a0 == n / 100;
    //@ assert a1 == (n / 10) % 10;
    //@ assert a2 == n % 10;
    
    return a0 == 7 || a1 == 7 || a2 == 7;
}

bool func2(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int k)
{
    unsigned int diff1;
    unsigned int diff2;
    unsigned int diff3;
    unsigned int diff4;
    unsigned int max_diff;

    //@ assert 0 <= a < b < c < d < e <= 123;
    //@ assert 0 <= k <= 123;

    diff1 = a > b ? a - b : b - a;
    diff2 = b > c ? b - c : c - b;
    diff3 = c > d ? c - d : d - c;
    diff4 = d > e ? d - e : e - d;

    //@ assert diff1 == abs_diff(a,b);
    //@ assert diff2 == abs_diff(b,c);
    //@ assert diff3 == abs_diff(c,d);
    //@ assert diff4 == abs_diff(d,e);

    max_diff = diff1;
    if (max_diff < diff2) {
        max_diff = diff2;
    }
    if (max_diff < diff3) {
        max_diff = diff3;
    }
    if (max_diff < diff4) {
        max_diff = diff4;
    }

    //@ assert max_diff == max_of_four(diff1,diff2,diff3,diff4);
    //@ assert max_diff == diff1 || max_diff == diff2 || max_diff == diff3 || max_diff == diff4;

    return max_diff <= k;
}

bool check_lucky_sequence(int n, unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int k)
{
    
    bool has_lucky = func1(n);
    bool is_compact = func2(a, b, c, d, e, k);
    
    //@ assert (has_lucky == true <==> has_seven(n)) && (is_compact == true <==> (b - a <= k && c - b <= k && d - c <= k && e - d <= k));
    
    return has_lucky && is_compact;
}
