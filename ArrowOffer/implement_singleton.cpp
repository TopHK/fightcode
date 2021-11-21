#include <iostream>
using namespace std;

template <typename T>
class Singleton {
public:
    T& GetInstance() {
        if (instance == NULL) {
            Lock lock;
            if (instance == NULL) {
                instance = new T();
                atexit(Destroy);
            }
        }
        return *T;
    }
protected:
    Singleton() {}
    ~Singleton() {}
private:
    Singleton(const Singleton& rhs) {}
    Singleton& operator=(const Singleton& rhs) {}
    void Destroy() {
        if (instance != NULL) {
            delete instance;
            instance = NULL;
        }
    }

    static T* volatile instance;
};

