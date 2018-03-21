#include <cstdio>

int main(){
	int f=0;
	char c=getchar();
	while(c!=EOF){
		if(c=='"'){
			if(!f) printf("``");
			else printf("''");
			f=!f;
		}
		else printf("%c",c);
		c=getchar();
	}
}