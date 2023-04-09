#include "pch.h"
#include "gtest/gtest.h"
#pragma warning(disable: 2664)

TEST(ReplaceMinMaxWithAverageTest, ReplacesMinMaxWithAverage) {
    int test_arr[5] = { 3, 7, 2, 8, 5 };
    n = 5;
    memcpy(arr, test_arr, sizeof(test_arr));

    replaceMinMaxWithAverage();

    int expected_arr[5] = { 3, 7, 5, 5, 5 };
    for (int i = 0; i < n; i++) {
        ASSERT_EQ(expected_arr[i], arr[i]);
    }

    stringstream ss;
    ss << "Array after replacing min and max with average: ";
    ss << "3 7 5 5 5";
    ss << endl;
    ASSERT_EQ(ss.str(), testing::internal::GetCapturedStdout());
}
