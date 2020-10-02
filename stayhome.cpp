#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
using namespace std;
int _ID = 1;

class Challenge
{
    char name[32];
    unsigned short numberOfRaters;
    unsigned short numberOfChallenges;
    float sumRate;
public:
    Challenge(const char* _name = "")
    {
        this->numberOfRaters = 0;
        this->sumRate = 0.00;
        this->numberOfChallenges = 1;
        
        strcpy(this->name, _name);
    }

    const char* getName() const
    {
        return this->name;
    }
    void increaseChallenges()
    {
        this->numberOfChallenges++;
    }
    int getNumberOfChallenges()
    {
        return this->numberOfChallenges;
    }

    void ChangeRating(double newRating)
    {
        this->numberOfRaters++;
        sumRate+= newRating;
    }
    void print()
    {
        cout<<this->name<<endl;
        if(numberOfChallenges < 2)
        {
            cout<<"new"<<endl;
        }
        else if(numberOfChallenges > 2 && numberOfChallenges < 10)
        {
            cout <<"quite recently" << endl;
        }
        else
        {
            cout<<"old"<<endl;
        }
        
        cout<<(double)sumRate/numberOfRaters;
    }
};

class arrOfChallenges
{
    Challenge* challenges;
    int size;
    int capacity;

    public:
    arrOfChallenges()
    {
        capacity = 4;
        size = 0;
        challenges = new Challenge[capacity];
    }
    arrOfChallenges(const arrOfChallenges& other)
    {
        if(this != &other)
        {
            this->capacity = other.capacity;
            this->size = other.size;
            this->challenges = new Challenge[capacity];

            for (int i = 0; i < size; i++)
            {
                this->challenges[i] = other.challenges[i];
            }
            
        }
    }
    const arrOfChallenges& operator= (const arrOfChallenges& other)
    {
        if(this != &other)
        {
            delete[] this->challenges;
            this->capacity = other.capacity;
            this->size = other.size;
            this->challenges = new Challenge[capacity];

            for (int i = 0; i < size; i++)
            {
                this->challenges[i] = other.challenges[i];
            }
            
        }
        return *this;
    }
    ~arrOfChallenges()
    {
        delete[] challenges;
    }

    bool contains(const char* challengeName)
    {
        for (int i = 0; i < size; i++)
        {
            if (strcmp(challenges[i].getName(), challengeName) == 0)
            {
                return true;
            }
            
        }
        return false;
        
    }
    void add(const char* challengeName)
    {
        if(this->contains(challengeName))
        {
            for (int i = 0; i < size; i++)
            {
                if (strcmp(challenges[i].getName(), challengeName) == 0)
                {
                    challenges[i].increaseChallenges();
                    
                }
            }
        }
        else
        {
            
            if(size == capacity)
            {
                capacity *= 2;
                Challenge* buffer = new Challenge[capacity];

                for (size_t i = 0; i < size; i++)
                {
                    buffer[i] = challenges[i];
                }

                delete[] challenges;
                challenges = buffer;
                
            }

            Challenge newChallenge(challengeName);
            challenges[size] = newChallenge;
            
            size++;
        }
        return;
    }

    void remove(const char* challengeName)
    {
        if(this->contains(challengeName))
        {
            int index = 0;
            Challenge* buffer = new Challenge[capacity];
            for (int i = 0; i < size; i++)
            {
                if(strcmp(challenges[i].getName(), challengeName) == 0)
                {
                    continue;
                }
                else
                {
                    buffer[index] = challenges[i];
                    index++;
                }

            }

            delete[] this->challenges;
            this->challenges = buffer;
            this->size--;
        }
        else
        {
            cout << "wrong challenge"<<endl;
        }
        
        
    }

    Challenge& getByName(const char* challengeName)
    {
        for (int i = 0; i < size; i++)
        {
            if(strcmp(challenges[i].getName(), challengeName) == 0)
            {
                return challenges[i];
            }
        }
        
    }
    void print()
    {
        for (size_t i = 0; i < size; i++)
        {
            challenges[i].print();
        }
        
    }

    const int getSize()
    {
        return this->size;
    }

    Challenge& operator [] (int i)
    {
        return this->challenges[i];
    }

    
};

class User
{
    char* name;
    char email[100];
    int years;
    int ID;
    arrOfChallenges unfinishedChals;

