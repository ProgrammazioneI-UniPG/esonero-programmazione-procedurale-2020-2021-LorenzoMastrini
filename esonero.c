#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char plaintext[128];
  char key[128];
  printf("Inserisci una stringa da cifrare (MAX 128 caratteri):\t\t\t(doppio invio per proseguire)\n");
  fgets(plaintext, 128, stdin);
  while(getchar() != '\n' && getchar() != EOF);                                 //Pulisce il buffer (evita un doppio invio)
  int l_plaintext = strlen(plaintext);
  int l_key;
  time_t t;
  int scelta;
  printf("\n\nCome vuoi procedere?\n");
  printf("1. Scrivere una stringa di lunghezza pari o maggiore a quella del plaintext\n");
  printf("2. Generare una stringa casualmente\n");
  printf("Digita 1 o 2 per scegliere (digita 0 per uscire): ");
  scanf("%d", &scelta);
  while(getchar() != '\n' && getchar() != EOF);
  while((int)scelta != 0 && (int)scelta != 1 && (int)scelta != 2) {
    printf("L'opzione selezionata non è disponibile. Riprova: ");
    scanf("%d", &scelta);
    while(getchar() != '\n' && getchar() != EOF);                               //Pulisce il buffer
  }

  switch(scelta) {
    case 1:
    printf("\nHai selezionato 1.\n");
    printf("Inserisci una stringa chiave con cui cifrare il testo:\n");
    fgets(key, 128, stdin);
    l_key = strlen(key);
    while(l_key < l_plaintext){
      printf("La stringa chiave deve essere di lunghezza maggiore o uguale a quella del plaintext:\n");
      fgets(key, 128, stdin);
      l_key = strlen(key);
    }
    break;

    case 2:
    srand((unsigned) time(&t));
    printf("\nHai selezionato 2.\n");
    for(int i = 0; i <= l_plaintext; i++) {
    key[i] = (rand() % 128) + 32;                                               //Genera casualmente la stringa
    }
    printf("La chiave generata casualmente è: %s\n", key);
    break;

    case 0:
    exit(0);
    }

  char ciphertext[l_plaintext];
  for(int i = 0; i <= l_plaintext; i++) {                                       //Cifratura
    ciphertext[i] = plaintext[i] ^ key[i];
  }
  printf("\n\nIl testo cifrato è: %s\n", ciphertext);

  for(int i = 0; i <= l_plaintext; i++) {                                       //Decifratura
    plaintext[i] = ciphertext[i] ^ key[i];
  }
  printf("Il testo decifrato è: %s\n", plaintext);

  return 0;
  }
