#include <stdbool.h>

/*@ predicate is_odd(integer x) = x % 2 == 1; */

/*@ predicate subset_of(integer set1_min, integer set1_max, 
                        integer set2_min, integer set2_max) = 
    set1_min >= set2_min && set1_max <= set2_max; */

/*@ predicate disjoint(integer min1, integer max1, 
                       integer min2, integer max2) = 
    max1 < min2 || min1 > max2; */

/*@ lemma test3_lemma1: 
    \forall integer x; (x == 1 || x == 3 || x == 5 || x == 7 || x == 9) && x < 8 ==> x == 1 || x == 3 || x == 5 || x == 7; */

/*@ lemma test3_lemma2: 
    \forall integer x; (x == 1 || x == 3 || x == 5 || x == 7 || x == 9) ==> is_odd(x); */

/*@ lemma test3_lemma3: 
    \forall integer x; (x == 1 || x == 3 || x == 5 || x == 7 || x == 9) ==> x >= 1; */

/*@ lemma test3_lemma4: 
    \forall integer x; (x == 3 || x == 5 || x == 7 || x == 9) ==> (x == 3 || x == 5 || x == 7 || x == 9); */

/*@ lemma test3_lemma5: true; */

/*@
  requires 0 <= X <= 9 && 0 <= A <= 9;
  ensures (X < A ==> \result == 0) && (X >= A ==> \result == 10);
  assigns \nothing;
*/
int func(int X, int A)
{
    int result;
    if (X < A) {
        result = 0;
        //@ assert result == 0;
    } else {
        result = 10;
        //@ assert result == 10;
    }
    return result;
}

/*@ assigns \nothing; */
void test3()
{
    //@ assert (1 == 1 || 1 == 3 || 1 == 5 || 1 == 7 || 1 == 9) && 1 < 8;
    //@ assert (3 == 1 || 3 == 3 || 3 == 5 || 3 == 7 || 3 == 9) && 3 < 8;
    //@ assert (5 == 1 || 5 == 3 || 5 == 5 || 5 == 7 || 5 == 9) && 5 < 8;
    //@ assert (7 == 1 || 7 == 3 || 7 == 5 || 7 == 7 || 7 == 9) && 7 < 8;
    //@ assert !((9 == 1 || 9 == 3 || 9 == 5 || 9 == 7 || 9 == 9) && 9 < 8);
    
    //@ assert subset_of(1, 9, 1, 2147483647);
    //@ assert disjoint(1, 9, 0, 0);
    //@ assert (3 == 3 || 3 == 5 || 3 == 7 || 3 == 9);
    //@ assert true;
}
