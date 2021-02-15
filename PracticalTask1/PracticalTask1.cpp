#include <iostream>
using namespace std;
void CalculateBigInt(int num) 
{
    char bytes[4];
    for (int i = 0; i < 4; i++)
    {
        num >>= 8 * i;
        bytes[i] = num & 15;
    }
    cout << "Big-Endian:";
    for (int k = 3; k >= 0; k--)
    {
        for (int i = 0; i < 8; i++)
        {
            cout << ((bytes[k] & 128) >> 7);
            bytes[k] <<= 1;
        }
    }
}
void CalculateLittleInt(int num)
{
    char bytes[4];
    for (int i = 0; i < 4; i++)
    {
        num >>= 8 * i;
        bytes[i] = num & 15;
    }
    cout << "Little-Endian:";
    for (int k = 0; k < 4; k++)
    {
        for (int i = 0; i < 8; i++)
        {
            cout << ((bytes[k] & 128) >> 7);
            bytes[k] <<= 1;
        }
    }
}
int main()
{
    cout << "Input your number: ";
    double num;
    cin >> num;
    cout << endl;
    cout << "int:" << endl;
    CalculateBigInt((int)num);
    cout << endl;
    CalculateLittleInt((int)num);
}