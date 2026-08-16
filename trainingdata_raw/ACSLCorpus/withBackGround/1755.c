/*@
    predicate valid_string(char *s, integer len) =
        len == 4 &&
        \forall integer i; 0 <= i < len ==> ('0' <= s[i] && s[i] <= '9') &&
        s[0] != '0';

    logic integer count_twos(char *s, integer len, integer idx) =
        idx <= 0 ? 0 :
        (s[idx-1] == '2' ? 1 : 0) + count_twos(s, len, idx-1);

    lemma count_bounds:
        \forall char *s, integer len, integer idx;
        valid_string(s, len) && 0 <= idx <= len ==>
        0 <= count_twos(s, len, idx) <= idx;
*/

/*@
    requires \valid(s+(0..3));
    requires valid_string(s, 4);
    ensures 0 <= \result <= 4;
    assigns \nothing;
*/
unsigned int func(char *s)
{
    unsigned int count = 0;
    unsigned int index = 0;
    
    /*@
        loop invariant 0 <= index <= 4;
        loop invariant 0 <= count <= index;
        loop invariant count == count_twos(s, 4, index);
        loop assigns index, count;
        loop variant 4 - index;
    */
    while (index < 4)
    {
        //@ assert 0 <= index < 4;
        if (s[index] == '2')
        {
            //@ assert s[index] == '2';
            count += 1;
        }
        index += 1;
    }
    //@ assert index == 4;
    //@ assert count == count_twos(s, 4, 4);
    return count;
}
