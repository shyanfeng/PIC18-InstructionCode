#include "unity.h"
#include "Bytecode.h"
#include "Bcf.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_bcf_should_throw_error_exception__if_operand1_over_range(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xfff,
					.operand2 = 0,
					.operand3 = ACCESS
                  };
  int exception;
  
  // Test BCF of the bytecode			  
  FSR[code.operand1] = 0x53;
  
  // Unit test
  Try{
	bcf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_RANGE, exception);
  }
  
}

void test_bcf_should_throw_error_exception__if_operand2_more_than_7_and_less_than_0(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = -1,
					.operand3 = ACCESS
                  };
  int exception;
  
  // Test BCF of the bytecode			  
  FSR[code.operand1] = 0x53;
  
  // Unit test
  Try{
	bcf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND2, exception);
  }
  
}

void test_bcf_should_throw_error_exception__if_operand3_more_than_negative_5_and_1_and_is_negative_2_and_negative_3(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 0,
					.operand3 = -3
                  };
  int exception;
  
  // Test BCF of the bytecode			  
  FSR[code.operand1] = 0x23;
  
  // Unit test
  Try{
	bcf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND3, exception);
  }
  
}

void test_bcf_should_clear_seventh_bit_to_0(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 7,
					.operand3 = 0
                  };
	
  // Test BCF of the bytecode
  FSR[code.operand1] = 0xC7;
  bcf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x47, FSR[code.operand1]);
}

void test_bcf_should_clear_sixth_bit_to_0() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 6,
					.operand3 = 0
                  };
	
  // Test BCF of the bytecode
  FSR[code.operand1] = 0xD7;
  bcf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x97, FSR[code.operand1]);
}

void test_bcf_should_clear_fifth_bit_to_0() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 5,
					.operand3 = 0
                  };
	
  // Test BCF of the bytecode
  FSR[code.operand1] = 0xE7;
  bcf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0xC7, FSR[code.operand1]);
}

void test_bcf_should_clear_fourth_bit_to_0() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 4,
					.operand3 = ACCESS
                  };
	
  // Test BCF of the bytecode
  FSR[code.operand1] = 0x57;
  bcf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x47, FSR[code.operand1]);
}

void test_bcf_should_clear_third_bit_to_0() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 3,
					.operand3 = -1
                  };
	
  // Test BCF of the bytecode
  FSR[code.operand1] = 0xAC;
  bcf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0xA4, FSR[code.operand1]);
}

void test_bcf_should_clear_second_bit_to_0() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 2,
					.operand3 = ACCESS
                  };
	
  // Test BCF of the bytecode
  FSR[code.operand1] = 0x7D;
  bcf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x79, FSR[code.operand1]);
}

void test_bcf_should_clear_first_bit_to_0() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 1,
					.operand3 = -1
                  };
	
  // Test BCF of the bytecode
  FSR[code.operand1] = 0x6B;
  bcf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x69, FSR[code.operand1]);
}

void test_bcf_should_clear_zero_bit_to_0() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 0,
					.operand3 = 0
                  };
	
  // Test BCF of the bytecode
  FSR[code.operand1] = 0xE7;
  bcf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0xE6, FSR[code.operand1]);
}

void test_bcf_should_clear_seventh_bit_to_0_BSR() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x41,
					.operand2 = 7,
					.operand3 = 1
                  };
	
  // Test BCF of the bytecode
  FSR[code.operand1 +(FSR[BSR]<<8)] = 0x8F;
  bcf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x0F, FSR[code.operand1 + (FSR[BSR]<<8)]);
}

void test_bcf_should_clear_sixth_bit_to_0_BSR() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x41,
					.operand2 = 6,
					.operand3 = BANKED
                  };
	
  // Test BCF of the bytecode
  FSR[code.operand1 +(FSR[BSR]<<8)] = 0x72;
  bcf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x32, FSR[code.operand1 + (FSR[BSR]<<8)]);
}

void test_bcf_should_clear_fifth_bit_to_0_BSR() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x41,
					.operand2 = 5,
					.operand3 = -4
                  };
	
  // Test BCF of the bytecode
  FSR[code.operand1+(FSR[BSR]<<8)] = 0x6A;
  bcf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x4A, FSR[code.operand1 + (FSR[BSR]<<8)]);
}

void test_bcf_should_clear_fourth_bit_to_0_BSR() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x41,
					.operand2 = 4,
					.operand3 = 1
                  };
	
  // Test BCF of the bytecode
  FSR[code.operand1+(FSR[BSR]<<8)] = 0xD3;
  bcf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0xC3, FSR[code.operand1 + (FSR[BSR]<<8)]);
}

void test_bcf_should_clear_third_bit_to_0_BSR() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x41,
					.operand2 = 3,
					.operand3 = BANKED
                  };
	
  // Test BCF of the bytecode
  FSR[code.operand1+(FSR[BSR]<<8)] = 0xFB;
  bcf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0xF3, FSR[code.operand1 + (FSR[BSR]<<8)]);
}

void test_bcf_should_clear_second_bit_to_0_BSR() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x41,
					.operand2 = 2,
					.operand3 = -4
                  };
	
  // Test BCF of the bytecode
  FSR[code.operand1+(FSR[BSR]<<8)] = 0xAF;
  bcf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0xAB, FSR[code.operand1 + (FSR[BSR]<<8)]);
}

void test_bcf_should_clear_first_bit_to_0_BSR() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x41,
					.operand2 = 1,
					.operand3 = 1
                  };
	
  // Test BCF of the bytecode
  FSR[code.operand1+(FSR[BSR]<<8)] = 0xC3;
  bcf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0xC1, FSR[code.operand1 + (FSR[BSR]<<8)]);
}

void test_bcf_should_clear_zero_bit_to_0_BSR() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x41,
					.operand2 = 0,
					.operand3 = 1
                  };
	
  // Test BCF of the bytecode
  FSR[code.operand1+(FSR[BSR]<<8)] = 0x73;
  bcf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x72, FSR[code.operand1 + (FSR[BSR]<<8)]);
}

void test_bcf_should_throw_exception_error_BSR_more_than_15() {

  ExceptionError exception;
  
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BCF,
                      .name = "bcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x54,
					.operand2 = 0,
					.operand3 = 1
                  };
	
  // Test BCF of the bytecode
  FSR[BSR] = 0xff;
  
  Try{
	bcf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_BSR, exception);
  }

}