    public:
    User(const char* _name = "", const int _years = 0,const char* _email = "Unknown")
    {
        if(_name != nullptr)
        {
            name = new char[strlen(_name) + 1];
            strcpy(name, _name);
        }
            
        else
        {
            name = new char[1];
            strcpy(name, "");
        }

        this->years = _years;
        strcpy(email, _email);
        ID = _ID;
        _ID++;
    }
    

    User(const User& other)
    {
        if (this != &other)
        {
            this->name = new char[strlen(other.name) + 1];

            strcpy(this->name, other.name);
            strcpy(this->email, other.email);
            this->years = other.years;
            
            ID = _ID;
            unfinishedChals = other.unfinishedChals;
            _ID++;
            
        }
    }

    User& operator = (const User& other)
    {
        if (this != &other)
        {
            delete[] this->name;

            this->name = new char[strlen(other.name) + 1];

            strcpy(this->name, other.name);
            strcpy(this->email, other.email);
            this->years = other.years;
            unfinishedChals = other.unfinishedChals;

        }
        
        return *this; 
    }

    ~User()
    {
        delete[] name;
    }

    const char* getName() const
    {
        return this->name;
    }

    void print()
    {
        cout << this->ID << endl;
        cout<<name<<endl;
            if(years > 0 && years < 90)
            {
                cout<<years<<endl;
            }
            else
            {
                cout<<"Unknown"<<endl;
            }
            cout<<email<<endl;
        for (int i = 0; i < unfinishedChals.getSize(); i++)
        {
            unfinishedChals[i].print();
        }
        
    }
    const char* getEmail()const
    {
        return this->email;
    }

    void addUnfinishedChallenge(const char* challengeTag)
    {
        if(!this->unfinishedChals.contains(challengeTag))
        {
            this->unfinishedChals.add(challengeTag);
        }
        return;
        
    }

    void removeChallenge(const char* challengeName)
    {
        this->unfinishedChals.remove(challengeName);
    }

    int getId()
    {
        return this->ID;
    }
};

class allUsers
{
    User* users;
    int size;
    int capacity;

    public:
    allUsers()
    {
        capacity = 4;
        size = 0;
        users = new User[capacity];
    }
    allUsers(const allUsers& other)
    {
        if(this != &other)
        {
            this->capacity = other.capacity;
            this->size = other.size;
            this->users = new User[capacity];

            for (int i = 0; i < size; i++)
            {
                this->users[i] = other.users[i];
            }
            
        }
    }
    const allUsers& operator= (const allUsers& other)
    {
        if(this != &other)
        {
            delete[] this->users;
            this->capacity = other.capacity;
            this->size = other.size;
            this->users = new User[capacity];

            for (int i = 0; i < size; i++)
            {
                this->users[i] = other.users[i];
            }
            
        }
        return *this;
    }
    ~allUsers()
    {
        delete[] users;
    }

    User& operator [] (int i)
    {
        return this->users[i];
    }

    const int getSize() const
    {
        return this->size;
    }

    void add(const char* userInfo)
    {
        
        if(size == capacity)
        {
            capacity *= 2;
            User* buffer = new User[capacity];

            for (size_t i = 0; i < size; i++)
            {
                buffer[i] = users[i];
            }

            delete[] users;
            users = buffer;
            
        }

        char*_userInfo = nullptr;
        _userInfo = new char[strlen(userInfo) + 1];

        strcpy(_userInfo, userInfo);

        char* userName =  nullptr;
        char* userYears =  nullptr;
        char* userEmail =  nullptr;
        int years = -1;

        char* tok;
        tok = strtok(_userInfo, " ");
        if(tok != nullptr)
        {
            userName = new char[strlen(tok) + 1];
            strcpy(userName, tok);
        }

        tok = strtok(NULL, " ");

        if(tok != NULL)
        {
            userYears = new char[strlen(tok) + 1];
            strcpy(userYears, tok);

            
            if(strlen(userYears) == 1)
            {
                if(userYears[0] >= '0' && userYears[0] <= '9')
                    years = userYears[0] - '0';
            }
                
            else if(strlen(userYears) == 2)
            {
                if(userYears[0] >= '0' && userYears[0] <= '9')
                {
                    years = (userYears[0] - '0')*10;
                    if(userYears[1] >= '0' && userYears[1] <= '9')
                    {
                         years += userYears[1] - '0';
                    }
                }           
            }
            else
            {
                userEmail = new char[strlen(tok) + 1];
                strcpy(userEmail, tok);
            }
            
        }
        

        tok = strtok(NULL, " ");
        
        if(tok != NULL)
        {
            userEmail = new char[strlen(tok) + 1];
            strcpy(userEmail, tok);
        }
        
        if(userName != nullptr)
        {  

            if(userEmail != nullptr && (years > -1 && years < 90))
            {
                User newUser(userName, years, userEmail);
                users[size] = newUser;
            }
            else if(userEmail != nullptr)
            {
                
                User newUser(userName, -1, userEmail);
                users[size] = newUser;
            }
            else if(userEmail == nullptr && (years > -1 && years < 90))
            {
                User newUser(userName, years);
                users[size] = newUser;
            }
            else
            {
                User newUser(userName);
                users[size] = newUser;
            }
            size++;
        }

        if(_userInfo != nullptr)
            delete[]userInfo;

        if(userName != nullptr)
            delete[] userName;
        if(userYears != nullptr)
            delete[] userYears;
        if(userEmail != nullptr)
            delete[] userEmail;
    }

