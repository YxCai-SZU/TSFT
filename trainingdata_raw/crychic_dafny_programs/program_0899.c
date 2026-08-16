// Generated C + ACSL

/*@
    requires 0 < x <= 100;
    decreases (8 - x);
    assigns \nothing;
*/
void DFS(int x)
{
  if ((x <= 7))
  {
    //@ assert x >= 1 && x <= 7;
    //@ assert x * 2 >= 2 && x * 2 <= 14;
    //@ assert x * 2 > 7 || (x * 2 >= 1 && x * 2 <= 7);
    //@ assert x * 2 + 1 > 7 || (x * 2 + 1 >= 1 && x * 2 + 1 <= 7);
    DFS(x * 2);;
    /* unsupported stmt: print x, " "; */
    DFS(x * 2 + 1);;
  }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  //@ assert 1 > 0 && 1 <= 100;
  DFS(1);;
}