#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int turn(int y, int x);
int main(int argc, string argv[]){
    if(argv[1] != '\0'){
        if(argc == 2){
            int l = strlen(argv[1]);//l:�[�K�ܼƪ���
            //�p�G�[�K���r�꦳�D�^��r�h�n���X
            int m=0;
            for(int g=0;g<l;g++){
            
                if((argv[1][g]>=65 && argv[1][g]<=90) || (argv[1][g]>=97 && argv[1][g]<=122)){
                    argv[1][g]=toupper(argv[1][g]);
                }else{
                    m++;
                }
            }
            if(m>1){
                printf("Usage: ./caesar k\n");
                return 1;
            }
            //�}�l�[�K
            printf("plaintext:  ");
            string s = get_string();
            printf("ciphertext: ");
            for(int i=0,j=0,c=0,n=strlen(s);i < n;i++ ){
               if(((int)s[i]>=65 && (int)s[i]<=90) || ((int)s[i]>=97 && (int)s[i]<=122)){
                   c=((int)argv[1][j%l]-65)+(int)s[i];//�[�K�r��ASCII+�n�ܪ��r
                    if( isupper(s[i])){
                        printf("%c",toupper((char) turn(65,c)));
                    }else if(islower(s[i])){
                        printf("%c",tolower((char) turn(97,c)));
                    }
                   j++;//j:�`�@�n�[�K���r��
               }else{
                   printf("%c",s[i]);
               }
            }
            
            printf("\n");
           return 0; 
        }else{
            printf("Usage: ./caesar k\n");
            return 1;
        }
        
    }else{
        printf("Usage: ./caesar k\n");
        return 1;
    }
    
}

int turn(int y, int x){
    int count=0;
    count=((x-y) % 26) + y;
    return count;
}