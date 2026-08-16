// Generated C + ACSL

/*@
    requires s_len > 0;
    requires s != \null;
    requires \valid_read(s + (0 .. s_len-1));
    requires \forall integer i; 0 <= i < s_len ==> s[i] != \null;
    requires \forall integer i; 0 <= i < s_len ==> \valid_read(s[i] + (0 .. 1));
    assigns \nothing;
    ensures \exists integer i; 0 <= i < s_len && \result == s[i][0] &&
            (\forall integer j; 0 <= j < s_len ==> s[i][1] <= s[j][1]);
*/
int MinSecondValueFirst(int** s, int s_len)
{
  int minSecondIndex = 0;
  {
    int i = 1;
/*@
  loop invariant 1 <= i <= s_len;
  loop invariant 0 <= minSecondIndex < s_len;
  loop invariant minSecondIndex < i;
  loop invariant \forall integer j; 0 <= j < i ==> s[minSecondIndex][1] <= s[j][1];
  loop invariant minSecondIndex == \at(minSecondIndex, LoopEntry) ||
                 (\exists integer k; \at(i, LoopEntry) <= k < i && minSecondIndex == k);
  loop assigns i, minSecondIndex;
  loop variant s_len - i;
*/
    while ((i < s_len))
      {
        if ((s[i][1] < s[minSecondIndex][1]))
        {
          minSecondIndex = i;
        }
        i = (i + 1);
      }
  }
  /*@ assert 0 <= minSecondIndex < s_len; */
  /*@ assert \forall integer j; 0 <= j < s_len ==> s[minSecondIndex][1] <= s[j][1]; */
  int firstOfMinSecond = s[minSecondIndex][0];
  /*@ assert firstOfMinSecond == s[minSecondIndex][0]; */
  /*@ assert \forall integer j; 0 <= j < s_len ==> s[minSecondIndex][1] <= s[j][1]; */
  return firstOfMinSecond;  // Dafny implicit return
}