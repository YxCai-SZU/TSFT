#include <limits.h>

/*@ predicate is_valid_time(integer t) = 0 <= t <= 23; */

/*@ predicate t1_earlier_than_t2(integer t1, integer t2) = t1 < t2; */

/*@ predicate within_d_hours(integer t1, integer t2, integer d) = 
      t1 <= t2 && t2 <= t1 + d; */

/*@ logic integer max_earliest_arrive_logic(integer t1, integer t2, integer d) =
      (t2 <= t1 + d) ? t2 : t1 + d; */

/*@ lemma ret_ge_t1: 
      \forall integer t1, t2, d; 
      is_valid_time(t1) && is_valid_time(t2) && is_valid_time(d) && 
      t1_earlier_than_t2(t1, t2) ==> 
      max_earliest_arrive_logic(t1, t2, d) >= t1; */

/*@ lemma ret_le_t2: 
      \forall integer t1, t2, d; 
      is_valid_time(t1) && is_valid_time(t2) && is_valid_time(d) && 
      t1_earlier_than_t2(t1, t2) ==> 
      max_earliest_arrive_logic(t1, t2, d) <= t2; */

/*@ lemma ret_le_t1_plus_d: 
      \forall integer t1, t2, d; 
      is_valid_time(t1) && is_valid_time(t2) && is_valid_time(d) && 
      t1_earlier_than_t2(t1, t2) ==> 
      max_earliest_arrive_logic(t1, t2, d) <= t1 + d; */

/*@ lemma within_d_case: 
      \forall integer t1, t2, d; 
      is_valid_time(t1) && is_valid_time(t2) && is_valid_time(d) && 
      t1_earlier_than_t2(t1, t2) && within_d_hours(t1, t2, d) ==> 
      max_earliest_arrive_logic(t1, t2, d) == t2; */

/*@ lemma beyond_d_case: 
      \forall integer t1, t2, d; 
      is_valid_time(t1) && is_valid_time(t2) && is_valid_time(d) && 
      t1_earlier_than_t2(t1, t2) && !within_d_hours(t1, t2, d) ==> 
      max_earliest_arrive_logic(t1, t2, d) == t1 + d; */

/*@ requires 0 <= t1 <= 23;
    requires 0 <= t2 <= 23;
    requires 0 <= d <= 23;
    requires t1 < t2;
    ensures \result >= t1;
    ensures \result <= t2;
    ensures \result <= t1 + d;
    ensures (t1 <= t2 && t2 <= t1 + d) ==> \result == t2;
    ensures (t2 > t1 + d) ==> \result == t1 + d;
    assigns \nothing;
*/
int max_earliest_arrive(int t1, int t2, int d) {
    int ret;
    
    //@ assert is_valid_time(t1);
    //@ assert is_valid_time(t2);
    //@ assert is_valid_time(d);
    //@ assert t1_earlier_than_t2(t1, t2);
    
    if (t2 <= t1 + d) {
        //@ assert within_d_hours(t1, t2, d);
        ret = t2;
    } else {
        //@ assert !within_d_hours(t1, t2, d);
        ret = t1 + d;
    }
    
    //@ assert ret == max_earliest_arrive_logic(t1, t2, d);
    return ret;
}
