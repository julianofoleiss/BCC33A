typedef struct {
    int dado;
    struct T_NOH* prox;
} T_NOH;

typedef struct {
    struct T_NOH* primeiro;
    struct T_NOH* ultimo;
} T_LINT;

T_NOH* T_NOH_criar(int dado);
int T_NOH_get_dado(T_NOH* E);
void T_NOH_set_dado(T_NOH* E);

T_LINT* LINT_criar();
void LINT_inserir(T_LINT *L, int dado);
T_NOH* LINT_remover(T_LINT *L, int dado);
void LINT_destruir(T_LINT *L);
T_NOH* LINT_buscar(T_LINT* L, int dado);
