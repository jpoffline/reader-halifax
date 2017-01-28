

#pragma once
#include <string>



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
    HALIFAX_TRANSACTION_ROW():
        date("yyyy/mm/dd"), 
        type(""),
        sort_code(""), 
        account_number(""),
        description(""), 
        debit_amount(0), 
        credit_amount(0), 
        balance(0)
    {

    };

    HALIFAX_TRANSACTION_ROW(
        std::string idate,
        std::string itype,
        std::string isort_code,
        std::string iaccount_number,
        std::string idescription,
        float idebit_amount,
        float icredit_amount,
        float ibalance
        ) : 
            date(idate), 
            type(itype),
            sort_code(isort_code), 
            account_number(iaccount_number),
            description(idescription), 
            debit_amount(idebit_amount), 
            credit_amount(icredit_amount), 
            balance(ibalance)
    {

    };

};