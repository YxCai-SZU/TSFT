// Generated C + ACSL

/*@
    requires s != \null;
    requires s_len > 0;
    requires \valid_read(s + (0 .. s_len-1));
    assigns \nothing;
    ensures \forall integer i; 0 <= i < s_len ==> \result <= s[i];
    ensures \exists integer i; 0 <= i < s_len && \result == s[i];
*/
int FindSmallest(int* s, int s_len)
{
  int min = s[0];
  /*@ assert \exists integer k; k == 0 && min == s[k]; */
  {
    int i = 1;
/*@
  loop invariant 1 <= i <= s_len;
  loop invariant \forall integer k; 0 <= k < i ==> min <= s[k];
  loop invariant \exists integer k; 0 <= k < i && min == s[k];
  loop assigns i, min;
  loop variant s_len - i;
*/
    while ((i < s_len))
      {
        if ((s[i] < min))
        {
          min = s[i];
          /*@ assert min == s[i]; */
          /*@ assert \exists integer k; 0 <= k <= i && min == s[k]; */
        }
        /*@ assert \forall integer k; 0 <= k <= i ==> min <= s[k]; */
        i = (i + 1);
      }
    /*@ assert i == s_len; */
    /*@ assert \forall integer k; 0 <= k < s_len ==> min <= s[k]; */
    /*@ assert \exists integer k; 0 <= k < s_len && min == s[k]; */
  }
  return min;
}