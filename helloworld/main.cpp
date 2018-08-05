#include <iostream>

using namespace std;

char findFirstRecurringChar(const char *input, long length)
{
    char ret = '';
    char temp = '';

    for(int i = 0; i < length-1; i++)
    {
        temp = input[i];

        for(int j = i+1; j < length; j++)
        {
            if(temp == input[j])
            {
                ret = temp;
                return ret;
            }
        }
    }
    return '';
}

int main()
{
    cout << "Hello World!" << endl;
    char[] input = "ABCDAB";
    char output = findFirstRecurringChar(input, strlen(input));
    cout<< output<<endl;
    return 0;
}
