#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string WhatPicture(string s[])
{
    int length=20;
    int HowManyBadRow=0, HowManyBadColumns=0;
    int HowManyOnes=0;
    char RightBit;

    for(int i=0;i<20;i++)
    {

        for(int j=0;j<20;j++)
        {
            if(s[i][j]=='1') HowManyOnes++;
            if(j==19)
            {

                if(HowManyOnes%2==1)
                {
                    RightBit='1';
                }
                else
                {
                    RightBit='0';
                }

                if(RightBit!=s[i][20])
                {
                    HowManyBadRow++;
                }

                HowManyOnes=0;
            }
        }
    }

    for(int i=0;i<20;i++)
    {

        for(int j=0;j<20;j++)
        {

            if(s[j][i]=='1')HowManyOnes++;
            if(j==19)
            {
                if(HowManyOnes%2==1)
                {
                    RightBit='1';
                }
                else
                {
                    RightBit='0';
                }
                if(RightBit!=s[20][i])
                {
                    HowManyBadColumns++;
                }
                HowManyOnes=0;
            }
        }
    }

    if(HowManyBadColumns>1 || HowManyBadRow>1)
    {
        return "nienaprawialny";
    }
    else if(HowManyBadColumns>0 || HowManyBadRow>0)
    {
        return "naprawialny";
    }
    else
    {
        return "poprawny";
    }
}

int HowManyErrors(string s[])
{
    int length=20;
    int HowManyBadRow=0, HowManyBadColumns=0;
    int HowManyOnes=0;
    char RightBit;
    for(int i=0;i<20;i++)
    {

        for(int j=0;j<20;j++)
        {
            if(s[i][j]=='1') HowManyOnes++;
            if(j==19)
            {

                if(HowManyOnes%2==1)
                {
                    RightBit='1';
                }
                else
                {
                    RightBit='0';
                }

                if(RightBit!=s[i][20])
                {
                    HowManyBadRow++;
                }

                HowManyOnes=0;
            }
        }
    }

    for(int i=0;i<20;i++)
    {

        for(int j=0;j<20;j++)
        {

            if(s[j][i]=='1')HowManyOnes++;
            if(j==19)
            {
                if(HowManyOnes%2==1)
                {
                   RightBit='1';
                }
                else
                {
                    RightBit='0';
                }
                if(RightBit!=s[20][i])
                {
                    HowManyBadColumns++;
                }
                HowManyOnes=0;
            }
        }
    }

    return HowManyBadColumns+HowManyBadRow;
}

int main()
{
    ifstream data("dane_obrazki.txt");
    ofstream data2("wyniki.txt");

    string bf[21];
    int length, HowManyRepairable=0, HowManyCorrect=0, HowManyIrreparable=0, maxErrors=0;
    int k=0;
    
    while(k<200)
    {
        for(int i=0;i<21;i++) {
                data>>bf[i];
                cout<<bf[i]<<endl;
        }
        if(HowManyErrors(bf)>maxErrors) {
            maxErrors=HowManyErrors(bf);
        }
        if(WhatPicture(bf)=="poprawny") {
            HowManyCorrect++;
        }
        if(WhatPicture(bf)=="naprawialny") {
            HowManyRepairable++;
        }
        if(WhatPicture(bf)=="nienaprawialny") {
            HowManyIrreparable++;
        }
        k++;
        cout<<endl;
    }

    cout<<"Poprawnych: "<<HowManyCorrect<<endl;
    cout<<"Naprawialnych: "<<HowManyRepairable<<endl;
    cout<<"Nienaprawialnych: "<<HowManyIrreparable<<endl;
    cout<<"Maks bledow: "<<maxErrors<<endl;
    return 0;
}