#include "gtest/gtest.h"
#include "queue.hpp"

class QueueTest : public ::testing::Test
{
protected:
    void testData(const std::vector<int> expected_data)
    {
        ASSERT_EQ(expected_data.size(), queue_.size());
        auto queue_cpy = queue_;
        for (auto i = 0; i < queue_cpy.size(); i++)
        {
            ASSERT_EQ(expected_data.at(i), queue_cpy.pop());
        }
    }
    Queue queue_;
};
TEST_F(QueueTest, push)
{
    testData({});
    queue_.push(1);
    testData({1});
    queue_.push(2);
    testData({1, 2});
    queue_.push(3);
    testData({1, 2, 3});
}
TEST_F(QueueTest, pop)
{
    queue_.push(1);
    queue_.push(2);
    queue_.push(3);
    ASSERT_EQ(queue_.pop(), 1);
    ASSERT_EQ(queue_.pop(), 2);
    ASSERT_EQ(queue_.pop(), 3);

    try
    {
        queue_.pop();
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
TEST_F(QueueTest, clear)
{
    queue_.clear();
    ASSERT_EQ(queue_.size(), 0);

    queue_.push(1);
    queue_.clear();
    ASSERT_EQ(queue_.size(), 0);

    queue_.push(1);
    queue_.push(2);
    queue_.clear();
    ASSERT_EQ(queue_.size(), 0);

    queue_.push(1);
    queue_.push(2);
    queue_.push(3);
    queue_.clear();
    ASSERT_EQ(queue_.size(), 0);

}
TEST_F(QueueTest, peek)
{
    try
    {
        queue_.peek();
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
    queue_.push(1);
    ASSERT_EQ(queue_.peek(), 1);
    queue_.push(2);
    ASSERT_EQ(queue_.peek(), 1);
    queue_.push(3);
    ASSERT_EQ(queue_.peek(), 1);
    queue_.pop();
    ASSERT_EQ(queue_.peek(), 2);
    queue_.pop();
    ASSERT_EQ(queue_.peek(), 3);
}
TEST_F(QueueTest, isEmpty)
{
    ASSERT_TRUE(queue_.isEmpty());

    queue_.push(1);
    ASSERT_FALSE(queue_.isEmpty());

    queue_.push(2);
    ASSERT_FALSE(queue_.isEmpty());

    queue_.push(3);
    ASSERT_FALSE(queue_.isEmpty());
}

TEST_F(QueueTest, size)
{
    ASSERT_EQ(queue_.size(), 0);
    queue_.push(1);
    ASSERT_EQ(queue_.size(), 1);
    queue_.push(2);
    ASSERT_EQ(queue_.size(), 2);
    queue_.push(3);
    ASSERT_EQ(queue_.size(), 3);
    queue_.pop();
    ASSERT_EQ(queue_.size(), 2);
    queue_.pop();
    ASSERT_EQ(queue_.size(), 1);
    queue_.pop();
    ASSERT_EQ(queue_.size(), 0);
}
