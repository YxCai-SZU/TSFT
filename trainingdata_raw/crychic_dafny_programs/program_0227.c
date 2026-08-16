// Generated C + ACSL

/*@
    requires seq1 != \null;
    requires seq2 != \null;
    requires seq1_len >= 0;
    requires seq2_len >= 0;
    requires \valid_read(seq1 + (0 .. seq1_len-1));
    requires \valid_read(seq2 + (0 .. seq2_len-1));
    assigns \nothing;
    ensures \result == 1 <==>
        (\exists integer i; 0 <= i < seq1_len &&
            (\exists integer j; 0 <= j < seq2_len && seq1[i] == seq2[j]));
    ensures \result == 0 <==>
        (\forall integer i; 0 <= i < seq1_len ==>
            (\forall integer j; 0 <= j < seq2_len ==> seq1[i] != seq2[j]));
*/
int AnyValueExists(int* seq1, int seq1_len, int* seq2, int seq2_len)
{
  int result = 0;
  /*@ assert result >= 0 && result <= 2147483647; */
  {
    int i = 0;
/*@
  loop invariant 0 <= i <= seq1_len;
  loop invariant result == 0 || result == 1;
  loop invariant result == 1 ==> (\exists integer k; 0 <= k < i && (\exists integer m; 0 <= m < seq2_len && seq1[k] == seq2[m]));
  loop invariant result == 0 ==> (\forall integer k; 0 <= k < i ==> (\forall integer m; 0 <= m < seq2_len ==> seq1[k] != seq2[m]));
  loop assigns i, result;
  loop variant seq1_len - i;
*/
    while ((i < seq1_len))
      {
        int found = 0;
        /*@
          loop invariant 0 <= j <= seq2_len;
          loop invariant found == 0 || found == 1;
          loop invariant found == 1 ==> (\exists integer m; 0 <= m < j && seq1[i] == seq2[m]);
          loop invariant found == 0 ==> (\forall integer m; 0 <= m < j ==> seq1[i] != seq2[m]);
          loop assigns j, found;
          loop variant seq2_len - j;
        */
        for (int j = 0; j < seq2_len; j++) {
          if (seq1[i] == seq2[j]) {
            found = 1;
            break;
          }
        }
        if (found)
        {
          result = 1;
          break;
        }
        i = (i + 1);
      }
  }
  return result;
}