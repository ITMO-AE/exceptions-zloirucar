# Задача 1
Напишите функцию `checkEqual` для проверки двух строк на равенство по длине.
```cpp
void checkEqual(const string& left, const string& right);
```

В случае, если строка `left` не равна строке `right`, функция должна выбрасывать исключение `runtime_error` с содержанием "<left> != <right>", где `<left>` и `<right>` - строки, которые хранятся в переменных `left` и `right` соответственно.

Если `left == right`, функция должна корректно завершаться.

Например, код
```cpp
int main() {
  try {
    EnsureEqual("Hello C++", "Hello C++");
    EnsureEqual("Hello C++", "Bye C++");
  } catch (runtime_error& e) {
    cout << e.what() << endl;
  }
  return 0;
}
```
Вывод:
```sh
Hello C++ != Bye C++
```

# Задача 2 

Поменяйте реализацию конструктора класса `Rational` так, чтобы он выбрасывал исключение `invalid_argument`, если знаменатель равен нулю. Кроме того, переделайте реализацию оператора деления для класса `Rational` так, чтобы он выбрасывал исключение `domain_error`, если делитель равен нулю.

```cpp
int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
```
