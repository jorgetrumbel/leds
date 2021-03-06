/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include "cmock.h"
#include "mock_errores.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_LedsOffAfterCreate(void);
extern void test_TurnOnOneLed(void);
extern void test_TurnOffOneLed(void);
extern void test_TurnOnAndOffManyLeds(void);
extern void test_InvalidUpperLimitTurnOnLed(void);
extern void test_TurnOnAllLeds(void);
extern void test_TurnOffAllLeds(void);
extern void test_ConsultOnLed(void);
extern void test_ConsultOffLed(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_errores_Init();
}
static void CMock_Verify(void)
{
  mock_errores_Verify();
}
static void CMock_Destroy(void)
{
  mock_errores_Destroy();
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, UNITY_LINE_TYPE line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_leds.c");
  run_test(test_LedsOffAfterCreate, "test_LedsOffAfterCreate", 23);
  run_test(test_TurnOnOneLed, "test_TurnOnOneLed", 30);
  run_test(test_TurnOffOneLed, "test_TurnOffOneLed", 36);
  run_test(test_TurnOnAndOffManyLeds, "test_TurnOnAndOffManyLeds", 43);
  run_test(test_InvalidUpperLimitTurnOnLed, "test_InvalidUpperLimitTurnOnLed", 52);
  run_test(test_TurnOnAllLeds, "test_TurnOnAllLeds", 58);
  run_test(test_TurnOffAllLeds, "test_TurnOffAllLeds", 64);
  run_test(test_ConsultOnLed, "test_ConsultOnLed", 71);
  run_test(test_ConsultOffLed, "test_ConsultOffLed", 79);

  CMock_Guts_MemFreeFinal();
  return UnityEnd();
}
