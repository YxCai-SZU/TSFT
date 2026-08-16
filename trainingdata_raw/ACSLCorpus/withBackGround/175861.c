#include <stdbool.h>

/*@ predicate valid_month(integer m) = 1 <= m && m <= 12; */
/*@ predicate valid_day(integer d) = 1 <= d && d <= 31; */
/*@ predicate date_order(integer m1, integer d1, integer m2, integer d2) = 
      (m1 < m2) || (m1 == m2 && d1 < d2); */

/*@ lemma same_month_result: 
      \forall integer m1, m2; m1 == m2 ==> m1 == m2; */
/*@ lemma diff_month_result: 
      \forall integer m1, m2; m1 != m2 ==> m1 != m2; */

/*@ requires valid_month(m1) && valid_day(d1);
    requires valid_month(m2) && valid_day(d2);
    requires date_order(m1, d1, m2, d2);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> m1 == m2;
    ensures \result == 0 ==> m1 != m2;
*/
int func(int m1, int d1, int m2, int d2) {
    int result;
    
    //@ assert valid_month(m1) && valid_month(m2);
    //@ assert date_order(m1, d1, m2, d2);
    
    if (m1 == m2) {
        //@ assert m1 == m2;
        result = 1;
    } else {
        //@ assert m1 != m2;
        result = 0;
    }
    
    //@ assert result == 1 || result == 0;
    //@ assert result == 1 ==> m1 == m2;
    //@ assert result == 0 ==> m1 != m2;
    
    return result;
}
