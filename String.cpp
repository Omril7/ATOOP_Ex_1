//
// Created by Omri Leizerovitch on 04/03/2022.
//

#include "String.h"

String::StringValue::StringValue(const char *initValue) : refCount(1) {
    data = new char[strlen(initValue)+1];
    strcpy(data, initValue);
}
String::StringValue::~StringValue() {
    delete[] data;
}

String::String(const char *initValue) : value(new StringValue(initValue)) {}
String::String(const String& rhs) : value(rhs.value) { // shallow copy
    ++value->refCount;
}
String::~String() {
    if(--value->refCount == 0) {
        delete value;
    }
}
String& String::operator=(const String & rhs) {
    if (value == rhs.value) {
        return *this;
    }
    if(--value->refCount ==0) {
        delete value;
    }
    value = rhs.value;
    ++value->refCount;

    return *this;
}
const char& String::operator[](int i) const {
    return value->data[i];
}
char& String::operator[](int i) {
    if(value->refCount > 1) {
        // the value is shared by other instances
        --value->refCount;
        value = new StringValue(value->data);
    }
    return value->data[i];
}