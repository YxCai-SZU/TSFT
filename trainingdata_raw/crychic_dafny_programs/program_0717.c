// Generated C + ACSL

/*@
    requires year >= 1583;
    requires 1 <= month <= 12;
    requires 1 <= day <= 31;
    requires month > 2 ==> year > 1583 || (year == 1583 && month >= 10);
    assigns \nothing;
    ensures 0 <= \result <= 6;
*/
int GetDayOfWeek(int year, int month, int day)
{
  int m;
  int y;
  if ((month <= 2))
  {
    m = (month + 12);
    y = (year - 1);
  }
  else
  {
    m = month;
    y = year;
  }
  int k = (y % 100);
  int j = (y / 100);
  int h = ((((((day + ((13 * (m + 1)) / 5)) + k) + (k / 4)) + (j / 4)) - (2 * j)) % 7);
  if ((h < 0))
  {
    h = (h + 7);
  }
  int weekday = ((h + 5) % 7);
  /*@ assert weekday >= 0 && weekday <= 2147483647; */
  return weekday;
}

/*@
    requires 0 <= weekday <= 6;
    assigns \nothing;
    ensures \result != \null;
    ensures \valid_read(\result);
*/
char* GetChineseWeekday(int weekday)
{
  char* name;
  switch (weekday) {
    case 0:
      name = "星期一";
      break;
    case 1:
      name = "星期二";
      break;
    case 2:
      name = "星期三";
      break;
    case 3:
      name = "星期四";
      break;
    case 4:
      name = "星期五";
      break;
    case 5:
      name = "星期六";
      break;
    case 6:
      name = "星期日";
      break;
    default:
      name = "";
      break;
  }
  return name;
}

/*@
    requires year >= 1583;
    requires 1 <= month <= 12;
    requires 1 <= day <= 31;
    requires month > 2 ==> (year > 1583 || (year == 1583 && month >= 10));
    assigns \nothing;
    ensures \result != \null;
    ensures \valid_read(\result);
*/
char* GetWeek(int year, int month, int day)
{
  int weekday = GetDayOfWeek(year, month, day);
  char* weekdayName = GetChineseWeekday(weekday);
  return weekdayName;
}