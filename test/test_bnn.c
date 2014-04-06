#include "unity.h"
#include "Bytecode.h"
#include "Bnn.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_bnn_over_range_should_throw_error(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BNN,
                      .name = "bnn"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xffff,
					.operand2 = 0,
					.operand3 = ACCESS
                  };
  int exception;
  
  // Unit test
  Try{
	bnn(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_RANGE, exception);
  }
}

void test_bnn_should_branch_and_return_operand1(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BNN,
                      .name = "bnn"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x55,
					.operand2 = 0,
					.operand3 = ACCESS
                  };

  // Test BCF of the bytecode
	bnn(&code);
  
  // Unit test
  TEST_ASSERT_EQUAL(0x55, code.operand1);
}

void test_bnn_should_not_branch_and_return_absoluteAddress(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BNN,
                      .name = "bnn"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x55,
					.operand2 = 0,
					.operand3 = ACCESS
                  };

  // Test BCF of the bytecode
	code.absoluteAddress = 0x20;
	FSR[STATUS] = 0b00010000;
	bnn(&code);
  
  // Unit test
  TEST_ASSERT_EQUAL(0x21, code.absoluteAddress);
}
