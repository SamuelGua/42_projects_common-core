#include <iostream>
#include <cstdlib>
#include <cstring>

class N {
    private:
        char buffer[100];
        int value;
    public:
    
        N(int val) {
            value = val;
        }

        virtual int operator+(N &other) {
            return this->value + other.value;
        }

        virtual int operator-(N &other) {
            return this->value - other.value;
        }

        void setAnnotation(char *param) {
            size_t len = strlen(param);
            memcpy(this->buffer, param, len);
        }

};



int main(int argc, char *argv[]) {
    if (argc < 2) {
        _exit(1);
    }

    N *a = new N(42);
    N *b = new N(15);

    a->setAnnotation(argv[1]); // Potentiel overflow ici

    int sum = *b + *a;
    int diff = *b - *a;

    std::cout << "b + a = " << sum << std::endl;
    std::cout << "b - a = " << diff << std::endl;

    delete a;
    delete b;

    return 0;
}
