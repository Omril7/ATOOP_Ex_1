//
// Created by Omri Leizerovitch on 04/03/2022.
//

#ifndef EXERCISE_1_STRING_H
#define EXERCISE_1_STRING_H

#include <cstring>
#include <iostream>

class String {
public:
    String(const char *val=""); // conversion c'tor
    String(const String&);      // copy c'tor
    ~String();                  // d'tor
    String& operator= (const String&);
    int size() const {return strlen(value->data);}
    char* getData() { return value->data;}
    int count() const {return value->refCount;}
    const char& operator[](int i) const;
    char& operator[](int i);    // copy on write
    friend std::ostream& operator<<(std::ostream& os, const String& s);
private:
    struct StringValue {
        int refCount;
        char* data;
        StringValue(const char *initValue);
        ~StringValue();
    };
    StringValue *value;
};
inline std::ostream& operator<<(std::ostream& os, const String& s) {
    for(int i=0; i < strlen(s.value->data); i++) {
        os << s.value->data[i] << " ";
    }
    return os;
}


#endif //EXERCISE_1_STRING_H
