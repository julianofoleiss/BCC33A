typedef struct T_NOH {
    int dado;
    struct T_NOH* prox;
} T_NOH;

typedef struct T_LINT {
    struct T_NOH* primeiro;
    struct T_NOH* ultimo;
    int tamanho;
} T_LINT;

T_NOH* NOH_criar(int dado);
int NOH_get_dado(T_NOH* E);
void NOH_set_dado(T_NOH* E, int dado);

T_LINT* LINT_criar();
void LINT_inserir(T_LINT *L, int dado);
T_NOH* LINT_remover(T_LINT *L, int dado);
void LINT_destruir(T_LINT *L);
T_NOH* LINT_buscar(T_LINT* L, int dado);
int LINT_vazia(T_LINT *L);
