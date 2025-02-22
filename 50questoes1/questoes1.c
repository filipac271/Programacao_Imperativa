#include <stdio.h>
#include <stdlib.h>

int Maior()
{
  int numero;
  int maior = 0;

  printf("insere uma sequencia termian em zero: \n");
  scanf("%d", &numero);

  while (numero != 0)
  {
    if (numero > maior)
    {
      maior = numero;
    }
    scanf("%d", &numero);
  }
  printf("O maior numero é %d\n", maior);
}

// 2
int media()
{
  int numero;
  int total = 0;
  int quantos = 0;

  printf("insere uma sequencia termian em zero: \n");
  scanf("%d", &numero);

  while (numero != 0)
  {
    total = total + numero;
    quantos++;

    scanf("%d", &numero);
  }

  printf("A media é %d \n", total / quantos);
}

// 3 nao gosto muito desta 1 if e 1 else if
int segundoMaior()
{
  int n = 1, max = 0, max2 = 0;
  while (n != 0)
  {
    scanf("%d", &n);
    if (n >= max)
    {             // se o n for maior que max entao passa para max
      max2 = max; // e o max passa a ser o 2 max
      max = n;
    }
    else if (n > max2 && n < max)
    {
      max2 = n;
    }
  }
  return max2;
}

// 4 tambem nao gosto muito mas o segredo esta no while
int bitsUm(unsigned int n)
{
  int i = 0;
  int r = 0;
  int acc = 0;

  while (n != 0)
  {
    r = n % 2; // atencao !!!
    n = n / 2; // atencao!!!!
    if (r == 1)
      acc++;
  }
  return acc;
}

// 5 horrivel
int trailingZ(unsigned int n)
{
  int i = 0;
  int r = 0;
  int acc = 0;
  int encontreium = 0;

  if (n == 0)
  {
    acc = 32;
  }

  while (n != 0 && encontreium == 0)
  {
    r = n % 2; // atencao !!!
    n = n / 2; // atencao!!!!
    if (r == 0)
      acc++;

    else
      encontreium = 1;
  }
  return acc;
}

// 6
int qDig(int n)
{
  int r = 0;

  if (n == 0)
  {
    return 1;
  }

  while (n != 0)
  {
    n = n / 10;
    r++;
  }

  return r;
}

// 7 funcionou
char *mystrcat(char s1[], char s2[])
{
  int i = strlen(s1);
  int tamanho = i + strlen(s2);
  int j = 0;

  for (i, j; i < tamanho; i++)
  {
    s1[i] = s2[j];
    j++;
  }
  s1[tamanho] = '\0'; // nao esquecer!!!
  return s1;
}

// 8 funcionou ehehe
char *strcpy(char *dest, char source[])
{
  int i = 0;
  int j = 0;

  for (i; source[i] != '\0'; i++)
  {
    dest[i] = source[i];
  }
  dest[i] = '\0';
  return dest;
}

// 9
int strcmp(char s1[], char s2[])
{
  int i = 0; // so é preciso i, nao te  metas a inventar

  for (i; s1[i] != '\0' && s2[i] != '\0'; i++)
  {

    if (s1[i] != s2[i])
    {
      return s1[i] - s2[i];
    }
  }
  return s1[i] - s2[i];
}

// 10 bleh rever

char *strstr(const char *s1, const char *s2)
{
  if (*s2 == '\0')
    return (char *)s1; // Se s2 estiver vazia, retorna s1

  while (*s1 != '\0')
  {
    const char *temp_s1 = s1;
    const char *temp_s2 = s2;

    while (*temp_s2 != '\0' && *temp_s1 == *temp_s2)
    {
      temp_s1++;
      temp_s2++;
    }

    if (*temp_s2 == '\0')
      return (char *)s1; // Se s2 foi encontrado em s1, retorna a posição de s1

    s1++; // Move para o próximo caractere em s1
  }

  return NULL; // Retorna NULL se s2 não for encontrado em s1
}

// 11
void strrev(char s[])
{
  int i = 0;
  int j = (strlen(s) - 1); // nao esquecer o menos um!!!!
  char temp;

  for (i, j; i < j; i++, j--)
  {
    temp = s[i]; //!!!!!!!
    s[i] = s[j];
    s[j] = temp;
  }
}

