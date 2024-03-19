# Move семантики - 20.03.2024


### **Ако използваме динамична памет за член-данните трябва да реализираме цялата голяма четворка!**

За примерите ще ползваме класа `Complex`, само че този път класът ще си има име:
```cpp
class Complex {
private:
    double real;
    double imag;

    // New
    char* name;
public:
    ...

    // New
    Complex add(Complex const& other) const {
      // Some magical code
      return result;
    }
};
```

### Какво ще се случи, ако направим следното нещо?

```cpp
void someFunction(Complex number) {
  // More magical code
}

int main() {
  Complex a, b;
  someFunction(a.add(b));

  return 0;
}
```

Ще се създаде временен обект, който не е записан никъде от `a.add(b)`, който после ще се копира при извикването на функцията и при една правилна реализация на класа `Complex` ще се задели нова памет за името, защото ще се извика COPY конструктор. Но това е излишно!     
В такъв случай може да използваме MOVE конструктор, с който ние си "кредем" вече заделената памет при първото създаване на обект.


```cpp
class Complex {
private:
    double real;
    double imag;

    // New
    char* name;
public:
    ...

    // New
    Complex(Complex&& other) {
      this->real = other.real;
      this->imag = other.imag;
      this->name = other.name;

      other.name = nullptr;
    }

    Complex& operator=(Complex&& other) {
      if (this != &other) {
        this->real = other.real;
        this->imag = other.imag;
        this->name = other.name;

        other.name = nullptr;
      }

      return *this;
    }
};
```

## Задачи
## 1. задача
Допълнете задачата от предишния път като добавите Move семантики за класа `Set`.

## 2. задача
Напишете клас, който да представлявя [динамичен масив](https://en.wikipedia.org/wiki/Dynamic_array) от цели числа. Имплементирайте следните методи:

- Конструктор по подразбиране, който създава празен масив.
- Copy constructor и Assignment operator.
- Move constructor и Move assignment operator.
- Destructor, който освобождава динамичната памет!
- `append(value)`, който добавя стойността `value` накрая на масива.
- `insert(pos, value)`, който вмъква стойността `value` на позиция `pos`.
- `pop()`, който премахва стойността, която е на последна позиция в масива.
- `remove(pos)`, който премахва стойността, която се намира на позиция `pos`.
- `clear()`, който премахва всички елементи от масива.
- `isEmpty()`, който връща дали масивът е празен или съдържа елементи.
- `size()`, който връща броя на елементите в масива.
- `get(pos)`, който връща числото, което се намира на позиция `pos`.
- `set(pos, value)`, който записва стойността `value` на позиция `pos`.
- `find(value)`, който връща позицията на стойността `value`.
