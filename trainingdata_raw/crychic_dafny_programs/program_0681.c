// Generated C + ACSL

#include <stddef.h>

typedef struct {
  int temp;
  int humidity;
  int pressure;
  int rain;
} WeatherData;

typedef struct {
  int has_value;
  WeatherData data;
} Option;

typedef struct {
  int isAuthenticated;
} API;

static API api = {0};
static int isAuthenticated = 0;
static int collectedDataCount = 0;

/*@
    assigns isAuthenticated;
    ensures \old(isAuthenticated) ==> isAuthenticated;
    ensures \result ==> isAuthenticated;
    ensures \result == 1 || \result == 0;
*/
int Authenticate(void)
{
  int success = 1;
  /*@ assert success >= 0 && success <= 2147483647; */
  if (success)
  {
    isAuthenticated = 1;
    /*@ assert isAuthenticated >= 0 && isAuthenticated <= 2147483647; */
  }
  return success;
}

/*@
    requires isAuthenticated;
    assigns \nothing;
    ensures \result.has_value == 0 || \result.has_value == 1;
    ensures \result.has_value == 1 ==> (
        \result.data.humidity >= 0 &&
        \result.data.humidity <= 100 &&
        \result.data.rain >= 0
    );
*/
Option CollectData(void)
{
  int temp = 20;
  int humidity = 50;
  int pressure = 1013;
  int rain = 0;
  if (((humidity >= 0) && (humidity <= 100)))
  {
    Option result;
    result.has_value = 1;
    result.data.temp = temp;
    result.data.humidity = humidity;
    result.data.pressure = pressure;
    result.data.rain = rain;
    return result;
  }
  Option none;
  none.has_value = 0;
  return none;
}

/*@
    requires collectedDataCount >= 0;
    requires collectedDataCount < 2147483647;
    assigns isAuthenticated, api, collectedDataCount;
    ensures \result == 1 ==> isAuthenticated;
    ensures \result == 0 || \result == 1;
    ensures collectedDataCount >= \old(collectedDataCount);
    ensures collectedDataCount <= \old(collectedDataCount) + 1;
*/
int StartInsertingData(void)
{
  int success = Authenticate();
  /*@ assert success >= 0 && success <= 2147483647; */
  /*@ assert success == 1 ==> isAuthenticated; */
  if (!(success))
  {
    /*@ assert collectedDataCount == \at(collectedDataCount, Pre); */
    return 0;
  }
  /*@ assert isAuthenticated; */
  /*@ assert collectedDataCount >= 0; */
  /*@ assert collectedDataCount < 2147483647; */
  Option data = CollectData();
  /*@ assert data.has_value == 0 || data.has_value == 1; */
  if (data.has_value)
  {
    /*@ assert collectedDataCount < 2147483647; */
    collectedDataCount = (collectedDataCount + 1);
    /*@ assert collectedDataCount >= 0 && collectedDataCount <= 2147483647; */
    /*@ assert collectedDataCount == \at(collectedDataCount, Pre) + 1; */
    return 1;
  }
  /*@ assert collectedDataCount == \at(collectedDataCount, Pre); */
  return 0;
}