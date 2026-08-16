#include <limits.h>

/*@ predicate valid_time(integer h, integer m) =
      h >= 0 && h <= 23 && m >= 0 && m <= 59; */

/*@ predicate time_order(integer h1, integer m1, integer h2, integer m2) =
      h1 * 60 + m1 <= h2 * 60 + m2; */

/*@ logic integer total_minutes(integer h, integer m) = h * 60 + m; */

/*@ lemma time_diff_lemma:
      \forall integer h1, m1, h2, m2, k;
      valid_time(h1, m1) && valid_time(h2, m2) &&
      time_order(h1, m1, h2, m2) &&
      k >= 0 && k <= total_minutes(h2, m2) - total_minutes(h1, m1) ==>
      total_minutes(h2, m2) - total_minutes(h1, m1) - k >= 0; */

/*@ requires valid_time(h1, m1);
    requires valid_time(h2, m2);
    requires time_order(h1, m1, h2, m2);
    requires k >= 0;
    requires k <= total_minutes(h2, m2) - total_minutes(h1, m1);
    ensures \result == total_minutes(h2, m2) - total_minutes(h1, m1) - k;
    assigns \nothing;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int t1;
    int t2;
    int time_diff;
    int not_asleep;

    //@ assert valid_time(h1, m1);
    t1 = h1 * 60 + m1;
    
    //@ assert valid_time(h2, m2);
    t2 = h2 * 60 + m2;
    
    //@ assert time_order(h1, m1, h2, m2);
    time_diff = t2 - t1;
    
    //@ assert k >= 0 && k <= time_diff;
    not_asleep = time_diff - k;
    
    //@ assert not_asleep == total_minutes(h2, m2) - total_minutes(h1, m1) - k;
    return not_asleep;
}
