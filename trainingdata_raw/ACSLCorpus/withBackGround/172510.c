#include <limits.h>

/*@
    predicate in_range(integer x) = 400 <= x && x < 2000;
    
    logic integer compute_result(integer x) =
        x >= 1800 ? 1 :
        x >= 1600 ? 2 :
        x >= 1400 ? 3 :
        x >= 1200 ? 4 :
        x >= 1000 ? 5 :
        x >= 800 ? 6 :
        x >= 600 ? 7 : 8;
    
    lemma result_range: \forall integer x; in_range(x) ==> 1 <= compute_result(x) <= 8;
    lemma result_8_range: \forall integer x; in_range(x) && compute_result(x) == 8 ==> 400 <= x <= 599;
    lemma result_7_range: \forall integer x; in_range(x) && compute_result(x) == 7 ==> 600 <= x <= 799;
    lemma result_6_range: \forall integer x; in_range(x) && compute_result(x) == 6 ==> 800 <= x <= 999;
    lemma result_5_range: \forall integer x; in_range(x) && compute_result(x) == 5 ==> 1000 <= x <= 1199;
    lemma result_4_range: \forall integer x; in_range(x) && compute_result(x) == 4 ==> 1200 <= x <= 1399;
    lemma result_3_range: \forall integer x; in_range(x) && compute_result(x) == 3 ==> 1400 <= x <= 1599;
    lemma result_2_range: \forall integer x; in_range(x) && compute_result(x) == 2 ==> 1600 <= x <= 1799;
    lemma result_1_range: \forall integer x; in_range(x) && compute_result(x) == 1 ==> 1800 <= x <= 1999;
*/

/*@
    requires in_range(x);
    ensures \result >= 1 && \result <= 8;
    ensures \result == 8 ==> 400 <= x <= 599;
    ensures \result == 7 ==> 600 <= x <= 799;
    ensures \result == 6 ==> 800 <= x <= 999;
    ensures \result == 5 ==> 1000 <= x <= 1199;
    ensures \result == 4 ==> 1200 <= x <= 1399;
    ensures \result == 3 ==> 1400 <= x <= 1599;
    ensures \result == 2 ==> 1600 <= x <= 1799;
    ensures \result == 1 ==> 1800 <= x <= 1999;
*/
int func(int x)
{
    int result = 8;
    
    //@ assert result == 8;
    
    if (x >= 600) {
        result -= 1;
        //@ assert result == 7;
    }
    
    if (x >= 800) {
        result -= 1;
        //@ assert result == 6;
    }
    
    if (x >= 1000) {
        result -= 1;
        //@ assert result == 5;
    }
    
    if (x >= 1200) {
        result -= 1;
        //@ assert result == 4;
    }
    
    if (x >= 1400) {
        result -= 1;
        //@ assert result == 3;
    }
    
    if (x >= 1600) {
        result -= 1;
        //@ assert result == 2;
    }
    
    if (x >= 1800) {
        result -= 1;
        //@ assert result == 1;
    }
    
    //@ assert result >= 1 && result <= 8;
    return result;
}
