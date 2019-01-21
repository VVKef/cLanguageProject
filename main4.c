#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
#define MAXNAMESIZE 20
struct A{ 
	char surname[MAXNAMESIZE];
	char name[MAXNAMESIZE];
	int age;
	int gradeC;
	int gradeJava;
	int gradeCplusplus;
	float average;
	char password[MAXNAMESIZE];
};

void eggrafh(struct A *Users,int i,int *sumPtr);
int checkNames(char *surname,struct A *Users,int position);
void createPass(char *surname,char *password);
void modify(struct A *Users,int j);
void view(struct A *Users,int *sumPtr);
void search(struct A *Users,int j,int *sumPtr);
void sort(struct A *Users,int *sumPtr);
void swap(struct A *Users,int x,int y);
void structCopy(struct A UsersA,struct A *UsersB);
int main (){
	char surname[MAXNAMESIZE];
	char name[MAXNAMESIZE];
	int age;
	int gradeC;
	int gradeJava;
	int gradeCplusplus;
	float average;
	char password[MAXNAMESIZE];
	int i;
	int j;
	struct A Users[MAXSIZE]; 
	char choice[10];
	char potential[7]="1";
	int sum=0;
	int loginCounter=0;	
	while(strcmp(potential,"EXIT")!=0){
	printf("Kalws orisate sthn Arxikh Othoni.\n");
	printf("Eisagete 'Register' h 'Login' gia Eggrafh h Sundesh,antistoixa.\n");
	scanf("%s",&choice);
	while((strcmp(choice,"Register")!=0) && (strcmp(choice,"Login")!=0)){ 	//Elegxos egkurothtas.
		printf("Dwste mia apo tis parapanw epiloges.\n");
		scanf("%s",&choice);
	}
	for(i=0;i<=sum;i++){
		if((strcmp(choice,"Register")==0)){
			eggrafh(Users,i,&sum); //Kalw thn Eggrafh.
			loginCounter=loginCounter+1;
			printf("Eisagete 'Register' h 'Login' gia Eggrafh h Sundesh,antistoixa.\n");
			scanf("%s",&choice);
			while((strcmp(choice,"Register")!=0) && (strcmp(choice,"Login")!=0)){
				printf("Dwste mia apo tis parapanw epiloges.\n");
				scanf("%s",&choice);
			}
		}
	}
		if((strcmp(choice,"Login")==0)){
			loginCounter=loginCounter+1;
			if (loginCounter==1){
				printf("Den exete kanei eggrafh.\n");
				printf("Eisagete 'Register' gia Eggrafh.\n");
				scanf("%s",&choice);
				while((strcmp(choice,"Register")!=0)){
					printf("Dwste 'Register' gia Eggrafh.\n");
					scanf("%s",&choice);
				}
				for(i=0;i<=sum;i++){
					if((strcmp(choice,"Register")==0)){
						eggrafh(Users,i,&sum); //Kalw thn Eggrafh.
						loginCounter=loginCounter+1;
						printf("Eisagete 'Register' h 'Login' gia Eggrafh h Sundesh,antistoixa.\n");
						scanf("%s",&choice);
					}
				}
				while((strcmp(choice,"Register")!=0) && (strcmp(choice,"Login")!=0)){
					printf("Dwste mia apo tis parapanw epiloges.\n");
					scanf("%s",&choice);
				}
			}
		}
		printf("Dwste username kai password gia na sundetheite.\n"); //Arxizei to login.
		scanf("%s%s",&surname,&password);
		for(j=0;j<=sum;j++){
			if(strcmp(surname,Users[j].surname)==0 && strcmp(password,Users[j].password)==0){
				while(strcmp(potential,"EXIT")!=0){
					printf("Kalws irthate stin othoni foithth.\n");
					printf("Dwste ena apo parakatw lektika.\n");
					printf("Modify\tView\tSearch\tSort\tEXIT\n\n");
					scanf("%s",&potential);
					while((strcmp(potential,"Modify")!=0) && (strcmp(potential,"View")!=0) && (strcmp(potential,"Search")!=0) && (strcmp(potential,"Sort")!=0) && (strcmp(potential,"EXIT")!=0)){ //Elegxos egkurothtas gia potential.
						printf("Dwsate lanthasmeno lektiko.Prospathiste xana.\n");
						printf("\tModify\tView\tSearch\tSort\tEXIT\n\n");
						scanf("%s",&potential);
					}
					if(strcmp(potential,"Modify")==0){
						printf("%s %s %d %d %d %d\n",Users[j].surname,Users[j].name,Users[j].age,Users[j].gradeC,Users[j].gradeJava,Users[j].gradeCplusplus); //Emfanizw ta stoixeia prin tis dunatothtes.
						modify(Users,j); //Kalw thn Modify.
						
					}
					else if(strcmp(potential,"View")==0){
						view(Users,&sum); // Kalw thn View.
						
					}
					else if(strcmp(potential,"Search")==0){
						search(Users,j,&sum); //Kalw thn Search.
						
					}
					else if(strcmp(potential,"Sort")==0){
						sort(Users,&sum); //Kalw thn Sort.
					}
				}
				for(j=0;j<=7;j++){
					potential[j]="1";
				}
			}
		}
	}
}