// 12
void strnoV(char t[])
{
  int i, pos;
  for (i = 0, pos = 0; t[i] != '\0'; i++)
  {
    if (t[i] != 'a' && t[i] != 'e' && t[i] != 'i' && t[i] != 'o' && t[i] != 'u' && t[i] != 'A' && t[i] != 'E' && t[i] != 'I' && t[i] != 'O' && t[i] != 'U')
    {
      t[pos++] = t[i]; // atencao a isto!!!!!
    }
  }
  t[pos] = '\0'; //!!!!!!!
}

// 13
void truncW(char t[], int n)
{
  int i = 0;
  int j = 0;
  int count = 0;
  while (t[i] != '\0')
  { // enquanto nao for \0
    if (!isspace(t[i]))
    { // se nao for espaco
      if (count < n)
      {              // se o count for menor que n
        t[j] = t[i]; // entao o tj passa a ser ti
        j++;         // passa para a proxima letra
      }
      count++; // o count acrescenta
    }
    else
    {             // se o count for maior
      count = 0;  // reiniciar o count
      t[j] = ' '; // passar para o proximo espaco
      j++;        // passar para o proximo
    }
    i++; // incremeneta o i
  }
  t[j] = '\0';
}

// 14
char charMaisfreq(char s[])
{
  int i = 0;
  int j = 0;
  int pos = 0;
  int freq = 0;
  int maisFreq = 0;

  for (i = 0; s[i] != '\0'; i++)
  {
    for (j = i; s[j] != '\0'; j++)
    { // precisa do segundo for
      if (s[i] == s[j])
      {
        freq++;
      }
    }
    if (freq > maisFreq)
    {
      maisFreq = freq;
      pos = i;
    }
    freq = 0; // por causa disto
  }
  return s[pos];
}

// 15

int iguaisConsecutivos(char s[])
{
  int consec = 1, max = 0;
  for (int i = 0; s[i]; i++)
  {
    if (s[i] == s[i + 1])
      consec++;
    else
    {
      if (consec > max) //!!!!!!
        max = consec;
      consec = 1;
    }
  }
  return max;
}

// 16
int difConsecutivos(char s[])
{
  int consec = 0, max = 0;
  for (int i = 0; s[i] != '\0'; i++)
  {
    if (s[i] != s[i + 1])
      consec++;
    else
    {
      if (consec > max)
        max = consec;
      consec = 1;
    }
  }
  return max;
}

// 16 estranho
int difConsecutivo1s(char s[])
{
  int i = 0;
  int count = 1;
  int maiorseq = 0;

  if (s[0] != '\0')
    maiorseq = 1;

  for (; s[i] && s[i + 1] != '\0'; i++)
  {

    if (s[i] != s[i + 1])
    { // se fosse para filtrar as letras é para usar isAlpha e depois count++
      count++;
    }
    else
    {
      if (count > maiorseq)
      {
        maiorseq = count;
      }
      count = 1;
      printf("Demos reset ao count %c \n", s[i]);
    }
  }
  return maiorseq;
}

// 17 3 fors!!!!!!!
int maiorPrefixo(char s1[], char s2[])
{
  int i = 0;
  int j = 0;
  int k = 0;

  for (i; s1[i] != '\0'; i++)
    ;
  for (j; s2[j] != '\0'; j++)
    ;
  for (k; s1[k] == s2[k] && k < i; k++)
    ;

  return k;
}

// 18 estranho nao gosto muitp
int maiorSufixo(char s1[], char s2[])
{
  int i, j, ans = -1;
  for (i = 0; s1[i]; i++)
    ;
  for (j = 0; s2[j]; j++)
    ;
  while (s1[i--] == s2[j--])
    ans++;
  return ans;
}

// 19 é preciso ter calma
int sufPref(char s1[], char s2[])
{
  int i = 0, j = 0, acc = 0;
  for (i; s1[i]; i++)
  {
    if (s1[i] == s2[j++])
    { // atencao ao j++
      acc++;
    }
    else
      acc = j = 0; //!!!!!!
  }
  return acc;
}

