#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

void checkNextSymbol(stringstream& stream)
{
    if (stream.peek() != '/')
    {
        stringstream s;
        s << "expected /, but get " << char (stream.peek());
        throw runtime_error(s.str());
    }
    stream.ignore(1);
}

Date ParseDate(string const & str)
{
    stringstream stream(str);
    Date date;

    stream >> date.day;
    checkNextSymbol(stream);

    stream >> date.month;
    checkNextSymbol(stream);

    stream >> date.year;

    return date;
}

int main()
{
    string test_date = "11!05/2018";

    try{

        Date date = ParseDate(test_date);
        cout << date.day << " " << date.month << " " << date.year << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }

}
