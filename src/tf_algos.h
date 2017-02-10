#pragma once
#include "transaction_file.h"
#include <iostream>

class TF_algos
: public TRANSACTION_FILE
{
    private:
        TRANSACTION_FILE& tf;
    public:
        
        TF_algos(TRANSACTION_FILE& t) : tf(t){}
        
        void sort_debit_amounts()
        {
            tf.debit_amounts.sort();
            tf.debit_amounts.print_idx_items(std::cout);
        }
        
        void sort_credit_amounts()
        {
            tf.credit_amounts.sort();
            tf.credit_amounts.print_idx_items(std::cout);
        }
};