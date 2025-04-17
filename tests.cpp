#include <gtest/gtest.h>
#include "utils.h"

TEST(UtilsTest, GetData) {
    Actions::Utils utils("test");
    EXPECT_EQ("test", utils.getData());
}

TEST(UtilsTest, SetData) {
    Actions::Utils utils("old");
    utils.setData("new");
    EXPECT_EQ("new", utils.getData());
}

TEST(UtilsTest, AddFunction) {
    Actions::Utils utils("");
    EXPECT_EQ(3, utils.add(1, 2));
    EXPECT_FLOAT_EQ(3.5, utils.add(1.5, 2.0));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