    void print()
    {
        for (size_t i = 0; i < size; i++)
        {
            users[i].print();
            
        }
        
    }

    bool contains(const char* name)
    {
        for (int i = 0; i < size; i++)
        {
            if(strcmp(users[i].getName(), name) == 0)
            {
                return true;
            }
        }
        return false;
    }

};

bool isChallenge(const char* command)
{
    char arr[20] = "challenge ";
    for(int i = 0; i < strlen("challenge "); i++)
    {
        if(command[i] != arr[i])
        {
            return false;
        }
    }
    return true;
}

bool isFinish(const char* command)
{
    char arr[10] = "finish ";
    for(int i = 0; i < strlen("finish "); i++)
    {
        if(command[i] != arr[i])
        {
            return false;
        }
    }
    return true;
}

bool isProfileInfo(const char* command)
{
    char arr[20] = "profile_info ";
    for(int i = 0; i < strlen("profile_info "); i++)
    {
        if(command[i] != arr[i])
        {
            return false;
        }
    }
    return true;
}

bool isListBy(const char* command)
{
    char arr[20] = "list_by ";
    for(int i = 0; i < strlen("list_by "); i++)
    {
        if(command[i] != arr[i])
        {
            return false;
        }
    }
    return true;
}

bool isLoad(const char* command)
{
    char arr[20] = "load ";
    for(int i = 0; i < strlen("load "); i++)
    {
        if(command[i] != arr[i])
        {
            return false;
        }
    }
    return true;
}

bool isRegistration(const char* command)
{
    char arr[20] = "registration ";
    for(int i = 0; i < strlen("registration "); i++)
    {
        if(command[i] != arr[i])
        {
            return false;
        }
    }
    return true;
}

class handleFunctions
{

    allUsers allUsers; 
    arrOfChallenges allChallenges;
    public:
    void handleCommand(const char* command)
    {
        char * _command = new char[strlen(command) + 1];
        strcpy(_command, command);

        if(isRegistration(_command))
        {
            registration(_command + 13);
        }
        else if(isChallenge(_command))
        {
            challenge(_command + 10);
        }
        else if(isFinish(_command))
        {
            finish(_command + 7);
        }
        else if(isProfileInfo(_command))
        {
            profileInfo(_command + 13);
        }
        else if(isListBy(_command))
        {
            listBy(_command + 8);
        }
        else if(isLoad(_command))
        {
            load(_command + 5);
        }  
        else
        {
            cout<<"Invalid command!"<<endl;
        }

        if(_command != nullptr)
            delete[] _command;
         
    }

    void registration(const char* userInfo)
    {
        allUsers.add(userInfo);
    }

