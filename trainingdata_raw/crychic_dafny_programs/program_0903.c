// Generated C + ACSL

/*@
    requires n > 0;
    assigns \nothing;
*/
void PrintDashes(int n)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= n;
  loop assigns i;
  loop variant n - i;
*/
  while ((i < n))
    {
      /* unsupported stmt: print "-"; */
      i = (i + 1);
    }
  /* unsupported stmt: print "\n"; */
}

/*@
    requires msg != \null;
    requires msg_len >= 0;
    requires \valid_read(msg + (0 .. msg_len-1));
    assigns \nothing;
*/
void PrintMessage(char* msg, int msg_len)
{
  PrintDashes(30);;
  /* unsupported stmt: print msg, "\n"; */
  PrintDashes(30);;
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  PrintMessage("        VITOR SKT        ", 25);;
  PrintMessage("        VITOR SZ        ", 25);;
  PrintMessage("        VITOR SK        ", 25);;
}