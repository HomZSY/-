/*
 �ݹ��½��������� 
 author ZSY
 �ķ��� S->(A)|aAb   A->eA'|dSA'   A'->dA'|null 

*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int S();  //�ӳ���P(S) 
int A();  //�ӳ��� P(A) 
int _A();  //�ӳ��� P(A')
int subs;  //���������±� 
char str[20]; //������������ַ��� 

main(){
	int len;  //�����������ַ����ĳ��� 
    int m;  //Ҫ���Ե����Ĵ��� 
    printf("��ǰ���ķ�Ϊ:\n\t S->(A)|aAb \n\t A->eA'|dSA' \n\t A'->dA'|null\n");
    printf("������Լ�����䣬�����������");  
    scanf("%d",&m);  
    while(m--)  
    {  
        printf("��������䣨����20���ַ�����");  
        scanf("%s",str);  
        len = strlen(str);  
        str[len]='#';  
        str[len+1]='\0';  
        S();
        printf("����һ����ȷ����䣬���ϵ�ǰ���ķ�\n");  
        strcpy(str,"");  
        subs = 0;  
    } 
} 

int S(){
	if(str[subs] == '('){
		subs++;
		A();
		if(str[subs] == ')'){
			subs++;
		}else{
			printf("\n����䲻���ϵ�ǰ�ķ�!\n");  
            exit(0);
		}
	}else if(str[subs] != 'a'){
		printf("\n����䲻���ϵ�ǰ�ķ�!\n");  
  		exit(0);
	}else{
		subs++;
		A();
		if(str[subs] == 'b'){
			subs++;
		}else{
			printf("\n����䲻���ϵ�ǰ�ķ�!\n");
            exit(0);
		}
	}
}

int A(){
	if(str[subs] == 'e'){
		subs++;
		_A();
	}else if(str[subs] != 'd'){
		printf("\n����䲻���ϵ�ǰ�ķ�\n");
  		exit(0);
	}else{
		S();
	} 
}

int _A(){
	if(str[subs] == 'd'){
		subs++;
		_A();
	}else if(str[subs] == 'b'){
 		return 0;
	}else if(str[subs] == ')'){
 		return 0;
	}else{
		printf("\n����䲻���ϵ�ǰ�ķ�\n");
  		exit(0);
	}
}