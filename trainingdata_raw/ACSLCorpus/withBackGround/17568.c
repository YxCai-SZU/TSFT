/*@
    logic integer f(integer i) = i * 5;
    logic integer g(integer i) = 5 * i;
    
    predicate is_equal_f_g(integer i) = f(i) == g(i);
*/

/*@
    lemma two_multiples_equal:
        \forall integer i; f(i) == g(i);
*/

/*@
    predicate seq_equal{L1,L2}(int *a, int *b, integer len) =
        \forall integer i; 0 <= i < len ==> \at(a[i],L1) == \at(b[i],L2);
*/

/*@
    lemma two_maxes_equal{L1,L2}:
        \forall int *a, int *b, integer len;
        seq_equal{L1,L2}(a, b, len) ==>
        (\forall integer i; 0 <= i < len ==> \at(a[i],L1) == \at(b[i],L2));
*/

/*@
    lemma two_mins_equal{L1,L2}:
        \forall int *a, int *b, integer len;
        seq_equal{L1,L2}(a, b, len) ==>
        (\forall integer i; 0 <= i < len ==> \at(a[i],L1) == \at(b[i],L2));
*/

int main()
{
    //@ assert \true;
    return 0;
}
