/*
// HEADER:
//Transaction Date,
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
#include "utils.h"
#include "dateutils.h"


struct HALIFAX_TRANSACTION_ROW
{
    std::string date; // DD/MM/YYYY-format
    std::string type;
    std::string sort_code;
    std::string account_number;
    std::string description;
    float debit_amount;
    float credit_amount;
    float balance;
};

template<class T>
class TRANSACTION_ITEMS{
    private:
        std::vector<T> items;
        std::vector<std::pair<T, int> > unique_items;
        bool has_collapsed_to_unique;
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
            // first = item
            // second = count(item) in original list.
            for(auto &item : items)
            {
                bool found = false;
                for(auto & unique : unique_items)
                {
                    if(unique.first == item)
                    {
                        unique.second ++;
                        found = true;
                        break;
                    }
                }
                if(!found)
                {
                    unique_items.push_back(make_pair(item, 1));
                }
            }
            has_collapsed_to_unique = true;
        }

        void print_unique()
        {
            if(!has_collapsed_to_unique)
            {
                collapse_to_unique();
            }
            for(auto& unique : unique_items)
            {
                std::cout << unique.first << " " << unique.second << std::endl;
            }
        }
};

class TIMESERIES_date{
    private:
        std::string date;
        std::vector<HALIFAX_TRANSACTION_ROW> items;
    public:
        TIMESERIES_date(std::string d) : date(d) {};
        void add_item(HALIFAX_TRANSACTION_ROW item)
        {
            items.push_back(item);
        }
        void print()
        {
            std::cout << date << std::endl;
        }


};

class TIMESERIES{
    private:
        std::vector<TIMESERIES_date> series;
    public:
        TIMESERIES(){}  
        void add_date(std::string d)
        {
            series.push_back(TIMESERIES_date(d));
        }
        void print()
        {
            for(auto& t : series)
            {
                t.print();
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