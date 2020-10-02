#include <iostream>
#include <cstring>
#include <cassert>

class Word
{
    char word[20];

    public:
    Word ()
    {
        init ("");
    }

    Word (const char c)
    {
        init (c);
    }

    Word (const char *s)
    {
        init (s);
    }

    void init (const char *value)
    {
        strcpy (this->word, value);
    }

    void init (char c)
    {
        word[0] = c;
        word[1] = 0;
    }

    Word operator [] (int i)
    {
        return word[i];
    }

    Word operator + (char c)
    {
        assert (strlen (word) < 20);
        Word result;
        result.init (this->word);
        size_t len = strlen(result.word);
        result.word[len] = c;
        result.word[len + 1] = 0;   
        return result; 
    }

    Word operator += (char c)
    {
        assert (strlen (this->word) < 20);
        size_t len = strlen(this->word);
        this->word[len] = c;
        this->word[len + 1] = 0;   
        return *this;
    }

    bool operator < (Word other)
    {
        return strcmp (this->word, other.word) < 0;
    }

    bool operator == (Word other)
    {
        return strcmp (this->word, other.word) == 0;
    }

    void print()
    {
        std::cout << this->word << std::endl;
    }

    ~Word()
    {
        delete[] this->word;
    }
};

int main()
{
    Word w1("");
    Word w2("life");

    w2[2].print();

    (w1 + 'a').print();
    (w1 += 'b').print();

    //cout << w1 < w2;
    //cout << w1 == w2;

    return 0;
}