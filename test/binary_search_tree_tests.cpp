#include "gtest/gtest.h"
#include "binary_search_tree.hpp"
#include <sstream>

class BinarySearchTreeTest : public ::testing::Test
{
protected:
    struct NodeData
    {
        int left_data_;
        int right_data_;
    };

    void testData(const std::vector<int> expected_data)
    {
        auto data_dfs = bst_.getDataDF(bst_.root());

        std::stringstream ss;
        ss << "expected_data: { ";
        for (auto data : expected_data)
        {
            ss << data << " ";
        }
        ss << "}, data_dfs: { ";
        for (auto data : data_dfs)
        {
            ss << data << " ";
        }
        ss << "}";
        auto description = ss.str();

        ASSERT_EQ(expected_data.size(), data_dfs.size()) << "sizes don't match: " << description;

        for (auto i = 0; i < data_dfs.size(); i++)
        {
            ASSERT_EQ(expected_data.at(i), data_dfs.at(i)) << description;
        }
    }
    void setup(const std::vector<int> &init_data)
    {
        bst_.clear();
        for (auto data : init_data)
        {
            bst_.insert(data);
        }
    }
    void testInsert(const std::vector<int> &init_data, const std::vector<int> expected_dfs_data)
    {
        setup(init_data);
        testData(expected_dfs_data);
    };
    void testRemove(const std::vector<int> &init_data, const int to_remove, const std::vector<int> expected_dfs_data)
    {
        setup(init_data);
        bst_.remove(to_remove);
        testData(expected_dfs_data);
    };
    BinarySearchTree bst_;
};
TEST_F(BinarySearchTreeTest, insert)
{
    // Depth 0 Cases
    testInsert({5}, {5});

    // Depth 1 Cases
    testInsert({5, 3}, {5, 3});

    testInsert({5, 5}, {5, 5});

    testInsert({5, 7}, {5, 7});

    // Depth 2 Cases
    // b < a
    testInsert({5, 3, 1}, {5, 3, 1});

    testInsert({5, 3, 3}, {5, 3, 3});

    testInsert({5, 3, 4}, {5, 3, 4});

    testInsert({5, 3, 5}, {5, 3, 5});

    testInsert({5, 3, 7}, {5, 3, 7});

    // b == a
    testInsert({5, 5, 1}, {5, 5, 1});

    testInsert({5, 5, 3}, {5, 5, 3});

    testInsert({5, 5, 5}, {5, 5, 5});

    testInsert({5, 5, 7}, {5, 5, 7});

    // b > a
    testInsert({5, 7, 3}, {5, 3, 7});

    testInsert({5, 7, 5}, {5, 5, 7});

    testInsert({5, 7, 6}, {5, 7, 6});

    testInsert({5, 7, 7}, {5, 7, 7});

    testInsert({5, 7, 8}, {5, 7, 8});
}

TEST_F(BinarySearchTreeTest, remove)
{
    // Depth 0 Cases
    testRemove({}, 0, {});

    // Depth 1 Cases
    testRemove({5, 3}, 3, {5});
    testRemove({5, 3}, 5, {3});

    testRemove({5, 5}, 5, {5});

    testRemove({5, 7}, 7, {5});
    testRemove({5, 7}, 5, {7});

    // Depth 2 Cases

    // b < a
    testRemove({5, 3, 1}, 1, {5, 3});
    testRemove({5, 3, 1}, 3, {5, 1});
    testRemove({5, 3, 1}, 5, {3, 1});

    testRemove({5, 3, 3}, 3, {5, 3});
    testRemove({5, 3, 3}, 5, {3, 3});

    testRemove({5, 3, 4}, 4, {5, 3});
    testRemove({5, 3, 4}, 3, {5, 4});
    testRemove({5, 3, 4}, 5, {3, 4});

    testRemove({5, 3, 5}, 5, {3, 5});
    testRemove({5, 3, 5}, 3, {5, 5});

    testRemove({5, 3, 7}, 7, {5, 3});
    testRemove({5, 3, 7}, 3, {5, 7});
    testRemove({5, 3, 7}, 5, {3, 7});

    // b == a
    testRemove({5, 5, 1}, 1, {5, 5});
    testRemove({5, 5, 1}, 5, {5, 1});

    testRemove({5, 5, 3}, 3, {5, 5});
    testRemove({5, 5, 3}, 5, {5, 3});

    testRemove({5, 5, 5}, 5, {5, 5});

    testRemove({5, 5, 7}, 7, {5, 5});
    testRemove({5, 5, 7}, 5, {5, 7});

    // b > a
    testRemove({5, 7, 3}, 3, {5, 7});
    testRemove({5, 7, 3}, 7, {5, 3});
    testRemove({5, 7, 3}, 5, {3, 7});

    testRemove({5, 7, 5}, 5, {5, 7});
    testRemove({5, 7, 5}, 7, {5, 5});

    testRemove({5, 7, 6}, 6, {5, 7});
    testRemove({5, 7, 6}, 7, {5, 6});
    testRemove({5, 7, 6}, 5, {7, 6});

    testRemove({5, 7, 7}, 7, {5, 7});
    testRemove({5, 7, 7}, 5, {7, 7});

    testRemove({5, 7, 8}, 8, {5, 7});
    testRemove({5, 7, 8}, 7, {5, 8});
    testRemove({5, 7, 8}, 5, {7, 8});
}
