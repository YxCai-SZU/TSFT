// Generated C + ACSL

void BooleanIfExample(void);
void IfElseExample(void);
void NumberComparisonExample(void);
void TruthyFalsyExample(void);
void AndOrExample(void);
void TernaryExample(void);

/*@
    assigns \nothing;
*/
void Main(void)
{
  BooleanIfExample();;
  IfElseExample();;
  NumberComparisonExample();;
  TruthyFalsyExample();;
  AndOrExample();;
  TernaryExample();;
}

/*@
    assigns \nothing;
*/
void BooleanIfExample(void)
{
  int check = 1;
  if (check)
  {
    /* unsupported stmt: print "1 block\n"; */
  }
}

/*@
    assigns \nothing;
*/
void IfElseExample(void)
{
  int check = 0;
  if (check)
  {
    /* unsupported stmt: print "1 block\n"; */
  }
  else
  {
    /* unsupported stmt: print "0 block\n"; */
  }
}

/*@
    assigns \nothing;
*/
void NumberComparisonExample(void)
{
  int number = 5;
  if ((number == 5))
  {
    /* unsupported stmt: print "number is 5\n"; */
  }
}

/*@
    requires \true;
    assigns \nothing;
*/
void TruthyFalsyExample(void)
{
  int number = 0;
  if ((number != 0))
  {
    /* unsupported stmt: print "Truthy block for number\n"; */
  }
  if ((number == 0))
  {
    /* unsupported stmt: print "Falsy block for 0\n"; */
  }
  char *name = "Vinay";
  int name_len = 5;
  if ((name_len > 0))
  {
    /* unsupported stmt: print "Truthy block for string\n"; */
  }
}

/*@
    assigns \nothing;
*/
void AndOrExample(void)
{
  int number = 5;
  char *name = "Vinay";
  if (((number == 5) && (name != 0)))
  {
    /* unsupported stmt: print "And Block\n"; */
  }
}

/*@
    assigns \nothing;
*/
void TernaryExample(void)
{
  int a = 3;
  int b = 4;
  if ((a > b))
  {
    /* unsupported stmt: print "Bigger\n"; */
  }
  else
  {
    /* unsupported stmt: print "Smaller\n"; */
  }
  int size = 1;
  char *personality = (size) ? ("Big") : ("Small");
  /* unsupported stmt: print "The cat is ", personality, "\n"; */
}