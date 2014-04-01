/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
    CEXCEPTION_T e; \
    Try { \
      setUp(); \
      TestFunc(); \
    } Catch(e) { TEST_ASSERT_EQUAL_HEX32_MESSAGE(CEXCEPTION_NONE, e, "Unhandled Exception!"); } \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>
#include "CException.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_clrf_should_throw_error_exception__if_operand1_over_range(void);
extern void test_clrf_should_throw_error_exception__if_operand2_more_than_1_and_less_than_negative_5(void);
extern void test_clrf_should_clear_fileReg_when_if_operand3_more_than_negative_5_and_1_and_is_negative_2_and_negative_3(void);
extern void test_clrf_should_clear_fileReg_when_operand1_is_less_than_0x80_operand2_is_empty_and_operand3_is_0(void);
extern void test_clrf_should_clear_fileReg_when_operand1_is_more_than_0x80_operand2_is_empty_and_operand3_is_ACCESS(void);
extern void test_clrf_should_clear_BSR_is_more_than_0_and_less_than_15_when_operand2_is_empty_and_operand3_is_1(void);
extern void test_clrf_should_clear_fileReg_when_operand1_is_less_than_0x80_and_operand2_is_0_and_operand3_is_empty(void);
extern void test_clrf_should_clear_fileReg_when_operand1_is_more_than_0x80_and_operand2_is_ACCESS_and_operand3_is_empty(void);
extern void test_clrf_should_clear_BSR_is_more_than_0_and_less_than_15_when_operand2_is_BANKED_and_operand3_is_empty(void);
extern void test_clrf_should_throw_exception_error_BSR_more_than_15(void);


//=======Test Reset Option=====
void resetTest()
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "test_clrf.c";
  UnityBegin();
  RUN_TEST(test_clrf_should_throw_error_exception__if_operand1_over_range, 9);
  RUN_TEST(test_clrf_should_throw_error_exception__if_operand2_more_than_1_and_less_than_negative_5, 35);
  RUN_TEST(test_clrf_should_clear_fileReg_when_if_operand3_more_than_negative_5_and_1_and_is_negative_2_and_negative_3, 61);
  RUN_TEST(test_clrf_should_clear_fileReg_when_operand1_is_less_than_0x80_operand2_is_empty_and_operand3_is_0, 87);
  RUN_TEST(test_clrf_should_clear_fileReg_when_operand1_is_more_than_0x80_operand2_is_empty_and_operand3_is_ACCESS, 108);
  RUN_TEST(test_clrf_should_clear_BSR_is_more_than_0_and_less_than_15_when_operand2_is_empty_and_operand3_is_1, 129);
  RUN_TEST(test_clrf_should_clear_fileReg_when_operand1_is_less_than_0x80_and_operand2_is_0_and_operand3_is_empty, 150);
  RUN_TEST(test_clrf_should_clear_fileReg_when_operand1_is_more_than_0x80_and_operand2_is_ACCESS_and_operand3_is_empty, 170);
  RUN_TEST(test_clrf_should_clear_BSR_is_more_than_0_and_less_than_15_when_operand2_is_BANKED_and_operand3_is_empty, 190);
  RUN_TEST(test_clrf_should_throw_exception_error_BSR_more_than_15, 211);

  return (UnityEnd());
}
