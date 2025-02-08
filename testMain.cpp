#include <iostream>
#include "../include/doctest.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

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


int main() {
    int n, iterations;
    cin >> n;

    cin >> iterations;

    for (int i = 0; i < iterations; i++) {



    }


}

TEST_CASE("Testing fisher_yates function") {{


}