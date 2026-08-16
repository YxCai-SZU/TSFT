#include <limits.h>
#include <stdbool.h>

/*@ predicate bounds(integer n, integer m, integer x, integer a) =
      1 <= n <= 100 &&
      1 <= m <= 100 &&
      1 <= x <= 100 &&
      1 <= a <= 100;
*/

/*@ logic integer min_val(integer n, integer m) =
      n < m ? n : m;
*/

/*@ logic integer max_val(integer n, integer m) =
      n > m ? n : m;
*/

/*@ lemma min_val_bounds: \forall integer n, m;
      bounds(n, m, 1, 1) ==> 1 <= min_val(n, m) <= 100;
*/

/*@ lemma max_val_bounds: \forall integer n, m;
      bounds(n, m, 1, 1) ==> 1 <= max_val(n, m) <= 100;
*/

int func(int n, int m, int x, int a) {
    int min_val;
    int max_val;
    int max_loop;
    int i;
    
    //@ assert bounds(n, m, x, a);
    
    min_val = n < m ? n : m;
    max_val = n > m ? n : m;
    
    //@ assert min_val == min_val(n, m);
    //@ assert max_val == max_val(n, m);
    
    max_loop = x;
    i = 0;
    
    while (i < a) {
        //@ assert i < a;
        if (x + i > max_val) {
            max_loop = x + i;
        }
        //@ assert max_loop >= x;
        //@ assert max_loop <= n + m + x + a;
        i++;
    }
    
    //@ assert i == a;
    //@ assert max_loop >= x;
    //@ assert max_loop <= n + m + x + a;
    
    int result = max_loop < min_val ? min_val : max_loop;
    
    //@ assert result >= 0;
    //@ assert result <= n + m + x + a;
    
    return result;
}

/*@
    predicate is_in_range(integer n) = -40 <= n <= 40;
    predicate is_result(integer n, bool r) = r == (n >= 30);
*/

bool func2(long N)
{
    bool result;
    
    //@ assert -40 <= N <= 40;
    
    result = (N >= 30);
    
    //@ assert result == (N >= 30);
    
    return result;
}

/*@
    predicate valid_input(integer n, integer m, integer x, integer a, integer temp) =
        bounds(n, m, x, a) && is_in_range(temp) && temp >= 30;
    
    predicate output_positive(integer result) = result >= 0;
*/

int complex_function(int n, int m, int x, int a, long temp) {
    //@ assert bounds(n, m, x, a) && is_in_range(temp) && temp >= 30;
    
    int threshold = func(n, m, x, a);
    
    //@ assert threshold >= 0 && threshold <= n + m + x + a;
    
    bool flag = func2(temp);
    
    //@ assert flag == (temp >= 30);
    
    int result;
    if (flag) {
        result = threshold;
    } else {
        result = 0;
    }
    
    //@ assert result >= 0;
    
    return result;
}