// 20
int contaPal(char s[])
{
  int word = 0, total = 0;
  for (int i = 0; s[i]; i++)
  {
    if (s[i] == ' ' || s[i] == '\n')
    {
      if (word)
        total++; // se estiver a zero entao vai aumentar o total
      word = 0;
    }
    else
      word = 1;
  }
  // apos o loop verificamos se a ultima palavra ainda nao foi cotnada
  // se nao tiver sido contamo la
  if (word)
    total++;
  return total;
}

// 21
int contaVogais(char s[])
{
  int i = 0, acc = 0;

  for (i; s[i] != '\0'; i++)
  {
    if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
    {
      acc++;
    }
  }
  return acc;
}

// 22
int contida(char a[], char b[])
{
  int i = 0, acc = 0, j = 0;
  for (i, j; a[i] != '\0' && b[j] != '\0'; j++)
  {
    if (a[i] == b[j])
    {
      acc++;
      i++;
    }
  }
}

//22
int contida(char s1[],char s2[]){
    int i,j;
    for(i=0;s1[i]!='\0';i++){
        for(j=0;s2[j]!='\0';j++){
            if(s1[i]==s2[j]){
                break;
            }
        }
        if(s2[j]=='\0'){
            return 0;
        }
    }
    return 1;
}

// 23
int palindroma(char s[])
{
  int i = 0, j = strlen(s) - 1; // -1 por causa do barra 0
  for (i, j; i < j; i++, j--)
    if (s[i] != s[j])
      return 0;
  return 1; // é mais facil ver se sao diferentes(!!!!!!)
}



//24 funfou à primeira !!!!!! festaaaaaa

int remRep (char x[]){
  int i = 0;
  int j = 0;
  for (i,j; x[i] != '\0'; i++){
    if (x[i] != x[i+1]){
      x[j++] = x[i];
    }
  }
  x[j] = '\0'; //!!!!!!!!!!
  return j;
}

//25 mais ao menos
int limpaEspacos(char t[]){
    int i, j;
    for(i = 0, j = 0; t[i] != '\0'; i++){
        if(t[i] != ' ' || (t[i] == ' ' && t[i+1] != ' ')){
        t[j] = t[i];
        j++;
        }
    }
    t[j] = '\0';
    return j;
}

//26 meio estranha mas até se entende
void insert(int v[],int N, int x){
  // iniciamos o array
    for(int i = 0; i < N; i++) {
      // verificamos que o x é menor que um vi
        if(v[i] > x) {
      // percorremos o array ao contrario até 
      //chegarmos à posicao onde vamos por o x
            for(int j = N; j > i; j--) {
                v[j] = v[j - 1];
            }
            // pomos o x nessa posiçao
            v[i] = x;
            break;
        }
        // se o x for maior que todos os aelementos do array
        if(i == N - 1) {
            v[N] = x;
        }
    }
}

// 27 nao gosto desta é meio estranha
void merge (int r [], int a[], int b[], int na, int nb){
  int i, j, k;
    i = j = 0;

    for(k = 0; i < na && j < nb; k++) {
        if (a[i] <= b[j]) {
            r[k] = a[i++];
        } else {
            r[k] = b[j++];
        }
    }

    for(; i < na; k++) {
        r[k] = a[i++];
    }

    for(; j < nb; k++) {
        r[k] = b[j++];
    }

}



//28 meio esquisito isto
int crescente (int a[], int i, int j){
  for(i; i < j; i++)
  if(a[i] > a[i+1]){ // atencao ao sinal!!!!!
    return 0;
  } 
  return 1;
}

//29 funcionou à primeira ehehe !!!!!
int retiraNeg (int v[], int N){
  int i = 0;
  int j = 0;
  for( i; i < N; i ++){
    if(v[i] > 0){
      v[j] = v[i];
      j++;
    }
  }
  return j;
}

//30 bastante estranha
int menosFreq (int v[], int N) {
    int freq = 1, minFreq = N, ans = v[0], i;
    for(i = 1; i < N; i++) { // o i começa a um porque comparamos cada variavel com a anterior
        if(v[i] == v[i - 1]) freq++; // se forem iguais aumenta a freq
        if(v[i] != v[i - 1]) { // se nao forem iguais
// compara a freq e a minFreq para ver qual é mais pequena
            if(freq < minFreq) {
                minFreq = freq;
                ans = v[i - 1]; // o i esta a apontar para o proximo elemento a ser
// processado pelo loop entao o i-1 é que é o elemento menos frequente
            }
            freq = 1; // reset a frequencia para um
        }
    } // verifica uma ultima vez tudo
    if(freq < minFreq) {
        minFreq = freq;
        ans = v[i - 1];
    }
    return ans;
}