void eggrafh(struct A *Users,int i,int *sumPtr){
	float average;
	int flag=0;
	printf("Kalws irthate sto stadio ths eggrafhs.\n");
	printf("Dwste to epwnumo\n");
	scanf("%s",Users[i].surname);
	flag=checkNames(Users[i].surname,Users,i);
	while(flag==0){
		printf("Dwste allo epwnumo\n");
		scanf("%s",Users[i].surname);
		flag=checkNames(Users[i].surname,Users,i);	//Sthn flag paei 0 h 1 gia to ean uparxei to onoma.			
	}
	printf("Dwste to onoma\n");
	scanf("%s",Users[i].name);
	printf("Dwste tin hlikia\n");
	scanf("%d",&(Users[i].age));
	printf("Dwste ton vathmo C\n");
	scanf("%d",&(Users[i].gradeC));
	printf("Dwste ton vathmo Java\n");
	scanf("%d",&(Users[i].gradeJava));
	printf("Dwste ton vathmo C++\n");
	scanf("%d",&(Users[i].gradeCplusplus));
	average=(Users[i].gradeC+Users[i].gradeJava+Users[i].gradeCplusplus)/3.0; //Upologismos Mesou Orou.
	Users[i].average=average;
	createPass(Users[i].surname,Users[i].password); // Dhmiourgia password.
	(*sumPtr)=(*sumPtr)+1;
}

int checkNames(char *surname,struct A *Users,int position){ //To position einai to i apo thn Eggrafh.
	int i;
	int flag=1; // An einai lathos gurnaei 0 an einai swsto gurnaei 1.
	for(i=0;i<MAXSIZE;i++){
		if(i==position){
			continue;
		}
		else {
			if(strcmp(surname,Users[i].surname)==0){
				flag=0;
			}
		}
	}
	return flag;
}

void createPass(char *surname,char *password){ //Pairnei to username k epistrefei to antistoixo password.
	int i;
	for(i=0;i<sizeof(surname);i++){
		if((i % 2)==0){
			if(surname[i]>='A' && surname[i]<='Z'){
				password[i]=surname[i]+32;
			}
			else if(surname[i]>='a' && surname[i]<='z'){
				password[i]=surname[i]-32;
			}
		}
		else {
			password[i]=surname[i];
		}
	}
}

void modify(struct A *Users,int i){
	int potentialNo;
	printf("Poio thes na allaxeis?\n");
	scanf("%d",&potentialNo);
	if(potentialNo==1){
		printf("Dwste to neo epwnumo.\n");
		scanf("%s",Users[i].surname);
		printf("To neo epwnumo einai %s\n",Users[i].surname);
	}
	else if(potentialNo==2){
		printf("Dwste to neo onoma.\n");
		scanf("%s",Users[i].name);
		printf("To neo onoma einai %s\n",Users[i].name);
	}
	else if(potentialNo==3){
		printf("Dwste th nea hlikia.\n");
		scanf("%d",&Users[i].age);
		printf("H nea hlikia einai %d\n",Users[i].age);	
	}
	else if(potentialNo==4){
		printf("Dwste to neo vathmo sthn C.\n");
		scanf("%d",&Users[i].gradeC);
		printf("O neos vathmos sthn C einai %d\n",Users[i].gradeC);	
	}
	else if(potentialNo==5){
		printf("Dwste to neo vathmo sthn Java.\n");
		scanf("%d",&Users[i].gradeJava);	
		printf("O neos vathmos sthn Java einai %d\n",Users[i].gradeJava);
	}
	else if(potentialNo==6){
		printf("Dwste to neo vathmo sthn C++.\n");
		scanf("%d",&Users[i].gradeCplusplus);
		printf("O neos vathmos sthn C++ einai %d\n",Users[i].gradeCplusplus);	
	}
}

void view(struct A *Users,int *sumPtr){
	int i;
	for(i=0;i<=*sumPtr;i++){
		printf("%s %s %d %.2f\n",Users[i].surname,Users[i].name,Users[i].age,Users[i].average2);
	}
	printf("To plithos twn eggegrammenwn foithtwn einai : %d\n",*sumPtr);
}

void search(struct A *Users,int j,int *sumPtr){
	char joker;
	printf("Dwse to arxiko gramma tou epwnumou pou psaxneis kai tha sou emfanisw tous\nen logw foithtes pou 3ekinoun \nme to sugkekrimeno gramma,\nkathws kai ta stoixeia tous.\n");
	scanf(" %c",&joker);
	for(j=0;j<=*sumPtr;j++){
		if(joker==Users[j].surname[0]){
			printf("%s %s %.2f\n",Users[j].surname,Users[j].name,Users[j].average);
		}
	}
}

void sort(struct A *Users,int *sumPtr){ //Ta3inomhsh se Fthinousa.
	int i;
	int j;
	int temp;
	for(i=0;i<*sumPtr;i++){
		for(j=0;j<(*sumPtr-1-i);j++){
			if(Users[j].average<Users[j+1].average){
			swap(Users,j,(j+1));
			}
		}
	}
	printf("Katanemhmenoi oi mesoi oroi,me ta antistoixa onomata einai ws e3hs.\n");
	for(j=0;j<=*sumPtr;j++){
		printf("%s %s %.2f\n",Users[j].surname,Users[j].name,Users[j].average);
	}	
}

void swap(struct A *Users,int x,int y){ //Dhmiourgei temp (Voithitika sthn Sort gia thn antimetathesi.)
	struct A temp;
    structCopy(Users[x],&temp);
    structCopy(Users[y],&Users[x]);
    structCopy(temp,&Users[y]);
}

void structCopy(struct A UsersA,struct A *UsersB){ //Antigrafei ta dedomena A tou B.
	strcpy((*UsersB).password,UsersA.password);
	strcpy((*UsersB).surname,UsersA.surname);
	strcpy((*UsersB).name,UsersA.name);
	(*UsersB).age=UsersA.age;
	(*UsersB).gradeC=UsersA.gradeC;
	(*UsersB).gradeJava=UsersA.gradeJava;
	(*UsersB).gradeCplusplus=UsersA.gradeCplusplus;
	(*UsersB).average=UsersA.average;
}
