#include <string.h>
#include "../src/input_validation.c"
#include <assert.h>

void test_find_specialty_index() {
    char specialties[5][200] = { "Computer Science", "Mathematics", "Mechanical Engineering", "Statistics", "Physics" };
    assert(find_specialty_index(specialties, 5, "Mechanical Engineering") == 2);
    assert(find_specialty_index(specialties, 5, "Economics") == -1);
    assert(find_specialty_index(specialties, 5, "Computer Science") == 0);
    assert(find_specialty_index(specialties, 5, "Physics") == 4);
}

void test_is_valid_string() {
    assert(is_valid_string("James Kuk") == 1);
    assert(is_valid_string("") == 0);
    assert(is_valid_string("James./@") == 0);
    assert(is_valid_string("James+-") == 0);
}

void test_is_valid_degree() {
    assert(is_valid_degree("Bachelor") == 1);
    assert(is_valid_degree("Master") == 1);
    assert(is_valid_degree("master") == 0);
    assert(is_valid_degree("bachelor") == 0);
    assert(is_valid_degree("hfgf") == 0);
    assert(is_valid_degree("564") == 0);
}

void test_get_valid_double() {
    double result = get_valid_double("Enter a positive number: ");
    assert(result == 3.05);
}

void test_get_valid_int() {
    int result = get_valid_int("Enter a positive integer: ");
    assert(result == 42);
}

void test_is_profession() {
    assert(is_profession("Lecturer") == 1);
    assert(is_profession("Dean") == 1);
    assert(is_profession("gfghfg") == 0);
    assert(is_profession("4564") == 0);
}

void test_file_exists() {
    assert(file_exists("existing_file.txt") == 1);
    assert(file_exists("hfghf.txt") == 0);
}

int main() {
    test_is_valid_string();
    test_find_specialty_index();
    test_is_valid_degree();
    test_get_valid_double();
    test_get_valid_int();
    test_is_profession();
    test_file_exists();
    printf("All tests passed! \n");
}
