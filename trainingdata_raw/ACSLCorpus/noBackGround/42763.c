/*@
    requires \valid_read(numbers + (0..len-1));
    requires len >= 0;
    requires len < 0x7fffffff;
    ensures \result >= -1;
    ensures \result < len;
    ensures \result == -1 ==> \forall integer k; 0 <= k < len ==> numbers[k] != target;
    ensures \result >= 0 ==> numbers[\result] == target;
    assigns \nothing;
*/
int find_index(int *numbers, int len, int target)
{
    int i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer k; 0 <= k < (i) ==> (numbers)[k] != (target));
        loop assigns i;
        loop variant len - i;
    */
    while (i < len)
    {
        //@ assert 0 <= i < len;
        if (numbers[i] == target)
        {
            //@ assert numbers[i] == target;
            return i;
        }
        //@ assert numbers[i] != target;
        i++;
    }
    return -1;
}
