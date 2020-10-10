#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

/* Modify these two lines according to the project */
#include "DonorOperations.h"
#define PROJECT_NAME    "BloodBankManagementSystem"

/* Prototypes for all the test functions */

void test_AddDonor(void);
void test_List(void);
//void test_DeleteDonor(void);
//void test_Update(void);
//void test_Search(void);

void test_menu(void);

/* Start of the application test */
int main() {
/* Note: Do not edit START*/
  /*Initialize and setup the Test Framework */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
/* Note: Do not edit END */


  /* Add your test functions in this format for testing*/


  CU_add_test(suite, "Add", test_AddDonor);
  CU_add_test(suite, "List", test_List);
  //CU_add_test(suite, "Delete", test_DeleteDonor);
  //CU_add_test(suite, "Update", test_Update);
  //CU_add_test(suite, "Search", test_Search);
	CU_add_test(suite, "Valid", test_menu);


/* Note: Do not edit START*/
  /* Setup Test Framework to output the result to Screen */
  CU_basic_set_mode(CU_BRM_VERBOSE);

  /* run the unit test framework*/
  CU_basic_run_tests();

  /* Cleaning the Resources used by Unit test framework */
  CU_cleanup_registry();
/* Note: Do not edit END */
  return 0;
}
void test_menu(void) {
  CU_ASSERT(1 == valid_choice('2'));
  CU_ASSERT(1 == valid_choice('5'));
  CU_ASSERT(0 == valid_choice('8'));
  CU_ASSERT(0 == valid_choice('9'));
}
  void test_List(void) {
  CU_ASSERT(1 == List());
  }

void test_AddDonor(void) {

  CU_ASSERT(0 == AddDonor());
}
  /* Dummy fail*/
  //CU_ASSERT(2 == AddDonor());
//}*/
/*
void test_Update(void) {
  CU_ASSERT(0 == Update() || 1 == Update());

  /* Dummy fail*/
 // CU_ASSERT(-1 == Update());
//}*/

/*
void test_DeleteDonor(void)
{
	CU_ASSERT(0 == DeleteDonor() || 1 == DeleteDonor() || -1 == DeleteDonor());

  /* Dummy fail*/
 // CU_ASSERT(2 == DeleteDonor());
//}*/
/*
void test_List(void){
	CU_ASSERT(0 == List() || 1 == List());

  /* Dummy fail*/
  //CU_ASSERT(-1 == List());
//}*/
/*
void test_Search(void){
	CU_ASSERT(0 == Search() || 1 == Search());

  /* Dummy fail
  //CU_ASSERT(-1 == Search());
}*/
