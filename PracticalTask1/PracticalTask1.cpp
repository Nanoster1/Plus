#include <iostream>
using namespace std;
void CalculateBig(char *num, int bytes) 
{
    cout << "Big-Endian:";
    for (int i = bytes - 1; i >= 0; i--)
    {
        for (int k = 0; k < 8; k++)                          
        {
            cout << ((*(num + i) >> (7 - k)) & 1);
        }
    }
    cout << endl;
}
void CalculateLittle(char *num, int bytes)
{
    cout << "Little-Endian:";
    for (int i = 0; i < bytes; i++)
    {
        for (int k = 0; k < 8; k++)                          
        {
            cout << ((*(num + i) >> (7 - k)) & 1);
        }
    }
    cout << endl;
}
int main()
{
    cout << "Input your number: ";
    double num;
    cin >> num;
    int numInt = (int)num;
    int numInt2 = (int)num;
    float numFloat = (float)num;
    float numFloat2 = (float)num;
    cout << "int:" << endl;
    CalculateBig((char*)&numInt, 4);
    CalculateLittle((char*)&numInt2, 4);
    cout << "float:" << endl;
    CalculateBig((char*)&numFloat, 4);
    CalculateLittle((char*)&numFloat2, 4);
    cout << "double:" << endl;
    CalculateBig((char*)&num, 8);
    CalculateLittle((char*)&num, 8);
}