    void challenge(const char* challengeInfo)
    {
        char* tokArray = new char[strlen(challengeInfo) + 1];
        strcpy(tokArray, challengeInfo);
        
        char* tok;
        tok = strtok(tokArray, " ");
        char* challengerName = nullptr;
        char* challengeTag = nullptr;

        if (tok != NULL)
        {
            challengerName = new char[strlen(tok) + 1];
            strcpy(challengerName, tok);
        }
        
        if(challengerName != nullptr)
        {
            if(allUsers.contains(challengerName))
            {
                tok = strtok(NULL, " ");
    
                if(tok != NULL)
                {
                    challengeTag = new char[strlen(tok) + 1];
                    strcpy(challengeTag, tok);
                }
                

                if(challengeTag != nullptr)
                {
                    if(challengeTag[0] != '#' && (strlen(challengeTag) < 2 || strlen(challengeTag) > 31))
                    {
                        cout<<"Challenge must start with # and be 31 symbols long!";
                        return;
                    }
                    else
                    {
                        tok = strtok(NULL, " ");
                        if(tok != NULL)
                        {
                            
                            while(tok != NULL)
                            {
                                
                                if (!allUsers.contains(tok))
                                {
                                    
                                    cout<<tok << " is not a registered user. Try challenging some registered users."<<endl;
                                    if(challengerName != nullptr)
                                        delete[] challengerName;
                                    if(challengeTag != nullptr)
                                        delete[] challengeTag;
                                    return;
                                }
                                tok = strtok(NULL, " ");
                            }
                            
                            delete[] tokArray;
                            tokArray = new char[strlen(challengeInfo) + 1];
                            strcpy(tokArray, challengeInfo);
                            
                            tok = strtok(tokArray, " ");

                            tok = strtok(NULL, " ");
                            tok = strtok(NULL, " ");
                            
                            while(tok != NULL)
                            {
                                
                                for(int i = 0; i < allUsers.getSize(); i++)
                                {
                                    
                                    if(strcmp(allUsers[i].getName(), tok) == 0)
                                    {
                                        
                                        allUsers[i].addUnfinishedChallenge(challengeTag);
                                    }
                                }
                                
                                tok = strtok(NULL, " ");
                            }

                            allChallenges.add(challengeTag);
                        }
                        else
                        {
                            cout<<"You haven't specified who you want to challenge! Try again."<<endl;
                            return;
                        }
                        
                        
                    }
                }
            }
            else
            {
                cout << "No in";
                return;
            }
        }

        if(challengerName != nullptr)
            delete[] challengerName;
        if(challengeTag != nullptr)
            delete[] challengeTag;
    }

    void finish(const char* finishInfo)
    {
        char * infoToChar = nullptr;
        infoToChar = new char[strlen(finishInfo) + 1];
        strcpy(infoToChar, finishInfo);

        char* tok = strtok(infoToChar, " ");
        char* tag = nullptr;
        char* userId = nullptr;
        char* rateToChar = nullptr;
        double rate;
        int userID;

        if (tok != NULL)
        {
            tag = new char[strlen(tok) + 1];
            strcpy(tag, tok);
        }
        

        tok = strtok(NULL, " ");
        if (tok != NULL)
        {
            userId = new char[strlen(tok) + 1];
            strcpy(userId, tok); 

            int length = strlen(userId);
            
            for (int i = 0; i < length; i++)
            {
                if(userId[i] < '0' || userId[i] > '9')
                {
                    cout<<"No such ID"<<endl;
                    if(userId != nullptr)
                        delete[] userId;
                    if(rateToChar != nullptr)
                        delete[] rateToChar;
                    if(tag != nullptr)
                        delete[] tag;
                    if(infoToChar != nullptr)
                        delete[] infoToChar;

                    return; 
                }
                int currentDigit = userId[i]-'0';
                userID +=currentDigit*pow(10,length - i);
            }


            tok = strtok(NULL, " ");
            if (tok != NULL)
            {
                rateToChar = new char[strlen(tok) + 1];
                strcpy(rateToChar, tok);


                rate = strtod(rateToChar, NULL);
                if (rate > -5.0 && rate < 10.0)
                {
                    for(int i = 0; i < allUsers.getSize(); i++)
                    {
                        if(allUsers[i].getId()  == userID)
                        {
                            allUsers[i].removeChallenge(tag);
                        }
                    }
                    
                    for(int i = 0; i < allChallenges.getSize(); i++)
                    {
                        if(strcmp(allChallenges[i].getName(), tag) == 0)
                        {
                            allChallenges[i].ChangeRating(rate);
                        }
                    }
                }
                else
                {
                    cout << "Rate mustbe betwen -5.0 and 10.0.";   
                }
            }
        }  
        
        if(userId != nullptr)
            delete[] userId;
        if(rateToChar != nullptr)
            delete[] rateToChar;
        if(tag != nullptr)
            delete[] tag;
        if(infoToChar != nullptr)
            delete[] infoToChar;

    }

    void profileInfo(const char* name)
    {
        if (allUsers.contains(name))
        {
            for (size_t i = 0; i < allUsers.getSize(); i++)
            {
                if(strcmp(allUsers[i].getName(), name) == 0)
                {
                    allUsers[i].print();             
                }
                
            }
        }
        else
        {
            cout << "No such user!";
        }
    }

