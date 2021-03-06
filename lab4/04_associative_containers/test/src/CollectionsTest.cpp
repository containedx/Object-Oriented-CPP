#include "TestIncludes.h"
#include <set>
#include <map>
#include <bits/stdc++.h>

using namespace std;

TEST(SetInt, RemoveElements) {

    set <int> set;
    set.insert(1);
    set.insert(2);
    set.insert(3);

    ASSERT_EQ(3u, set.size());
    EXPECT_EQ(1u, set.count(1));
    EXPECT_EQ(1u, set.count(2));
    EXPECT_EQ(1u, set.count(3));

    set.erase(2);

    ASSERT_EQ(2u, set.size());
    EXPECT_EQ(1u, set.count(1));
    EXPECT_EQ(0u, set.count(2));
    EXPECT_EQ(1u, set.count(3));
}

TEST(SetDouble, ElementsSortedWhenIterating) {

    set <double> set;

    ASSERT_TRUE(set.empty());

    set.insert(3.3);
    set.insert(2.2);

    ASSERT_EQ(2u, set.size());
    EXPECT_EQ(1u, set.count(3.3));
    EXPECT_EQ(1u, set.count(2.2));

    set.insert(4.4);
    set.insert(1.1);
    ASSERT_EQ(4u, set.size());
    EXPECT_EQ(1u, set.count(3.3));
    EXPECT_EQ(1u, set.count(2.2));
    EXPECT_EQ(1u, set.count(4.4));
    EXPECT_EQ(1u, set.count(1.1));

    set.insert(0.0);

    auto iter = set.begin();
    EXPECT_EQ(0.0, *iter++);
    EXPECT_EQ(1.1, *iter++);
    EXPECT_EQ(2.2, *iter++);
    EXPECT_EQ(3.3, *iter++);
    EXPECT_EQ(4.4, *iter++);
    EXPECT_EQ(set.end(), iter);
}

TEST(SetString, ElementsSortedInReversedAplhabeticalOrderWhenIterating) {

    struct Comparator {
        bool operator()(const string& a, const string& b) const
        {
            return a > b? true : false;
        }
    };

    set <string, Comparator> set{};
    set.insert("Bb");
    set.insert("Ba");
    set.insert("Ab");
    set.insert("Aa");


    auto iter = set.begin();
    EXPECT_EQ("Bb", *iter++);
    EXPECT_EQ("Ba", *iter++);
    EXPECT_EQ("Ab", *iter++);
    EXPECT_EQ("Aa", *iter++);
    EXPECT_EQ(set.end(), iter);

    set.insert("Ca");

    iter = set.begin();
    EXPECT_EQ("Ca", *iter++);
    EXPECT_EQ("Bb", *iter++);
    EXPECT_EQ("Ba", *iter++);
    EXPECT_EQ("Ab", *iter++);
    EXPECT_EQ("Aa", *iter++);
    EXPECT_EQ(set.end(), iter);

}

TEST(SetInt, InvalidComparatorThatCausesOnlyOneElementToBeInserted) {

    struct Comparator {
        bool operator()(const int& a, const int&b) const
        {
            return false;
        }
    };

    set <int, Comparator> set{};


    ASSERT_TRUE(set.empty());

    set.insert(1);

    ASSERT_EQ(1u, set.size());

    set.insert(33);
    set.insert(43);

    ASSERT_EQ(1u, set.size());
}

TEST(SetInt, InvalidComparatorThatCausesMultipleCopiesOfTheSameElementToBeInserted) {

    struct Comparator {
        bool operator()(const int& a, const int&b) const
        {
            return true;
        }
    };

    set<int, Comparator> set{};

    ASSERT_TRUE(set.empty());

    set.insert(1);

    ASSERT_EQ(1u, set.size());

    set.insert(2);

    ASSERT_EQ(2u, set.size());
}

TEST(SetValue, CustomTypeAndComparator) {

    struct Value {
        int a;
        int b;
    };

    struct Comparator {
        bool operator()(const Value& a, const Value& b) const
        {
            if(a.a > b.a)
                return true;
            else if(a.a == b.a)
                if(a.b < b.b)
                     return true;
            else
                return false;
        }
    };

    set < Value, Comparator > set {};

    ASSERT_TRUE(set.empty());

    set.insert(Value{3,0});

    ASSERT_EQ(1u, set.size());
    EXPECT_EQ(1u, set.count(Value{3, 0}));

    set.insert(Value{6,0});

    ASSERT_EQ(2u, set.size());
    EXPECT_EQ(1u, set.count(Value{3, 0}));
    EXPECT_EQ(1u, set.count(Value{6, 0}));

    set.insert(Value{3,3});

    ASSERT_EQ(3u, set.size());
    EXPECT_EQ(1u, set.count(Value{3, 0}));
    EXPECT_EQ(1u, set.count(Value{6, 0}));
    EXPECT_EQ(1u, set.count(Value{3, 3}));

    set.insert(Value{6,6});

    ASSERT_EQ(4u, set.size());
    EXPECT_EQ(1u, set.count(Value{3, 0}));
    EXPECT_EQ(1u, set.count(Value{6, 0}));
    EXPECT_EQ(1u, set.count(Value{3, 3}));
    EXPECT_EQ(1u, set.count(Value{6, 6}));
}

