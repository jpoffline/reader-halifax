#pragma once

#include <vector>
#include "unique_item.h"

template<class T>
class TRANSACTION_ITEMS {

    private:
        std::vector<T> items;

        bool has_collapsed_to_unique;
        std::vector<UNIQUE_ITEM<T> > unique_items;
    public:

        TRANSACTION_ITEMS()
        {
            has_collapsed_to_unique = false;
        }
        void add(T i)
        {
            items.push_back(i);
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