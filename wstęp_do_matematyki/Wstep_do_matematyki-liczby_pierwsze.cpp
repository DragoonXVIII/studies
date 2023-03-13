#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;



bool czy_pierwsza(int liczba)
{
    for(int i=2;i<=sqrt(liczba);i++)
    {
        if(liczba%i==0)
        {
        //cout<<"false"<<endl;
        return false;
        }
    }
    return true;
}



int main()
{

long a,b,last=2,max_ciag=0;
bool pom1;


/*
cout<<"Podaj a"<<endl;
cin>>a;
cout<<"Podaj b"<<endl;
cin>>b;
*/

    for(long i=3;i<=/*2147483647*/99999999;i++)
    {
        if(czy_pierwsza(i))
        {
            if((i-last)>=102)
            {
            for(long j=last;j<=i;j++)
            {
                cout<<j<<", ";
            }
            cout<<endl;
            cout<<"Od: "<<last<<"do: "<<i<<", koniec ciagu, jego dlugosc to: "<<i-last-2<<endl;
            if(i-last-2>max_ciag)
                max_ciag=i-last-2;
            }
            last=i;

        }
    }

/*
if(czy_pierwsza(a))
    cout<<"true"<<endl;
if(czy_pierwsza(b))
    cout<<"true"<<endl;
*/


//cout<<"xD";

cout<<max_ciag<<endl;

return 0;
}
