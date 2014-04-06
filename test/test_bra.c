#include "unity.h"
#include "Bytecode.h"
#include "Bra.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_bra_over_range_should_throw_error(){
	int exception;
 // Create test fixture
  Instruction inst = {
                      .mnemonic = BRA,
                      .name = "bra"
                     };
					 
    Bytecode code = { .instruction = &inst,
                    .operand1 = 0xfffff,
					.operand2 = -1,
					.operand3 = -1
                  };
				  
	// Unit Test
	Try{
		bra(&code);
	}Catch(exception){
		TEST_ASSERT_EQUAL(ERROR_RANGE, exception);
	}
}

void test_bra_should_return_operand1(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BRA,
                      .name = "bra"
                     };
					 
    Bytecode code = { .instruction = &inst,
                    .operand1 = 100,
					.operand2 = -1,
					.operand3 = -1
                  };
				  
	// Test BCF of the bytecode
	bra(&code);
	
	// Unit Test
	TEST_ASSERT_EQUAL(100, code.operand1);
}