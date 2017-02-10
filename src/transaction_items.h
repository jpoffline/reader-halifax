#pragma once

#include <vector>
#include <algorithm>
#include "unique_item.h"

template<class T>
class TRANSACTION_ITEMS {

    private:
        std::vector<T> items;
        std::vector<std::pair<int, T>> idx_items;
        bool has_collapsed_to_unique;
        std::vector<UNIQUE_ITEM<T> > unique_items;
        struct Cmp_second{
            bool operator()(const std::pair<int, T>& l, const std::pair<int, T>& r)const{
                return l.second < r.second;
            }
        };

    public:

        TRANSACTION_ITEMS()
        {
            has_collapsed_to_unique = false;
        }
        
        void sort()
        {
            std::sort(begin(idx_items), end(idx_items), Cmp_second());
        }

        void print_idx_items(std::ostream& whereto)
        {
            for(auto& idx : idx_items)
            {
                whereto << idx.first << " " << idx.second << "\n";
            }
        }

        void add(T i)
        {
            items.push_back(i);
            idx_items.push_back(std::make_pair(items.size() - 1, i));
            if(has_collapsed_to_unique)
            {
                has_collapsed_to_unique = false;
            }
        }
        T get(int i)
        {
            return items[i];
        }
        void print(std::ostream& whereto)
        {
            for(auto &i : items) 
            {
                whereto << i << " -> ";
            }
        }
        void print()
        {
            print(std::cout);
        }
        void print(int i, std::ostream& whereto)
        {
            whereto << items[i];
        }
        
        void print(int i)
        {
            print(i,std::cout);
        }
        
        size_t size()
        {
            return items.size();
        }

        void collapse_to_unique()
        {
            // Method to collapse the items to just the unique ones;
            // counts up how many instances appeared in the original.
            // Stores the unique items in a vector of pairs; 
            int idx = 0;
            for(auto &item : items)
            {
                
                bool found = false;
                for(auto& u : unique_items)
                {
                    if(u.name == item)
                    {
                        u.add_idx(idx);
                        found = true;
                        break;
                    }
                }

                if(!found)
                {
                    unique_items.push_back(UNIQUE_ITEM<T>(item, idx));
                }
                idx ++;

            }
            has_collapsed_to_unique = true;
        }

        void print_unique()
        {
            if(!has_collapsed_to_unique)
            {
                collapse_to_unique();
            }
            
            for(auto& unique_item : unique_items)
            {
                std::cout << unique_item << std::endl;
            }
        }
};