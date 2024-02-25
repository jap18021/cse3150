#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "student.h"

TEST_CASE("Student Tests") {
    SUBCASE("calculate_grade") {
        student s;
        s.mscore = 40;
        s.fscore = 50;
        s.hwgrades = {0, 0, 0};

        double expected_score = 0.3 * s.mscore + 0.3 * s.fscore + 0.4 * ((0 + 0 + 0) / 3.0);
        double actual_score = calculate_grade(s);
        CHECK(actual_score == doctest::Approx(expected_score));
    }

    SUBCASE("getStudent") {
        std::stringstream input("123\nHu Tao\n50\n40\n0\n0\n0\n-1\n");
        std::cin.rdbuf(input.rdbuf());

        student s = getStudent();

        CHECK(s.id == 123);
        CHECK(s.name == "Hu Tao");
        CHECK(s.fscore == 50);
        CHECK(s.mscore == 40);
        CHECK(s.hwgrades == std::vector<int>{0, 0, 0});
    }

    SUBCASE("printStudent") {
        student s;
        s.id = 123;
        s.name = "Hu Tao";
        s.fscore = 50;
        s.mscore = 40;
        s.hwgrades = {0, 0, 0};

        std::stringstream output;
        std::streambuf* old_cout = std::cout.rdbuf(output.rdbuf());
        printStudent(s);
        std::cout.rdbuf(old_cout);

        std::string expected_output = "Student ID: 123\nStudent Name: Hu Tao\nFinal Exam Score: 50\nMidterm Exam Score: 40\nHomework Grades: 0 0 0 \nTotal Class Score: ";
        CHECK(output.str().find(expected_output) != std::string::npos);
    }
}
