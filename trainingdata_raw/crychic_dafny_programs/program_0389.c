int Foo(int n);

/*@
    assigns \nothing;
*/
void Main(void)
{
  int x = Foo(2);
  /*@ assert \true; */
  /* unsupported stmt: print x, " ", x.good?, "\n"; */
  int y = Foo(5);
  /*@ assert \true; */
  /* unsupported stmt: print y, " ", y.good?, "\n"; */
}