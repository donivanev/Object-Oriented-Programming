#include <iostream>
#include <clocale>
#include <string>
#include "Fire.h"
#include "Water.h"
#include "Earth.h"
#include "Air.h"
#include "Gold.h"
#include "Spirit.h"
#include "Stone.h"
#include "Energy.h"
#include "Metal.h"
#include "Alchemic.h"
using namespace std;

void splitStringBySpace(string cmd, vector<string>& v)
{
    int place = 0;
    string token, delimeter = " ";

    while ((place = cmd.find(delimeter)) != string::npos)
    {
        token = cmd.substr(0, place);
        v.push_back(token);
        cmd.erase(0, place + delimeter.length());
    }
    v.push_back(cmd);

    //for (string s : v)
    //{
        //cout << s << endl;
    //}
}

void splitStringByPlusOrEqualSign(string cmd, vector<string>& v)
{
    int place = 0;
    string token, delimeterPlus = "+ ", delimeterEqualSign = "= ";

    while ((place = cmd.find(delimeterPlus)) != string::npos || (place = cmd.find(delimeterEqualSign)) != string::npos)
    {
        token = cmd.substr(0, place);
        v.push_back(token);
        cmd.erase(0, place + delimeterPlus.length());
    }
    v.push_back(cmd);

    //for (string s : v)
    //{
        //cout << s << endl;
    //}
}

void handleBasicElements(string element, vector<string>& vectorOfElements, int amount, string e, Fire &fire, Water &water, Earth &earth, Air &air)
{
    for (int i = 0; i < 4; i++)
    {
        getline(cin, element);
        splitStringBySpace(element, vectorOfElements);
    }
    for (int i = 0; i < 8; i++)
    {
        if (i % 2 != 0)
        {
            amount = stoi(vectorOfElements.at(i - 1));
            e = vectorOfElements.at(i);

            if (e == "Fire") fire = Fire(amount, "Fire");
            else if (e == "Water") water = Water(amount, "Water");
            else if (e == "Earth") earth = Earth(amount, "Earth");
            else if (e == "Air") air = Air(amount, "Air");
        }
    }
    cout << fire.getAmount() << endl;
    cout << water.getAmount() << endl;
    cout << earth.getAmount() << endl;
    cout << air.getAmount() << endl;
}

bool isEquationValid(string formula, Fire f, Water w, Earth e, Air a)
{
    Metal m("Metal"); Stone s("Stone"); Energy en("Energy"); Spirit sp("Spirit"); Gold g("Gold");
    bool flag = true;
    vector<string> vector;
    int place = 0;
    string token, delimeterPlus = " + ", delimeterEqualSign = " = ";

    while ((place = formula.find(delimeterPlus)) != string::npos || (place = formula.find(delimeterEqualSign)) != string::npos)
    {
        token = formula.substr(0, place);
        vector.push_back(token);
        formula.erase(0, place + delimeterPlus.length());
    }
    vector.push_back(formula);

    for (int i = 0; i < vector.size() - 1; i++)
    {
        if (vector[i] == "Fire")
        {
            for (int j = 0; j < vector.size() - 1; j++)
            {
                if (vector[j] != "Fire")
                {
                    if (f.interacts(vector[j]) == false)
                    {
                        flag = false;
                    }
                }
            }
        }
        else if (vector[i] == "Water")
        {
            for (int j = 0; j < vector.size() - 1; j++)
            {
                if (vector[j] != "Water")
                {
                    if (w.interacts(vector[j]) == false)
                    {
                        flag = false;
                    }
                }
            }
        }
        else if (vector[i] == "Earth")
        {
            for (int j = 0; j < vector.size() - 1; j++)
            {
                if (vector[j] != "Earth")
                {
                    if (e.interacts(vector[j]) == false)
                    {
                        flag = false;
                    }
                }
            }
        }
        else if (vector[i] == "Air")
        {
            for (int j = 0; j < vector.size() - 1; j++)
            {
                if (vector[j] != "Air")
                {
                    if (a.interacts(vector[j]) == false)
                    {
                        flag = false;
                    }
                }
            }
        }
        else if (vector[i] == "Metal")
        {
            for (int j = 0; j < vector.size() - 1; j++)
            {
                if (vector[j] != "Metal")
                {
                    if (m.interacts(vector[j]) == false)
                    {
                        flag = false;
                    }
                }
            }
        }
        else if (vector[i] == "Stone")
        {
            for (int j = 0; j < vector.size() - 1; j++)
            {
                if (vector[j] != "Stone")
                {
                    if (s.interacts(vector[j]) == false)
                    {
                        flag = false;
                    }
                }
            }
        }
        else if (vector[i] == "Energy")
        {
            for (int j = 0; j < vector.size() - 1; j++)
            {
                if (vector[j] != "Energy")
                {
                    if (en.interacts(vector[j]) == false)
                    {
                        flag = false;
                    }
                }
            }
        }
        else if (vector[i] == "Spirit")
        {
            for (int j = 0; j < vector.size() - 1; j++)
            {
                if (vector[j] != "Spirit")
                {
                    if (sp.interacts(vector[j]) == false)
                    {
                        flag = false;
                    }
                }
            }
        }
        else if (vector[i] == "Gold")
        {
            for (int j = 0; j < vector.size() - 1; j++)
            {
                if (vector[j] != "Gold")
                {
                    if (g.interacts(vector[j]) == false)
                    {
                        flag = false;
                    }
                }
            }
        }
    }

    return flag;
}

