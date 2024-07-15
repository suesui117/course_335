#include<iostream>
#include<string>

using namespace std;


int encode1 ( const int RADIX, const string & s)
{
    int hashval = 0;

    std::cout <<"radix is " <<  RADIX << " hashvalue is "<<hashval<<"\n";
    for (int i = 0; i < s.length(); i++)
    {
        std::cout << "element is "<< s[i] << " " << s[i]+0 << "\n";
        
        // everytime hashvalue is increased by ascii of current char + 10 * previous hashval
        hashval = s[i] + RADIX * hashval; // p(x) = s_i + x(q(x)),

        std::cout <<"radix is " <<  RADIX << " hashvalue is "<<hashval<<"\n";

    }

    return hashval;
}


long long encode2 ( const int RADIX, const string & s)
{
    int sum = s[0];
    int product = 1;

    for (int i = 1; i < s.length(); i++)
    {
        product = product * RADIX; // 1 * 10 = 10
        sum = sum + s[i] * product; // 97 + 97 * 10 = 1067

        //product = 10 * 10 = 100
        // sum = 1067 + 97 * 100 = 2037
    }     
    return sum;
}


int main()
{
    string test = "aab";
    
    int char_size = 10;

    cout << encode1(char_size, test) <<"\n";
    cout << encode2(char_size, test) << endl;

    return 0;
}