/**
 * \file test.c
 * \author Adrien GARROUSTE
 * \brief Tests linked list
 * \version 0.1
 * \date 2020-10-05
 * \copyright No copyright, no right
 */

#include <stdio.h>
#include "../headers/tests_utils.h"
#include "../headers/link.h"

void display_status(int nb_tests, int nb_success);
void test_add_at_begin_first_val(int * nb_tests, int * nb_success);
void test_add_at_begin_three_values(int * nb_tests, int * nb_success);
void test_add_at_end_three_values(int * nb_tests, int * nb_success);
void test_remove_at_begin(int * nb_tests, int * nb_success);
void test_remove_at_begin_zero_values(int * nb_tests, int * nb_success);
void test_remove_at_end(int * nb_tests, int * nb_success);
void test_remove_at_end_zero_values(int * nb_tests, int * nb_success);
void test_remove_first_occur_one_occur(int * nb_tests, int * nb_success);
void test_remove_first_occur_no_occur(int * nb_tests, int * nb_success);
void test_remove_first_occur_several_occur(int * nb_tests, int * nb_success);
void test_empty_zero_values(int * nb_tests, int * nb_success);
void test_empty_several_values(int * nb_tests, int * nb_success);
void test_remove_all_occur_several_occur(int * nb_tests, int * nb_success);
void test_remove_all_occur_no_occur(int * nb_tests, int * nb_success);

/**
 * \brief Launch tests
 * \return return error code 
 */
int main(void) {

    int nb_tests = 0, nb_success = 0;

    test_add_at_begin_first_val(&nb_tests, &nb_success);
    test_add_at_begin_three_values(&nb_tests, &nb_success);
    test_add_at_end_three_values(&nb_tests, &nb_success);
    test_remove_at_begin(&nb_tests, &nb_success);
    test_remove_at_begin_zero_values(&nb_tests, &nb_success);
    test_remove_at_end(&nb_tests, &nb_success);
    test_remove_at_end_zero_values(&nb_tests, &nb_success);
    test_remove_first_occur_one_occur(&nb_tests, &nb_success);
    test_remove_first_occur_no_occur(&nb_tests, &nb_success);
    test_remove_first_occur_several_occur(&nb_tests, &nb_success);
    test_empty_zero_values(&nb_tests, &nb_success);
    test_empty_several_values(&nb_tests, &nb_success);
    //test_remove_all_occur_several_occur(&nb_tests, &nb_success);
    //test_remove_all_occur_no_occur(&nb_tests, &nb_success);

    display_status(nb_tests, nb_success);
}

/**
 * \brief Display the number of passed tests
 * \param nb_tests Number of tests
 * \param nb_success Number of passed tests
 */
void display_status(int nb_tests, int nb_success) {
    printf("PASSED %d / %d\n", nb_success, nb_tests);
}

/**
 * \brief Test add_at_begin function with one value
 * \param nb_tests number of total tests
 * \param nb_success number of passed tests
 */
void test_add_at_begin_first_val(int * nb_tests, int * nb_success) {

    List list;

    create(&list);

    add_at_begin(&list, 12);

    if (count(list) == 1) {
        (*nb_success)++;
    } else {
        printf("Fail : test_add_at_begin_first_val\n");
    }

    (*nb_tests)++;
}

/**
 * \brief Test add_at_begin function with three values
 * \param nb_tests number of total tests
 * \param nb_success number of passed tests
 */
void test_add_at_begin_three_values(int * nb_tests, int * nb_success) {

    List list;
    int expected[] = { 98, 10, 12 };
    int * result;

    create(&list);

    add_at_begin(&list, 12);
    add_at_begin(&list, 10);
    add_at_begin(&list, 98);

    result = to_array(list);

    if (count(list) == 3 && compare(expected, 3, result, 3) == 0) {
        (*nb_success)++;
    } else {
        printf("Fail : test_add_at_begin_three_values\n");
    }

    (*nb_tests)++;
}

