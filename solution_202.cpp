//
// Created by 01 on 2025/7/9.
//
#include<iostream>
#include<vector>
#include<cmath>
#include <unordered_map>
using namespace std;

vector<int> getNum(int n) {
    vector<int> v;
    while (n != 0) {
        v.push_back(n % 10);
        n = n / 10;
    }
    return v;
}

bool isHappy(int n) {
    vector<int> v = getNum(n);
    unordered_map<int, int> n_map;
    n_map[n]++;
    while(n != 1) {
        int sum = 0;
        for (auto it = v.begin(); it != v.end(); it++) {
            sum += pow(*it,2);
        }
        n = sum;
        n_map[n]++;
        if (n_map[n]==2) return false;
        v= getNum(n);
    }
    return true;
}