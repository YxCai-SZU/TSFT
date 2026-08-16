// Generated C + ACSL

/*@
    requires s != \null;
    requires s_len >= 0;
    requires \valid_read(s + (0 .. s_len-1));
    assigns \nothing;
*/
void PrintString(char* s, int s_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= s_len;
  loop assigns i;
  loop variant s_len - i;
*/
  while ((i < s_len))
    {
      /* unsupported stmt: print s[i]; */
      i = (i + 1);
    }
  /* unsupported stmt: print "\n"; */
}

/*@
    requires arr != \null;
    requires arr_len > 0;
    requires \valid(arr + (0 .. arr_len-1));
    requires \valid_read(arr[0 .. arr_len-1]);
    assigns \nothing;
*/
void PrintStringArray(char** arr, int arr_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= arr_len;
  loop assigns i;
  loop variant arr_len - i;
*/
  while ((i < arr_len))
    {
      /* unsupported stmt: print arr[i]; */
      i = (i + 1);
    }
  /* unsupported stmt: print "\n"; */
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  char* str = "abcd";
  char* strArr[4];
  strArr[0] = "a";
  strArr[1] = "b";
  strArr[2] = "c";
  strArr[3] = "d";
  PrintStringArray(strArr, 4);;
  /* unsupported stmt: print "<< This is same >>\n"; */
  PrintString(str, 4);;
}