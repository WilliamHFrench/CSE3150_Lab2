//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "include/doctest.h"
#include "fisherYates.cpp"


using namespace std;


void setupPlusAndMinuses(int ary[], int totalLength, int n){
    for(int i = 0; i< totalLength; i++){
        if(i<n){
            ary[i] = 1;
        }
        else{
            ary[i] = -1;
        }
    }
}

bool ListMatch(int a1[], int a2[], int TotalLength){
    bool same = true;
    for(int i = 0; i < TotalLength; i++){
        if(a1[i] != a2[i]){
            return false;
        }
    }
    return same;
}


bool ListChecker(int ary[], int totalLength){
    bool Correct = true;
    int sum = ary[0];
    if(sum == -1){
        for (int i = 1; i < totalLength; i++){
            sum = sum + ary[i];
            if(sum > 0){
                return false;
            }
        };
    }
    else{
        for (int i = 1; i < totalLength; i++){
            sum = sum + ary[i];
            if(sum < 0){
                return false;
            }

    }
}
    return Correct;
}

struct results{
    float result;
    int totalPermutations;
    int passingPermutations;
};

int random_number() {
    return rand(); // Returns a pseudo-random number
}

results PRunner(int p, int n){
    int pass = 0;
    double r = 0.0;
    int arr[2 * n];
    setupPlusAndMinuses(arr, 2*n, n);
    for (int i = 0; i < p; i++){
        fisher_yates(arr, 2*n, random_number);
        if(ListChecker(arr, 2*n)){
            pass = pass + 1;
        }
    }
    results answer;
    answer.totalPermutations = p;
    answer.passingPermutations = pass;
    r = (static_cast<double>(pass) / p);
    answer.result = r;
    return answer;
}


TEST_CASE("Testing ListMatch") {
    int nums_1[] = {1,-1};
    int nums_2[] = {1,1};
    int nums_3[] = {1,1};

    CHECK(!ListMatch(nums_1, nums_2, 2));
    CHECK(ListMatch(nums_2, nums_3, 2));
};


TEST_CASE("Testing setupPlusandMinuses") {
    int nums_1[] = {1,-1};
    int nums_2[] = {1,1,-1,-1};
    int nums_3[] = {1,1,1,-1,-1,-1};

    int tester1[2] = {};
    int tester2[4] = {};
    int tester3[6] = {};

    setupPlusAndMinuses(tester1, 2, 1);
    CHECK(ListMatch(nums_1, tester1, 2));
    setupPlusAndMinuses(tester2, 4, 2);
    CHECK(ListMatch(nums_2, tester2, 4));
    setupPlusAndMinuses(tester3, 6, 3);
    CHECK(ListMatch(nums_3, tester3, 6));
};

TEST_CASE("Testing ListChecker") {
    int nums_1[] = {1,-1, 1, -1, 1, -1};
    int nums_2[] = {-1, 1,-1, 1};
    int nums_3[] = {};
    int nums_4[] = {1,1,1,-1,-1,-1, -1};
    int nums_5[] = {-1,-1,1,1,1,-1, -1};


    CHECK(ListChecker(nums_1, 6));
    CHECK(ListChecker(nums_2, 4));
    CHECK(ListChecker(nums_3, 0));
    CHECK(!ListChecker(nums_4, 7));
    CHECK(!ListChecker(nums_5, 7));
};

TEST_CASE("Testing Prunner") {
    results a = PRunner(5000, 50);
    results b = PRunner(5000, 100);
    results c = PRunner(10000, 50);
    results d = PRunner(10000, 100);

    CHECK(a.totalPermutations==5000);
    CHECK(a.result < 0.05);
    CHECK(0.03 < a.result);

    CHECK(b.totalPermutations==5000);
    CHECK(b.result < 0.02);
    CHECK(0.01 < b.result);

    CHECK(c.totalPermutations==10000);
    CHECK(c.result < 0.05);
    CHECK(0.03 < c.result);

    CHECK(d.totalPermutations==10000);
    CHECK(d.result < 0.02);
    CHECK(0.01 < d.result);

    MESSAGE("A total: " << a.totalPermutations);
    MESSAGE("A passing: " << a.passingPermutations);
    MESSAGE("A result: " <<a.result);

    MESSAGE("B total: " << b.totalPermutations);
    MESSAGE("B passing: " << b.passingPermutations);
    MESSAGE("B result: " <<b.result);

    MESSAGE("C total: " << c.totalPermutations);
    MESSAGE("C passing: " << c.passingPermutations);
    MESSAGE("C result: " <<c.result);

    MESSAGE("D total: " << d.totalPermutations);
    MESSAGE("D passing: " << d.passingPermutations);
    MESSAGE("D result: " <<d.result);
};