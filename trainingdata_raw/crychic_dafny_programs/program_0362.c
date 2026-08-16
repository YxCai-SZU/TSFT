// Generated C + ACSL

/*@
    requires s != \null;
    requires s_len >= 0;
    requires \valid_read(s + (0 .. s_len-1));
    assigns \nothing;
    ensures \result == 1 <==>
        (\forall integer i; 0 <= i < s_len ==>
            (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' ||
             s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' ||
             s[i] == '8' || s[i] == '9'));
    ensures \result == 0 <==>
        (\exists integer i; 0 <= i < s_len &&
            !(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' ||
              s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' ||
              s[i] == '8' || s[i] == '9'));
*/
int allDigits(char* s, int s_len)
{
  int result = 1;
  /*@ assert result >= 0 && result <= 2147483647; */
  {
    int i = 0;
/*@
  loop invariant 0 <= i <= s_len;
  loop invariant \forall integer ii; 0 <= ii < i ==>
    (s[ii] == '0' || s[ii] == '1' || s[ii] == '2' || s[ii] == '3' ||
     s[ii] == '4' || s[ii] == '5' || s[ii] == '6' || s[ii] == '7' ||
     s[ii] == '8' || s[ii] == '9');
  loop invariant result == 1;
  loop assigns i;
  loop variant s_len - i;
*/
    while ((i < s_len))
      {
        /*@ assert 0 <= i < s_len; */
        /*@ assert \valid_read(&s[i]); */
        if (!(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' ||
              s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' ||
              s[i] == '8' || s[i] == '9'))
        {
          /*@ assert !(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' ||
                       s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' ||
                       s[i] == '8' || s[i] == '9'); */
          /*@ assert 0 <= i < s_len; */
          /*@ assert \exists integer j; 0 <= j < s_len &&
                !(s[j] == '0' || s[j] == '1' || s[j] == '2' || s[j] == '3' ||
                  s[j] == '4' || s[j] == '5' || s[j] == '6' || s[j] == '7' ||
                  s[j] == '8' || s[j] == '9'); */
          return 0;
        }
        /*@ assert s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' ||
                   s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' ||
                   s[i] == '8' || s[i] == '9'; */
        i = (i + 1);
      }
    /*@ assert i == s_len; */
    /*@ assert \forall integer ii; 0 <= ii < s_len ==>
          (s[ii] == '0' || s[ii] == '1' || s[ii] == '2' || s[ii] == '3' ||
           s[ii] == '4' || s[ii] == '5' || s[ii] == '6' || s[ii] == '7' ||
           s[ii] == '8' || s[ii] == '9'); */
  }
  return result;
}