int main()
{
	setlocale(LC_CTYPE, "bulgarian");

    Fire fire; Water water; Earth earth; Air air;
    Metal metal; Stone stone; Energy energy; Spirit spirit;
    Gold gold;
    AlchemicalBook book;

    cout << "Please enter the amounts of the basic elements on separate lines" << endl;
    cout << "After that enter the formulas you want the book to have on separate lines" << endl;
    cout << "When you want to stop entering data, please write \"end\"" << endl;

    cout << "Example: \n2 Earth \n4 Fire \n1 Water \n10 Air" 
         << "\nAir + Air = Spirit \nMetal + Stone = Gold \nFire + Earth = Metal"
         << "\nFire + Water + Earth = Gold \nWater + Earth = Stone \nSpirit + Air = Energy" 
         << "\nWater + Air = Energy \nGold + Spirit + Fire = Philosopher's Stone \n/ Fire"
         << "\nEnergy + Earth = Stone \nend" << endl;

    /*vector<string> rand = { "Gold", "Spirit", "Fire" };
    rand.erase(rand.begin());
    rand.insert(rand.begin(), { "Metal" , "Stone"});
    for (string s : rand)
    {
        cout << s << endl;
    }
    cout << metal.interacts("Fire") << endl;
    cout << metal.interacts("Water") << endl; 
    cout << metal.interacts("Earth") << endl;
    cout << metal.interacts("Air") << endl;
    cout << metal.interacts("Stone") << endl;
    cout << metal.interacts("Energy") << endl;*/

    bool start = false;
    int amount = 0, counter = 0;
    string e, element, formula, PHFormula;
    vector<string> vectorOfElements;
    vector<string> vectorOfFormulas;
    Formula f;

    handleBasicElements(element, vectorOfElements, amount, e, fire, water, earth, air);
    
    while (true)
    {
        getline(cin, formula);

        if (formula == "end")
        {
            break;
        }
        else
        {
            if (formula[0] != '/')
            {
                if (formula.find("Philosopher's Stone") != string::npos)
                {
                    start = true;
                    PHFormula = formula;
                    cout << "Philosopher's Stone equation!" << endl;
                }
                else
                {
                    if (!isEquationValid(formula, fire, water, earth, air))
                    {
                        cout << "Wrong equation." << endl;

                    }
                    else
                    {
                        f = Formula(formula);
                        book.push(f);
                    }
                }
            }
        }
    }

    //book.print();

    if (start)
    {
        book.filter(PHFormula);

        int amounts[4];
        amounts[0] = fire.getAmount();
        amounts[1] = water.getAmount();
        amounts[2] = earth.getAmount();
        amounts[3] = air.getAmount();
        Alchemic alchemic(book, amounts);

        bool answer = alchemic.isItPossibleToCreateThePhilosopherStone();
        if (answer) cout << "Да, възможно е";
        else cout << "Не, не е възможно";
    }
    else
    {
        cout << "You haven't specified the Philosopher's Stone equation." << endl;
    }

	return 0;
}