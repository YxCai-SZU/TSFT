#include <stdbool.h>
#include <limits.h>

/* ========== Original functions (unchanged) ========== */

/* --- func1 (from snippet 1) --- */
/*@
    predicate has_seven(integer n) =
        (n / 100) % 10 == 7 ||
        (n % 100) / 10 == 7 ||
        n % 10 == 7;
*/

bool func1(unsigned long n)
{
    unsigned long n_100;
    unsigned long n_10;
    unsigned long n_1;
    bool ans;

    n_100 = n / 100;
    n_10 = n % 100 / 10;
    n_1 = n % 10;
    ans = false;

    if (n_100 == 7)
    {
        ans = true;
    }
    else if (n_10 == 7)
    {
        ans = true;
    }
    else if (n_1 == 7)
    {
        ans = true;
    }

    //@ assert ans == (n_100 == 7 || n_10 == 7 || n_1 == 7);

    return ans;
}

/* --- func2 (from snippet 2) --- */
/*@ predicate is_increasing(int *s, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> s[i] < s[j];
*/

/*@ predicate is_all_positive(int *s, integer len) =
      \forall integer i; 0 <= i < len ==> s[i] > 0;
*/

/*@ predicate is_all_within_range(int *s, integer len) =
      \forall integer i; 0 <= i < len ==> 1 <= s[i] && s[i] <= 100;
*/

bool func2(int a, int b, int c, int d)
{
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    //@ assert 1 <= d && d <= 100;
    
    if (a < b && c < b && c - a >= d) {
        return true;
    } else {
        return false;
    }
}

/* --- func3 (from snippet 3) --- */
/*@
    predicate valid_range(integer x) = 1 <= x && x <= 10000;
*/

/*@
    logic integer absolute_difference(integer x, integer y) =
        x > y ? x - y : y - x;
*/

/*@
    lemma diff_bounds:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==>
            0 <= absolute_difference(a, b) && absolute_difference(a, b) <= 9999;
*/

int func3(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int sa;
    unsigned int sc;
    int result;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    
    sa = (a > b) ? (a - b) : (b - a);
    sc = (c > d) ? (c - d) : (d - c);
    
    //@ assert sa == absolute_difference(a, b);
    //@ assert sc == absolute_difference(c, d);
    
    if (sa > sc)
    {
        //@ assert sa > sc;
        //@ assert sa - sc <= 10000;
        result = 1;
    }
    else if (sa < sc)
    {
        //@ assert sc > sa;
        //@ assert sc - sa <= 10000;
        result = -1;
    }
    else
    {
        //@ assert sa == sc;
        //@ assert sa - sc == 0;
        result = 0;
    }
    
    //@ assert result >= -1 && result <= 1;
    return result;
}

/* ========== Synthesized function ========== */

/* Scenario: A lottery number validation system.
   A 3-digit "lucky" number (100-999) is checked for containing digit 7.
   Then, four "bonus" numbers (each 1-100) are checked for a specific increasing condition.
   Finally, the "lucky" number and the four numbers are combined into two pairs,
   and their absolute differences are compared to produce a final status (-1, 0, or 1).
   The synthesized function ensures that the final status corresponds to whether
   the lucky number contains a 7 and the bonus condition holds.
*/

int lottery_validation(unsigned long lucky_number, int a, int b, int c, int d)
{
    bool has_seven_flag;
    bool condition_flag;
    int status;
    
    has_seven_flag = func1(lucky_number);
    
    condition_flag = func2(a, b, c, d);
    
    status = func3((unsigned int)lucky_number, (unsigned int)a, (unsigned int)b, (unsigned int)c);
    
    //@ assert (has_seven_flag == true && condition_flag == true) ==> (status == 1 || status == 0 || status == -1);
    
    return status;
}
