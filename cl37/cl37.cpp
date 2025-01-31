#include <iostream>

using namespace std;

// Dependency Inversion principle

class AbstractLanguage { // SR
public:
    virtual void Start() = 0;
};

class InterpretedLanguage { // IS
public:
    virtual void Interpret() = 0;
};

class CompiledLanguage {
public:
    virtual void Compile() = 0;
};

class CPlusPlus : public AbstractLanguage, public CompiledLanguage { // O/C
public:
    void Start() override {
        cout << "C++ started." << endl;
    }

    void Compile() override {
        cout << "Started Compile Language." << endl;
    }
};

class Python : public AbstractLanguage, public InterpretedLanguage { // O/C
public:
    void Start() override {
        cout << "Python started." << endl;
    }

    void Interpret() override {
        cout << "Started Interpret Language." << endl;
    }
};

// За таким же принципом створити клас "Пайтон"

class StrictProgrammer {
    CompiledLanguage* compiled;
public:
    StrictProgrammer(CompiledLanguage* compiled) {
        this->compiled = compiled;
    }
    void printer() {
        compiled->Compile();
    }
};

class DynamicProgrammer {
    InterpretedLanguage* interpret;
public:
    DynamicProgrammer(InterpretedLanguage* interpret) {
        this->interpret = interpret;
    } 
    void printer() {
        interpret->Interpret();
    }
};

void ShowInfoAboutLanguage(AbstractLanguage* languge) {
    languge->Start();
}

int main() {
    AbstractLanguage* first = new CPlusPlus();
    CompiledLanguage* firstCompiled = new CPlusPlus();
    InterpretedLanguage* inter = new Python();

    ShowInfoAboutLanguage(first);
    firstCompiled->Compile();

    first = new Python();
    ShowInfoAboutLanguage(first);
    inter->Interpret();

}



