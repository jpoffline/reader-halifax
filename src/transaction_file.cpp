
#include "transaction_file.h"


void TRANSACTION_FILE::read_file(std::string filename)
{
    std::ifstream myfilestream(filename);
    while(!myfilestream.eof())
    {
        std::string line;
        std::getline(myfilestream, line); // skip header
        while(std::getline(myfilestream, line))
        {
            std::istringstream iss(line);
            {
                std::string v;
                std::string d,t,s,a,desc;
                std::string das, cas, bals;
                float da, ca, bal;
            
                getline( iss, d, ',' );
                getline( iss, t, ',' );
                getline( iss, s, ',' );
                getline( iss, a, ',' );
                getline( iss, desc, ',' );
                getline( iss, das, ',' );
                getline( iss, cas, ',' );
                getline( iss, bals);
                da = std::atof(das.c_str());
                ca = std::atof(cas.c_str());
                bal = std::atof(bals.c_str());

                dates.add(d);
                types.add(t);
                sort_codes.add(s);
                account_numbers.add(a);
                descriptions.add(desc);
                debit_amounts.add(da);
                credit_amounts.add(ca);
                balances.add(bal);
                
            }
        }
    }
    myfilestream.close();

}


void TRANSACTION_FILE::print_balances()
{
    balances.print();
}


void TRANSACTION_FILE::print_ordered_data()
{
    auto n = dates.size();
    for(int i = 0; i < n; i++)
    {
        dates.print(i);
        std::cout << " ";
        balances.print(i);
        std::cout << std::endl;
    }
}

void TRANSACTION_FILE::print_date_description()
{
    auto n = dates.size();
    for(int i = 0; i < n; i++)
    {
        dates.print(i);
        std::cout << " ";
        descriptions.print(i);
        std::cout << std::endl;
    }
}

void TRANSACTION_FILE::print_unique_descriptions()
{
    descriptions.print_unique();
}

void TRANSACTION_FILE::create_time_series()
{
    std::string date = "";
    for(int i = 0; i < dates.size(); i++)
    {   
        auto d = dates.get(i);

        if(date != d)
        {
            time_series.add_date(d);
            date = d;
        }
        
        time_series.add_to_top(get_row_for_idx(i));
        
    }
}

void TRANSACTION_FILE::print_time_series()
{
    time_series.print();
}

HALIFAX_TRANSACTION_ROW TRANSACTION_FILE::get_row_for_idx(int i)
{
    return HALIFAX_TRANSACTION_ROW(
        dates.get(i),
        types.get(i),
        sort_codes.get(i),
        account_numbers.get(i),
        descriptions.get(i),
        debit_amounts.get(i),
        credit_amounts.get(i),
        balances.get(i)
    );
}