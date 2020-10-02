#include "AlchemicalBook.h"

void AlchemicalBook::splitStringByPlusOrEqualSign(string cmd, vector<string>& v)
{
    int place = 0;
    string token, delimeterPlus = " + ", delimeterEqualSign = " = ";

    while ((place = cmd.find(delimeterPlus)) != string::npos || (place = cmd.find(delimeterEqualSign)) != string::npos)
    {
        token = cmd.substr(0, place);
        v.push_back(token);
        cmd.erase(0, place + delimeterPlus.length());
    }

    //for (string s : v)
    //{
         //cout << s << endl;
    //}
}

void AlchemicalBook::filter(Formula f)
{
    splitStringByPlusOrEqualSign(f.getEquation(), this->splittedFormula);
    vector<string> vector1;
    vector1 = this->splittedFormula;

    int index = 0, fCounter = 0, wCounter = 0, eCounter = 0, aCounter = 0;

    while(!vector1.empty())
    {
        string el = vector1[index];

        if (el == "Fire" || el == "Water" || el == "Earth" || el == "Air")
        {
            cout << el << " is basic element." << endl;
            if (el == "Fire")
            {
                fCounter++;
            }
            if (el == "Water")
            {
                wCounter++;
            }
            if (el == "Earth")
            {
                eCounter++;
            }
            if (el == "Air")
            {
                aCounter++;
            }
            vector1.erase(vector1.begin());
        }
        else
        {
            // search in array of formulas
            for (int i = 0; i < this->arrayOfFormulas.size(); i++)
            {
                string current = this->arrayOfFormulas[i].getEquation();
                int found = current.find_last_of(" = ");

                if (current.substr(found + 1) == el)
                {
                    cout << "Found it, the equation is: " << current << endl;

                    int place = 0;
                    string token, delimeterPlus = " + ", delimeterEqualSign = " = ", firstElement;
                    vector<string> newvector;

                    while ((place = current.find(delimeterPlus)) != string::npos
                        || (place = current.find(delimeterEqualSign)) != string::npos)
                    {
                        token = current.substr(0, place);
                        newvector.push_back(token);
                        current.erase(0, place + delimeterPlus.length());
                    }
                    newvector.push_back(current);

                    vector1.erase(vector1.begin());
                    for (int i = 0; i < newvector.size() - 1; i++)
                    {
                        vector1.insert(vector1.begin(), newvector[i]);
                    }
                    for (string s : vector1)
                    {
                        cout << s << endl;
                    }
                    break;
                }
            }
        }
    }

    cout << "Fire: " << fCounter << endl;
    cout << "Water: " << wCounter << endl;
    cout << "Earth: " << eCounter << endl;
    cout << "Air: " << aCounter << endl;

    basicElements[0] = fCounter;
    basicElements[1] = wCounter;
    basicElements[2] = eCounter;
    basicElements[3] = aCounter;
}

void AlchemicalBook::push(Formula f)
{
	this->arrayOfFormulas.push_back(f);
}

void AlchemicalBook::print()
{
	for (Formula f : this->arrayOfFormulas)
	{
		cout << f << endl;
	}
}

int AlchemicalBook::getFireAmount()
{
    return basicElements[0];
}

int AlchemicalBook::getWaterAmount()
{
    return basicElements[1];
}

int AlchemicalBook::getEarthAmount()
{
    return basicElements[2];
}

int AlchemicalBook::getAirAmount()
{
    return basicElements[3];
}


