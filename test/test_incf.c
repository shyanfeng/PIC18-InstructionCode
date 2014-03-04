#include "unity.h"
#include "Bytecode.h"
#include "Incf.h"

void setUp() {}
void tearDown() {}

void test_incf_should_increment_fileReg_and_store_in_fileReg() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = INCF,
                      .name = "incf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xB4,
					.operand2 = 1,
					.operand3 = 0
                  };
	
  // Test incf of the bytecode
  FSR[code.operand1] = 0x40;
  incf(&code);
	
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x41, FSR[code.operand1]);
}

void test_incf_should_increment_fileReg_and_store_in_WREG() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = INCF,
                      .name = "incf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xB5,
					.operand2 = 0,
					.operand3 = 0
                  };
	
  // Test incf of the bytecode
  FSR[code.operand1] = 0xF2;
  incf(&code);
	
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0xF2, FSR[code.operand1]);
  TEST_ASSERT_EQUAL_HEX8(0xF3, FSR[WREG]);
}

void test_incf_should_increment_fileReg_and_select_BSR_and_store_in_fileReg() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = INCF,
                      .name = "incf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xB2,
					.operand2 = 1,
					.operand3 = 1
                  };
	
  // Test incf of the bytecode
  FSR[code.operand1] = 0x53;
  FSR[BSR] = 0x0C;
  FSR[code.operand1+(FSR[BSR]<<8)] = 22;
  incf(&code);

  
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(23, FSR[code.operand1+(FSR[BSR]<<8)]);
}

void test_incf_should_increment_fileReg_and_select_BSR_and_store_in_WREG() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = INCF,
                      .name = "incf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xB2,
					.operand2 = 0,
					.operand3 = 1
                  };
	
  // Test incf of the bytecode
  FSR[code.operand1] = 0x34;
  FSR[BSR] = 0x08;
  FSR[code.operand1+(FSR[BSR]<<8)] = 56;
  incf(&code);

  
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(56, FSR[code.operand1+(FSR[BSR]<<8)]);
  TEST_ASSERT_EQUAL_HEX8(57, FSR[WREG]);
}