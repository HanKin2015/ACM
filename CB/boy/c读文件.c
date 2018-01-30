#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *nodeF = fopen("", "r");
    while(!feof(nodeF)){
		int id;
		//const char label[50]="";
		//fscanf(nodeF, "%d\t%s\n", &id, label);
		fscanf(nodeF, "%d\t%*[^\n]\n", &id);
		if(!id){
			//AddNode(id, label);

		}
    }
    fclose(nodeF);
    return 0;
}

