#include <iostream>
#include <cstring>
using namespace std;

class Dictionary
{
    char word[100];
    char meaning[500];

    public:
    Dictionary()
    {
        word = nullptr;
        meaning = nullptr;
    }

    Dictionary(const char *_word, const char *_meaning)
    {
        int l = strlen(word);
        word = new char[l + 1];
        strcpy(word, _word);
        int l2 = strlen(meaning);
        meaning = new char[l2 + 1];
        strcpy(meaning, _meaning);
    }

    Dictionary operator + (const Dictionary &other)
    {
        if (strcat(this.meaning, other.meaning) > 500)
        {
            strncat(this.meaning, other.meaning, 500);
        }
        else
        {
            strcat(this.meaning, other.meaning);
        }
    }

    Dictionary(const Dictionary &other)
    {
        int l = strlen(word);
        word = new char[l + 1];
        strcpy(word, other.word);
        int l2 = strlen(meaning);
        meaning = new char[l2 + 1];
        strcpy(meaning, other.meaning);
    }

    ~Dictionary()
    {
        delete[] word;
        word = nullptr;
    }

    void showWords(Dictionary data, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << data[i].word << " means: " << data[i].meaning << endl;
        }
    }

    char *findMeaning()
    {
        return this.meaning;
    }

    void sort(Dictionary d, int size)
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < size - i; i++)
            {
                if (cmp(d[j], d[j + 1]))
                {
                    Dictionary helper = d[j];
                    d[j] = d[j + 1];
                    d[j + 1] = helper;   
                }
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;

    Dictionary* d = new Dictionary[n];

    return 0;
}