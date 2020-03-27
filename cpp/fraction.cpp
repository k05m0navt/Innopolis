#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

// Class fraction
class Fraction 
{
    private:

        int numerator, denumerator, int_part = 0;

    public:
        Fraction();
        Fraction(int n, int d);  

        int getNumerator();

        int getDenumerator();

        int getIntPart();

        bool convertStringToFraction(string FractionString);

        bool convertIntToFraction(int FractionInt);

        bool convertDoubleToFraction(double FractionDouble);

        double convertFractionToDouble(void);

        long euclidian(int num, int denum);

        bool gcd();
        
        friend istream& operator >> (istream& is, const Fraction& fraction);
        friend ostream& operator << (ostream& out, const Fraction& fraction);


};

// Default constructor
Fraction::Fraction()
{
    numerator = 0;
    denumerator = 1;
}

// Main constructor
Fraction::Fraction(int n, int d)
{
    if (d == 0)
    {
        cout << "Denumerator can not be zero" << endl;
    }else if (n == 0)
    {
        this->numerator = 0;
        this->denumerator = 0;
    }else
    {
        int sign = 1;
        if (n<0)
        {
            sign *= -1;
            n *= -1;
        }
        if (d<0)
        {
            sign *= -1;
            d *= -1;
        }
        gcd();   
    } 
} 

// Get numerator
int Fraction::getNumerator()
{
    return this->numerator;
}

// Get Denumerator
int Fraction::getDenumerator()
{
    return this->denumerator;
}

int Fraction::getIntPart()
{
    return this->int_part;
}

long Fraction::euclidian(int num, int denum)
{
    return denum == 0 ? num : this->euclidian(denum, num % denum);
}
// Euclidian algorithm for fractions
bool Fraction::gcd()
{
    long gcd(this->euclidian(this->numerator, this->denumerator));

    if (1 < gcd) {
		this->numerator /= gcd;
		this->denumerator /= gcd;

		return true;
    } 
    else 
    {
        return false;
    }
}

//Convert int to fraction
bool Fraction::convertIntToFraction(int Int)
{
    this->denumerator = 1;
    this->numerator = 1;
    this->int_part = Int;

    return true;
}

// Convert String to fraction(need to update)
bool Fraction::convertStringToFraction(string String)
{
    size_t pos1 = String.find(" ");
    size_t pos2 = String.find("/");

    if (pos2 != string::npos) 
    {
        int int_part = atol(String.substr(0, pos1).c_str());
        this->denumerator = atol(String.substr(pos2 + 1).c_str());	
        if (pos1 != string::npos)
            this->numerator = int_part*(this->denumerator) + atol(String.substr(pos1 + 1, pos2).c_str());	
        else
            this->numerator = atol(String.substr(0, pos2).c_str());
        return (this->denumerator == 0) ? false : true;
    }
    else
    {
        this->denumerator = 1;
        this->numerator = 1;
        this->int_part = atol(String.substr(pos1 + 1, pos2).c_str());
    }


    

    return false;
}

bool Fraction::convertDoubleToFraction(double FractionDouble)
{
    this->denumerator = 1;
    while ((double)(int)FractionDouble != FractionDouble)
    {
        FractionDouble = FractionDouble * 10;
        this->denumerator = this->denumerator * 10;
    }
    
    this->numerator = (int)FractionDouble;
    gcd();
    if (this->numerator > this->denumerator)
    {
        this->int_part = (int)(this->numerator / this->denumerator);
        convertDoubleToFraction((double)(this->numerator / this->denumerator) - this->int_part);
    }
    return 1; 
}

double Fraction::convertFractionToDouble(void)
{
    return (double)this->numerator / (double)this->denumerator;
}

std::ostream& operator<<(std::ostream &out, Fraction &Fraction) 
{
    if (Fraction.getIntPart() == 0)
        out << Fraction.getNumerator() << "/" << Fraction.getDenumerator();
    else if (Fraction.getDenumerator() != 1)
        out << Fraction.getIntPart() << " " << Fraction.getNumerator() << "/" << Fraction.getDenumerator(); 
    else
        out << Fraction.getNumerator();
	return out;
}

std::istream& operator>>(std::istream &in, Fraction &Fraction) 
{
	std::string input;

	in >> input;

    Fraction.convertStringToFraction(input);

	return in;
}

int main(int argc, char const *argv[])
{
    string str;
    Fraction fraction;

    str = "1"; 
    while(str != "0")
    {
        getline(cin, str);
        if (str == "0")
            break;
        else if (str == "1")
        {
            getline(cin, str);
            int Int = stoi(str); 
            fraction.convertIntToFraction(Int);
            cout << fraction;
        }
        //need to update cin
        else if (str == "2")
        {
            cin >> fraction;
            cout << fraction;
            std::cout << (int)trunc((double)fraction.getNumerator() / (double)fraction.getDenumerator());
        }
        else if (str == "3")
        {
            getline(cin, str);
            double FractionDouble = stod(str);
            fraction.convertDoubleToFraction(FractionDouble);
            cout << fraction;
        }
        else if (str == "4")
        {
            cin >> fraction;
            std::cout << fraction.convertFractionToDouble();
        }
        else if (str == "5")
        {
            
        }
        else if (str == "6")
        {
            
        }
        else if (str == "7")
        {
            
        }
        else if (str == "8")
        {
            
        }
        else if (str == "9")
        {
            
        }
        else if (str == "10")
        {
            
        }
    }
    return 0;
}
