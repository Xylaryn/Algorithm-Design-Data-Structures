#ifndef BIGNUMCALC_H
#define BIGNUMCALC_H

#include <list>
#include <string>

class BigNumCalc {
  public:
    BigNumCalc();
    ~BigNumCalc();

    // Method to build a list representation of a large number from a string
    std::list<int> buildBigNum(std::string numString);

    // Method to add two large integers
    std::list<int> add(std::list<int> num1, std::list<int> num2);

    // Method to subtract num2 from num1
    std::list<int> sub(std::list<int> num1, std::list<int> num2);

    // Method to multiply num1 by num2, where num2 is a signle digit integer
    std::list<int> mul(std::list<int> num1, std::list<int> num2);
};

#endif // BIGNUMCALC_H