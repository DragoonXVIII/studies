#include <iostream>
#include <vector>


using namespace std;



void wczytaj_dane(string &wzor, string &tekst)
{
    cout << "Podaj wzor: "<<endl;
    getline(cin>>ws, wzor);
    cout << "Podaj tekst: "<<endl;
    getline(cin>>ws, tekst);
    cout<<"W:"<<wzor<<endl;
    cout<<"T:"<<tekst<<endl;
}



void Algorytm_naiwny(string pattern, string text) {
    int m = pattern.size();
    int n = text.size();

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for(j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
        {
            cout<<"Znaleziono x wystapienie zaczynajace sie w indexie: "<<i<<endl;
        }
    }
}


void computeLPSArray(string pattern, vector<int>& lps) {
    int m = pattern.size();
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(string pattern, string text) {
    int m = pattern.size();
    int n = text.size();

    vector<int> lps(m);
    computeLPSArray(pattern, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            cout << "Znaleziono wzorzec na indeksie " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
}



int main()
{
    string wzor,tekst;
    while(true)
    {
        int index;
        cout<<"Wpisz index odpowiadajacy pozadanej czynnosci:\n1. Wczytanie danych\n2. Algorytm naiwny\n3. Algorytm Knutha-Morrisa-Pratta\n4. Algorytm Boyer'a-Moore'a\n5. Zakoncz\n";
        cout<<"Index: ";
        cin>>index;

        switch (index)
        {
            case 1:
            {
                cout<<"Wczytanie danych:"<<endl;
                wczytaj_dane(wzor,tekst);
                break;
            }
            case 2:
            {
                Algorytm_naiwny(wzor,tekst);
                break;
            }
            case 3:
            {

                break;
            }
            case 4:
            {

                break;
            }
            case 5:
            {
                return 0;
            }
        }
        //system("cls");
    }
    return 0;
}


/*
void Algorytm_naiwnyv0(string &wzor, string &tekst)
{
    for(int i=0;i<tekst.length();i++)
    {
        bool poprawny = true;
        if(wzor[0]==tekst[i])
        {
            for(int j=i;j<i+wzor.length();j++)
            {
                if(tekst[j]!=wzor[j-i])
                {
                    poprawny = false;
                    break;
                }
            }
        }
        if(poprawny)
        {
            cout<<"Znaleziono x wystapienie zaczynajace sie w indexie: "<<i<<endl;
            i+=int(tekst.length());
        }
    }
    return;
}

void Algorytm_naiwnyv1(string &wzor, string &tekst)
{
    for(int i=0;i<tekst.size();i++)
    {
        bool poprawny = true;
        if(tekst[i]==wzor[0])
        {
            for(int j=0;j<wzor.size();j++)
            {
                if(tekst[i+j]!=wzor[j])
                {
                    poprawny= false;
                    break;
                }
            }
        }
        if(poprawny)
        {
            cout<<"Znaleziono x wystapienie zaczynajace sie w indexie: "<<i<<endl;
            i+=int(tekst.size());
        }
    }
    return;
}
 */
