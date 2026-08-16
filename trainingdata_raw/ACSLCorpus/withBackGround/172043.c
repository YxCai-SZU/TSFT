#include <limits.h>

/*@ predicate r_in_range(integer r) = 1 <= r && r <= 100; */

/*@ logic integer func_spec(integer r) = r * r; */

/*@
  requires r_in_range(r);
  ensures \result == func_spec(r);
  assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at top
    int result;
    
    //@ assert r_in_range(r);
    //@ assert r * r <= 10000;
    
    result = r * r;
    return result;
}

/*@ logic integer perimeter_circle_spec(integer r) = 2 * r * 3; */

/*@
  requires r_in_range(r);
  ensures \result == perimeter_circle_spec(r);
  assigns \nothing;
*/
int perimeter_circle(int r)
{
    // Variable declarations at top
    int result;
    
    //@ assert r_in_range(r);
    //@ assert 2 * r <= 200;
    //@ assert 2 * r * 3 <= 600;
    
    result = 2 * r * 3;
    return result;
}

/*@ logic integer area_circle_spec(integer r) = r * r * 3; */

/*@
  requires r_in_range(r);
  ensures \result == area_circle_spec(r);
  assigns \nothing;
*/
int area_circle(int r)
{
    // Variable declarations at top
    int result;
    
    //@ assert r_in_range(r);
    //@ assert r * r <= 10000;
    //@ assert r * r * 3 <= 30000;
    
    result = r * r * 3;
    return result;
}

/*@ lemma func_correct: \forall integer r; r_in_range(r) ==> func_spec(r) == r * r; */

/*@ lemma perimeter_correct: \forall integer r; r_in_range(r) ==> perimeter_circle_spec(r) == 2 * r * 3; */

/*@ lemma area_correct: \forall integer r; r_in_range(r) ==> area_circle_spec(r) == r * r * 3; */

int main()
{
    // Test cases
    int test1 = func(5);
    //@ assert test1 == 25;
    
    int test2 = perimeter_circle(5);
    //@ assert test2 == 30;
    
    int test3 = area_circle(5);
    //@ assert test3 == 75;
    
    return 0;
}
