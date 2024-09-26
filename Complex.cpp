#include <iostream>
#include <cmath>
using namespace std;

struct Complex {
    double Real;
    double Imaginary;

    // Toán tử +
    Complex operator + (Complex &complexOther)
    {
        Complex result;
        result.Real = Real + complexOther.Real;
        result.Imaginary = Imaginary + complexOther.Imaginary;
        return result;
    }

    // Toán tử -
    Complex operator - (Complex &complexOther)
    {
        Complex result;
        result.Real = Real - complexOther.Real;
        result.Imaginary = Imaginary - complexOther.Imaginary;
        return result;
    }
    
    // Toán tử *
    Complex operator * (Complex &complexOther)
    {
        Complex result;
        result.Real = (Real * complexOther.Real) - (Imaginary * complexOther.Imaginary);
        result.Imaginary = (Real * complexOther.Imaginary) + (Imaginary * complexOther.Real);
        return result;
    }

    // Toán tử /
    Complex operator / (Complex &complexOther)
    {
        Complex result;
        result.Real = (Real * complexOther.Real + Imaginary * complexOther.Imaginary) /  (complexOther.Real * complexOther.Real + complexOther.Imaginary * complexOther.Imaginary);
        result.Imaginary = (Imaginary * complexOther.Real - Real * complexOther.Imaginary) /  (complexOther.Real * complexOther.Real + complexOther.Imaginary * complexOther.Imaginary);
        return result;
    }

    // Toán tử <<
    friend ostream& operator << (ostream& output, Complex& c)
    {
        output << c.Real;
        if (c.Imaginary >= 0) output << " + " << c.Imaginary << "i";
        else output << " - " << - c.Imaginary << "i";
        return output;
    }

    // Toán tử >>
    friend istream& operator >> (istream& input, Complex& c) 
    {
        input >> c.Real >> c.Imaginary;
    }
};

int main()
{  
    Complex num1, num2;
    cout << "So phuc thu nhat la (Nhap theo dinh dang a + bi): ";
    cin >> num1;
    cout << "So phuc thu hai la (Nhap theo dinh dang a + bi): ";
    cin >> num2;
    cout << num2 << endl;
    Complex result1 =  num1 + num2;
    Complex result2 =  num1 - num2;
    Complex result3 =  num1 * num2;
    Complex result4 =  num1 / num2;

    cout << "Tong: " << result1 << endl;
    cout << "Hieu: " << result2 << endl;
    cout << "Tich: " << result3 << endl;
    cout << "Thuong: " << result4 << endl;

    return 0;
}