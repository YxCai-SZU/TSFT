#include <limits.h>

/*@
    predicate is_permutation(integer a, integer b, integer c, integer val) =
        val == (a * 10 + b + c) ||
        val == (a + b * 10 + c) ||
        val == (a + b + c * 10);

    lemma permutations_definition:
        \forall integer a, b, c, k;
            0 <= k < 3 ==>
            (k == 0 ==> is_permutation(a, b, c, a * 10 + b + c)) &&
            (k == 1 ==> is_permutation(a, b, c, a + b * 10 + c)) &&
            (k == 2 ==> is_permutation(a, b, c, a + b + c * 10));
*/

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result >= 0;
    ensures is_permutation(a, b, c, \result);
*/
int func(int a, int b, int c)
{
    int answer = INT_MIN;
    int permutations[3];
    int i = 0;
    
    permutations[0] = a * 10 + b + c;
    permutations[1] = a + b * 10 + c;
    permutations[2] = a + b + c * 10;
    
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant answer >= INT_MIN;
        loop invariant \forall integer k; 0 <= k < i ==> answer >= permutations[k];
        loop invariant i == 0 ==> answer == INT_MIN;
        loop invariant i > 0 ==> 
            is_permutation(a, b, c, answer);
        loop invariant \forall integer k; 0 <= k < 3 ==> 
            is_permutation(a, b, c, permutations[k]);
        loop assigns i, answer;
        loop variant 3 - i;
    */
    while (i < 3)
    {
        int current_value = permutations[i];
        //@ assert is_permutation(a, b, c, current_value);
        
        if (current_value > answer)
        {
            answer = current_value;
        }
        //@ assert answer >= INT_MIN;
        //@ assert \forall integer k; 0 <= k <= i ==> answer >= permutations[k];
        
        i++;
    }
    
    //@ assert answer >= 0;
    //@ assert is_permutation(a, b, c, answer);
    return answer;
}
