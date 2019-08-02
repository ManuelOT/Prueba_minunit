#include "minunit.h"
#include "../Suma/suma.h"


MU_TEST(test_suma) {
	mu_check(10 == suma(3, 7));
	mu_assert(-21 == suma(-7, -14), "Pruebo suma negativo");
	mu_assert_int_eq(5, suma(0, 5));
}



MU_TEST_SUITE(test_suite) {
	//MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(test_suma);
	/*MU_RUN_TEST(test_assert);
	MU_RUN_TEST(test_assert_int_eq);
	MU_RUN_TEST(test_assert_double_eq);

	MU_RUN_TEST(test_check_fail);
	MU_RUN_TEST(test_assert_fail);
	MU_RUN_TEST(test_assert_int_eq_fail);
	MU_RUN_TEST(test_assert_double_eq_fail);

	MU_RUN_TEST(test_string_eq);
	MU_RUN_TEST(test_string_eq_fail);

	MU_RUN_TEST(test_fail);*/
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}

