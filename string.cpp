#include <iostream>
#include <cstring>
#include <cassert>

class String
{
    public:
    char str[255];
    //char *str;
    int strLen = 0; 

    void init (const char *value)
    {
        strcpy (this->str, value);
    }

    void init (char c)
    {
        str[0] = c;
        str[1] = 0;
    }

    String (const char *s)
    {
        init (s);
    }

    String ()
    {
        init ("");
    }

    String (char c)
    {
        init (c);
    }

    String operator + (String other)
    {
        assert (strlen(this->str) + strlen(other.str) <= 255);
        String result;
        result.init (this->str);
        strcat (result.str, other.str);
        return result;
    }  

    //s + c
    String operator + (char c)
    { 
        assert (strlen (str) < 254);
        String result;
        result.init (this->str);
        size_t len = strlen(result.str);
        result.str[len] = c;
        result.str[len + 1] = 0;   
        return result;
    }

    String operator += (String s)
    {
        assert (this->length() + s.length() < 255);
        strcat (this->str, s.str);
        return *this;
    }

    String operator += (char c)
    {
        assert (strlen (this->str) < 254);
        size_t len = strlen(this->str);
        this->str[len] = c;
        this->str[len + 1] = 0;   
        return *this;
    }

    bool operator < (String other)
    {
        return strcmp (this->str, other.str) < 0;
    }

    bool operator > (String &other)
    {
        return strcmp(this->str, other.str) > 0;
    }

    bool operator <= (const String &other)
    {
        return strcmp(this->str, other.str) <= 0;
    }

    bool operator >= (const String &other)
    {
        return strcmp(this->str, other.str) >= 0;
    }

    bool operator != (String other)
    {
        return strcmp(this->str, other.str) != 0;
    }

    bool operator == (String other)
    {
        return strcmp (this->str, other.str) == 0;
    }

    void assign (String other)
    {
        strcpy (this->str,other.str);
    }

    size_t length ()
    {  
        return strlen (this->str);
    }

    void print ()
    {
        std::cout << "\"" << this->str << "\"" << std::endl;
    }

    char operator [] (size_t i)
    {
        return str[i];
    }

    String slice(int start, int end) 
    {
        String res;

        int len = end - start + 1;
        int i = start, resultIndex = 0;
        char* result = new char[len];

        while (i <= end)
        {
            result[resultIndex] = this->str[i];
            resultIndex++, i++;
        }

        result[len] = '\0';

        res.length = len;
        res.str = result;

        return res;
    }

    void replacement(char *source, const char *newWord)
    {
        for (int i = 0; *(newWord + i); i++)
        {
            *(source + i) = *(newWord + i);
        }
    }

    String operator + (char c, String s)
    {
        String result (c);
        result += s;
        return result;
    }

    String toString (unsigned int x)
    {
        String result;
        result.init("");
        if (x < 9)
        {
            result += ('0' + x);
        } 
        else 
        {
            while (x > 0)
            {
                //result = operator+ ('0' + x % 10,result);
                result = ('0' + x % 10) + result; //най-дясна цифра
                x /= 10;
            }
        }
        return result;
    }

    String reverse (String s)
    {
        String result;
        result.init ("");

        for (int i = s.length() - 1; i >= 0; i--)
        {
            result = result + s[i];
        }
        return result;
    }

    String toUpper (String s)
    {
        String result;
        result.init ("");

        for (size_t i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                result += (s[i] + ('A'-'a'));
            } 
            else 
            {
                result += s[i];
            }
        }
        return result;
    }

    String concat(String s)
    {
        String result;
        result.init ("");

        for (size_t i = 0; i < s.length(); i++)
        {
            result += s[i];
        }
        return result;
    }
};

std::ostream& operator << (std::ostream& out, String s)
{
   out << s.str; 
   return out;
}

int main ()
{

    String s1 ("Hello"), s2 (" world!"), s4 ('c');

    String s3 (s1);



    

};