#include "time_series.h"


void TIMESERIES_date::add_item(HALIFAX_TRANSACTION_ROW item)
{
    total_credit += item.credit_amount;
    total_debit += item.debit_amount;
    items.push_back(item);
}

void TIMESERIES_date::print(std::ostream& whereto)
{
    whereto << "DATE: " << date << "\n";
    whereto << " #transactions: " << items.size() << "\n";
    int trans_id = 1;
    for(auto& h : items)
    {
        whereto << "  " << trans_id << " ";
        whereto <<  "  DEBIT: " << std::setw(10)<< std::left<<h.debit_amount ;
        whereto << "  CREDIT: " << std::setw(15)<< std::left << h.credit_amount << "\n";
        trans_id ++;
    }
    whereto << "Total debit: " << total_debit << "\n";
    whereto << "Total credit: " << total_credit << "\n";
    whereto << "BALANCE: " << items[items.size() - 1].balance << "\n";
    whereto << "\n";
    
}

void TIMESERIES_date::print()
{
    print(std::cout);
}




TIMESERIES::TIMESERIES(){}  

void TIMESERIES::add_date(std::string d)
{
    series.push_back(TIMESERIES_date(d));
}

void TIMESERIES::add_to_top()
{
    series[series.size() - 1].add_item(HALIFAX_TRANSACTION_ROW());
}

void TIMESERIES::add_to_top(HALIFAX_TRANSACTION_ROW htr)
{
    series[series.size() - 1].add_item(htr);
}

void TIMESERIES::print()
{
    for(auto& t : series)
    {
        t.print();
    }
}


