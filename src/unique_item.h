#pragma once

#include <vector>
#include <iostream>


template<class T>
struct UNIQUE_ITEM{
    T name;
    std::vector<int> indexes;
    std::vector<float> credits;
    std::vector<float> debits;
    UNIQUE_ITEM(T n, int i) : name(n){add_idx(i);};

    void add_idx(int i)
    {
        indexes.push_back(i);
    }
    friend std::ostream &operator << (std::ostream &output, const UNIQUE_ITEM<T> &u) 
    { 
        output << u.name << "\n   #instances: " << u.indexes.size() << " / indexes: ";
        for(auto& i : u.indexes) output << i << " "; 
        output << "\n";
        return output;       
      }
};