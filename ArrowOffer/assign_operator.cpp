#include <iostream>
#include <string.h>
using namespace std;


class CMyString {
public:
    CMyString(char* p_data=NULL);
    CMyString(const CMyString& other);
    CMyString& operator=(const CMyString& rhs);
    ~CMyString();
    void Print();
private:
    char* p_data_;
};

CMyString::CMyString(char *p_data) {
    if (p_data == NULL) {
        p_data_ = NULL;
    } else {
        int len = strlen(p_data);
        p_data_ = new char[len+1];
        strcpy(p_data_, p_data);
    }
}

CMyString::CMyString(const CMyString& other){
    if (other.p_data_ == NULL) {
        p_data_ = NULL;
    } else {
        int len = strlen(other.p_data_);
        p_data_ = new char[len + 1];
        strcpy(p_data_, other.p_data_);
    }
}

CMyString& CMyString::operator=(const CMyString &rhs) {
    if (this != &rhs) {
        CMyString str_temp(rhs);
        char* p_data_temp = str_temp.p_data_;
        str_temp.p_data_ = p_data_;
        p_data_ = p_data_temp;
    }
    return *this;
}

CMyString::~CMyString()
{
    if(p_data_ != NULL)
    {
        delete []p_data_;
        p_data_ = NULL;
    }
}

void CMyString::Print() {
    cout << p_data_ << endl;
}

int main(){
    char* p_data = "Hello World!";
    CMyString str_a(p_data);

    CMyString str_b("C++");
    CMyString str_c("Java");
    str_b = str_a = str_c;
    str_b.Print();
    str_a.Print();
    return 0;
}
