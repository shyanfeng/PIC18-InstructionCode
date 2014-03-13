#include "unity.h"
#include "Bytecode.h"
#include "Clrf.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_clrf_should_clear_fileReg() {
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

void test_clrf_should_clear_BSR() {
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
	//TEST_ASSERT_EQUAL(0xff, FSR[0x54]);
	TEST_ASSERT_EQUAL(ERROR_BSR, exception);
  }

}

void test_clrf_operand1_should_throw_exception_more_than_255_or_less_than_0(){
  ExceptionError exception;
  
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CLRF,
                      .name = "clrf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xfff,
					.operand2 = -1,
					.operand3 = 1
                  };
	
  // Test CLRF of the bytecode
  
  Try{
	clrf(&code);
  }
  Catch(exception){
	//TEST_ASSERT_EQUAL(0xff, FSR[0x54]);
	TEST_ASSERT_EQUAL(ERROR_RANGE, exception);
  }
}