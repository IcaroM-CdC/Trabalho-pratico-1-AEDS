typedef struct professor tipo_professor;

struct professor {

    char *nome;
    char *curso;
    char *esp;  // Pos, doutorado ou mestrado
    char *CPF;

    unsigned int senha;
    unsigned int idade;
    unsigned int ID;

};

tipo_professor* cria_professor(char *nome, char *curso, char *esp, char *CPF, unsigned int idade, unsigned int senha, unsigned int ID);