/**
 * \brief Test add_at_end function with three values
 * \param nb_tests number of total tests
 * \param nb_success number of passed tests
 */
void test_add_at_end_three_values(int * nb_tests, int * nb_success) {

    List list;
    int expected[] = { 12, 10, 98 };
    int * result;

    create(&list);

    add_at_end(&list, 12);
    add_at_end(&list, 10);
    add_at_end(&list, 98);

    result = to_array(list);

    if (count(list) == 3 && compare(expected, 3, result, 3) == 0) {
        (*nb_success)++;
    } else {
        printf("Fail : test_add_at_end_three_values\n");
    }

    (*nb_tests)++;
}

/**
 * \brief Test remove_at_begin function
 * \param nb_tests number of total tests
 * \param nb_success number of passed tests
 */
void test_remove_at_begin(int * nb_tests, int * nb_success) {

    List list;
    int expected[] = { 10, 98 };
    int * result;

    create(&list);

    add_at_end(&list, 12);
    add_at_end(&list, 10);
    add_at_end(&list, 98);

    remove_at_begin(&list);

    result = to_array(list);

    if (count(list) == 2 && compare(expected, 2, result, 2) == 0) {
        (*nb_success)++;
    } else {
        printf("Fail : test_remove_at_begin\n");
    }

    (*nb_tests)++;
}

/**
 * \brief Test test_remove_at_begin_zero_values function
 * \param nb_tests number of total tests
 * \param nb_success number of passed tests
 */
void test_remove_at_begin_zero_values(int * nb_tests, int * nb_success) {

    List list;

    create(&list);

    remove_at_begin(&list);

    if (count(list) == 0) {
        (*nb_success)++;
    } else {
        printf("Fail : test_remove_at_begin_zero_values\n");
    }

    (*nb_tests)++;
}

/**
 * \brief Test remove_at_end function
 * \param nb_tests number of total tests
 * \param nb_success number of passed tests
 */
void test_remove_at_end(int * nb_tests, int * nb_success) {

    List list;
    int expected[] = { 10, 12 };
    int * result;

    create(&list);

    add_at_end(&list, 10);
    add_at_end(&list, 12);
    add_at_end(&list, 98);

    remove_at_end(&list);

    result = to_array(list);

    if (count(list) == 2 && compare(expected, 2, result, 2) == 0) {
        (*nb_success)++;
    } else {
        printf("Fail : test_remove_at_end\n");
    }

    (*nb_tests)++;
}

/**
 * \brief Test remove_at_end function
 * with no value in list
 * \param nb_tests number of total tests
 * \param nb_success number of passed tests
 */
void test_remove_at_end_zero_values(int * nb_tests, int * nb_success) {

    List list;

    create(&list);

    remove_at_end(&list);

    if (count(list) == 0) {
        (*nb_success)++;
    } else {
        printf("Fail : test_remove_at_end_zero_values\n");
    }

    (*nb_tests)++;
}

/**
 * \brief Test remove_first_occur function
 * with one occurence
 * \param nb_tests number of total tests
 * \param nb_success number of passed tests
 */
void test_remove_first_occur_one_occur(int * nb_tests, int * nb_success) {

    List list;
    int expected[] = { 10, 30 };
    int * result;

    create(&list);

    add_at_end(&list, 10);
    add_at_end(&list, 20);
    add_at_end(&list, 30);

    remove_first_occur(&list, 20);

    result = to_array(list);

    if (count(list) == 2 && compare(expected, 2, result, 2) == 0) {
        (*nb_success)++;
    } else {
        printf("Fail : test_remove_first_occur_one_occur\n");
    }

    (*nb_tests)++;
}

/**
 * \brief Test remove_first_occur function
 * with no occurence
 * \param nb_tests number of total tests
 * \param nb_success number of passed tests
 */
