// Generated C + ACSL

/*@
    requires year > 0;
    assigns \nothing;
    ensures \result <==> ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
*/
int IsLeapYear(int year)
{
  int result;
  if (((year % 4) == 0))
  {
    if (((year % 100) != 0))
    {
      result = 1;
      /*@ assert result >= 0 && result <= 2147483647; */
    }
    else
    {
      result = ((year % 400) == 0);
    }
  }
  else
  {
    result = 0;
  }
  return result;  // Dafny implicit return
}

/*@
    requires startYear > 0;
    requires endYear >= startYear;
    assigns \nothing;
*/
void PrintLeapYearsInRange(int startYear, int endYear)
{
  int currentYear = startYear;
/*@
  loop invariant startYear <= currentYear <= endYear + 1;
  loop invariant currentYear >= startYear;
  loop assigns currentYear;
  loop variant endYear - currentYear + 1;
*/
  while ((currentYear <= endYear))
    {
      int isLeap = IsLeapYear(currentYear);
      if (isLeap)
      {
        /* unsupported stmt: print "Year ", currentYear, " is a leap year\n"; */
      }
      currentYear = (currentYear + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int isLeap = IsLeapYear(2024);
  if (isLeap)
  {
    /* unsupported stmt: print "2024 is a leap year\n"; */
  }
  PrintLeapYearsInRange(2020, 2030);;
}