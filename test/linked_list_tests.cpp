#include "gtest/gtest.h"
#include "linked_list.hpp"

TEST(LinkedListTests, append)
{
    LinkedList ll;
    ASSERT_EQ(ll.size(), 0);
    ll.append(1);
    ASSERT_EQ(ll.size(), 1);
    ASSERT_EQ(ll.data(0), 1);
    ll.append(2);
    ASSERT_EQ(ll.size(), 2);
    ASSERT_EQ(ll.data(1), 2);
    ll.append(3);
    ASSERT_EQ(ll.size(), 3);
    ASSERT_EQ(ll.data(2), 3);
}

TEST(LinkedListTests, prepend)
{
    LinkedList ll;
    ASSERT_EQ(ll.size(), 0);
    ll.prepend(1);
    ASSERT_EQ(ll.size(), 1);
    ASSERT_EQ(ll.data(0), 1);
    ll.prepend(2);
    ASSERT_EQ(ll.size(), 2);
    ASSERT_EQ(ll.data(0), 2);
    ll.prepend(3);
    ASSERT_EQ(ll.size(), 3);
    ASSERT_EQ(ll.data(0), 3);
}