#include "gtest/gtest.h"
#include "linked_list.hpp"

class LinkedListTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }
    void compareData(const std::vector<int> expected_data)
    {
        ASSERT_EQ(expected_data.size(), ll_.size());
        for (auto i = 0; i < ll_.size(); i++)
        {
            ASSERT_EQ(expected_data.at(i), ll_.data(i));
        }
    }
    LinkedList ll_;
};
TEST_F(LinkedListTest, append)
{

    compareData({});
    ll_.append(1);
    compareData({1});
    ll_.append(2);
    compareData({1, 2});
    ll_.append(3);
    compareData({1, 2, 3});
}

TEST_F(LinkedListTest, prepend)
{
    compareData({});
    ll_.prepend(1);
    compareData({1});
    ll_.prepend(2);
    compareData({2, 1});
    ll_.prepend(3);
    compareData({3, 2, 1});
}

TEST_F(LinkedListTest, insert)
{

    // --------
    // Empty List
    // --------
    std::function<void()> reset;

    reset = [=]() {
        ll_.clear();
    };
    reset();
    compareData({});

    ll_.insert(-1, 1);
    compareData({1});

    reset();
    ll_.insert(0, 1);
    compareData({1});
    
    reset();
    ll_.insert(1, 1);
    compareData({1});

    // --------
    // 1 Item in List
    // --------

    reset = [=]() {
        ll_.clear();
        ll_.append(1);
    };
    reset();
    compareData({1});

    ll_.insert(-1, 2);
    compareData({2, 1});

    reset();
    ll_.insert(0, 2);
    compareData({2, 1});
    
    reset();
    ll_.insert(1, 2);
    compareData({1, 2});
    
    reset();
    ll_.insert(2, 2);
    compareData({1, 2});
    
    // --------
    // 2 Items in List
    // --------
    reset = [=]() {
        ll_.clear();
        ll_.append(1);
        ll_.append(2);
    };
    reset();
    compareData({1, 2});

    ll_.insert(-1, 3);
    compareData({3, 1, 2});
    
    reset();
    ll_.insert(0, 3);
    compareData({3, 1, 2});
    
    reset();
    ll_.insert(1, 3);
    compareData({1, 3, 2});
    
    reset();
    ll_.insert(2, 3);
    compareData({1, 2, 3});
    
    reset();
    ll_.insert(3, 3);
    compareData({1, 2, 3});
}

TEST_F(LinkedListTest, removeHead)
{       
    ll_.append(1);
    ll_.append(2);
    ll_.append(3);
    compareData({1, 2, 3});

    ll_.removeHead();
    compareData({2, 3});

    ll_.removeHead();
    compareData({3});

    ll_.removeHead();
    compareData({});

    ll_.removeHead();
    compareData({});
}


TEST_F(LinkedListTest, removeTail)
{       
    ll_.append(1);
    ll_.append(2);
    ll_.append(3);
    compareData({1, 2, 3});

    ll_.removeTail();
    compareData({1, 2});

    ll_.removeTail();
    compareData({1});

    ll_.removeTail();
    compareData({});

    ll_.removeTail();
    compareData({});
}

TEST_F(LinkedListTest, remove)
{       

    // --------
    // Empty List
    // --------
    std::function<void()> reset;

    reset = [=]() {
        ll_.clear();
    };
    reset();
    compareData({});

    ll_.remove(-1);
    compareData({});

    reset();
    ll_.remove(0);
    compareData({});
    
    reset();
    ll_.remove(1);
    compareData({});

    // --------
    // 1 Item in List
    // --------

    reset = [=]() {
        ll_.clear();
        ll_.append(1);
    };
    reset();
    compareData({1});

    ll_.remove(-1);
    compareData({});

    reset();
    ll_.remove(0);
    compareData({});
    
    reset();
    ll_.remove(1);
    compareData({});
    
    reset();
    ll_.remove(2);
    compareData({});
    
    // --------
    // 2 Items in List
    // --------
    reset = [=]() {
        ll_.clear();
        ll_.append(1);
        ll_.append(2);
    };
    reset();
    compareData({1, 2});

    ll_.remove(-1);
    compareData({2});
    
    reset();
    ll_.remove(0);
    compareData({2});
    
    reset();
    ll_.remove(1);
    compareData({1});
    
    reset();
    ll_.remove(2);
    compareData({1});

    // --------
    // 3 Items in List
    // --------
    reset = [=]() {
        ll_.clear();
        ll_.append(1);
        ll_.append(2);
        ll_.append(3);
    };
    reset();
    compareData({1, 2, 3});

    ll_.remove(-1);
    compareData({2, 3});
    
    reset();
    ll_.remove(0);
    compareData({2, 3});
    
    reset();
    ll_.remove(1);
    compareData({1, 3});
    
    reset();
    ll_.remove(2);
    compareData({1, 2});

    reset();
    ll_.remove(3);
    compareData({1, 2});
}


TEST_F(LinkedListTest, clear)
{
    ll_.clear();
    compareData({});

    ll_.append(1);
    ll_.clear();
    compareData({});

    ll_.append(1);
    ll_.append(2);
    ll_.clear();
    compareData({});

    ll_.append(1);
    ll_.append(2);
    ll_.append(3);
    ll_.clear();
    compareData({});
}

TEST_F(LinkedListTest, search)
{
    ll_.clear();
    compareData({});
    // empty list returns no results
    ll_.search(1);
    auto results = ll_.search(5);
    ASSERT_EQ(results.size(), 0);

    // populated list without match returns no results
    ll_.append(1);
    ll_.append(2);
    ll_.append(3);
    ll_.append(4);
    results = ll_.search(5);
    ASSERT_EQ(results.size(), 0);

    // populated list with one match returns one result
    ll_.clear();
    ll_.append(1);
    ll_.append(2);
    ll_.append(3);
    ll_.append(4);
    results = ll_.search(2);
    ASSERT_EQ(results.size(), 1);

    // populated list with multiple matches returns multiple results
    ll_.clear();
    ll_.append(1);
    ll_.append(2);
    ll_.append(2);
    ll_.append(4);
    results = ll_.search(2);
    ASSERT_EQ(results.size(), 2);
}

TEST_F(LinkedListTest, isEmpty)
{
    ll_.clear();
    compareData({});
    
    // empty list is empty
    ASSERT_TRUE(ll_.isEmpty());

    // list with size 1 is not empty
    ll_.append(1);
    ASSERT_FALSE(ll_.isEmpty());

    // list with size 2 is not empty
    ll_.append(2);
    ASSERT_FALSE(ll_.isEmpty());

    // list with size 3 is not empty
    ll_.append(3);
    ASSERT_FALSE(ll_.isEmpty());
}
