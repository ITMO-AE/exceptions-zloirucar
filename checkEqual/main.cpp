#include <iostream>
#include <exception>
#include<string>

using namespace std;

//class runtimeerror : public exception
//{
//public:
//    runtimeerror(string msg):exception()
//    {
//        cout << msg << endl;;
//    }

//};

void checkEqual(const string& left, const string& right)
{
    left.size() != right.size()? throw runtime_error(left+" != "+right):false;
}

int main()
{
    try {
        checkEqual("Hello C++", "Hello C++");
        checkEqual("Hello C++", "Bye C++");
      } catch (runtime_error& e) {
        cout << e.what() << endl;
      }
      return 0;
    }

