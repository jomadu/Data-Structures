#include "gtest/gtest.h"
#include "double_linked_list.hpp"

class DoubleLinkedListTest : public ::testing::Test
{
protected:
    void testData(const std::vector<int> expected_data)
    {
        ASSERT_EQ(expected_data.size(), dll_.size());
        for (auto i = 0; i < dll_.size(); i++)
        {
            ASSERT_EQ(expected_data.at(i), dll_.data(i));
        }
    }
    DoubleLinkedList dll_;
};
TEST_F(DoubleLinkedListTest, append)
{
    testData({});
    dll_.append(1);
    testData({1});

    dll_.append(2);
    testData({1, 2});

    dll_.append(3);
    testData({1, 2, 3});
}

TEST_F(DoubleLinkedListTest, prepend)
{
    testData({});
    dll_.prepend(1);
    testData({1});
    dll_.prepend(2);
    testData({2, 1});
    dll_.prepend(3);
    testData({3, 2, 1});
}

TEST_F(DoubleLinkedListTest, insert)
{
    // --------
    // Empty List
    // --------
    std::function<void()> reset;

    reset = [=]() {
        dll_.clear();
    };
    reset();
    testData({});

    dll_.insert(-1, 1);
    testData({1});

    reset();
    dll_.insert(0, 1);
    testData({1});
    
    reset();
    dll_.insert(1, 1);
    testData({1});

    // --------
    // 1 Item in List
    // --------

    reset = [=]() {
        dll_.clear();
        dll_.append(1);
    };
    reset();
    testData({1});

    dll_.insert(-1, 2);
    testData({2, 1});

    reset();
    dll_.insert(0, 2);
    testData({2, 1});
    
    reset();
    dll_.insert(1, 2);
    testData({1, 2});
    
    reset();
    dll_.insert(2, 2);
    testData({1, 2});
    
    // --------
    // 2 Items in List
    // --------
    reset = [=]() {
        dll_.clear();
        dll_.append(1);
        dll_.append(2);
    };
    reset();
    testData({1, 2});

    dll_.insert(-1, 3);
    testData({3, 1, 2});
    
    reset();
    dll_.insert(0, 3);
    testData({3, 1, 2});
    
    reset();
    dll_.insert(1, 3);
    testData({1, 3, 2});
    
    reset();
    dll_.insert(2, 3);
    testData({1, 2, 3});
    
    reset();
    dll_.insert(3, 3);
    testData({1, 2, 3});
}

TEST_F(DoubleLinkedListTest, removeHead)
{       
    dll_.append(1);
    dll_.append(2);
    dll_.append(3);
    testData({1, 2, 3});

    dll_.removeHead();
    testData({2, 3});

    dll_.removeHead();
    testData({3});

    dll_.removeHead();
    testData({});

    dll_.removeHead();
    testData({});
}


TEST_F(DoubleLinkedListTest, removeTail)
{       
    dll_.append(1);
    dll_.append(2);
    dll_.append(3);
    testData({1, 2, 3});

    dll_.removeTail();
    testData({1, 2});

    dll_.removeTail();
    testData({1});

    dll_.removeTail();
    testData({});

    dll_.removeTail();
    testData({});
}

TEST_F(DoubleLinkedListTest, remove)
{       

    // --------
    // Empty List
    // --------
    std::function<void()> reset;

    reset = [=]() {
        dll_.clear();
    };
    reset();
    testData({});

    dll_.remove(-1);
    testData({});

    reset();
    dll_.remove(0);
    testData({});
    
    reset();
    dll_.remove(1);
    testData({});

    // --------
    // 1 Item in List
    // --------

    reset = [=]() {
        dll_.clear();
        dll_.append(1);
    };
    reset();
    testData({1});

    dll_.remove(-1);
    testData({});

    reset();
    dll_.remove(0);
    testData({});
    
    reset();
    dll_.remove(1);
    testData({});
    
    reset();
    dll_.remove(2);
    testData({});
    
    // --------
    // 2 Items in List
    // --------
    reset = [=]() {
        dll_.clear();
        dll_.append(1);
        dll_.append(2);
    };
    reset();
    testData({1, 2});

    dll_.remove(-1);
    testData({2});
    
    reset();
    dll_.remove(0);
    testData({2});
    
    reset();
    dll_.remove(1);
    testData({1});
    
    reset();
    dll_.remove(2);
    testData({1});

    // --------
    // 3 Items in List
    // --------
    reset = [=]() {
        dll_.clear();
        dll_.append(1);
        dll_.append(2);
        dll_.append(3);
    };
    reset();
    testData({1, 2, 3});

    dll_.remove(-1);
    testData({2, 3});
    
    reset();
    dll_.remove(0);
    testData({2, 3});
    
    reset();
    dll_.remove(1);
    testData({1, 3});
    
    reset();
    dll_.remove(2);
    testData({1, 2});

    reset();
    dll_.remove(3);
    testData({1, 2});
}


TEST_F(DoubleLinkedListTest, clear)
{
    dll_.clear();
    testData({});

    dll_.append(1);
    dll_.clear();
    testData({});

    dll_.append(1);
    dll_.append(2);
    dll_.clear();
    testData({});

    dll_.append(1);
    dll_.append(2);
    dll_.append(3);
    dll_.clear();
    testData({});
}

TEST_F(DoubleLinkedListTest, search)
{
    // empty list returns no results
    dll_.search(1);
    auto results = dll_.search(5);
    ASSERT_EQ(results.size(), 0);

    // populated list without match returns no results
    dll_.append(1);
    dll_.append(2);
    dll_.append(3);
    dll_.append(4);
    results = dll_.search(5);
    ASSERT_EQ(results.size(), 0);

    // populated list with one match returns one result
    dll_.clear();
    dll_.append(1);
    dll_.append(2);
    dll_.append(3);
    dll_.append(4);
    results = dll_.search(2);
    ASSERT_EQ(results.size(), 1);

    // populated list with multiple matches returns multiple results
    dll_.clear();
    dll_.append(1);
    dll_.append(2);
    dll_.append(2);
    dll_.append(4);
    results = dll_.search(2);
    ASSERT_EQ(results.size(), 2);
}

TEST_F(DoubleLinkedListTest, isEmpty)
{   
    // empty list is empty
    ASSERT_TRUE(dll_.isEmpty());

    // list with size 1 is not empty
    dll_.append(1);
    ASSERT_FALSE(dll_.isEmpty());

    // list with size 2 is not empty
    dll_.append(2);
    ASSERT_FALSE(dll_.isEmpty());

    // list with size 3 is not empty
    dll_.append(3);
    ASSERT_FALSE(dll_.isEmpty());
}
