// Generated C + ACSL

/*@
    requires s != \null;
    requires s_len >= 0;
    requires \valid_read(s + (0 .. s_len-1));
    assigns \nothing;
*/
void PrintStringCharacters(char* s, int s_len)
{
  /* unsupported stmt: print "parcours par élément\n"; */
  int i = 0;
/*@
  loop invariant 0 <= i <= s_len;
  loop assigns i;
  loop variant s_len - i;
*/
  while ((i < s_len))
    {
      /* unsupported stmt: print "caractere : *", s[i], "*\n"; */
      i = (i + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  char* testString = "chaine de caractere";
  PrintStringCharacters(testString, 19);;
}