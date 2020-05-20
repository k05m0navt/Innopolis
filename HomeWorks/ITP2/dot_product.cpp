//All necessary libs
#include <iostream>
#include <exception>
using namespace std;

//Exception class to catch when length of two containers are not equal
class LengthsNotEqualException: public exception
{
    virtual const char* what() const throw()
    {
        return "The lengths of two containers are not equal";
    }
} lnee;

//Template function to find dot product of two containers
template <typename T>
T dot_product(T cont1[], T cont2[], int length1, int length2)
{
    T result = 0;

    if (length1 != length2)
        throw lnee;
    else
    {
        for(int i = 0; i < length1; i++)
            result = result + cont1[i] * cont2[i];

        return (result);
    }
    
}

//Main function
int main(int argc, const char** argv) {

    //Lengths of containers
    int length1;
    int length2;

    //Input length and values of the first container
    cin >> length1;
    double cont1[length1];
    for(int i=0;i<length1;i++)
        cin >> cont1[i];

    //Input length and values of the second container
    cin >> length2;
    double cont2[length2];
    for(int i=0;i<length2;i++)
        cin >> cont2[i];

    //Try/Catch Block
    try
    {
        double result = dot_product<double>(cont1, cont2, length1, length2);
        cout << result << endl;
    }
    catch (exception& e)
    {
        cout << e.what() << '\n';
    }

    return 0;
}