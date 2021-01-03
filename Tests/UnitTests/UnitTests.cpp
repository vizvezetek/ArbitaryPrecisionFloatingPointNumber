#include "../../Fpn.cpp"
#include <gtest/gtest.h>

//ASSIGNMENT OPERATORS [ = + - / * ]
TEST(unitTests, assign_equal){
    Fpn f1(std::to_string((double)100),100);
    Fpn f2 = f1;
    ASSERT_EQ(f1, f2);
}

TEST(unitTests, assign_add){
    Fpn f1(std::to_string((double)100),100);
    Fpn f2(std::to_string((double)100),100);
    Fpn result(std::to_string((double)200),100);
    ASSERT_EQ(result, f1+f2);
}

TEST(unitTests, assign_subtract){
    Fpn f1(std::to_string((double)100),100);
    Fpn f2(std::to_string((double)100),100);
    Fpn result(std::to_string((double)0),100);
    ASSERT_EQ(result, f1-f2);
}

TEST(unitTests, assign_divide){
    Fpn f1(std::to_string((double)100),100);
    Fpn f2(std::to_string((double)2),100);
    Fpn result(std::to_string((double)50),100);
    ASSERT_EQ(result, f1/f2);
}

TEST(unitTests, assign_multiply){
    Fpn f1(std::to_string((double)100),100);
    Fpn f2(std::to_string((double)2),100);
    Fpn result(std::to_string((double)200),100);
    ASSERT_EQ(result, f1*f2);
}

//BOOL OPERATORS [ < > <= >= == != ]
TEST(unitTests, operator_smaller){
    Fpn f1(std::to_string((double)100),100);
    Fpn f2(std::to_string((double)200),100);
    ASSERT_EQ(true, f1 < f2);
    ASSERT_EQ(true, f1 <= f2);
}

TEST(unitTests, operator_larger){
    Fpn f1(std::to_string((double)200),100);
    Fpn f2(std::to_string((double)100),100);
    ASSERT_EQ(true, f1 > f2);
    ASSERT_EQ(true, f1 >= f2);
}

TEST(unitTests, operator_equal){
    Fpn f1(std::to_string((double)100),100);
    Fpn f2(std::to_string((double)100),100);
    ASSERT_EQ(true, f1 == f2);
    ASSERT_EQ(true, f1 >= f2);
    ASSERT_EQ(true, f1 <= f2);
}

TEST(unitTests, operator_not_equal){
    Fpn f1(std::to_string((double)100),100);
    Fpn f2(std::to_string((double)200),100);
    ASSERT_EQ(true, f1 != f2);
}

//GETTERS AND SETTERS
TEST(unitTests, getter_and_setter_SIGN){
    Fpn f1(std::to_string((double)100),100);
    f1.setSign('+');
    ASSERT_EQ('+', f1.getSign());
}


TEST(unitTests, getter_and_setter_INTPART){
    Fpn f1(std::to_string((double)100),100);
    f1.setIntPart("9000");
    ASSERT_EQ("9000", f1.getIntPart());
}

TEST(unitTests, getter_and_setter_FRACTPART){
    Fpn f1(std::to_string((double)100),100);
    f1.setFractPart("9000");
    ASSERT_EQ("9", f1.getFractPart());
}

TEST(unitTests, getter_FRACTPRECISION){
    Fpn f1(std::to_string((double)100),100);
    ASSERT_EQ(100, f1.getFractPrecision());
}

TEST(unitTests, getter_NUMBER){
    Fpn f1(std::to_string((double)100),100);
    ASSERT_EQ("100.0", f1.getNumber());
}

//MATH FUNCTIONS [ SQRT SIN COS ABS ROUND FACT ]
TEST(unitTests, math_SQRT){
    Fpn f1(std::to_string((double)100),100);
    Fpn result(std::to_string((double)10),100);
    ASSERT_EQ(result, Fpn::sqrt(f1));
}

TEST(unitTests, math_SIN){
    Fpn f1(std::to_string((double)0),100);
    Fpn result(std::to_string((double)0),100);
    ASSERT_EQ(result, Fpn::sin(f1));
}

TEST(unitTests, math_COS){
    Fpn f1(std::to_string((double)0),100);
    Fpn result(std::to_string((double)1),100);
    ASSERT_EQ(result, Fpn::cos(f1));
}

TEST(unitTests, math_ABS){
    Fpn f1(std::to_string((double)-100),100);
    Fpn result(std::to_string((double)100),100);
    ASSERT_EQ(result, Fpn::abs(f1));
}

TEST(unitTests, math_ROUND){
    Fpn f1(std::to_string((double)0.9),100);
    Fpn result(std::to_string((double)1),100);
    ASSERT_EQ(result, Fpn::round(f1));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}