    void listBy(const char* listInfo)
    {
        int size = allChallenges.getSize();

        if(strcmp(listInfo, "newest") == 0)
        {   
            
            for (int i = size - 1; i >= 0; i--)
            {
                allChallenges[i].print();
            }
            
        }
        else if(strcmp(listInfo, "oldest") == 0)
        {
            for (int i = 0; i < size; i++)
            {
                allChallenges[i].print();
            }
        }
        else if(strcmp(listInfo, "most_popular") == 0)
        {
            for (int i = 0; i < size; i++)
            {
                Challenge currentPopular = allChallenges[i];
                for (int j = i+1; j < size; j++)
                {
                    if (allChallenges[j].getNumberOfChallenges() > allChallenges[i].getNumberOfChallenges())
                    {
                        currentPopular = allChallenges[j];
                    }
                    
                }
                currentPopular.print();
                
            }
            
        }
        else
        {
            cout << "Invalid command!";
        }
        
    }

    void load(const char* fileInfo)
    {
        fstream file;

        char * fileToChar = nullptr;
        fileToChar = new char[strlen(fileInfo) + 1];
        strcpy(fileToChar, fileInfo);

        char* tok = strtok(fileToChar, ".");
        char* ext = nullptr;
        char* fileN = nullptr;

        if (tok != NULL)
        {
            fileN = new char[strlen(tok) + 1];
            strcpy(fileN, tok);
        }

        tok = strtok(NULL, " ");

        if (tok != NULL)
        {
            ext = new char[strlen(tok) + 1];
            strcpy(ext, tok);
        }
        if(strcmp(fileN, "users" )!= 0)
        {
            cout<<"Wrong file name!"<<endl;
            return;
        }

        if (strcmp(ext, "txt") == 0)
        {
            file.open("users.txt");

            char c;
            while(!file.eof())
            {
                
                char *userInfo = new char[8];
                int allocated = 8;
                int index = 0;
                while (file.get(c))
                {
                    if( '\n' == c  ||  '\r' == c ) 
                    {
                        break;
                    }
                    else
                    {
                        if(index == allocated)
                        {
                            allocated *= 2;
                            char* buffer = new char[allocated];

                            for (int i = 0; i < index; i++)
                            {
                                buffer[i] = userInfo[i];
                            }
                            delete[] userInfo;
                            userInfo = buffer;
                            
                        }
                        userInfo[index] = c;
                        index++;
                    }
                    
                    
                }

                userInfo[index] = '\0';

                cout << userInfo << endl;
                allUsers.add(userInfo);

                delete[] userInfo;
            }
            file.close();
        }
        else if (strcmp(ext, "bin") == 0)
        {

            // StringLength = 0;
            // Name = "NoName";

            // ifstream iFile("challenges.bin", ios::binary|ios::in);
            // if(!iFile.is_open())
            // {
            //     cout << "Failed" << endl;
            // }
            // else
            // {
            //     iFile.read((char *)&StringLength, sizeof(unsigned short int));
            //     iFile.read((char *)&Name, StringLength);
            // }

            // cout << StringLength << " " << Name << endl;
  
            //file.open("challenges.bin");

            /* FOR BINARY FILES
            streampos size;
            char * memblock;

            ifstream file ("example.bin", ios::in|ios::binary|ios::ate);
            if (file.is_open())
            {
                size = file.tellg();
                memblock = new char [size];
                file.seekg (0, ios::beg);
                file.read (memblock, size);
                file.close();

                cout << "the entire file content is in memory";

                delete[] memblock;
            }
            else cout << "Unable to open file";
            */

           /*const unsigned long long size = 8ULL*1024ULL*1024ULL;
            unsigned long long a[size];

            FILE* stream = fopen("file.binary", "wb");
            for (unsigned long long j = 0; j < 1024; ++j)
            {
                fwrite(a, 1, size* sizeof(unsigned long long), stream);
            }
            fclose(stream);*/
        }
        else
        {
            cout << "Wrong ext" << endl;
        }

    }
};

int main()
{
    
    handleFunctions handler;
    

    char c;
    while (true)
    {
        char *command = new char[8];
        int allocated = 8;
        int index = 0;

        while (cin.get(c))
        {
            if( '\n' == c  ||  '\r' == c ) 
            {
                break;
            }
            else
            {
                if(index == allocated)
                {
                    allocated *= 2;
                    char* buffer = new char[allocated];

                    for (int i = 0; i < index; i++)
                    {
                        buffer[i] = command[i];
                    }
                    delete[] command;
                    command = buffer;
                    
                }
                command[index] = c;
                index++;
            }
            
            
        }

        command[index] = '\0';

        handler.handleCommand(command);
        delete[] command;
    }

    return 0;
}
