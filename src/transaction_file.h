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
#include "unique_item.h"
#include "transaction_items.h"

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
        HALIFAX_TRANSACTION_ROW get_row_for_idx(int i);
        
}; 

