typedef struct Client cli;
struct Datnas{
	int dia; 
	int mes;
	int ano;
};
void Cadnome(char* clinome);
void Cadcpf(char* clicpf);
char Cadgen();
struct Datnas caddatnas();
int validnome(char* nome);
int validcpf(char* cpf);
int validgen(char gen);
int validnas(struct Datnas nasdate);