void test_remove_first_occur_no_occur(int * nb_tests, int * nb_success) {

    List list;
    int expected[] = { 10, 20, 30 };
    int * result;

    create(&list);

    add_at_end(&list, 10);
    add_at_end(&list, 20);
    add_at_end(&list, 30);

    remove_first_occur(&list, 90);

    result = to_array(list);

    if (count(list) == 3 && compare(expected, 3, result, 3) == 0) {
        (*nb_success)++;
    } else {
        printf("Fail : test_remove_first_occur_no_occur\n");
    }

    (*nb_tests)++;
}

/**
 * \brief Test remove_first_occur function
 * with several occurences
 * \param nb_tests number of total tests
 * \param nb_success number of passed tests
 */
void test_remove_first_occur_several_occur(int * nb_tests, int * nb_success) {

    List list;
    int expected[] = { 10, 30, 20, 30 };
    int * result;

    create(&list);

    add_at_end(&list, 30);
    add_at_end(&list, 10);
    add_at_end(&list, 30);
    add_at_end(&list, 20);
    add_at_end(&list, 30);

    remove_first_occur(&list, 30);

    result = to_array(list);

    if (count(list) == 4 && compare(expected, 4, result, 4) == 0) {
        (*nb_success)++;
    } else {
        printf("Fail : test_remove_first_occur_several_occur\n");
    }

    (*nb_tests)++;
}

/**
 * \brief Test empty function
 * with zero values
 * \param nb_tests number of total tests
 * \param nb_success number of passed tests
 */
void test_empty_zero_values(int * nb_tests, int * nb_success) {

    List list;

    create(&list);

    empty(&list);

    if (count(list) == 0) {
       (*nb_success)++;
    } else {
        printf("Fail : test_empty_zero_values\n");
    }

    (*nb_tests)++;
}

/**
 * \brief Test empty function
 * with several values
 * \param nb_tests number of total tests
 * \param nb_success number of passed tests
 */
void test_empty_several_values(int * nb_tests, int * nb_success) {

    List list;

    create(&list);

    add_at_end(&list, 1);
    add_at_end(&list, 1);
    add_at_end(&list, 1);
    add_at_end(&list, 1);
    add_at_end(&list, 1);

    empty(&list);

    if (count(list) == 0) {
       (*nb_success)++;
    } else {
        printf("Fail : test_empty_several_values\n");
    }

    (*nb_tests)++;
}

/**
 * \brief Test remove_all_occur function
 * with several occurences
 * \param nb_tests number of total tests
 * \param nb_success number of passed tests
 */
void test_remove_all_occur_several_occur(int * nb_tests, int * nb_success) {

    List list;
    int expected[] = { 10, 20 };
    int * result;
    create(&list);

    add_at_end(&list, 30);
    add_at_end(&list, 10);
    add_at_end(&list, 30);
    add_at_end(&list, 20);
    add_at_end(&list, 30);

    remove_all_occur(&list, 30);

    result = to_array(list);

    display_arr(result, 10);

    if (count(list) == 2 && compare(expected, 2, result, 2) == 0) {
        (*nb_success)++;
    } else {
        printf("Fail : test_remove_all_occur_several_occur\n");
    }

    (*nb_tests)++;
}

/**
 * \brief Test remove_all_occur function
 * with no occurences
 * \param nb_tests number of total tests
 * \param nb_success number of passed tests
 */
void test_remove_all_occur_no_occur(int * nb_tests, int * nb_success) {

    List list;
    int expected[] = { 10, 20, 30 };
    int * result;

    create(&list);

    add_at_end(&list, 10);
    add_at_end(&list, 20);
    add_at_end(&list, 30);

    remove_all_occur(&list, 90);

    result = to_array(list);

    if (count(list) == 3 && compare(expected, 3, result, 3) == 0) {
        (*nb_success)++;
    } else {
        printf("Fail : test_remove_all_occur_no_occur\n");
    }

    (*nb_tests)++;
}