/* Alihan Demirel 
 */

#include<stdio.h>
#include <string.h>
#define M   25 /* satır sayısı */
#define N	15 /* sütun sayısı */
int wordsearch(char word[], int location[]); /*fonksiyon tanımlama */
int lefttoright(char word[], int n, int startrow, int startcol); /*fonksiyon tanımlama */
int topdown(char word[], int n, int startrow, int startcol); /*fonksiyon tanımlama */
 /* puzzle */
char puzzle [25][15]= { { 'h','c','b','n','z','a','y','d','f','f','y','d','v','k','c' },
		{ 'j','i','m','c','y','v','w','f','i','a','h','r','y','y','u' },
		{ 'n','g','p','z','w','z','g','r','k','e','l','x','m','x','o' },
		{ 's','w','p','h','f','z','c','e','s','i','e','d','x','u','x' },
		{ 'b','l','h','z','o','l','l','s','m','k','s','w','n','w','m' },
		{ 'h','l','o','b','p','p','a','h','a','k','i','j','f','t','c' },
		{ 'e','b','f','p','s','n','i','v','d','v','w','l','z','t','r' },
		{ 'p','k','t','a','g','b','n','z','o','i','b','m','l','n','i' },
		{ 'y','k','f','v','i','n','b','g','j','r','z','y','d','s','u' },
		{ 'l','f','x','n','v','a','v','k','t','k','n','h','r','s','z' }, 
		{ 'c','a','d','i','l','l','a','c','m','a','z','d','a','s','l' },
		{ 'h','o','n','d','a','v','o','l','v','o','b','j','m','g','e' },
		{ 'f','o','r','d','a','u','d','i','r','a','l','e','e','m','x' },
		{ 'o','d','l','c','l','a','n','d','r','o','v','e','r','i','u' },
		{ 'b','t','e','h','o','l','d','e','n','v','o','p','c','t','s' },
		{ 'm','o','u','r','o','l','l','s','r','o','y','c','e','s','a' },
		{ 'w','y','h','y','u','n','d','a','i','l','k','a','d','u','a' },
		{ 'p','o','r','s','c','h','e','l','e','k','i','a','e','b','b' },
		{ 'e','t','m','l','u','i','e','f','o','s','t','y','s','i','p' },
		{ 'u','a','i','e','l','l','d','a','e','w','o','o','b','s','r' },
		{ 'g','o','n','r','n','f','e','r','r','a','r','i','e','h','o' },
		{ 'e','u','i','l','a','m','b','o','r','g','h','i','n','i','t' },
		{ 'o','s','u','z','u','k','i','m','a','e','o','r','z','o','o' },
		{ 't','n','b','e','n','t','l','e','y','n','i','s','s','a','n' },
		{ 'j','a','g','u','a','r','m','o','s','u','b','a','r','u','u' } }; 





int main()
{
	/* puzzle da bulunan soldan-saga veya yukarıdan-aşagı kelimeler */
	char words[33][15]= { "lamborghini", "alfaromeo", "lada", "mazda", 
			"toyota", "nissan", "mini", "jaguar", "mitsubishi", 
			"mercedesbenz", "porsche", "volkswagen", "lexus", "hyundai", 
			"honda", "holden", "ford", "saab", "volvo",	"proton", "peugeot", 
			"chrysler",	"bentley", "bmw", "audi", "rollsroyce",	"kia", 
			"landrover", "jeep", "daewoo", "suzuki", "subaru", "cadillac" };


	for(int i = 0; i < 33; i++){  
		int location[3] = {0};
		wordsearch(words[i],location); /*kelime arama fonksiyonudur kelimeleri ve lokasyonlarını dönderir */
		printf("%-15s %-5d %-5d %-5d\n", 
				words[i], location[0], location[1], location[2]);
	}
     /* kelimeleri ,kelimelerin satır,sütun ve yön bilgisini yazdırır */
	return 0;
}

int wordsearch(char word[], int location[]){
	int n = strlen(word); /* kelime uzunluğu bulma */
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			if (!lefttoright(word, n, i, j)){ /* kelimeyi eger soldan saga bulduysa yön bilgisi 0 dır */
				location[0] = i; /* i. satırda */
				location[1] = j; /* j. sütunda */
				location[2] = 0; /* yön bilgisi belirtır */
				return 1;

			} 

			else if(!topdown(word, n, i, j)){ /* kelimeyi  eger yukarıdan asagı bulduysa yön bilgisi 1 dır */
				location[0] = i; /* i. satırda */
				location[1] = j; /* j. sütunda */
				location[2] = 1; /* yön bilgisi belirtır */
				return 1;
			}

		}	

	}
	location[0] = -1;  /* Kelime yoksa tüm lokasyonları -1 dir */
	location[1] = -1;
	location[2] = -1;
	return 0;
}

int lefttoright(char word[], int n, int startrow, int startcol){ /* Bu fonksiyon uzunlugu bilinen kelimeyi soldan saga  harf harf aramaktadır */
	for (int i = 0 ; i < n; i++){
		

		if (startcol >= N){ /* satırın sonuna kadar kelimeyi arar */
			return 1;
		}
		else if (puzzle[startrow][startcol] != word[i]){ /*kelimeyi harf harf arar  hepsi buludugunda kelimenin bulundugunu belirtir */
			return 1;
		}

		
		else{
			startcol++; /* diger satıra gecirir */
		}
	}
	
	return 0;	

}


int topdown(char word[], int n, int startrow, int startcol) /*Bu fonksiyon uzunlugu bilinen kelimeyi yukarıdan asagı harf harf arar */
{
	for (int i = 0 ; i < n; i++){
		
		if (startrow >= M){ /* sütunun sonuna kadar kelimeyi arar bulamazsa diger sutuna gecer */
			return 1;
		}

		
		else if (puzzle[startrow][startcol] != word[i]){ /*kelimeyi harf harf arar  hepsi buludugunda kelimenin bulundugunu belirtir */
			return 1;
		}

		
		else{
			startrow++; /* diger sütuna gecirir */
		}
	}
	
	return 0;	

}
