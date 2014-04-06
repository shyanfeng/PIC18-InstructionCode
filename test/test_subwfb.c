#include "unity.h"
#include "Bytecode.h"
#include "Subwfb.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_subwfb_over_range_should_throw_error(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = SUBWFB,
                      .name = "subwfb"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xffff,
					.operand2 = 0,
					.operand3 = ACCESS
                  };
  int exception;	  
  
  // Unit test
  Try{
	subwfb(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_RANGE, exception);
  }
  
}

void test_subwfb_should_throw_error_exception__if_operand2_more_than_1_and_less_than_negative_5(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = SUBWFB,
                      .name = "subwfb"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x12,
					.operand2 = 8,
					.operand3 = ACCESS
                  };
  int exception;	

  // Test INCF of the bytecode			  
  FSR[code.operand1] = 0x53;
  
  // Unit test
  Try{
	subwfb(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND2, exception);
  }
  
}

void test_subwfb_should_throw_error_exception__if_operand3_more_than_1_and_less_than_negative_5(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = SUBWFB,
                      .name = "subwfb"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x12,
					.operand2 = 1,
					.operand3 = -8
                  };
  int exception;	

  // Test INCF of the bytecode			  
  FSR[code.operand1] = 0x53;
  
  // Unit test
  Try{
	subwfb(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND3, exception);
  }
  
}

void test_subwfb_should_subtract_W_from_f_with_borrow_when_operand1_less_than_80_and_operand2_is_F_and_operand3_is_ACCESS(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = SUBWFB,
                      .name = "subwfb"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x12,
					.operand2 = F,
					.operand3 = ACCESS
                  };
				  
  // Test SUBWFB of the bytecode			  
  FSR[code.operand1] = 0x19;
  FSR[WREG] = 0x0D;
  FSR[STATUS] = 0x1;
  code.absoluteAddress = 0x10;
  subwfb(&code);

  
  //Unit test
  TEST_ASSERT_EQUAL_HEX8(0x0E, FSR[code.operand1]);
  TEST_ASSERT_EQUAL_HEX8(0x0D, FSR[WREG]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
  
}

void test_subwfb_should_throw_exception_error_BSR_more_than_15(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = SUBWFB,
                      .name = "subwfb"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x12,
					.operand2 = 0,
					.operand3 = ACCESS
                  };
  int exception;	  
  // Test SUBWFB of the bytecode	
  FSR[BSR] = 0xff;
  
  // Unit test
  Try{
	subwfb(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_BSR, exception);
  }
  
}


