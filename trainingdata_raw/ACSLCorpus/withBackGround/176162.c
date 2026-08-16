#include <stdbool.h>

/*@ predicate multiple_of_3_or_5(integer n) = 
      n % 3 == 0 || n % 5 == 0; */

/*@ predicate multiple_of_3_and_5(integer n) = 
      n % 3 == 0 && n % 5 == 0; */

/*@ lemma mod_3_loop_preservation:
      \forall integer n, temp;
        temp >= 0 && temp <= n && temp % 3 == n % 3 ==>
        (temp - 3 >= 0 ==> (temp - 3) % 3 == n % 3); */

/*@ lemma mod_5_loop_preservation:
      \forall integer n, temp;
        temp >= 0 && temp <= n && temp % 5 == n % 5 ==>
        (temp - 5 >= 0 ==> (temp - 5) % 5 == n % 5); */

/*@ requires true; 
    ensures \result ==> multiple_of_3_or_5(n);
    ensures \result ==> (n % 3 == 0 || n % 5 == 0); */
bool is_multiple_of_3_or_5(unsigned int n)
{
    bool is_multiple = false;
    unsigned int i = 0;
    
    /*@ loop invariant 0 <= i <= 2;
        loop invariant is_multiple ==> (n % 3 == 0 || n % 5 == 0);
        loop assigns is_multiple, i;
        loop variant 2 - i; */
    while (i < 2)
    {
        if (i == 0)
        {
            unsigned int temp = n;
            
            /*@ loop invariant temp >= 0;
                loop invariant temp <= n;
                loop invariant temp % 3 == n % 3;
                loop assigns temp;
                loop variant temp; */
            while (temp >= 3)
            {
                temp -= 3;
                //@ assert temp % 3 == n % 3;
            }
            
            if (temp == 0)
            {
                is_multiple = true;
            }
        }
        else
        {
            unsigned int temp = n;
            
            /*@ loop invariant temp >= 0;
                loop invariant temp <= n;
                loop invariant temp % 5 == n % 5;
                loop assigns temp;
                loop variant temp; */
            while (temp >= 5)
            {
                temp -= 5;
                //@ assert temp % 5 == n % 5;
            }
            
            if (temp == 0)
            {
                is_multiple = true;
            }
        }
        
        i += 1;
    }
    
    return is_multiple;
}
