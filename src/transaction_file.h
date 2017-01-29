/*
// HEADER:
Transaction Date,
Transaction Type,
Sort Code,
Account Number,
Transaction Description,
Debit Amount,
Credit Amount,
Balance,
*/

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "utils.h"
#include "dateutils.h"
#include "time_series.h"
#include "halifax_transaction_row.h"


class TIMESERIES_date {

    private:
        std::string date;
        std::vector<HALIFAX_TRANSACTION_ROW> items;
        float total_credit;
        float total_debit;
        float final_balance;
    public:
        TIMESERIES_date(std::string d) 
        : date(d), total_credit(0), total_debit(0), final_balance(0) {};
        void add_item(HALIFAX_TRANSACTION_ROW item);
        void print(std::ostream& whereto);
        void print();

};

class TIMESERIES {
    
    private:
        std::vector<TIMESERIES_date> series;
    
    public:
        TIMESERIES(); 
        void add_date(std::string d);
        void add_to_top();
        void add_to_top(HALIFAX_TRANSACTION_ROW htr);
        void print();

};

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

template<class T>
class TRANSACTION_ITEMS {

    private:
        std::vector<T> items;

        bool has_collapsed_to_unique;
        std::vector<UNIQUE_ITEM<T> > unique_items_new;
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
                for(auto& u : unique_items_new)
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
                    unique_items_new.push_back(UNIQUE_ITEM<T>(item, idx));
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
            
            for(auto& unique_item : unique_items_new)
            {
                std::cout << unique_item << std::endl;
            }
        }
};


class TRANSACTION_FILE
{
    private:
        TRANSACTION_ITEMS<std::string> dates;
        TRANSACTION_ITEMS<std::string> types;
        TRANSACTION_ITEMS<std::string> sort_codes;
        TRANSACTION_ITEMS<std::string> account_numbers;
        TRANSACTION_ITEMS<std::string> descriptions;
        TRANSACTION_ITEMS<float> debit_amounts;
        TRANSACTION_ITEMS<float> credit_amounts;
        TRANSACTION_ITEMS<float> balances;
        TIMESERIES time_series;
    public:
        void read_file(std::string filename);
        void print_balances();
        void print_ordered_data();
        void print_date_description();
        void print_unique_descriptions();
        void create_time_series();
        void print_time_series();
        
}; 