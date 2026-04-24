#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int countPrimesInFile(const string &filename)
{
    ifstream file(filename);

    int num, count = 0;

    if (file.is_open())
    {
        while (file >> num)
        {
            if (isPrime(num))
            {
                count++;
            }
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }

    return count;
}
int main()
{
    int result = countPrimesInFile("NUMS.txt");
    cout << "Number of prime numbers: " << result << endl;
    return 0;
}