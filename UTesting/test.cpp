// test.cpp
#include "whattotest.cpp"
#include <gtest/gtest.h>
#include<algorithm>

 
TEST(SquareRootTest, PositiveNos) { 

	double a= 36.0;
    EXPECT_EQ(6, squareRoot(a));
    ASSERT_EQ(18.0, squareRoot(324.0));
    ASSERT_EQ(25.4, squareRoot(645.16));
    EXPECT_EQ("mera","merti");
    ASSERT_EQ("mer","mert");
    ASSERT_EQ("merati","merti");
    
}
 
TEST(SquareRootTest, NegativeNos) {
	
    ASSERT_EQ(-1.0, squareRoot(-15.0));
    ASSERT_EQ(-1.0, squareRoot(-0.2));
}

TEST(SquareRootTest,ZeroNos)
{
	ASSERT_EQ(0, squareRoot(0));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}