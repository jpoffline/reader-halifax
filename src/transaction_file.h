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


class TRANSACTION_FILE
{

    public:

        TRANSACTION_ITEMS<std::string> dates;
        TRANSACTION_ITEMS<std::string> types;
        TRANSACTION_ITEMS<std::string> sort_codes;
        TRANSACTION_ITEMS<std::string> account_numbers;
        TRANSACTION_ITEMS<std::string> descriptions;
        TRANSACTION_ITEMS<float> debit_amounts;
        TRANSACTION_ITEMS<float> credit_amounts;
        TRANSACTION_ITEMS<float> balances;
        TIMESERIES time_series;

        void read_file(std::string filename);
        void print_balances();
        void print_ordered_data();
        void print_date_description();
        void print_unique_descriptions();
        void create_time_series();
        void print_time_series();
        HALIFAX_TRANSACTION_ROW get_row_for_idx(int i);
        TRANSACTION_ITEMS<float>& get_debit_amounts()
        {
            return debit_amounts;
        }


}; 

