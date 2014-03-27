#include "unity.h"
#include "Bytecode.h"
#include "Clrf.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_clrf_should_throw_error_exception__if_operand1_over_range(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CLRF,
                      .name = "clrf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xfff,
					.operand2 = 0,
					.operand3 = ACCESS
                  };
  int exception;
  
  // Test CLRF of the bytecode			  
  FSR[code.operand1] = 0x53;
  
  // Unit test
  Try{
	clrf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_RANGE, exception);
  }
  
}

void test_clrf_should_throw_error_exception__if_operand2_more_than_1_and_less_than_negative_5(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CLRF,
                      .name = "clrf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 5,
					.operand3 = 0
                  };
  int exception;
  
  // Test CLRF of the bytecode			  
  FSR[code.operand1] = 0x53;
  
  // Unit test
  Try{
	clrf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND2, exception);
  }
  
}

void test_clrf_should_throw_error_exception__if_operand3_more_than_negative_5_and_1_and_is_negative_2_and_negative_3(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CLRF,
                      .name = "clrf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 0,
					.operand3 = -3
                  };
  int exception;
  
  // Test CLRF of the bytecode			  
  FSR[code.operand1] = 0x23;
  
  // Unit test
  Try{
	clrf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND3, exception);
  }
  
}

void test_clrf_should_clear_fileReg_when_operand2_is_empty() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CLRF,
                      .name = "clrf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = -1,
					.operand3 = 0
                  };
	
  // Test CLRF of the bytecode
  FSR[code.operand1] = 0x45;
  clrf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x00, FSR[code.operand1]);
}

void test_clrf_should_clear_BSR_when_operand2_is_empty() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CLRF,
                      .name = "clrf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x41,
					.operand2 = -1,
					.operand3 = 1
                  };
	
  // Test CLRF of the bytecode
  FSR[code.operand1] = 0x8F;
  FSR[BSR] = 0x0F;
  clrf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x00, FSR[code.operand1+(FSR[BSR]<<8)]);
}

void test_clrf_should_clear_fileReg_when_operand3_is_empty() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CLRF,
                      .name = "clrf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 0,
					.operand3 = -1
                  };
	
  // Test CLRF of the bytecode
  FSR[code.operand1] = 0x45;
  clrf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x00, FSR[code.operand1]);
}

void test_clrf_should_clear_BSR_when_operand3_is_empty() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CLRF,
                      .name = "clrf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x41,
					.operand2 = BANKED,
					.operand3 = -1
                  };
	
  // Test CLRF of the bytecode
  FSR[code.operand1] = 0x8F;
  FSR[BSR] = 0x0F;
  clrf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x00, FSR[code.operand1+(FSR[BSR]<<8)]);
}

void test_clrf_should_throw_exception_error_BSR_more_than_15() {

  ExceptionError exception;
  
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CLRF,
                      .name = "clrf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x54,
					.operand2 = -1,
					.operand3 = 1
                  };
	
  // Test CLRF of the bytecode
  FSR[BSR] = 0xff;
  
  Try{
	clrf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_BSR, exception);
  }

}
