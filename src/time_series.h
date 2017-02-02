
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
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
