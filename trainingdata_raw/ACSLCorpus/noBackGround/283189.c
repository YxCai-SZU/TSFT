#include <stddef.h>

/*@
    requires ((a) >= 0 && (a) <= 123) && ((b) >= 0 && (b) <= 123) && ((c) >= 0 && (c) <= 123) && ((d) >= 0 && (d) <= 123) && ((e) >= 0 && (e) <= 123);
    ensures \result >= 0;
*/
int func(int a, int b, int c, int d, int e)
{
    int answers[10];
    int min_value;
    int i;
    
    // Initialize answers array
    answers[0] = a + b + c + 3;
    answers[1] = a + b + d + 3;
    answers[2] = a + b + e + 3;
    answers[3] = a + c + d + 3;
    answers[4] = a + c + e + 3;
    answers[5] = a + d + e + 3;
    answers[6] = b + c + d + 3;
    answers[7] = b + c + e + 3;
    answers[8] = b + d + e + 3;
    answers[9] = c + d + e + 3;
    
    //@ assert ((answers[0]) >= 0);
    //@ assert ((answers[1]) >= 0);
    //@ assert ((answers[2]) >= 0);
    //@ assert ((answers[3]) >= 0);
    //@ assert ((answers[4]) >= 0);
    //@ assert ((answers[5]) >= 0);
    //@ assert ((answers[6]) >= 0);
    //@ assert ((answers[7]) >= 0);
    //@ assert ((answers[8]) >= 0);
    //@ assert ((answers[9]) >= 0);
    
    min_value = answers[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant \forall integer k; 0 <= k < i ==> min_value <= answers[k];
        loop invariant \exists integer j; 0 <= j < i && min_value == answers[j];
        loop invariant min_value >= 0;
        loop assigns i, min_value;
    */
    while (i < 10)
    {
        //@ assert i >= 1 && i < 10;
        if (answers[i] < min_value)
        {
            min_value = answers[i];
        }
        i++;
    }
    
    //@ assert min_value >= 0;
    return min_value;
}
