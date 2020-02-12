#include "gtest/gtest.h"
#include "circular_double_linked_list.hpp"

class CircularDoubleLinkedListTest : public ::testing::Test
{
protected:
    void testData(const std::vector<int> expected_data)
    {
        ASSERT_EQ(expected_data.size(), cdll_.size());
        for (auto i = 0; i < cdll_.size(); i++)
        {
            ASSERT_EQ(expected_data.at(i), cdll_.data(i));
        }
        if (cdll_.size() >= 1)
        {
            auto t = cdll_.tail()->next()->data();
            ASSERT_EQ(expected_data.at(0), cdll_.tail()->next()->data());
            ASSERT_EQ(expected_data.at(cdll_.size() - 1), cdll_.head()->prev()->data());
        }
    }
    CircularDoubleLinkedList cdll_;
};
TEST_F(CircularDoubleLinkedListTest, append)
{
    testData({});
    cdll_.append(1);
    testData({1});
    cdll_.append(2);
    testData({1, 2});
    cdll_.append(3);
    testData({1, 2, 3});

}

TEST_F(CircularDoubleLinkedListTest, prepend)
{
    testData({});
    cdll_.prepend(1);
    testData({1});
    cdll_.prepend(2);
    testData({2, 1});
    cdll_.prepend(3);
    testData({3, 2, 1});
}

TEST_F(CircularDoubleLinkedListTest, insert)
{
    // --------
    // Empty List
    // --------
    std::function<void()> reset;

    reset = [=]() {
        cdll_.clear();
    };
    reset();
    testData({});

    cdll_.insert(-1, 1);
    testData({1});

    reset();
    cdll_.insert(0, 1);
    testData({1});
    
    reset();
    cdll_.insert(1, 1);
    testData({1});

    // --------
    // 1 Item in List
    // --------

    reset = [=]() {
        cdll_.clear();
        cdll_.append(1);
    };
    reset();
    testData({1});

    cdll_.insert(-1, 2);
    testData({2, 1});

    reset();
    cdll_.insert(0, 2);
    testData({2, 1});
    
    reset();
    cdll_.insert(1, 2);
    testData({1, 2});
    
    reset();
    cdll_.insert(2, 2);
    testData({1, 2});
    
    // --------
    // 2 Items in List
    // --------
    reset = [=]() {
        cdll_.clear();
        cdll_.append(1);
        cdll_.append(2);
    };
    reset();
    testData({1, 2});

    cdll_.insert(-1, 3);
    testData({3, 1, 2});
    
    reset();
    cdll_.insert(0, 3);
    testData({3, 1, 2});
    
    reset();
    cdll_.insert(1, 3);
    testData({1, 3, 2});
    
    reset();
    cdll_.insert(2, 3);
    testData({1, 2, 3});
    
    reset();
    cdll_.insert(3, 3);
    testData({1, 2, 3});
}

TEST_F(CircularDoubleLinkedListTest, removeHead)
{       
    cdll_.append(1);
    cdll_.append(2);
    cdll_.append(3);
    testData({1, 2, 3});

    cdll_.removeHead();
    testData({2, 3});

    cdll_.removeHead();
    testData({3});

    cdll_.removeHead();
    testData({});

    cdll_.removeHead();
    testData({});
}


TEST_F(CircularDoubleLinkedListTest, removeTail)
{       
    cdll_.append(1);
    cdll_.append(2);
    cdll_.append(3);
    testData({1, 2, 3});

    cdll_.removeTail();
    testData({1, 2});

    cdll_.removeTail();
    testData({1});

    cdll_.removeTail();
    testData({});

    cdll_.removeTail();
    testData({});
}

TEST_F(CircularDoubleLinkedListTest, remove)
{       

    // --------
    // Empty List
    // --------
    std::function<void()> reset;

    reset = [=]() {
        cdll_.clear();
    };
    reset();
    testData({});

    cdll_.remove(-1);
    testData({});

    reset();
    cdll_.remove(0);
    testData({});
    
    reset();
    cdll_.remove(1);
    testData({});

    // --------
    // 1 Item in List
    // --------

    reset = [=]() {
        cdll_.clear();
        cdll_.append(1);
    };
    reset();
    testData({1});

    cdll_.remove(-1);
    testData({});

    reset();
    cdll_.remove(0);
    testData({});
    
    reset();
    cdll_.remove(1);
    testData({});
    
    reset();
    cdll_.remove(2);
    testData({});
    
    // --------
    // 2 Items in List
    // --------
    reset = [=]() {
        cdll_.clear();
        cdll_.append(1);
        cdll_.append(2);
    };
    reset();
    testData({1, 2});

    cdll_.remove(-1);
    testData({2});
    
    reset();
    cdll_.remove(0);
    testData({2});
    
    reset();
    cdll_.remove(1);
    testData({1});
    
    reset();
    cdll_.remove(2);
    testData({1});

    // --------
    // 3 Items in List
    // --------
    reset = [=]() {
        cdll_.clear();
        cdll_.append(1);
        cdll_.append(2);
        cdll_.append(3);
    };
    reset();
    testData({1, 2, 3});

    cdll_.remove(-1);
    testData({2, 3});
    
    reset();
    cdll_.remove(0);
    testData({2, 3});
    
    reset();
    cdll_.remove(1);
    testData({1, 3});
    
    reset();
    cdll_.remove(2);
    testData({1, 2});

    reset();
    cdll_.remove(3);
    testData({1, 2});
}


TEST_F(CircularDoubleLinkedListTest, clear)
{
    cdll_.clear();
    testData({});

    cdll_.append(1);
    cdll_.clear();
    testData({});

    cdll_.append(1);
    cdll_.append(2);
    cdll_.clear();
    testData({});

    cdll_.append(1);
    cdll_.append(2);
    cdll_.append(3);
    cdll_.clear();
    testData({});
}

TEST_F(CircularDoubleLinkedListTest, search)
{
    // empty list returns no results
    cdll_.search(1);
    auto results = cdll_.search(5);
    ASSERT_EQ(results.size(), 0);

    // populated list without match returns no results
    cdll_.append(1);
    cdll_.append(2);
    cdll_.append(3);
    cdll_.append(4);
    results = cdll_.search(5);
    ASSERT_EQ(results.size(), 0);

    // populated list with one match returns one result
    cdll_.clear();
    cdll_.append(1);
    cdll_.append(2);
    cdll_.append(3);
    cdll_.append(4);
    results = cdll_.search(2);
    ASSERT_EQ(results.size(), 1);

    // populated list with multiple matches returns multiple results
    cdll_.clear();
    cdll_.append(1);
    cdll_.append(2);
    cdll_.append(2);
    cdll_.append(4);
    results = cdll_.search(2);
    ASSERT_EQ(results.size(), 2);
}

TEST_F(CircularDoubleLinkedListTest, isEmpty)
{   
    // empty list is empty
    ASSERT_TRUE(cdll_.isEmpty());

    // list with size 1 is not empty
    cdll_.append(1);
    ASSERT_FALSE(cdll_.isEmpty());

    // list with size 2 is not empty
    cdll_.append(2);
    ASSERT_FALSE(cdll_.isEmpty());

    // list with size 3 is not empty
    cdll_.append(3);
    ASSERT_FALSE(cdll_.isEmpty());
}