//31 ficou meio estranha mas funciona
int maisFreq (int v[], int N){
  int i, freq = 1, maisfreq = 0, elemento = v[0];
  for(i = 0; i < N; i++){
    if(v[i] == v[i+1]) freq++;
    if(v[i] != v[i+1]){
      if(freq > maisfreq){
        maisfreq = freq;
        elemento = v[i]; // atencao aqui

      }
      freq = 1;
    }
  }
    if(freq > maisfreq){
        maisfreq = freq;
        elemento = v[i-1];
    }
    return elemento;
}


//32
int maxCresc (int v[], int N){
  int i, cresc = 1, maiscresc = 0;

  for(i = 0; i < N; i++){
    if(v[i] <= v[i+1]) cresc++; // atencao ao sinal!!!!
    if(v[i] > v[i+1]){
      if(cresc> maiscresc){
        maiscresc = cresc;
      
      }
      cresc  = 1;
    }
  }
    if(cresc > maiscresc){
      maiscresc = cresc;
    }
    return maiscresc;
}

//33 MEIO ESQUESITA, MAS da para entender, ver melhor depois
int elimRep(int v[],int n){
    int i,j,k;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
        if(v[i] == v[j]){
            for(k=j; k<n; k++){
            v[k] = v[k+1];
            }
            n--;
            j--;
        }
        }
    }
    return n;
}


//34
int elimRepOrd (int v[], int n){
    int i,j,k;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
        if(v[i] == v[j]){
            for(k=j; k<n; k++){
            v[k] = v[k+1];
            }
            n--;
            j--;
        }
        }
    }
    return n;
}

//35
int comunsOrd (int a[], int na, int b[], int nb) {
    int i = 0, j = 0, ans = 0;
    while(i < na && j < nb) {
        if(a[i] == b[j]) { // atencao !!!!
            ans++;
            i++;
            j++;
        }
        else if(a[i] > b[j]) j++;
        else i++;
    }
    return ans;
}


//36
int elem (int a[], int na, int x){
  int i;

  for(i = 0; i < na; i++){
    if(a[i] == x) return 1;
  }
  return 0;
}


int comuns (int a[], int na, int b[], int nb){
  int i, acc = 0;

  for(i = 0; i < na ; i++){
    if(elem(b, nb, a[i])){
      acc++;
    }
  }
  return acc;
}


//37 funcionou à primeira ehehehhe
int minInd (int v[], int n){
  int i = 0, min = v[0], acc = 0;
  for(i; i< n ; i++ ){
    if(v[i] < min){
      min = v[i];
      acc = i;
    }
  }
  return acc;
}


//38 
void somasAc (int v[], int Ac [], int N) {
    int i;
    int j;
    
    for(i = 0; i < N; i++) {
        Ac[i] = 0; //iniciar o ac!!
        for(j = 0; j <= i; j++) {
            Ac[i] += v[j];
        }
    }
}

//39 meio estranaha
int triSup (int N, float m [N][N]){
    int i,j;
    for(i=0; i < N; i++){
        for(j=0; j < N; j++){
        if(i > j && m[i][j] != 0){ // é mais facil ver se sao diferente
            return 0;
        }
        }
    }
    return 1;
}

//40 top
void transposta (int N, float m [N][N]){
  int i = 0, j;
  float temp;

  for(i; i < N; i++){
        for(j = 0; j < i; j++){
          if(i != j){
            temp =m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
          }
        }
  }
}


//41 
void addTo (int N, int M, int a [N][M], int b[N][M]){
  int i, j ;
  for (i = 0; i < N; i++){
    for(j = 0; j < M; j++){
      a[i][j] = a[i][j] +b[i][j];
    }
  }
}

