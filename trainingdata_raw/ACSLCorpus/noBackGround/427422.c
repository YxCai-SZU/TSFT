#include <stdbool.h>
#include <stddef.h>

/*@ requires lenA <= lenB;
    ensures \result <= lenB - lenA + 1;
    assigns \nothing;
 */
size_t count_sub_array(int *A, size_t lenA, int *B, size_t lenB)
{
    size_t count = 0;
    size_t i = 0;
    
    if (lenA == 0 || lenB < lenA)
    {
        return count;
    }
    
    //@ assert count <= lenB - lenA + 1;
    
    /*@ loop invariant 0 <= i <= lenB - lenA + 1;
        loop invariant 0 <= count <= i;
        loop invariant count <= lenB - lenA + 1;
        loop assigns i, count;
        loop variant lenB - i;
    */
    while (i <= lenB - lenA)
    {
        bool match_found = true;
        size_t j = 0;
        
        /*@ loop invariant 0 <= j <= lenA;
            loop invariant match_found ==> (\forall size_t k; 0 <= k < (j) ==> (B)[(i) + k] == (A)[k]);
            loop assigns j, match_found;
            loop variant lenA - j;
        */
        while (j < lenA)
        {
            if (B[i + j] != A[j])
            {
                match_found = false;
                break;
            }
            j++;
        }
        
        if (match_found)
        {
            count++;
            //@ assert count <= lenB - lenA + 1;
        }
        
        i++;
        //@ assert count <= i;
    }
    
    //@ assert count <= lenB - lenA + 1;
    return count;
}
