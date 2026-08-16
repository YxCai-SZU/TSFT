#include <stdint.h>
#include <stdbool.h>

/* ========== Function 1: func1 ========== */
int64_t func1(int64_t k, int64_t n)
{
    int64_t ans;
    ans = 0;
    if (n - 2 * k >= 0)
    {
        ans = 1;
    }
    return ans;
}

/* ========== Function 2: func2 ========== */
/*@
    predicate valid_array(int *a, integer len) =
        len >= 3 &&
        1 <= a[0] <= 100 &&
        1 <= a[1] <= 100 &&
        1 <= a[2] <= 100;

    predicate is_sorted(int *a) =
        a[0] < a[1] && a[1] < a[2];
*/

bool func2(int *a)
{
    bool ans;
    ans = (a[0] < a[1] && a[1] < a[2]) ? true : false;
    return ans;
}

/* ========== Function 3: func3 ========== */
/*@
    predicate is_odd(integer n) = n % 2 == 1;
    predicate both_odd(integer x, integer y) = is_odd(x) && is_odd(y);
*/

bool func3(unsigned int x, unsigned int y)
{
    bool x_is_odd;
    bool y_is_odd;
    unsigned int n;
    
    n = x;
    while (n >= 2)
    {
        n -= 2;
    }
    x_is_odd = (n == 1);
    
    n = y;
    while (n >= 2)
    {
        n -= 2;
    }
    y_is_odd = (n == 1);
    
    return x_is_odd && y_is_odd;
}

/*@
    lemma modulo_equivalence:
        \forall integer x; 0 < x < 7 ==> 
        (x % 2 != 0) == (x % 2 == 1);
*/

/* ========== Main synthesized function: validate_team_roster ========== */
/*@
    predicate strong_team(int jersey1, int jersey2, int *scores) =
        (jersey2 - 2 * jersey1 >= 0) && 
        (scores[0] < scores[1] < scores[2]) && 
        (jersey1 % 2 == 1 && jersey2 % 2 == 1);
*/

bool validate_team_roster(int jersey1, int jersey2, int *scores)
{
    bool qualifies;
    bool sorted;
    bool both_odd;
    
    qualifies = (func1(jersey1, jersey2) == 1);
    
    sorted = func2(scores);
    
    both_odd = func3((unsigned int)jersey1, (unsigned int)jersey2);
    
    return qualifies && sorted && both_odd;
}

int main()
{
    return 0;
}
