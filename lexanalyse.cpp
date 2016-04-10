/*
	author ZSY �ʷ������� 
*/ 

#include <stdio.h>  
#include <string.h>  
  
char prog[80],token[8],ch;   //prog���ַ����� taken�������������ַ��������ж��Ƿ�Ϊ�ؼ���,ch�浱ǰ�ַ� 
int syn,p,sum;  
char *rwtab[7]={"if","then","else","while","do","begin","end"};  
void analyze(void);  
main()  
{  
    p=0;  
    printf("\n ������һ���ַ���(�� '#' ����):\n");  
      
    do{  
        scanf("%c",&ch);  
        prog[p++]=ch;  
    }while(ch!='#');  
      
    p=0;  
    do{  
        analyze();  
        switch(syn)  
        {  
            case 2:  
                printf("( %-10d%5d )\n",sum,syn);  
            break;  
              
            case -1:  
                printf("��������һ��������ַ���\n");  
                //getch();  
                return 0;  
            break;  
              
            default:   
      	 		printf("( %-10s%5d )\n",token,syn);  
            break;  
        }  
    }while(syn!=0);  
    //getch();  
 }  
  
 /* ���� */
void analyze(void)  
{    
    sum = 0;  
    for(int m=0; m<8; m++)  
        token[m++]= NULL;  
    ch=prog[p++];  
    while((ch==' ')||(ch=='\n'))  
        ch=prog[p++];  
    int m = 0;
    if(((ch<='z')&&(ch>='a'))||((ch<='Z')&&(ch>='A'))) //�����ַ� 
     {   
        while(((ch<='z')&&(ch>='a'))||((ch<='Z')&&(ch>='A')))  
        {  
            token[m++]=ch;  
            ch=prog[p++];  
        }  
        p--;  
        syn = 1;  
  
        for(int  n=0;n<7;n++){
        	if(strcmp(token,rwtab[n])==0)  //�ж��Ƿ�Ϊ�ؼ��� 
	        {   
	            syn = n+3; 
	        }  
        }   
     }  
     else if((ch>='0')&&(ch<='9'))  //�������� 
     {   
        while((ch>='0')&&(ch<='9'))  
        {  
            sum=sum*10+ch-'0';  
            ch=prog[p++];  
        }  
        p--;  
        syn=2;  
    }  
    else    //������� 
    {  
        switch(ch)  
        {  
        case '<':  
            token[m++]=ch;  
            ch=prog[p++];  
            if(ch=='=')  
            {   
                syn=22;  
                token[m++]=ch;  
            }  
            else  
            {    
                syn=35;  
                p--;  
            }  
        break;  
  
        case '>':  
            token[m++]=ch;  
            ch=prog[p++];  
            if(ch=='=')  
            {  
                syn=24;  
                token[m++]=ch;  
            }  
            else  
            {   
                syn=36;  
                p--;  
            }  
        break;  
  
        case '+':  
            token[m++]=ch;  
            ch=prog[p++];  
            if(ch=='+')  
            {  
                syn=17;  
                token[m++]=ch;  
            }  
            else  
            {  
                syn=31;  
                p--;  
            }  
        break;  
  
        case '-':  
            token[m++]=ch;  
            ch=prog[p++];  
            if(ch=='-')  
            {  
                syn=29;  
                token[m++]=ch;  
            }  
            else  
            {   
                syn=32;  
                p--;  
            }  
        break;  
  
        case '!':  
            ch=prog[p++];  
            if(ch=='=')  
            {   
                syn=21;  
                token[m++]=ch;  
            }  
            else  
            {   
                syn=38;  
                p--;  
            }  
        break;  
  
        case '=':  
            token[m++]=ch;  
            ch=prog[p++];  
            if(ch=='=')  
            {  
                syn=25;  
                token[m++]=ch;  
            }  
            else  
            {  
                syn=37;  
                p--;  
            }  
        break;  
  
        case '*':  
            syn=33;  
            token[m++]=ch;  
        break;  
  
        case '/':  
            syn=34;  
            token[m++]=ch;  
        break;  
  
        case '(':   
            syn=52;  
            token[m++]=ch;  
        break;  
  
        case ')':  
            syn=53;  
            token[m++]=ch;  
        break;  
  
        case '{':   
            syn=55;  
            token[m++]=ch;  
        break;  
  
        case '}':   
            syn=56;  
            token[m++]=ch;  
        break;  
  
        case ';':  
            syn=54;  
            token[m++]=ch;  
        break;  
  
        case '\"':  
            syn=57;  
            token[m++]=ch;  
        break;  
  
        case '#':   
            syn=0;  
            token[m++]=ch;  
        break;  
  
        case ':':  
            syn=50;  
            token[m++]=ch;  
        break;  
  
        default:  
            syn=-1;  
        break;  
        }  
    }  
        token[m++]='\0';  
} 
