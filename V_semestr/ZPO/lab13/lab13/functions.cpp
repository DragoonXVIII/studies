#include "functions.h"
bool isEven(int n)
{
    if(n%2==0)
        return true;
    else
        return false;
}

int sign(int n)
{
    if(n<0)
        return -1;
    if(n>0)
        return 1;
    else
        return 0;
}

vector<int> difference(vector<int> vec)
{
    vector<int>res;
    for(int i=1; i<vec.size();i++)
    {
        res.push_back(vec[i]-vec[i-1]);
    }
    return res;
}

void show(string line)
{
    if(line.empty())
        throw runtime_error("Pusty napis");
    cout<<"Podany napis to: "<<line<<endl;
}
