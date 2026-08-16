#include <stddef.h>
#include <stdint.h>

/*@
  requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
  ensures \result >= -1 && \result <= 3;
*/
int func(int a, int b, int c)
{
    int v[3];
    int i;
    int j;
    int temp_i;
    int temp_j;
    int counter;
    int k;
    int ans;
    
    v[0] = a;
    v[1] = b;
    v[2] = c;
    
    //@ assert ((3) == 3 &&       \forall integer k; 0 <= k < (3) ==> (1 <= ((&v[0])[k]) <= 100));
    
    i = 0;
    /*@ loop invariant 0 <= i <= 3;
        loop invariant ((3) == 3 &&
      \forall integer k; 0 <= k < (3) ==> (1 <= ((&v[0])[k]) <= 100));
        loop assigns i, j, v[0..2], temp_i, temp_j;
        loop variant 3 - i; */
    while (i < 3)
    {
        j = i + 1;
        /*@ loop invariant i < j <= 3;
            loop invariant ((3) == 3 &&
      \forall integer k; 0 <= k < (3) ==> (1 <= ((&v[0])[k]) <= 100));
            loop assigns j, v[0..2], temp_i, temp_j;
            loop variant 3 - j; */
        while (j < 3)
        {
            if (v[i] > v[j])
            {
                temp_i = v[i];
                temp_j = v[j];
                v[i] = temp_j;
                v[j] = temp_i;
            }
            //@ assert ((3) == 3 &&       \forall integer k; 0 <= k < (3) ==> (1 <= ((&v[0])[k]) <= 100));
            j++;
        }
        i++;
    }
    
    counter = 0;
    k = 0;
    /*@ loop invariant 0 <= k <= 2;
        loop invariant ((3) == 3 &&
      \forall integer k; 0 <= k < (3) ==> (1 <= ((&v[0])[k]) <= 100));
        loop invariant counter >= 0 && counter <= k;
        loop assigns k, counter;
        loop variant 2 - k; */
    while (k < 2)
    {
        if (v[k] == v[k + 1])
        {
            counter++;
        }
        k++;
    }
    
    if (counter == 3)
    {
        ans = 1;
    }
    else if (counter == 0)
    {
        ans = 3;
    }
    else
    {
        ans = 2;
    }
    
    //@ assert ans >= -1;
    //@ assert ans <= 3;
    
    return ans;
}
