#include "unity.h"
#include "Bytecode.h"
#include "Clrf.h"

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
					.operand2 = 0
                  };
	
  // Test CLRF of the bytecode
  FSR[code.operand1] = 0xFF;
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
					.operand2 = 1
                  };
	
  // Test CLRF of the bytecode
  FSR[code.operand1] = 0xFF;
  FSR[BSR] = 0x0F;
  clrf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x00, FSR[code.operand1+(FSR[BSR]<<8)]);
}