TEST(SetInt, ElementsGreaterThanGivenValue) {

    set <int, less <int> > set{};

    set.insert(3);
    set.insert(4);
    set.insert(5);
    set.insert(1);
    set.insert(2);

    ASSERT_EQ(5u, set.size());
    EXPECT_EQ(1u, set.count(1));
    EXPECT_EQ(1u, set.count(2));
    EXPECT_EQ(1u, set.count(3));
    EXPECT_EQ(1u, set.count(4));
    EXPECT_EQ(1u, set.count(5));

    auto iter = set.begin();
    *iter++;
    *iter++;

    EXPECT_EQ(3, *iter++);
    EXPECT_EQ(4, *iter++);
    EXPECT_EQ(5, *iter++);
    EXPECT_EQ(set.end(), iter);
}

TEST(MapStringString, CreateUsingInitializerList) {

    map <string, string> map{};

    map.insert({"CN", "China"});
    map.insert({"GR", "Greece"});
    map.insert({"FR", "France"});

    ASSERT_EQ(3u, map.size());
    EXPECT_EQ("China", map["CN"]);
    EXPECT_EQ("Greece", map["GR"]);
    EXPECT_EQ("France", map["FR"]);
}

TEST(MapMapStringInt, NestedCollections) {

    map <string, map <string, int> > map{};


    ASSERT_TRUE(map.empty());

    map["count"]["1"] = 12 ;

    ASSERT_EQ(1u, map.size());
    ASSERT_EQ(1u, map.count("count"));


    map["count"]["2"] = 4 ;
    map["count"]["3"] = 2 ;
    map["count"]["4"] = 7 ;

    ASSERT_EQ(4u, map["count"].size());
    EXPECT_EQ(12, map["count"]["1"]);
    EXPECT_EQ(4, map["count"]["2"]);
    EXPECT_EQ(2, map["count"]["3"]);
    EXPECT_EQ(7, map["count"]["4"]);
}

TEST(MultisetInt, RemoveRangeOfElements) {

    multiset <int> multiset = {};

    multiset.insert(1);
    for(int i=0; i<12; i++)
        multiset.insert(2);
    for(int i=0; i<3; i++)
        multiset.insert(3);

    ASSERT_EQ(16, multiset.size());
    EXPECT_EQ(1, multiset.count(1));
    EXPECT_EQ(12, multiset.count(2));
    EXPECT_EQ(3, multiset.count(3));

    multiset.erase(2);

    ASSERT_EQ(4, multiset.size());
    EXPECT_EQ(1, multiset.count(1));
    EXPECT_EQ(3, multiset.count(3));
}

TEST(UnorderedSetValue, CustomTypeHashAndComparator) {

    struct Value {
        int a;
        int b;
        int c;
    };

    struct Hash {
        size_t operator()(const Value& X) const
        {
            return (hash<int>()(X.a)) ^ (hash<int>()(X.b)) ^ (hash<int>()(X.c));
        }
    };

    struct Equal {
        bool operator()(const Value &A, const Value &B) const
        {
            if( A.a == B.a && A.b == B.b && A.c == B.c )
                return true;
            else
                return false;
        }
    };

    unordered_set< Value, Hash, Equal > unordered_set = {};

    ASSERT_TRUE(unordered_set.empty());

    unordered_set.insert({1, 1, 1});

    ASSERT_EQ(1u, unordered_set.size());
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1, 1}));



    ASSERT_EQ(1u, unordered_set.size());
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1, 1}));

    unordered_set.insert({1, 2, 1});
    unordered_set.insert({2, 1, 1});
    unordered_set.insert({2, 2, 1});
    unordered_set.insert({1, 1, 2});
    unordered_set.insert({1, 2, 2});
    unordered_set.insert({2, 1, 2});
    unordered_set.insert({2, 2, 2});

    ASSERT_EQ(8u, unordered_set.size());
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1, 1}));
    EXPECT_EQ(1u, unordered_set.count(Value{1, 2, 1}));
    EXPECT_EQ(1u, unordered_set.count(Value{2, 1, 1}));
    EXPECT_EQ(1u, unordered_set.count(Value{2, 2, 1}));
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1, 2}));
    EXPECT_EQ(1u, unordered_set.count(Value{1, 2, 2}));
    EXPECT_EQ(1u, unordered_set.count(Value{2, 1, 2}));
    EXPECT_EQ(1u, unordered_set.count(Value{2, 2, 2}));
}

TEST(UnorderedSetInt, BucketsAndLoadFactor) {

    unordered_set <int> unordered_set = {};
    unordered_set.insert(1);

    ASSERT_EQ(1u, unordered_set.size());
    EXPECT_EQ(2u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(1.0 / 2.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    unordered_set.insert(2);

    ASSERT_EQ(2u, unordered_set.size());
    EXPECT_EQ(2u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    unordered_set.insert(2);
    unordered_set.insert(3);
    unordered_set.insert(3);

    ASSERT_EQ(3u, unordered_set.size());
    EXPECT_EQ(5u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(3.0 / 5.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    unordered_set.insert(5);

    ASSERT_EQ(4u, unordered_set.size());
    EXPECT_EQ(5u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(4.0 / 5.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    unordered_set.insert(4);

    ASSERT_EQ(5u, unordered_set.size());
    EXPECT_EQ(5u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    unordered_set.insert(5);
    unordered_set.insert(6);
    unordered_set.insert(7);
    unordered_set.insert(8);
    unordered_set.insert(9);
    unordered_set.insert(10);

    ASSERT_EQ(10u, unordered_set.size());
    EXPECT_EQ(11u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(10.0 / 11.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    unordered_set.insert(11);

    ASSERT_EQ(11u, unordered_set.size());
    EXPECT_EQ(11u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(11.0 / 11.0, unordered_set.load_factor());
}
