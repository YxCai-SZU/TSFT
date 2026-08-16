#include <stdbool.h>

/* First function: checks ordering/equality pattern of three numbers (1-9) */
/*@
    predicate is_valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 9 &&
        1 <= b && b <= 9 &&
        1 <= c && c <= 9;

    predicate condition_holds(integer a, integer b, integer c) =
        (a < b && b < c) ||
        (a > b && b > c) ||
        (a == b && b != c) ||
        (a != b && b == c);
*/

bool check_pattern(unsigned long long a, unsigned long long b, unsigned long long c)
{
    bool result;

    if (a < b && b < c)
    {
        //@ assert a < b && b < c;
        result = true;
    }
    else if (a > b && b > c)
    {
        //@ assert a > b && b > c;
        result = true;
    }
    else if (a == b && b != c)
    {
        //@ assert a == b && b != c;
        result = true;
    }
    else if (a != b && b == c)
    {
        //@ assert a != b && b == c;
        result = true;
    }
    else
    {
        //@ assert !(a < b && b < c) && !(a > b && b > c) && !(a == b && b != c) && !(a != b && b == c);
        result = false;
    }

    return result;
}

/* Second function: computes sum of three numbers (1-100) and checks array contains a value */
/*@ predicate in_range(integer x) = 1 <= x <= 100; */

/*@ predicate valid_inputs(integer a, integer b, integer c) = 
        in_range(a) && in_range(b) && in_range(c); */

/*@ logic integer sum(integer a, integer b, integer c) = a + b + c; */

/*@ lemma func_postcondition: 
        \forall integer a, b, c, result; 
        valid_inputs(a, b, c) && result == sum(a, b, c) ==> 
        valid_inputs(a, b, c); */

int compute_sum(int a, int b, int c)
{
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    
    int result = a + b + c;
    
    //@ assert result == sum(a, b, c);
    return result;
}

/*@ predicate contains_value(int *arr, integer len, integer value) = 
        \exists integer i; 0 <= i < len && arr[i] == value; */

/* Synthesized function: real-world scenario - "Smart Locker PIN Validation System"
   Data flow: 
   1. User enters a 3-digit PIN (each digit 1-9) for pattern validation
   2. System computes a checksum from three sensor readings (1-100 each)
   3. If pattern is valid (strictly increasing/decreasing or two equal) AND checksum is within threshold (sum <= 150), 
      the locker should unlock; otherwise it remains locked.
   Control flow: sequential composition with condition based on pattern result.
*/

/*@ predicate unlock_condition(integer a1, integer a2, integer a3, integer b1, integer b2, integer b3) =
        condition_holds(a1, a2, a3) && (sum(b1, b2, b3) <= 150);
*/

int smart_locker_unlock(unsigned long long a1, unsigned long long a2, unsigned long long a3,
                        int b1, int b2, int b3)
{
    bool pattern_valid = check_pattern(a1, a2, a3);
    int checksum = compute_sum(b1, b2, b3);
    int unlock = 0;
    
    if (pattern_valid && checksum <= 150)
    {
        unlock = 1;
    }
    
    //@ assert (unlock == 1) <==> (condition_holds(a1, a2, a3) && (sum(b1, b2, b3) <= 150));
    
    return unlock;
}
