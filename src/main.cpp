/*
// HEADER:
//Transaction Date,
Transaction Type,
Sort Code,
Account Number,
Transaction Description,
Debit Amount,
Credit Amount,Balance,
*/
#include <iostream>
#include <string>
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

template <class COMPANY>
class TRANSACTION_FILE
{
    private:
        std::vector<COMPANY> rows;
    public:
        void read_file(std::string filename);
};



int main(){

    TRANSACTION_FILE<HALIFAX_TRANSACTION_ROW> htf;
    DATEUTILS date("01/01/1988");
    date.print(std::cout);
    
    
}