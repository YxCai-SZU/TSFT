#include <stdbool.h>

/*@ requires (1 <= (a) <= 10000 &&
      1 <= (b) <= 10000 &&
      1 <= (c) <= 10000 &&
      1 <= (d) <= 10000);
    ensures \result == a + c || \result == a + d || 
            \result == b + c || \result == b + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int v[4];
    int index;
    int max_val;
    int i;
    
    v[0] = a + c;
    v[1] = a + d;
    v[2] = b + c;
    v[3] = b + d;
    
    index = 0;
    max_val = v[0];
    i = 1;
    
    /*@ loop invariant 0 <= i <= 4;
        loop invariant 0 <= index < 4;
        loop invariant \exists integer k; 0 <= k < i && max_val == v[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_val >= v[j];
        loop invariant v[0] == a + c;
        loop invariant v[1] == a + d;
        loop invariant v[2] == b + c;
        loop invariant v[3] == b + d;
        loop invariant (1 <= (a) <= 10000 &&
      1 <= (b) <= 10000 &&
      1 <= (c) <= 10000 &&
      1 <= (d) <= 10000);
        loop assigns i, max_val, index;
        loop variant 4 - i;
    */
    while (i < 4)
    {
        //@ assert 0 <= i < 4;
        if (v[i] > max_val)
        {
            max_val = v[i];
            index = i;
        }
        i = i + 1;
    }
    
    //@ assert \exists integer k; 0 <= k < 4 && v[index] == v[k];
    //@ assert v[index] == a + c || v[index] == a + d || v[index] == b + c || v[index] == b + d;
    return v[index];
}
