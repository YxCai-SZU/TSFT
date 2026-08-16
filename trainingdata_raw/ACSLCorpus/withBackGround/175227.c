#include <stdbool.h>

/*@ predicate is_valid(integer a) = 1 <= a && a <= 10; */

/*@ predicate is_target(integer a) = a == 7 || a == 5 || a == 3; */

/*@ lemma arr_property:
      \forall integer i; 0 <= i < 3 ==> (i==0 ==> 7==7) && (i==1 ==> 5==5) && (i==2 ==> 3==3); */

/*@ requires is_valid(a);
    ensures \result == true <==> is_target(a);
    assigns \nothing;
 */
bool func(unsigned long a)
{
    unsigned long arr[3] = {7, 5, 3};
    unsigned int i = 0;
    bool result = false;

    /*@ loop invariant 0 <= i <= 3;
        loop invariant is_valid(a);
        loop invariant \forall integer k; 0 <= k < i ==> a != arr[k];
        loop invariant \forall integer k; 0 <= k < 3 ==> arr[k] == arr[k];
        loop assigns i, result;
        loop variant 3 - i;
     */
    while (i < 3)
    {
        //@ assert 0 <= i < 3;
        if (a == arr[i])
        {
            result = true;
            //@ assert is_target(a);
            return result;
        }
        i += 1;
    }
    //@ assert \forall integer k; 0 <= k < 3 ==> a != arr[k];
    result = false;
    //@ assert !is_target(a);
    return result;
}
