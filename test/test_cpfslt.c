#include "unity.h"
#include "Bytecode.h"
#include "Cpfslt.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_cpfslt_should_throw_error_exception_if_operand1_over_range(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CPFSLT,
                      .name = "cpfslt"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xffff,
					.operand2 = 0,
					.operand3 = ACCESS
                  };
  int exception;
  
  // Unit test
  Try{
	cpfslt(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_RANGE, exception);
  }
}

void test_cpfslt_should_throw_error_exception_if_operand2_more_than_1_and_less_than_negative_5(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CPFSLT,
                      .name = "cpfslt"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = -1,
					.operand3 = -1
                  };
  int exception;
  
  // Test CPFSLT of the bytecode			  
  FSR[code.operand1] = 0x53;
  
  // Unit test
  Try{
	cpfslt(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND2, exception);
  }
}

void test_cpfslt_should_throw_error_exception__if_operand3_is_not_empty(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CPFSLT,
                      .name = "cpfslt"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 0,
					.operand3 = 1
                  };
  int exception;
  
  // Test CPFSLT of the bytecode			  
  FSR[code.operand1] = 0x23;
  
  // Unit test
  Try{
	cpfslt(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND3, exception);
  }
}

void test_cpfslt_should_skip_if_F_less_than_W_and_return_1_when_operand1_is_less_than_0x80_and_operand2_is_ACCESS_and_operand3_is_negative_1(){
  int value;
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CPFSLT,
                      .name = "cpfslt"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = ACCESS,
					.operand3 = -1
                  };
				  
  // Test CPFSLT of the bytecode			  
  FSR[code.operand1] = 0x24;
  FSR[WREG] = 0x30;
  code.absoluteAddress = 0x10;
  cpfslt(&code);

  TEST_ASSERT_EQUAL_HEX8(0x12, code.absoluteAddress);
 
}

void test_cpfslt_should_not_skip_if_F_more_than_W_and_return_0_when_operand1_is_less_than_0x80_and_operand2_is_ACCESS_and_operand3_is_negative_1(){
  int value;
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CPFSLT,
                      .name = "cpfslt"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = ACCESS,
					.operand3 = -1
                  };
				  
  // Test CPFSLT of the bytecode			  
  FSR[code.operand1] = 0x56;
  FSR[WREG] = 0x30;
  code.absoluteAddress = 0x10;
  cpfslt(&code);
  
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
 
}

void test_cpfslt_should_skip_if_F_less_than_W_and_return_1_when_operand1_is_more_than_0x80_operand2_is_ACCESS_and_operand3_is_negative_1(){
  int value;
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CPFSLT,
                      .name = "cpfslt"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xAE,
					.operand2 = ACCESS,
					.operand3 = -1
                  };
				  
  // Test CPFSLT of the bytecode			  
  FSR[code.operand1 + (0x0F00)] = 0x24;
  FSR[WREG + (0x0F00)] = 0x33;
  code.absoluteAddress = 0x10;
  cpfslt(&code);
  
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x12, code.absoluteAddress);
 
}

void test_cpfslt_should_not_skip_if_F_more_than_W_and_return_0_when_operand1_is_more_than_0x80_operand2_is_ACCESS_and_operand3_is_negative_1(){
  int value;
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CPFSLT,
                      .name = "cpfslt"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xAE,
					.operand2 = ACCESS,
					.operand3 = -1
                  };
				  
  // Test CPFSLT of the bytecode			  
  FSR[code.operand1 + (0x0F00)] = 0x24;
  FSR[WREG + (0x0F00)] = 0x13;
  code.absoluteAddress = 0x10;
  cpfslt(&code);
  
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
 
}

void test_cpfslt_should_skip_if_F_less_than_W_BSR_and_return_1_when_operand2_is_BANKED_and_operand3_is_negative_1(){
  int value;
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CPFSLT,
                      .name = "cpfslt"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x9A,
					.operand2 = BANKED,
					.operand3 = -1
                  };
				  
  // Test CPFSLT of the bytecode			  
  FSR[BSR] = 0x08;
  FSR[code.operand1 + (FSR[BSR]<<8)] = 0x34;
  FSR[WREG + (FSR[BSR]<<8)] = 0x67;
  code.absoluteAddress = 0x10;
  cpfslt(&code);
  
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x12, code.absoluteAddress);
 
}

void test_cpfslt_should_not_skip_if_F_less_than_W_BSR_and_return_0_when_operand2_is_BANKED_and_operand3_is_negative_1(){
  int value;
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CPFSLT,
                      .name = "cpfslt"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x9A,
					.operand2 = BANKED,
					.operand3 = -1
                  };
				  
  // Test CPFSLT of the bytecode			
  FSR[BSR] = 0x08;  
  FSR[code.operand1 + (FSR[BSR]<<8)] = 0x34;
  FSR[WREG + (FSR[BSR]<<8)] = 0x22;
  code.absoluteAddress = 0x10;
  cpfslt(&code);
  
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
 
}

void test_cpfslt_should_skip_if_F_more_than_W_BSR_and_return_1_when_operand2_is_BANKED_and_operand3_is_negative_1(){
  int value;
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CPFSLT,
                      .name = "cpfslt"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x9A,
					.operand2 = BANKED,
					.operand3 = -1
                  };
				  
  // Test CPFSLT of the bytecode			  
  FSR[BSR] = 0x08;
  FSR[code.operand1 + (FSR[BSR]<<8)] = 0x67;
  FSR[WREG + (FSR[BSR]<<8)] = 0x74;
  code.absoluteAddress = 0x10;
  cpfslt(&code);
  
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x12, code.absoluteAddress);
 
}

void test_cpfslt_should_not_skip_if_F_more_than_W_BSR_and_return_0_when_operand2_is_BANKED_and_operand3_is_negative_1(){
  int value;
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CPFSLT,
                      .name = "cpfslt"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x9A,
					.operand2 = BANKED,
					.operand3 = -1
                  };
				  
  // Test CPFSLT of the bytecode			  
  FSR[BSR] = 0x08;
  FSR[code.operand1 + (FSR[BSR]<<8)] = 0x67;
  FSR[WREG + (FSR[BSR]<<8)] = 0x23;
  code.absoluteAddress = 0x10;
  cpfslt(&code);
  
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
 
}

void test_cpfslt_should_throw_exception_error_BSR_more_than_15() {

  ExceptionError exception;
  
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CPFSLT,
                      .name = "cpfslt"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x54,
					.operand2 = -1,
					.operand3 = -1
                  };
	
  // Test CPFSLT of the bytecode
  FSR[BSR] = 0xff;
  
  Try{
	cpfslt(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_BSR, exception);
  }
}
