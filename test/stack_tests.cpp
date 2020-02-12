#include "gtest/gtest.h"
#include "stack.hpp"

class StackTest : public ::testing::Test
{
protected:
    void testData(const std::vector<int> expected_data)
    {
        ASSERT_EQ(expected_data.size(), stack_.size());
        auto stack_cpy = stack_;
        for (auto i = 0; i < stack_cpy.size(); i++)
        {
            ASSERT_EQ(expected_data.at(i), stack_cpy.pop());
        }
    }
    Stack stack_;
};
TEST_F(StackTest, push)
{
    testData({});
    stack_.push(1);
    testData({1});
    stack_.push(2);
    testData({2, 1});
    stack_.push(3);
    testData({3, 2, 1});
}
TEST_F(StackTest, pop)
{
    stack_.push(1);
    stack_.push(2);
    stack_.push(3);
    ASSERT_EQ(stack_.pop(), 3);
    ASSERT_EQ(stack_.pop(), 2);
    ASSERT_EQ(stack_.pop(), 1);

    try
    {
        stack_.pop();
        FAIL() << "should have thrown std::out_of_range exception";
    }
    catch(const std::out_of_range& e)
    {
        ASSERT_STREQ(e.what(), "Data retrieval idx out of range.");
    }
    catch(...)
    {
        FAIL() << "expected std::out_of_range exception";
    }
}
TEST_F(StackTest, clear)
{
    stack_.clear();
    ASSERT_EQ(stack_.size(), 0);

    stack_.push(1);
    stack_.clear();
    ASSERT_EQ(stack_.size(), 0);

    stack_.push(1);
    stack_.push(2);
    stack_.clear();
    ASSERT_EQ(stack_.size(), 0);

    stack_.push(1);
    stack_.push(2);
    stack_.push(3);
    stack_.clear();
    ASSERT_EQ(stack_.size(), 0);

}
TEST_F(StackTest, peek)
{
    try
    {
        stack_.peek();
        FAIL() << "should have thrown std::out_of_range exception";
    }
    catch(const std::out_of_range& e)
    {
        
        ASSERT_STREQ(e.what(), "Data retrieval idx out of range.");
    }
    catch(...)
    {
        FAIL() << "expected std::out_of_range exception";
    }
    stack_.push(1);
    ASSERT_EQ(stack_.peek(), 1);
    stack_.push(2);
    ASSERT_EQ(stack_.peek(), 2);
    stack_.push(3);
    ASSERT_EQ(stack_.peek(), 3);
    stack_.pop();
    ASSERT_EQ(stack_.peek(), 2);
    stack_.pop();
    ASSERT_EQ(stack_.peek(), 1);
}
TEST_F(StackTest, isEmpty)
{
    ASSERT_TRUE(stack_.isEmpty());

    stack_.push(1);
    ASSERT_FALSE(stack_.isEmpty());

    stack_.push(2);
    ASSERT_FALSE(stack_.isEmpty());

    stack_.push(3);
    ASSERT_FALSE(stack_.isEmpty());
}

TEST_F(StackTest, size)
{
    ASSERT_EQ(stack_.size(), 0);
    stack_.push(1);
    ASSERT_EQ(stack_.size(), 1);
    stack_.push(2);
    ASSERT_EQ(stack_.size(), 2);
    stack_.push(3);
    ASSERT_EQ(stack_.size(), 3);
    stack_.pop();
    ASSERT_EQ(stack_.size(), 2);
    stack_.pop();
    ASSERT_EQ(stack_.size(), 1);
    stack_.pop();
    ASSERT_EQ(stack_.size(), 0);
}