//42 meio estranha, bastante estranaha na verdade
int unionSet (int N, int v1[N], int v2[N], int r[N]) {
    int count = 0;
    int i = 0;
    for(i; i < N; i++) {
        r[i] = v1[i] || v2[i];
        count += r[i];
    }
    return count;
}


//43 bastante estranaha tambem e meio confusa
int intersectSet (int N, int v1[N], int v2[N],int r[N]){
  int count = 0;
  int i = 0;
  for( i; i < N; i++){
        r[i] = v1[i] && v2[i];
        count += r[i];
    }
    return count;
}


//44 bastante estranha 
int intersectMSet (int N, int v1[N], int v2[N],int r[N]) {
    int count = 0;
    for(int i = 0; i < N; i++) {
        if( v1[i] < v2[i]){
            r[i] = v1[i];
        }
        else {
            r[i] = v2[i];
        }
        count += r[i]; 
    }
    return count;
}


//45 tmb nao entendi
int unionMSet (int N, int v1[N], int v2[N], int r[N]){
	int i;
	int res = 0;
	for (i = 0; i < N; i++){
		if (v1[i] > v2[i]){
			r[i] = v1[i];
			res += v1[i];
		} else {
			r[i] = v2[i];
			res += v2[i];
		}
	}
	return res;
}

//46 funcionou à primeira despois destas ultimas desgraças
int cardinalMSet (int N, int v[N]){
  int i = 0;
  int cardinal = 0;

  for(i; i < N; i++){
    cardinal += v[i];
  }
  return cardinal;

}



//COPIADAS DO MARIO POR MOTIVOS OBVIOS

// Definições para representar as posições e movimentos de um robot
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
    int x, y;
} Posicao;

//47 tipo haskell, mdeu para entender
Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i= 0;
    for(; i< N; i++){
        if(mov[i]== Norte) inicial.y++; // atencao a como se escevem as coisas
        if(mov[i]== Sul) inicial.y--;
        if(mov[i]==Este) inicial.x++;
        if(mov[i]== Oeste) inicial.x--;
    }
    return inicial;
}

//48
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i= 0;
    for(; i< N; i++){
        if(final.y< inicial.y){ // se o y da posicao final for menor entao andou para baixo
            mov[i]= Sul; inicial.y--; // isto é sul
        }
        else if(final.y> inicial.y){  // o y for maior andou para cima
            mov[i]= Norte; inicial.y++;
        }
        else break;
    } // mesmo raciocionio para o x
    int j= i;
    for(; j< N; j++){
        if(final.x< inicial.x){
            mov[j]= Oeste;
            inicial.x--;
        }
        else if(final.x> inicial.x){
            mov[j]= Este;
            inicial.x++;
        }
        else break;
    }
    if(inicial.x!= final.x || inicial.y!= final.y) return -1; // estranho
    else return j;
}

//49
int maiscentral(Posicao pos[], int N) {
    int indice_mais_central = 0;
    int i;
    double distancia_mais_proxima = sqrt(pos[0].x * pos[0].x + pos[0].y * pos[0].y); // faz sentido
    for (i = 1; i < N; i++) {
        double distancia = sqrt(pos[i].x * pos[i].x + pos[i].y * pos[i].y);
        if (distancia < distancia_mais_proxima) { // até faz mais ao menos sentido
            indice_mais_central = i;
            distancia_mais_proxima = distancia;
        }
    }
    return indice_mais_central;
}

//50 estranho pura e simplesmente estranho
int vizinhos (Posicao p, Posicao pos[], int N){
    int i= 0, count= 0;
    for(; i< N; i++){
        if((pos[i].x +1== p.x && pos[i].y== p.y) || (pos[i].x -1== p.x && pos[i].y== p.y) 
        || (pos[i].y +1== p.y && pos[i].x== p.x) || (pos[i].y- 1== p.y && pos[i].x== p.x))count++;
    }
    return count;
}































































int main()
{

  int numero, maior = 0, smaior = 0;

  printf("Escreve uma sequencia terminada em 0: \n");
  scanf("%d", &numero);

  while (numero != 0)
  {
    if (numero > maior && numero > smaior)
    {
      smaior = maior;
      maior = numero;
    }
    else
    {
      smaior = numero;
    }
    scanf("%d", &numero);
  }
  printf("O segundo maior numero é %d \n", smaior);

  return 0;
}
