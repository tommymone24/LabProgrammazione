#include <gtest/gtest.h>
#include "../src/Task.h"

TEST(TaskTest, ConstructorInitializesValues) {
    Task t("Studiare c++", "Studio", "11/12/2025", false);

    EXPECT_EQ(t.description, "Studiare c++");
    EXPECT_EQ(t.category, "Studio");
    EXPECT_EQ(t.data, "11/12/2025");
    EXPECT_FALSE(t.completed);
}